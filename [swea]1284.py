# 수도요금 경쟁

t=int(input())
for testcase in range(1, t+1):
    p, q, r, s, w = map(int, input().split())

    result=[]
    result.append(w*p)
    temp=result[0]

    if w<=r:
        result.append(q)
        if temp > result[-1]:
            temp = result[-1]
    else:
        result.append(q+(w-r)*s)
        if temp > result[-1]:
            temp = result[-1]

    print('#'+str(testcase), temp)