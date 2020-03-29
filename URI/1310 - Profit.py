while True:
    try:
        days = int(input())
    except:
        break
    
    costPerDay = int(input())

    revenue = []
    for i in range(days):
        revenue.append(int(input()))
    #print(revenue)

    ans = revenue[0] - costPerDay
    apatotoAns = ans
    for i in revenue[1:]:
        profit = i - costPerDay
        if apatotoAns + profit < profit:
            apatotoAns = profit
            if apatotoAns > ans:
                ans = apatotoAns
        elif apatotoAns + profit > ans:
            apatotoAns += profit
            ans = apatotoAns
        else:
            apatotoAns += profit

    #print('ans = ', end = "")
    if ans > 0:
        print(ans)
    else:
        print(0)