# 서울_임베디드_21반_이가옥

# SW전공_필수 문제풀이
# 1974. 스도쿠 검증


# 가로줄, 세로줄 스도쿠 검증
def col_row(lst):
    temp=set(lst)
    if len(temp)==len(lst):
        return 1
    return 0

# 3X3 네모칸 스도쿠 검증
def square(lst):
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
    # 가로줄 스도쿠 검증
    for i in range(len(graph)):
        result+=col_row(graph[i])

    # 세로줄 스도쿠 검증
    for i in range(len(graph)):
        temp=[]
        for j in range(len(graph)):
            temp.append(graph[j][i])
        result+=col_row(temp)

    # 3X3 네모칸 스도쿠 검증
    for i in range(0, 7, 3):
        for j in range(0, 7, 3):
            temp2 = []
            for k in range(3):
                temp2.append(graph[i+k][j:j+3])
            result+=square(temp2)

    # 가로9줄, 세로9줄, 네모칸9개 => 27개의 검증이 모두 1(true)여야 모든 스도쿠 검증 완료!
    if result==27:
        print('#'+str(testcase), 1)
    else:
        print('#'+str(testcase), 0)


