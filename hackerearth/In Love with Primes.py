import math
N = 10**5+10
primes = [i for i in range(N)]

primes[1] = -1
for i in range(4, N, 2):
    primes[i] = -1
for i in range(3, int(math.sqrt(N)+1), 2):
    if primes[i] == i:
        for j in range(i*i, N, i):
            primes[j] = -1

for _ in range(int(input())):
    n = int(input())

    flag = 0
    for i in range(1, int(n/2)+1):
        #print("primes[ ", i, " ] = ", primes[i])
        #print("----------> primes[ ", n-i, " ] = ", primes[n-i])
        if primes[i] == i and primes[n-i] == n-i:
            #print("HaHa")
            flag = 1
            break

    #print("flag = ", flag)
    if flag:
        print("Deepa")
    else:
        print("Arjit")