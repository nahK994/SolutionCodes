color = []
G = {}
revG = {}
par = []
inputs = []
nodes = {}

#printInputs = []
#printOutputs = []

def findPar(a):
    if par[a] == a:
        return a
    par[a] = findPar(par[a])
    return par[a]

def dfs1(a):
    color[a] = 1
    for i in G[a]:
        if color[i] == 0:
            dfs1(i)

def dfs2(a):
    color[a] = 1
    for i in revG[a]:
        if color[i] == 0:
            dfs2(i)

while True:
    [node, edge] = [int(i) for i in input().split() if i.isdigit()]
    if node == 0 and edge == 0:
        break

    par = [i for i in range(node+1)]

    for j in range(edge):
        aa = [int(i) for i in input().split() if i.isdigit()]

        if aa[2] == 1:
            inputs.append([aa[0], aa[1]])
        else:
            aa0 = findPar(aa[0])
            aa1 = findPar(aa[1])
            if aa0 > aa1:
                par[aa0] = aa1
            else:
                par[aa1] = aa0

    for i in range(1, node+1):
        par[i] = findPar(i)
        nodes[par[i]] = 1

    for i in nodes.keys():
        G[i] = []
        revG[i] = []

    #kk = []
    for i in inputs:
        if not par[i[1]] in G[par[i[0]]]:
            G[par[i[0]]].append(par[i[1]])
            revG[par[i[1]]].append(par[i[0]])
            #kk.append([par[i[0]], par[i[1]]])
    #printInputs.append(kk)

    color = [0 for i in range(node+1)]
    dfs1(par[1])
    
    ans = 1
    for i in nodes.keys():
        if color[i] == 0:
            ans = 0
            break
    
    if ans == 1:
        color = [0 for i in range(node+1)]
        dfs2(par[1])

        for i in nodes.keys():
            if color[i] == 0:
                ans = 0
                break
    
    print(ans)
    #printOutputs.append(ans)
    
    inputs = []
    nodes = {}
    G = {}
    revG = {}
'''
with open("outputs.txt", "w") as f:
    for i in printOutputs:
        f.write(str(i) + '\n')

with open("inputs.txt", "w") as f:
    for i in printInputs:
        for j in i:
            f.write(str(j[0]) + ' ' + str(j[1]) + '\n')
        f.write('\n')
'''
#https://www.urionlinejudge.com.br/judge/en/problems/view/1128

'''
5 8
1 2 1
2 3 1
3 4 1
4 1 1
5 1 1
5 2 1
5 3 1
5 4 1

8 8
1 2 1
2 3 1
3 4 1
4 1 1
5 6 1
6 7 1
7 8 1
8 5 1

8 8
1 2 2
2 3 2
3 4 2
4 1 2
5 6 2
6 7 2
7 8 2
8 5 2
'''