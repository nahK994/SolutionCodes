while True:
    try:
        a = input()    
    except:
        break
    
    letterCount = 1
    for i in a:
        ch = ord(i)

        if ch >= ord('a') and ch <= ord('z') and letterCount%2 == 1:
            ch = ch - ord('a') + ord('A')
        elif ch >= ord('A') and ch <= ord('Z') and letterCount%2 == 0:
            ch = ch - ord('A') + ord('a')

        if (ch >= ord('a') and ch <= ord('z')) or (ch >= ord('A') and ch <= ord('Z')):
            letterCount += 1
        
        print('%c' %ch, end="")

    print()