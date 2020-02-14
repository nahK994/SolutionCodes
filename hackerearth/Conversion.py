for _ in range(int(input())):
    ch = input()
    for i in ch:
        if ord(i) == 32:
            print('$', end="")
        elif ord(i) >= ord('a') and ord(i) <= ord('z'):
            print(ord(i)-96, end="")
        elif ord(i) >= ord('A') and ord(i) <= ord('Z'):
            print(ord(i)-64, end="")
        elif ord(i) == 32:
            print('$', end="")
    print()