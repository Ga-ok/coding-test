# 간단한 소인수분해
t=int(input())

for testcase in range(1, t+1):
    n=int(input())
    result=[0, 0, 0, 0, 0]

    n_list=[2, 3, 5, 7, 11]
    for j in range(len(n_list)):
        if n%n_list[j]==0:
            i=0
            while n%n_list[j]==0:
                n=n//n_list[j]
                i+=1
            result[j]=i

    print('#'+str(testcase), end=' ')
    for r in result:
        print(r, end=' ')
    print()