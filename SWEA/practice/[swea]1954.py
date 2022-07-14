# 달팽이 숫자

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    result=[[1]*n for _ in range(n)]
    visited = [[0] * n for _ in range(n)]

    num=1
    dist=n-1
    direction=0

    dx=[0, 1, 0, -1]
    dy=[1, 0, -1, 0]

    x=0
    y=0
    visited[0][0]=1

    while True:

        for _ in range(dist):
            nx = x+dx[direction]
            ny = y+dy[direction]

            if 0<=nx<n and 0<=ny<n:
                if visited[nx][ny]==0:
                    num+=1
                    result[nx][ny]=num
                    x=nx
                    y=ny
                    visited[nx][ny]=1
        direction=(direction+1)%4

        if n%2!=0:
            if x==int(n//2) and y==int(n//2):
                break
        elif n%2==0:
            if x==int(n//2) and y==n//2 - 1:
                break

    print('#'+str(testcase))
    for r in range(n):
        for c in range(n):
            print(result[r][c], end=' ')
        print()



