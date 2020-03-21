for _ in range(int(input())):
    
    size1 = int(input())
    mp = {}
    for i in range(size1):
        aa = input()
        aa = aa.split()
        mp[aa[0]] = float(aa[1])
    
    size2 = int(input())
    sum = 0
    for i in range(size2):
        aa = input()
        aa = aa.split()
        sum += mp[aa[0]]*float(aa[1])
    
    print('R$ %0.2f' %sum)