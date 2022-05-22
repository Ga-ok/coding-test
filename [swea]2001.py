# 파리 퇴치

t=int(input())

for testcase in range(1, t+1):
    n, m = map(int, input().split())

    graph=[]
    for _ in range(n):
        temp=list(map(int, input().split()))
        graph.append(temp)

    r_list=[]
    for i in range(n-m+1):
        for j in range(n-m+1):
            result=0
            for m1 in range(m):
                for m2 in range(m):
                    result+=graph[i+m1][j+m2]
            r_list.append(result)

    r_list.sort(reverse=True)
    print('#'+str(testcase), r_list[0])
