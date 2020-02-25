[n, k] = [int(i) for i in input().split() if i.isdigit()]
arr = [int(i) for i in input().split() if i.isdigit()]

while k:
    a = [i for i in input().split()]
    b = [int(i) for i in a]
    if len(b) == 2:
        arr[b[1]-1] = 1-arr[b[1]-1]
    else:
        if arr[b[2]-1]:
            print("ODD")
        else:
            print("EVEN")
    k -= 1