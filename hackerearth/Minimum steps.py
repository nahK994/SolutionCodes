def func(a):
    if a%2 == 0:
        print(int(a/2))
    else:
        print(int((a-1)/2) + 1)

n = int(input())
arr = [int(i) for i in input().split() if i.isdigit()]
arr1 = [i for i in arr]
arr1.sort()
#print(arr)
#print(arr1)

ans1 = 0
for i in range(n):
    if arr[i] != arr1[i]:
        #print("HaHa")
        ans1 += 1

ans2 = 0
for i in range(n):
    #print(arr[i], arr1[n-1-i])
    if arr[i] != arr1[n-1-i]:
        #print("-->", i, n-1-i)
        ans2 += 1

if ans1 > ans2:
    func(ans2)
else:
    func(ans1)
#print(ans1, ans2)