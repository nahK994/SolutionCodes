ch = input()
ans = 0
a = []
for i in ch:
    if i == '(':
        a.append(i)
    elif i == ')':
        if len(a)>0 and a[len(a)-1] == '(':
            a.pop()
        else:
            ans += 1
ans += len(a)
print(ans)