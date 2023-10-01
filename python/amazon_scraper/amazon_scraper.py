#!/usr/bin/env python
# -*- coding: utf-8 -*-

import argparse
import os
import sys
import codecs
import csv
import fnmatch
import re
import socket
from contextlib import closing
from time import sleep

if sys.version_info[0] >= 3:
    import html
    import urllib.request as request
    import urllib.error as urlerror
else:
    import urllib2 as request
    import urllib2 as urlerror

idre = re.compile('product\-reviews/([A-Z0-9]+)/ref\=cm_cr_arp_d_hist', re.MULTILINE | re.S)
contentre = re.compile(
    'cm_cr-review_list.*?>(.*?)(?:askReviewsPageAskWidget|a-form-actions a-spacing-top-extra-large|/html)',
    re.MULTILINE | re.S)
blockre = re.compile('a-section review\">(.*?)report-abuse-link', re.MULTILINE | re.S)
ratingre = re.compile('star-(.) review-rating', re.MULTILINE | re.S)
titlere = re.compile('review-title.*?>(.*?)</a>', re.MULTILINE | re.S)
datere = re.compile('review-date">(.*?)</span>', re.MULTILINE | re.S)
reviewre = re.compile('base review-text">(.*?)</span', re.MULTILINE | re.S)
userre = re.compile('profile\/(.*?)["/].*?\<\/div\>.*?\<\/div\>.', re.MULTILINE | re.S)
helpfulre = re.compile('review-votes.*?([0-9]+).*?([0-9]+)', re.MULTILINE | re.S)

def download_page(url, referer, maxretries, timeout, pause):
    tries = 0
    htmlpage = None
    while tries < maxretries and htmlpage is None:
        try:
            code = 404
            req = request.Request(url)
            req.add_header('Referer', referer)
            req.add_header('User-agent',
                           'Mozilla/5.0 (X11; Linux i686) AppleWebKit/534.30 (KHTML, like Gecko) Ubuntu/11.04 Chromium/12.0.742.91 Chrome/12.0.742.91 Safari/534.30')
            with closing(request.urlopen(req, timeout=timeout)) as f:
                code = f.getcode()
                htmlpage = f.read()
                sleep(pause)
        except (urlerror.URLError, socket.timeout, socket.error):
            tries += 1
    if htmlpage:
        return htmlpage.decode('utf-8'), code
    else:
        return None, code

def get_review_filenames(input_dir):
    for root, dirnames, filenames in os.walk(input_dir):
        for filename in fnmatch.filter(filenames, '*.html'):
            yield os.path.join(root, filename)

def main():
    parser = argparse.ArgumentParser(description='Amazon review scraper')
    parser.add_argument('-d', '--dir', help='Directory with the data for parsing', required=True)
    parser.add_argument('-o', '--outfile', help='Output file path for saving the reviews in csv format', required=True)
    parser.add_argument('-r', '--maxretries', help='Max retries to download a file. Default: 3', required=False, type=int, default=3)
    parser.add_argument('-t', '--timeout', help='Timeout in seconds for http connections. Default: 180', required=False, type=int, default=180)
    parser.add_argument('-p', '--pause', help='Seconds to wait between http requests. Default: 1', required=False, default=1, type=float)
    parser.add_argument('ids', metavar='ID', nargs='+', help='Product IDs for which to download reviews')

    args = parser.parse_args()
    reviews = dict()

    with codecs.open(args.outfile, 'w', encoding='utf8') as out:
        writer = csv.writer(out, lineterminator='\n')
        for id_ in args.ids:
            basepath = args.dir + os.sep + id_
            for page in get_review_filenames(basepath):
                with codecs.open(page, mode='r', encoding='utf8') as file:
                    htmlpage = file.read()
                if not idre.search(htmlpage):
                    continue
                id_ = idre.findall(htmlpage)[0]
                print(id_, page)
                htmlpage = contentre.findall(htmlpage)[0]
                for block in blockre.findall(htmlpage):
                    title = titlere.findall(block)[0]
                    reviewtext = reviewre.findall(block)[0]
                    if sys.version_info[0] >= 3:
                        try:
                            title = html.unescape(title)
                        except Exception:
                            pass
                        try:
                            reviewtext = html.unescape(reviewtext)
                        except Exception:
                            pass
                    rating = int(ratingre.findall(block)[0])
                    date = datere.findall(block)[0]
                    user = 'ANONYMOUS'
                    usermatch = userre.findall(block)
                    if usermatch:
                        user = usermatch[0]
                    helptot = 0
                    helpyes = 0
                    helpmatch = helpfulre.findall(block)
                    if helpmatch:
                        helptot = int(helpmatch[0][0])
                        helpyes = int(helpmatch[0][1])
                        if helpyes > helptot:
                            helptot, helpyes = helpyes, helptot

                    if rating >= 4:
                        binaryrating = 'positive'
                    else:
                        binaryrating = 'negative'
                    if sys.version_info[0] >= 3:
                        review_row = [id_, date, user, title, reviewtext, rating, binaryrating, helptot, helpyes]
                    else:
                        review_row = [id_, unicode.encode(date, encoding='ascii', errors='ignore'),
                                      unicode.encode(user, encoding='ascii', errors='ignore'),
                                      unicode.encode(title, encoding='ascii', errors='ignore'),
                                      unicode.encode(reviewtext, encoding='ascii', errors='ignore'), rating,
                                      binaryrating, helptot, helpyes]
                    writer.writerow(review_row)

if __name__ == '__main__':
    main()
