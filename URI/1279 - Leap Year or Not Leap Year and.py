def leapYear(a):
    return (a%4 == 0 and a%100 != 0) or (a%4 == 0 and a%100 == 0 and a%400 == 0)

def huluculuYear(a):
    return a%15 == 0

def bulukuluYear(a):
    return leapYear(a) and a%55 == 0

def ordinaryYear(a):
    return not (leapYear(a) or huluculuYear(a) or bulukuluYear(a))


    1279 - Leap Year or Not Leap Year and …
loop = 1
while True:
    try:
        a = int(input())
    except:
        break

    if loop > 1:
        print()
    
    if leapYear(a):
        print('This is leap year.')
    if huluculuYear(a):
        print('This is huluculu festival year.')
    if bulukuluYear(a):
        print('This is bulukulu festival year.')
    if ordinaryYear(a):
        print('This is an ordinary year.')
    
    loop += 1