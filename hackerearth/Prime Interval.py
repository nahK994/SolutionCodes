import math
N = 10**5+10
primes = [i for i in range(N)]

primes[0] = -1
primes[1] = -1
for i in range(4, N, 2):
    primes[i] = -1
for i in range(3, int(math.sqrt(N)+1), 2):
    if primes[i] == i:
        for j in range(i*i, N, i):
            primes[j] = -1


[L, R] = [int(i) for i in input().split() if i.isdigit()]

a = -1
for i in range(L, R+1):
    if i == primes[i]:
        a = i
        print(i, end = "")
        break

for i in range(a+1, R+1):
    if primes[i] == i:
        print("", i, end = "")
print()