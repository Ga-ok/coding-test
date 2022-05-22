# round 함수를 이용하면 반올림을 쉽게 구할 수 있음!!

t=int(input())
for testcase in range(1, t+1):
    num = list(map(int, input().split()))

    num.sort()
    num=num[1:-1]

    result=sum(num)/8
    result2=int(result)

    temp=list(str(result).split('.'))
    temp=temp[-1][0]
    if int(temp)<5:
        result=result2
    else:
        result=result2+1

    print('#'+str(testcase), result)