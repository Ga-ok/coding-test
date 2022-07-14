# 문제명: 최대수 구하기 / list + for

t=int(input())
for testcase in range(1, t+1):
    num_list=list(map(int, input().split()))

    result=0
    for i in range(len(num_list)):
        if result < num_list[i]:
            result=num_list[i]

    print('#'+str(testcase), result)