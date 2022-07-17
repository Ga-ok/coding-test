# 새로운 불면증 치료법

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    cnt=[0]*10
    i=0
    while True:
        if cnt.count(0)==0:
            break

        temp=str(n*(i+1))
        for t in temp:
            cnt[int(t)]+=1
        i+=1

    print('#'+str(testcase), i*n)