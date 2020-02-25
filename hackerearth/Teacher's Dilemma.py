def rec(a, parr):
    if parr[a] == a:
        return a
    parr[a] = rec(parr[a], parr)
    return parr[a]

[node, edge] = [int(s) for s in input().split() if s.isdigit()]

groupLeads = []
par = [i for i in range(0, node+1)]
count = [0]*(node+1)

while edge:
    [a, b] = [int(aa) for aa in input().split() if aa.isdigit()]
    a = rec(a, par)
    b = rec(b, par)
    par[a] = b
    edge -= 1

for i in range(1, node+1):
    count[rec(i, par)] += 1
    if count[rec(i, par)] == 1:
        groupLeads.append(rec(i, par))

ans = 1
N = 10**9 + 7
for i in groupLeads:
    ans = ((ans%N)*(count[i]%N))%N

print(ans)