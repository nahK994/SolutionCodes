for _ in range(0, int(input())):
    aa = input()
    [node, edge] = [int(s) for s in aa.split() if s.isdigit()]
    
    V = []
    dist = []
    Q = []

    for i in range(0, node+1):
        V.append([])
        dist.append(999999)
    
    while(edge):
        aaa = input()
        [a, b] = [int(s) for s in aaa.split() if s.isdigit()]
        V[a].append(b)
        V[b].append(a)
        edge = edge - 1

    dist[1] = 0
    Q.append(1)
    
    while(len(Q)):
        a = Q[0]
        Q = Q[1:]

        for i in V[a]:
            if dist[i] > dist[a] + 1: 
                dist[i] = dist[a] + 1
                Q.append(i)
    print(dist[node])