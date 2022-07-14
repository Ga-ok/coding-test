# 문제명: 쉬운 거스름돈

t=int(input())
for testcase in range(1, t+1):
    money = int(input())
    m_list=[50000, 10000, 5000, 1000, 500, 100, 50, 10]
    result=[0, 0, 0, 0, 0, 0, 0, 0]

    for i in range(len(m_list)):
        if money>=m_list[i]:
            j=0
            while money>=m_list[i]:
                money-=m_list[i]
                j+=1
            result[i]=j
    print('#'+str(testcase), end=' ')

    for r in result:
        print(r, end=' ')
    print()
