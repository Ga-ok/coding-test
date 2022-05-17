# sum

for testcase in range(1, 11):
    tn=int(input())

    num_list=[]
    result=[]

    # 배열 초기화와 행의 합 구하기 동시 실행
    for _ in range(100):
        temp=list(map(int, input().split()))
        result.append(sum(temp))
        num_list.append(temp)

    # 열의 합 구하기
    for i in range(100):
        temp=0
        for j in range(100):
            temp+=num_list[j][i]
        result.append(temp)

    # 왼쪽 대각선의 합 구하기
    temp=0
    for i in range(100):
        temp+=num_list[i][i]

    result.append(temp)

    # 오른쪽 대각선의 합 구하기
    temp=0
    for i in range(100):
        temp+=num_list[i][99-i]

    result.append(temp)

    # 합 중 최댓값 구하기
    result.sort(reverse=True)

    print('#'+str(testcase), result[0])
