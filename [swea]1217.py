# 거듭제곱

def exp(m):
    if m == 0:
        return 1

    return n * exp(m - 1)


for testcase in range(1, 11):
    tn = int(input())

    n, m = map(int, input().split())
    result = exp(m)

    print('#' + str(testcase), result)