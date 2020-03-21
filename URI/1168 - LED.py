for _ in range(int(input())):
    a = input()
    ans = 0
    for i in a:
        if i=='0':
            ans += 6
        elif i=='1':
            ans += 2
        elif i=='2':
            ans += 5
        elif i=='3':
            ans += 5
        elif i=='4':
            ans += 4
        elif i=='5':
            ans += 5
        elif i=='6':
            ans += 6
        elif i=='7':
            ans += 3
        elif i=='8':
            ans += 7
        elif i=='9':
            ans += 6
    print('%d leds' %ans)