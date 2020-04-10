while True:
    try:
        a = input()
        b = input()
    except:
        break

    arr = [[0 for i in range(len(b))] for j in range(len(a))]

    ans = 0
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i] == b[j]:
                if i>0 and j>0:
                    arr[i][j] += arr[i-1][j-1]+1
                elif i==0 or j==0:
                    arr[i][j] = 1
                
                if ans < arr[i][j]:
                    ans = arr[i][j]

    print(ans)