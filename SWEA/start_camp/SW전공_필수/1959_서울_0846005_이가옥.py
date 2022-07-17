# 서울_임베디드_21반_이가옥

# SW전공_필수 문제풀이
# 1959. 두개의 숫자열

t=int(input())
for testcase in range(1, t+1):

    n, m = map(int, input().split())
    n_list=list(map(int, input().split()))
    m_list=list(map(int, input().split()))

    # n과 m 중 큰수와 작은수를 알 수 없기 때문에 if문 이용하여 처리
    max_list=[]
    min_list=[]
    if n > m:
        max_list = n_list
        min_list = m_list
    else:
        max_list = m_list
        min_list = n_list

    # 이중 for문을 돌며 마주보는 숫자의 합의 최댓값 구하기
    result=0
    for i in range(len(max_list)-len(min_list)+1):
        temp=0
        for j in range(len(min_list)):
            temp+=min_list[j]*max_list[i+j]
        if temp > result:
            result = temp

    print('#'+str(testcase), result)
