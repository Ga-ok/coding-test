# [도전] List 활용하기

bucket=[0]*7
a=[3, 3, 2, 6, 2]

for i in range(len(a)):
    bucket[a[i]]+=1

print(bucket)

