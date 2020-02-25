for _ in range(int(input())):
    [N, M] = [int(i) for i in input().split() if i.isdigit()]
    arrN = [int(i) for i in input().split() if i.isdigit()]
    arrM = [int(i) for i in input().split() if i.isdigit()]

    ans = []
    n = 0
    m = 0
    arrN.sort()
    arrM.sort()

    while n<N or m<M:
        if m>=M and n<N:
            while n<N:
                ans.append(arrN[n])
                n += 1
        elif n >= N and m<M:
            while m<M:
                ans.append(arrM[m])
                m += 1
        else:
            while True:
                if n>=N or m>=M:
                    break

                if arrN[n] < arrM[m]:
                    ans.append(arrN[n])
                    n += 1
                elif arrM[m] < arrN[n]:
                    ans.append(arrM[m])
                    m += 1
                else:
                    ans.append(arrN[n])
                    ans.append(arrM[m])
                    n += 1
                    m += 1 
    print(ans[-1], end = "")
    if len(ans) > 1:
        for i in ans[-2:-1*len(ans)-1: -1]:
            print("", i, end = "")
    print()