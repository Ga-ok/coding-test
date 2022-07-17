import json
import requests
import urllib.request

url = 'http://api.tvmaze.com/singlesearch/shows?q=narcos&embed=episodes'
r = requests.get(url)
print(r.text)
