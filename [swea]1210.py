# ladder1
def bfs(start):

    result=0

    dr=[0, 0]
    dc=[-1, 1]

    x=start[0]
    y=start[1]

    visited=[[0]*100 for _ in range(100)]
    visited[x][y]=1

    while True:

        flag=0
        for i in range(len(dc)):
            nx=x+dr[i]
            ny=y+dc[i]

            if 0<=nx<100 and 0<=ny<100:
                if ladder[nx][ny]==1:
                    if visited[nx][ny]==0:
                        x=nx
                        y=ny
                        visited[x][y]=1

                        flag=1
                        break

        if flag==0:
            nx=x-1
            if 0<nx<100 and ladder[nx][y]==1 and visited[nx][y]==0:
                x=nx
                visited[x][y]=1
            else:
                result=y
                break

    return result

for testcase in range(1, 11):
    tn = int(input())

    ladder=[]
    for i in range(100):
        temp = list(map(int, input().split()))
        ladder.append(temp)

    # 도착점 위치 찾기(end_r, end_c)
    end_r=0
    end_c=0
    for i in range(100):
        for j in range(100):
            if ladder[i][j]==2:
                end_r=i
                end_c=j

    # bfs를 이용하여 길 찾기
    result2=bfs([end_r, end_c])

    print('#'+str(testcase), result2)

