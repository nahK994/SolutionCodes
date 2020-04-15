par = []
color = []
mp = {}

def func(a):
    for i in mp[a]:
        if color[i] == 0:
            color[i] = 1
            if par[i] == -1 or func(par[i]):
                par[i] = a
                return True
            else:
                color[i] = 0
                return False
    return False

'''
def func(a):
    if color[a] == 1:
        return False

    color[a] = 1
    for i in mp[a]:
        if par[i] == -1 or func(a):
            par[i] = a
            return True
    
    return False
'''

for loop in range(int(input())):

    num1 = [int(i) for i in input().split()]
    num2 = [int(i) for i in input().split()]

    for i in range(1, len(num1)):
        if num1[i] == 0:
            continue
        mp[i] = []
        for j in range(1, len(num2)):
            if num2[j] % num1[i] == 0:
                mp[i].append(j)
    
    par = [-1]*110
    
    ans = 0
    for i in mp.keys():
        color = [0]*110
        if func(i):
            ans += 1
    
    print('Case %d: %d' %(loop+1, ans))