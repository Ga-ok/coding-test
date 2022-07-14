# 회문 1

for testcase in range(1, 11):

    target_len=int(input())
    str_list=[]
    for _ in range(8):
        temp=list(input())
        str_list.append(temp)

    # 가로 길이의 회문 찾기
    result=0
    for i in range(8):
        for j in range(8-target_len+1):
            temp=str_list[i][j:j+target_len]
            if temp==temp[::-1]:
                result+=1

    # 세로 길이의 회문을 찾기 위해 행열 바꿔주기
    temp=[[0]*8 for _ in range(8)]
    for i in range(8):
        for j in range(8):
            temp[j][i]=str_list[i][j]

    str_list=temp
    # 세로 길이의 회문 찾기
    for i in range(8):
        for j in range(8 - target_len + 1):
            temp = str_list[i][j:j + target_len]
            if temp == temp[::-1]:
                result += 1

    print("#"+str(testcase), result)


