lst=['ABE', 53, -99, -99, 124]

dic=dict()
for i in lst:
    dic[str(i)]=0
for i in lst:
    dic[str(i)]+=1

a=input()

if a in dic:
    print(dic[a])
else:
    print('잘못된 값 입력')