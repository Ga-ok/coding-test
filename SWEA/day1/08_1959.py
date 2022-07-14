# 문제명: 두 개의 숫자열

t=int(input())
for testcase in range(1, t+1):
    n, m = map(int, input().split())

    n_list=list(map(int, input().split()))
    m_list=list(map(int, input().split()))

    max_list=[]
    min_list=[]
    if n > m:
        max_list = n_list
        min_list = m_list
    else:
        max_list = m_list
        min_list = n_list

    result=0
    for i in range(len(max_list)-len(min_list)+1):
        temp=0
        for j in range(len(min_list)):
            temp+=min_list[j]*max_list[i+j]
        if temp > result:
            result = temp
    print('#'+str(testcase), result)
