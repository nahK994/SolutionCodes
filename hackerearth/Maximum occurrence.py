a = input()
count = [0]*500

ansMax = 0
ansCha = 300
for i in a:
    count[ord(i)] += 1
    if count[ord(i)] >= ansMax:
        if count[ord(i)] == ansMax:
            if ord(i) < ord(ansCha):
                ansCha = i
            continue
        ansMax = count[ord(i)]
        ansCha = i
print(ansCha, ansMax)