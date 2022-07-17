# 최빈수 구하기

t=int(input())

for testcase in range(1, t+1):
    n=int(input())

    point=list(map(int, input().split()))

    dic = dict()
    for i in range(101):
        dic[i] = 0

    for p in point:
        dic[p]+=1

    max_point=max(dic.values())
    result=0
    for key, value in dic.items():
        if max_point==value:
            result=key

    print('#'+str(testcase), result)