def rec(arr, a, b):
    if a == b:
        return 1
    
    mid = int((a+b)/2)
    left = rec(arr, a, mid)
    right = rec(arr, mid+1, b)
    
    if arr[mid] == arr[mid+1]:
        return left + right - 1
    else:
        return left + right

n = int(input())
A = [int(i) for i in input().split() if i.isdigit()]
B = [int(i) for i in input().split() if i.isdigit()]

q = int(input())
while q:
    ab = [int(i) for i in input().split() if i.isdigit()]
    arr = [-1]
    #arr = arr + [i for i in A[ab[0]-1: ab[1]]]
    #arr = arr + [i for i in B[ab[2]-1: ab[3]]]
    #arr.sort()
    #print("--->", arr)
    ans = {}
    #print(A[ab[0]-1: ab[1]])
    #print(B[ab[2]-1: ab[3]])
    for i in A[ab[0]-1: ab[1]+1]:
        if int(i in ans) == 0:
            ans[i] = True
    for i in B[ab[2]-1: ab[3]+1]:
        if int(i in ans) == 0:
            ans[i] = True

    print(len(ans))
    q -= 1