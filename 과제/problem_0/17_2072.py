# 문제명: 홀수만 더하기 / list + for + if

t=int(input())
for testcase in range(1, t+1):
    num_list=list(map(int, input().split()))

    result=0
    for i in range(len(num_list)):
        if num_list[i]%2==1:
            result+=num_list[i]

    print('#'+str(testcase), result)