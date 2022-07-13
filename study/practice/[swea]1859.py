t=int(input())

for testcase in range(1, t+1):
    n=int(input())
    n_list=list(map(int, input().split()))

    max_n=n_list[-1]
    result=0
    for i in range(n-2, -1, -1):
        if max_n < n_list[i]:
            max_n=n_list[i]
        else:
            result+=(max_n-n_list[i])

    print('#'+str(testcase), result)


