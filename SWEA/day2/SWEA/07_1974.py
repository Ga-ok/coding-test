# 스도쿠 검증 *****

def col_row(lst): # 가로줄, 세로줄 확인
    temp=set(lst)
    if len(temp)==len(lst):
        return 1
    return 0


def square(lst): # 네모칸 확인
    temp=set()
    for i in range(len(lst)):
        for j in lst[i]:
            temp.add(j)
    if len(temp)==9:
        return 1
    else:
        return 0

t=int(input())
for testcase in range(1, t+1):

    graph=[]
    for _ in range(9):
        temp=list(map(int, input().split()))
        graph.append(temp)

    result=0
    # 가로줄 확인
    for i in range(len(graph)):
        result+=col_row(graph[i])

    # 세로줄 확인
    for i in range(len(graph)):
        temp=[]
        for j in range(len(graph)):
            temp.append(graph[j][i])
        result+=col_row(temp)

    # 네모칸 확인
    for i in range(0, 7, 3):
        for j in range(0, 7, 3):
            temp2 = []
            for k in range(3):
                temp2.append(graph[i+k][j:j+3])
            result+=square(temp2)

    if result==27:
        print('#'+str(testcase), 1)
    else:
        print('#'+str(testcase), 0)



