for _ in range(int(input())):
    [N, X] = [int(s) for s in input().split() if s.isdigit()]
    arr = [int(s) for s in input().split() if s.isdigit()]

    color = [-1]*(2**N+1)
    count = 0

    for i in range(0, N+1):
        index = 1
        #print("HaHa")
        while True:
            if color[index] == -1:
                color[index] = arr[i]
                count += 1
                break
            elif color[index] == arr[i]:
                break
            elif color[index] > arr[i]:
                index *= 2
            else:
                index = 2*index+1
            print("................asdf................", index, color[index])

    if(count == X):
        print("Good")
    elif(count > X):
        print("Average")
    else:
        print("Bad") 