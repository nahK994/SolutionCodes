import math

b = int(input())
ans = []

for a in range(2,b+1):
    
    if(a == 2):
        ans.append(2)
        continue
    
    flag = 1
    if(a%2 == 0):
        flag = 0
        continue

    for i in range(3, int(math.sqrt(a))+2, 2):
        if(a%i == 0):
            flag = 0
            break

    if(flag):
        ans.append(a)

if len(ans) > 0:
    print(ans[0], end="")
    for i in ans[1:len(ans)]:
        print("", i, end="")
    print()