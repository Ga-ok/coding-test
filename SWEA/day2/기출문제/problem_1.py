# 민철이네 복호화 (1시간 10분 걸림ㅠㅠ) ****

pwd_s=list(input())
key_s=list(input())

result=pwd_s
for i in range(len(pwd_s)):
    j=-1
    while len(key_s)!=0:
        j+=1
        if pwd_s[i]==key_s[j]:
            result[i]='0'
            key_s.pop(j)
            break
        else:
            break

s=''
for r in result:
    if r != '0':
        s+=r

print(s)

