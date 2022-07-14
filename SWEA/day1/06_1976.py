# 문제명: 시각덧셈

t=int(input())

for testcase in range(1, t+1):
    hour1, min1, hour2, min2 = map(int, input().split())

    h_sum = hour1 + hour2
    m_sum = min1 + min2

    if h_sum>12:
        if h_sum%12==0:
            h_sum=12
        else:
            h_sum=h_sum%12

    if m_sum>59:
        h_sum+=m_sum//60
        m_sum=m_sum%60
    print('#'+str(testcase), h_sum, m_sum)
