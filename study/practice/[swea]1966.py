
t=int(input())
for testcase in range(1, t+1):
    n=int(input())
    n_list=list(map(int, input().split()))

    n_list.sort()
    print('#'+str(testcase), end=' ')
    for i in n_list:
        print(i, end=' ')
    print()