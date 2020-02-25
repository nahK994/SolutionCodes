for _ in range(int(input())):
    [n, k] = [int(i) for i in input().split() if i.isdigit()]
    arr = [int(i) for i in input().split() if i.isdigit()]

    arr.sort()
    a = 0
    b = 0

    for i in arr[0: (n-k)]:
        a += i
    for i in arr[len(arr)-(n-k): ]:
        b += i

    print(b-a)