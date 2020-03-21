for _ in range(int(input())):

    a = input()
    mp = {}
    max = -1
    
    for i in a:
        ch = ord(i)
        if not (ch >= ord('A') and ch <= ord('Z')) and not (ch >= ord('a') and ch <= ord('z')):
            continue

        if ch >= ord('A') and ch <= ord('Z'):
            ch = ch - ord('A') + ord('a')
        
        if not ch in mp:
            mp[ch] = 1
        else:
            mp[ch] += 1
        
        if max < mp[ch]:
            max = mp[ch]
        
    for i in sorted(mp.items(), key=lambda a: -1000*a[1] + a[0]):
        if i[1] == max:
            print('%c' %i[0], end="")
        else:
            break
    print()