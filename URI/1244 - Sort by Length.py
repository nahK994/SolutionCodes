def func(a):
    return -1*len(a)

for _ in range(int(input())):
    a = input()
    a = a.split()
    print(" ".join(sorted(a, key=func)))