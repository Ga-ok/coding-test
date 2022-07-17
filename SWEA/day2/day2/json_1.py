import json

a=dict()
a['name']='sanghi'
a['price']=4900
a['brand']='mcdonald'

b=json.dumps(a, indent=4)
print(b)