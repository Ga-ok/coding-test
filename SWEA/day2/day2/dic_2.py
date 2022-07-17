lst=['MC','BTS','BTS', 'MC', 'BTS']

dic=dict()
for i in lst:
    dic[i]=0

for i in lst:
    dic[i]+=1

print(dic)