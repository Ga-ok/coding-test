# 문제명: N줄 덧셈 / for 덧셈

n = int(input())

result = 0
for i in range(1, n + 1):
    result += i

print(result)