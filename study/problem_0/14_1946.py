# 문제명: 간단한 압축 풀기 / for문 돌리기 응용

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    result=''
    for i in range(n):
        s, num = input().split()
        num=int(num)
        result+= (s*num)

    print('#'+str(testcase))
    for i in range(len(result)):
        print(result[i], end='')
        if i%10 != 0 and i % 10 == 9:
            print()
