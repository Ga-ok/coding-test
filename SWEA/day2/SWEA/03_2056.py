# 연월일 달력
calendar = {'01':31, '02':28, '03':31, '04':30, '05':31, '06':30, '07':31, '08':31, '09':30, '10':31, '11':30, '12':31}

t=int(input())
for testcase in range(1, t+1):

    date=input()

    month=date[4:6]
    day=date[6:]

    result=str(date[:4])+"/"
    flag=0
    if 1<=int(month)<=12:
        result+=month+"/"
    else:
        flag=1
        print('#' + str(testcase), -1)
        continue

    if int(day)<=calendar[month]:
        result+=day
    else:
        flag=1
        print('#' + str(testcase), -1)
        continue

    print('#'+str(testcase), result)


