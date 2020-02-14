for _ in range(int(input())):
    ch = input()
    flag = 1
    for i in range(0, int(len(ch)/2)):
        if ch[i] != ch[int(len(ch))-1-i]:
            flag = 0
            break
    if(flag):
        print("YES")
    else:
        print("NO")