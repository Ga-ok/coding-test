# 서울_임베디드_21반_이가옥

# SW전공_필수 문제풀이
# 1961. 숫자 배열 회전

t=int(input())

# 숫자 배열 시계방향으로 90도 회전
def rotate_90():
    temp=[[0 for _ in range(n)] for _ in range(n)]
    for i in range(len(temp)):
        for j in range(len(temp)):
            temp[j][n-i-1]=graph[i][j]
    return temp

# 숫자 배열 시계방향으로 180도 회전
def rotate_180():
    temp = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(len(temp)):
        for j in range(len(temp)):
            temp[n-i-1][n-j-1] = graph[i][j]
    return temp

# 숫자 배열 시계방향으로 270도 회전
def rotate_270():
    temp = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(len(temp)):
        for j in range(len(temp)):
            temp[n-j-1][i] = graph[i][j]
    return temp


for testcase in range(1, t+1):
    n=int(input())

    graph=[]
    for _ in range(n):
        temp=list(map(int, input().split()))
        graph.append(temp)

    # 숫자 배열 회전 (90, 180, 270)
    graph_90 = rotate_90()
    graph_180 = rotate_180()
    graph_270 = rotate_270()

   # 문제에서 제시한 형태로 결과값 출력
    print('#'+str(testcase))
    for i in range(n):
        for s in graph_90[i]:
            print(s, end='')
        print(' ', end='')
        for s in graph_180[i]:
            print(s, end='')
        print(' ', end='')
        for s in graph_270[i]:
            print(s, end='')
        print()
