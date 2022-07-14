# 회문 2 : 가장 긴 회문의 길이 구하기

for testcase in range(1, 11):
    tn = int(input())

    str_list=[]
    for _ in range(100):
        temp=list(input())
        str_list.append(temp)

    palindrome=[]
    # 가로 길이의 회문 구하기
    for i in range(100):
        for j in range(100):
            for k in range(101):
                if j+k>100:
                    break
                temp=str_list[i][j:j+k]
                if temp==temp[::-1]:
                    palindrome.append(len(temp))

    str_list2=[[0]*100 for _ in range(100)]
    for i in range(100):
        for j in range(100):
            str_list2[j][i]=str_list[i][j]
    print(str_list2)

    str_list=str_list2
    # 세로 길이의 회문 구하기
    for i in range(100):
        for j in range(100):
            for k in range(101):
                if j + k > 100:
                    break
                temp = str_list[i][j:j + k]
                if temp == temp[::-1]:
                    palindrome.append(len(temp))

    palindrome.sort(reverse=True)

    print("#"+str(testcase), palindrome[0])