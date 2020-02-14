import math
 
def num_divisors(n):
    if n == 1:
        return 0

    ans = 0
    a = int(math.sqrt(n))

    for i in range(2, a+1):
        if n%i == 0:
            ans += i
            if a != int(n/i):
                ans += int(n/i)
    return ans+1
 
 
t = int(input())
for i in range(t):
    try:
        li = list(map(int, input().split()))
        for x in li:
            print(num_divisors(x))
    except:
        pass