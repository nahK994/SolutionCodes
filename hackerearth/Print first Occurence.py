for _ in range(int(input())):
    a = []
    ch = input()
    for i in ch:
        if (i in a) == False:
            a.append(i)
            print(i, end="")
    print()