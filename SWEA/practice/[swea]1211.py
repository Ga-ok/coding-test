# ladder2

def bfs(start):
    visited=[[0]*100 for _ in range(100)]

    x=start[0]
    y=start[1]

    dx=[0, 0]
    dy=[-1, 1]

    visited[x][y]=1

    dis=0
    while True:

        flag=0
        for i in range(len(dy)):
            nx=x+dx[i]
            ny=y+dy[i]

            if 0<=nx<100 and 0<=ny<100:
                if visited[nx][ny]==0:
                    if ladder[nx][ny]==1:
                        x=nx
                        y=ny
                        visited[x][y]=1
                        dis+=1

                        flag=1
                        break
        if flag==0:
            nx=x+1
            if 0<nx<99 and visited[nx][y]==0 and ladder[nx][y]==1:
                x=nx
                dis+=1
                visited[x][y]=1
            else:
                break

    return [dis, start[1]]

for testcase in range(1, 11):
    tn=int(input())

    ladder=[]
    for i in range(100):
        temp=list(map(int, input().split()))
        ladder.append(temp)

    result=[]
    for i in range(100):
        if ladder[0][i]==1:
        	distance, col = bfs([0, i])
        	result.append([distance, col])

    result.sort(key=lambda x:(x[0], -x[1]))
    print('#'+str(testcase), result[0][1])