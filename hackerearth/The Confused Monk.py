import math

N = 10**9+7

def GCD(a, b):

    if b == 0:
        return a
    c = GCD(b, a%b)
    return c

def modular(a, n):
    if n == 1:
        return a
    
    if n%2 == 0:
        aa = modular(a, int(n/2))
        return ((aa%N)*(aa%N))%N
    else:
        aa = modular(a, n-1)
        return ((aa%N)*(a%N))%N


t = int(input())
li = [int(i) for i in input().split() if i.isdigit()]

if t == 1:
    a = 1
    for i in range(li[0]):
        a = ((li[0]%N)*(a%N))%N
    print(a)
    
else:
    a = GCD(li[0], li[0])
    for i in li[1:]:
        if a>i:
            a = GCD(a, i)
        else:
            a = GCD(i, a)

    prod = 1
    for i in li:
        prod = ((prod%N)*(i%N))%N
    print(modular(prod, a))