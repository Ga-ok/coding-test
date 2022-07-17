import json
import requests
import urllib.request

url = 'http://api.tvmaze.com/singlesearch/shows?q=narcos&embed=episodes'
r = requests.get(url)

dic = json.loads(r.text)

url = dic['image']['medium']
urllib.request.urlretrieve(url, './img/img.jpg')

n=2
for i in dic['_embedded']['episodes']:
    url = i['image']['medium']
    urllib.request.urlretrieve(url, './img/img'+str(n)+'.jpg')
    n+=1




