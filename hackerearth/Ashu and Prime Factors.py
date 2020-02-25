import math

N = 10**6+1
primes = [i for i in range(N)]
ans = [1]*N

primes[0] = -1
primes[1] = -1
for i in range(4, N, 2):
    primes[i] = -1
    ans[2] += 1
for i in range(3, int(math.sqrt(N)), 2):
    if primes[i] == i:
        for j in range(i*i, N, i):
            if primes[j] != -1:
                ans[i] += 1
            primes[j] = -1


for _ in range(int(input())):
    n = int(input())

    print(ans[n])