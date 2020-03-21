for _ in range(int(input())):
    a = input()
    a = a.split(' ')
    for i in a:
        if len(i) == 0:
            continue
        print(i[0], end="")
    print()