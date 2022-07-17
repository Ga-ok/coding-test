# 서울_임베디드_21반_이가옥

# SW전공_선택 문제풀이
# 1226. 미로 1

from collections import deque
def bfs(s):

    queue=deque()
    visited=[[0]*16 for _ in range(16)]  # 방문한 지점 중복 방지를 위한 visited 배열

    queue.append(s)
    visited[s[0]][s[1]]=1

    dx=[-1, 0, 1, 0]
    dy=[0, -1, 0, 1]

    result=0
    while len(queue)>0: # 길을 모두 탐색한 경우 반복문 종료
        x, y = queue.popleft()
        if x==end[0] and y==end[1]: # 도착지점일 경우 반복문 종료
            result=1
            break

        for d in range(4):
            nx = x+dx[d]
            ny = y+dy[d]

            if 0<=nx<16 and 0<=ny<16:      # 다음 방문할 지점이 miro의 범위내에 있고,
                if visited[nx][ny]==0:     # 방문하지 않았고,
                    if miro[nx][ny]!='1':  # 벽이 아닐 경우,
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
                start=[i, j]    # 미로의 출발점 탐색
            elif miro[i][j]=='3':
                end=[i, j]      # 미로의 도착점 탐색

    print("#"+str(testcase), bfs(start))