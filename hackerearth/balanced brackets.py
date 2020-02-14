test = int(input())

for i in range(0, test):
    flag = 1
    ch = input()
    #print(ch)
    ans = []
    for j in range(0, len(ch)):
        #print(j, ch[j])
        if ch[j] == '(' or ch[j] == '{' or ch[j] == '[':
            #print("HaHa")
            ans.append(ch[j])
            continue

        #print("...", ans, type(ans), len(ans))
        if (ch[j] == ')' or ch[j] == '}' or ch[j] == ']') and len(ans) == 0:
            flag = 0
            break 
        elif (ch[j] == ')' and ans[-1] == '(') or (ch[j] == '}' and ans[-1] == '{') or (ch[j] == ']' and ans[-1] == '['):
            ans.pop()
        else:
            flag = 0
            break
        #print("...", ans, type(ans), len(ans))

    if(flag and len(ans) == 0):
        print("YES")
    else:
        print("NO")  