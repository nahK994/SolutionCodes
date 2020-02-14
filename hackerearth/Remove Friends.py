test = int(input())

for ii in range(0, test):

    aaa = input()

    [n, k] = [int(s) for s in aaa.split() if s.isdigit()]
    #print(n, k)
    
    aaa = input()
    friends= [int(s) for s in aaa.split() if s.isdigit()]
    #print(friends)
    
    ans = []
    ans.append(friends[0])
    for j in range(1, len(friends)):
        if friends[j] > ans[-1] and k:
            while(k>0 and len(ans) and ans[-1] < friends[j]):
                k = k-1
                ans.pop()
        ans.append(friends[j])
    
    while(k>0):
        ans.remove(-1)
        k = k-1

    print(ans[0], end="")
    for i in ans[1:len(ans)]:
        print("", i, end="")
    print()