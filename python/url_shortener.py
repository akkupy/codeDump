import tkinter as tk
import pyshorteners

def shorten():
      #creating instance of shortner class
      shortener=pyshorteners.Shortener()
      short_url=shortener.tinyurl.short(longurl_entry.get())
      print(shorturl_entry.insert(0,short_url))

# creating root window
root = tk.Tk()
root.title("URL Shortener")
root.geometry("300x150")


longurl_label=tk.Label(root,text="Enter URL")
longurl_entry=tk.Entry(root)
shorturl_label=tk.Label(root,text="Shortened URL")
shorturl_entry=tk.Entry(root)
shorten_button=tk.Button(root,text="Shorten URL", command=shorten)

longurl_label.pack()
longurl_entry.pack()
shorturl_label.pack()
shorturl_entry.pack()
shorten_button.pack()
root.mainloop()
