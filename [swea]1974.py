# 스도쿠 검증

def col_check():
    # 가로 검증
    for i in range(9):
        temp=set()
        for j in range(9):
            temp.add(graph[i][j])
        if len(temp)!=9:
            return False
    return True

def row_check():
    # 세로 검증
    for i in range(9):
        temp=set()
        for j in range(9):
            temp.add(graph[j][i])
        if len(temp)!=9:
            return False
    return True

def mini_check():

    start=[[0, 0], [0, 3], [0, 6], [3, 0], [3, 3], [3, 6], [6, 0], [6, 3], [6, 6]]

    # 3x3체크
    for s in start:
        sr=s[0]
        sc=s[1]
        temp=set()
        for i in range(3):
            for j in range(3):
                temp.add(graph[sr+i][sc+j])
        if len(temp)!=9:
            return False
    return True



t = int(input())
for testcase in range(1, t+1):
    graph=[]

    for _ in range(9):
        temp=list(map(int, input().split()))
        graph.append(temp)

    result=0
    if col_check()==True and row_check()==True and mini_check()==True:
        result=1
    print('#'+str(testcase), result)