# 문제명: 몫과 나머지 출력하기 / for로 테케 첫 등장, % 사용

t=int(input())

for testcase in range(1, t+1):
    n1, n2 = map(int, input().split())
    print('#'+str(testcase), n1//n2, n1%n2)
