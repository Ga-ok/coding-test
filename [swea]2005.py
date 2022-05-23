# 파스칼의 삼각형

t=int(input())

for testcase in range(1, t+1):
    n=int(input())
    result=[]

    for i in range(n):
        if i==0:
            result.append([1])
        elif i==1:
            result.append([1, 1])
        else:
            temp=result[-1]
            r=[1]
            for t in range(len(temp)-1):
                r.append(temp[t]+temp[t+1])
            r.append(1)
            result.append(r)

    print('#'+str(testcase))
    for i in range(n):
        for st in result[i]:
            print(st, end=' ')
        print()


