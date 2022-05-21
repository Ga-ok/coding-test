# 미로 1

from collections import deque
def bfs(s):

    queue=deque()
    visited=[[0]*16 for _ in range(16)]

    queue.append(s)
    visited[s[0]][s[1]]=1

    dx=[-1, 0, 1, 0]
    dy=[0, -1, 0, 1]

    result=0
    while len(queue)>0:
        x, y = queue.popleft()
        if x==end[0] and y==end[1]:
            result=1
            break

        for d in range(4):
            nx = x+dx[d]
            ny = y+dy[d]

            if 0<=nx<16 and 0<=ny<16:
                if visited[nx][ny]==0:
                    if miro[nx][ny]!='1':
                        queue.append([nx, ny])
                        visited[nx][ny]=1

    return result

for testcase in range(1, 11):
    tn = int(input())

    miro=[]
    for _ in range(16):
        temp=list(input())
        miro.append(temp)

    start=[]
    end=[]
    for i in range(16):
        for j in range(16):
            if miro[i][j]=='2':
                start=[i, j]
            elif miro[i][j]=='3':
                end=[i, j]

    print("#"+str(testcase), bfs(start))