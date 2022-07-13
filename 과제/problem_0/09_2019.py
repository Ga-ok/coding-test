# 문제명: 더블더블 / for문 문제

n = int(input())

result = 1
print(result, end=' ')

for i in range(1, n + 1):
    result = result * 2
    print(result, end=' ')