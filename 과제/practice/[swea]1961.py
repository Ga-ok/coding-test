# 숫자 배열 회전

def rotate90(temp):
    r_graph = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            r_graph[j][n - 1 - i] = temp[i][j]
    return r_graph


t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    graph=[]
    for _ in range(n):
        temp=list(map(int, input().split()))
        graph.append(temp)

    graph90=rotate90(graph)
    graph180=rotate90(graph90)
    graph270=rotate90(graph180)

    rotate_list=[]
    rotate_list.append(graph90)
    rotate_list.append(graph180)
    rotate_list.append(graph270)

    result=[[0]*3 for _ in range(n)]
    for i in range(n):
        for j in range(3):
            result[i][j]=rotate_list[j][i]

    print('#'+str(testcase))
    for i in result:
        for j in i:
            for k in j:
                print(k, end='')
            print('', end=' ')
        print()









