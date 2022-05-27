#새로운 불면증 치료법

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    result=set()
    cnt=0

    temp=''
    while True:
        cnt+=1
        temp=str(n*cnt)

        for t in list(temp):
            result.add(t)

        if len(result)==10:
            break

    print('#'+str(testcase), temp)