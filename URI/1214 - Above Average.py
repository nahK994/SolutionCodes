for _ in range(int(input())):
    a = [int(i) for i in input().split() if i.isdigit()]

    avg = 0
    for i in a[1:]:
        avg += i
    avg /= a[0]

    count = 0
    for i in a[1:]:
        if i>avg:
            count += 1
    print('%0.3f%%' %(count*100/a[0]))