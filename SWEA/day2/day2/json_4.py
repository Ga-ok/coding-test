import json

f1=open('output.txt', 'r')

txt = f1.read()
a = json.loads(txt) # str -> dict

for i in a['widget']['window'].keys():
    print(i, end=' ')
print()

for i in a['widget']['image'].values():
    print(i, end=' ')
print()

for i in a['widget']['text'].items():
    print(i, end=' ')
    
f1.close()