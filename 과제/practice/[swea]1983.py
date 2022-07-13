# 1983 조교의 성적 매기기

t=int(input())
for testcase in range(1, t+1):
    n, k = map(int, input().split())

    points=[]
    for i in range(0, n):
        x, y, z = map(int, input().split())
        points.append([i, 0.35*x + 0.45*y + 0.2*z])

    points.sort(key=lambda x:-x[1])

    temp=n//10
    result=''
    grade=['A+', 'A0', 'A-', 'B+', 'B0', 'B-', 'C+', 'C0', 'C-', 'D0']
    for i in range(0, n, n//10):
        for j in range(n//10):
            points[i+j].append(grade[i//(n//10)])

    for point in points:
        if point[0]==k-1:
            result=point[2]

    print('#'+str(testcase), result)





