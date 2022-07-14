# 쉬운 거스름돈

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    result=[]

    for money in [50000, 10000, 5000, 1000, 500, 100, 50, 10]:
        if n>=money:
            temp=n//money
            result.append(temp)
            n=n-(temp*money)

        else:
            result.append(0)

    print('#'+str(testcase))
    for t in result:
        print(t, end=' ')

