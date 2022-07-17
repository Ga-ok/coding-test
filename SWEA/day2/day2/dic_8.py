a=['MC', 'BTS', 'BTS', 'MC', 'BTS']

dic=dict()
for i in a:
    if i not in dic:
        dic[i]=0
    dic[i]+=1

for key, value in dic.items():
    print(key, ':', value, '개')
