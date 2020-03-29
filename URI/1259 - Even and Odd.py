while True:
    try:
        a = int(input())
    except:
        break
    
    even = []
    odd = []
    while a != 0:
        b = int(input())
        if b%2 == 0:
            even.append(b)
        else:
            odd.append(b)
        a -= 1
    
    even = sorted(even)
    odd = sorted(odd, reverse=True)

    for i in even:
        print(i)
    for i in odd:
        print(i)