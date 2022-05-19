# 길찾기
from collections import deque


def bfs():
    dq = deque()
    dq.append(stack1[0])
    dq.append(stack2[0])

    flag=0
    while len(dq) != 0:
        item = dq.popleft()

        if item==99:
            flag=1
            break

        if stack1[item] != 0:
            dq.append(stack1[item])
        if stack2[item] != 0:
            dq.append(stack2[item])

    return flag

for testcase in range(1, 11):
    tn, load = map(int, input().split())
    points=list(map(int, input().split()))

    stack1=[0]*100
    stack2=[0]*100
    for i in range(len(points)):
        if i%2 != 0:
            if stack1[points[i-1]] == 0:
                stack1[points[i-1]] = points[i]
            else:
                stack2[points[i-1]] = points[i]



    result=bfs()
    print('#'+str(testcase), result)


