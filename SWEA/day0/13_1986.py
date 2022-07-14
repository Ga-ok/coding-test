# 문제명: 지그재그 숫자 / for문 돌리기 응용

t = int(input())

for testcase in range(1, t + 1):
    n = int(input())

    result = 0
    for i in range(1, n + 1):
        if i % 2 == 0:
            result -= i
        else:
            result += i
    print('#' + str(testcase), result)