import math

def func():
    input1 = input()
    x = ''
    y = ''
    flag = 0
        
    for i in input1:
        if i == ' ':
            flag = 1

        if not flag:
            x += i
        else:
            y += i
        
    return [float(x), float(y)]


while True:
    try:
        [x1, y1] = func()
        [x2, y2] = func()

        #print(x1, y1)
        #print(x2, y2)
    except:
        break

    print('%0.4f' %math.sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ))