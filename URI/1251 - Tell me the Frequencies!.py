def func(a):
    return 10000*a[1]-a[0]

loop = 1
while True:
    try:
        a = input()
    except:
        break

    mp = {}
    for i in range(len(a)):
        if (ord(a[i]) in mp) == False:
            mp[ord(a[i])] = 1
        else:
            mp[ord(a[i])] += 1

    if loop > 1:
        print()
    loop = 2

    for i in sorted(mp.items(), key=func):
        print('%d %d' %(i[0], i[1]))