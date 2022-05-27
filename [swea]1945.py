# 간단한 소인수 분해

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    result=[]
    target=[2, 3, 5, 7, 11]
    while n>1:
        for i in target:
            if n%i==0:
                cnt=0
                while n%i==0:
                    n=n//i
                    cnt+=1
                result.append(cnt)
            else:
                result.append(0)


    print('#'+str(testcase), end=' ')
    for r in result:
        print(r, end=' ')
