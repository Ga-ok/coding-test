# 패턴마디의 길이

t=int(input())
for testcase in range(1, t+1):
    pattern = input()

    start = pattern[0]
    result=0
    for i in range(1, 30):
        if start==pattern[i]:
            temp1=[]
            temp2=[]
            for j in range(i):
                temp1.append(pattern[j])
                temp2.append(pattern[i+j])
            if temp1 == temp2:
                result=len(temp1)
                break

    print('#'+str(testcase), result)


