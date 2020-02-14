import math
 
def num_divisors(n):
    dividend = n
    divisor = 2
    numfactors = 1
    count = 0
    
    while dividend!=1:
        if divisor > math.sqrt(dividend):
            divisor = dividend
        
        while dividend%divisor == 0:
            dividend/=divisor
            count += 1
        
        numfactors *= (count+1)
        count = 0
        divisor += 1

    numfactors *= (count+1) 
    return numfactors
 
 
t = int(input())
for i in range(t):
    try:
        li = list(map(int, input().split()))
        for x in li:
            print(num_divisors(x))
    except:
        pass