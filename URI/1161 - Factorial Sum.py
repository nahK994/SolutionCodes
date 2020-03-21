fac = [i for i in range(21)]
fac[0] = 1 
for i in range(1, 21):
    fac[i] = fac[i]*fac[i-1]

while True:
    try:
        a = input()
    except:
        break
    
    a = [int(i) for i in a.split() if i.isdigit()]
    print(fac[a[0]]+fac[a[1]])