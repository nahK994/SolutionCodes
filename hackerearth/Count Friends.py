def rec(a, parr):
    if parr[a] == a:
        return a
    parr[a] = rec(parr[a], parr)
    return parr[a]

[node, edge] = [int(s) for s in input().split() if s.isdigit()]

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

print(count[par[1]]-1, end="")
if(len(count)>2):
    for i in range(2, node+1):
        print("", count[par[i]]-1, end="")
print()