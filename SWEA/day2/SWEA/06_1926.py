# 간단한 369게임

n=int(input())

result=''
for i in range(1, n+1):

    if i < 10:
        if str(i) in '369':
            result+='- '
        else:
            result+=str(i)+' '
    else:
        temp=''
        for s in range(len(str(i))):
            if str(i)[s] in '369':
                temp+='-'

        if temp=='':
            result+=str(i)+' '
        else:
            result+=temp+' '

print(result)