import json

a=dict()
a['name']='sanghi'
a['price']=4900
a['brand']='mcdonald'

b=json.dumps(a, indent=4) # json으로 바꾸기

c=json.loads(b) # 파이썬으로 불러오기
print(c)