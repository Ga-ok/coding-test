# 조합문제는 멱집합으로 풀어야 시간초과가 나지 않는다!
# {1, 2, 3, 4, 5}의 부분집합을 구한다고 생각하면, {1, 2} / {3, 4, 5}로 나눌 수 있다.
t=int(input())

def dfs(i, point, cal):
    global max_point

    if cal > limit:
        return
    if point > max_point:
        max_point=point
    if i==n:
        return

    dfs(i+1, point, cal)
    dfs(i+1, point+info[i][0], cal+info[i][1])

for testcase in range(1, t+1):
    n, limit = map(int, input().split())

    info=[]
    max_point=0
    for _ in range(n):
        temp=list(map(int, input().split()))
        info.append(temp)

    dfs(0, 0, 0)
    print('#'+str(testcase), max_point)
