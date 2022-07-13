# 문제명: 평균값 구하기 / list 사용하여 평균값 구하기

t=int(input())
for testcase in range(1, t+1):
    num_list=list(map(int, input().split()))

    result=0
    for i in range(len(num_list)):
        result+=num_list[i]

    result=result/10
    if result!=int(result):
        temp=result
        temp = int(temp*10)
        if temp%10 >= 5:
            result=int(result)+1

    print('#'+str(testcase), int(result))