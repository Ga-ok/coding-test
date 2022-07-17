# 알파벳을 숫자로 변환

alpha='ABCDEFGHIJKLMNOPQRSTUVWXYZ'

dic=dict()
for i in range(len(alpha)):
    if alpha[i] not in dic:
        dic[alpha[i]]=0
    dic[alpha[i]]=(i+1)

s=input()
result=[]
for i in s:
    result.append(dic[i])

for r in result:
    print(r, end=' ')

