# 홀수만 더하기

tn = int(input())

for testcase in range(1, tn+1):
    num_list=list(map(int, input().split()))

    result=0
    for num in num_list:
        if num%2!=0:
            result+=num
    print('#'+str(testcase), result)