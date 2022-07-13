# 문제명: 큰 놈, 작은 놈, 같은 놈 / 비교, for문 테케

testcase = int(input())

for t in range(1, testcase + 1):
    n1, n2 = map(int, input().split())

    if n1 > n2:
        print('#' + str(t), '>')
    elif n1 == n2:
        print('#' + str(t), '=')
    elif n1 < n2:
        print('#' + str(t), '<')