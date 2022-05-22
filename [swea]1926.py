# 최대상금

n=int(input())

result=''
for i in range(1, n+1):
    temp=''
    t=str(i)
    t2=list(t)

    while len(t2)>0:
        item=t2.pop()
        if item in ['3', '6', '9']:
            temp+='-'

    if temp=='':
        result+=t+' '
    if temp!='':
        result+=temp+' '

print(result)

