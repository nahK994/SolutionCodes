for _ in range(int(input())):
    
    mainStr = input()
    mainStrLen = len(mainStr)
    
    test = int(input())
    for loop in range(test):
        
        Str = input()
        StrLen = len(Str)
        if StrLen > mainStrLen:
            print('No')
            continue
        
        i = 0
        j = 0
        while j < StrLen:
            if mainStr[i] == Str[j]:
                i += 1
                j += 1
            else:
                i += 1
            
            if i == mainStrLen:
                break
            
        if j == StrLen:
            print('Yes')
        else:
            print('No')