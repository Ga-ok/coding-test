lst=['MC', 'BTS', 'BTS', 'MC', 'BTS']
go = dict()

for i in lst:
    if (i not in go): go[i]=0
    go[i]+=1

print(go['MC'])
print(go['BTS'])
