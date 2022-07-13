# 문제명: 시각 덧셈 / 수학적으로 계산하기

t=int(input())
for testcase in range(1, t+1):
    h1, m1, h2, m2 = map(int, input().split())
    h_res=h1+h2
    if h_res>12:
        h_res=h_res-12
    m_res=0
    if m1+m2>=60:
        h_res+=1
        m_res=m1+m2 - 60
    else:
        m_res=m1+m2

    print('#'+str(testcase), h_res, m_res)