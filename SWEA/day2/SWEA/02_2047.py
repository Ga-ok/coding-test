# 신문 헤드라인

alpha_upper='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
alpha_lower='abcdefghijklmnopqrstuvwxyz'

dic=dict()
for i in range(len(alpha_lower)):
    if alpha_lower[i] not in dic:
        dic[alpha_lower[i]]=0
    dic[alpha_lower[i]]=alpha_upper[i]

sentence=input()
result=''
for i in range(len(sentence)):
    if sentence[i] in dic:
        result+=dic[sentence[i]]
    else:
        result+=sentence[i]

print(result)