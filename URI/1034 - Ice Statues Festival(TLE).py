for _ in range(int(input())):
    [n, m] = [int(i) for i in input().split() if i.isdigit()]

    cubes = [int(i) for i in input().split() if i.isdigit()]

    arr = [1000000 for i in range(m+1)]
    arr[0] = 0

    for i in range(len(cubes)):
        for j in range(cubes[i], m+1):
            arr[j] = min(arr[j-cubes[i]] + 1, arr[j])

    print(arr[m])