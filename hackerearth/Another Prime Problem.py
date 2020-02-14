import math

n=10**6+100
arr=[True]*n
arr[0]=False
arr[1]=False

for i in range(2,int(math.sqrt(n))+2):
    if arr[i]:
        for j in range(i*i,n,i):
            arr[j]=False
for i in range(10**6,10**6+100):
    if arr[i] and i%11 == 1:
        v=i
        break
for i in range(n-1, -1, -1):
    if arr[i] and i%11 == 1:
        v=i
    arr[i]=v

for _ in range(int(input())):
    x=int(input())
    print(arr[x])

#Another Prime Problem / Submission (27472556) by Ashok (ashok123232)