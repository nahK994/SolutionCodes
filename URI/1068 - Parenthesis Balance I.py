while True:
    try:
        a = input()
    except:
        break
    S = []
    flag = 1
    for i in a:
        if(i == '('):
            S.append('(')
        elif(i == ')'):
            if(len(S)>0):
                S.pop()
            else:
                flag = 0
                break

    if(flag and len(S) == 0):
        print('correct')
    else:
        print('incorrect')