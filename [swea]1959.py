# 두개의 숫자열
t=int(input())
for testcase in range(1, t+1):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    min_l = 0
    max_l = 0

    min_list=[]
    max_list=[]

    if len(a)>=len(b):
        min_l=len(b)
        max_l=len(a)
        max_list=a
        min_list=b

    else:
        min_l = len(a)
        max_l = len(b)
        max_list = b
        min_list = a

    result=[]
    for i in range(max_l-min_l+1):
        temp=0
        for j in range(min_l):
            temp+= (min_list[j]*max_list[i+j])
        result.append(temp)

    result.sort(reverse=True)
    print('#'+str(testcase), result[0])


