### Amazon Review Scraper
# Overview
This is a Python script for scraping Amazon product reviews. It combines two scripts - one for downloading Amazon review pages and another for parsing those downloaded HTML pages to extract review information.

# Features
- Download Amazon review pages for specified product IDs.
- Parse downloaded HTML pages to extract review information such as title, review text, rating, date, user, and helpful votes.
- Save the extracted review data in a CSV file for further analysis.

# Prerequisites
- Python 3.x (Python 2.x is also supported with minor modifications)
- Required Python packages (install using pip install package_name):
> argparse
> codecs
> csv
> fnmatch
> re
> urllib (for Python 2.x)
> urllib.request (for Python 3.x)

# Usage
1 Clone or download the repository to your local machine.
2 Open a terminal and navigate to the directory containing the script files.
3 Run the scraper using the following command:

```
python scraper.py -d <directory_path> -o <output_file_path> <product_ids>
```

Replace <directory_path> with the path to the directory containing the downloaded Amazon review HTML pages, <output_file_path> with the desired output CSV file path, and <product_ids> with one or more Amazon product IDs for which you want to scrape reviews.
This will download and parse Amazon review pages for the specified product IDs and save the results in the specified CSV file.

# Options
- `-d` or `--dir`: Directory with the data for parsing (required).
- `-o` or `--outfile`: Output file path for saving the reviews in CSV format (required).
- `-r` or `--maxretries`: Maximum retries to download a file. Default is 3 (optional).
- `-t` or `--timeout`: Timeout in seconds for HTTP connections. Default is 180 (optional).
- `-p` or `--pause`: Seconds to wait between HTTP requests. Default is 1 (optional).
- `-m` or `--maxreviews`: Maximum number of reviews per item to download. Default is unlimited (optional).
- `-c` or `--captcha`: Retry on captcha pages until captcha is not asked. Default is to skip (optional).
- `ids`: Product IDs for which to download reviews (at least one required).
