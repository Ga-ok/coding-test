# 간단한 압축풀기

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    graph=[]
    for _ in range(n):
        x, y =map(str, input().split())
        graph.append([x, int(y)])

    result=[]
    temp=''
    for x, y in graph:
        for i in range(y):
            temp+=x
            if len(temp)==10:
                result.append(temp)
                temp=''
        if y==graph[-1][1]:
            result.append(temp)

    print('#'+str(testcase))
    for r in result:
        print(r)

