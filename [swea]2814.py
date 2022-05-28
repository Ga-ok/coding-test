# 최장경로

t=int(input())

def dfs(i, cnt):
    visited[i] = 1

    global max_cnt
    for j in range(1, n+1):
        if visited[j]==0 and adj[i][j]==1:
            visited[j]=1
            dfs(j, cnt+1)
            visited[j]=0

    if cnt>max_cnt:
        max_cnt=cnt


for testcase in range(1, t+1):
    n,m=map(int, input().split())

    graph=[]
    for i in range(m):
        temp=list(map(int, input().split()))
        graph.append(temp)

    adj=[[0]*(n+1) for _ in range(n+1)]
    max_cnt = 0
    for g in graph:
        x, y = g
        adj[x][y]=1
        adj[y][x]=1


    for i in range(1, n+1):
        visited = [0] * (n + 1)
        dfs(i, 1)


    print('#'+str(testcase), max_cnt)

