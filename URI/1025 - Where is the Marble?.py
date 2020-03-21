count = 1
while True:
    [test, query] = [int(i) for i in input().split() if i.isdigit()]
    if test == 0 and query == 0:
        break

    S = []
    while test:
        a = int(input())
        S.append(a)
        test -= 1
    S.sort()

    print('CASE# %d:' %count)
    count += 1

    for i in range(query):

        a = int(input())
        
        low = 0
        high = len(S)-1
        ansIndex = high

        while low<=high:
            mid = int((low+high)/2)
            if S[mid] >= a:
                ansIndex = mid
                high = mid-1
            elif S[mid] < a:
                low = mid+1
        
        if(S[ansIndex] == a):
            print('%d found at %d' %(a, ansIndex+1))
        else:
            print('%d not found' %a)