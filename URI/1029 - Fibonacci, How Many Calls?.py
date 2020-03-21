calls = [0 for i in range(60)]
fibs = [0 for i in range(60)]

calls[0] = 1
fibs[0] = 0
calls[1] = 1
fibs[1] = 1

def func(a):
    if a < 2:
        return [calls[a], fibs[a]]

    if fibs[a] != 0:
        return [calls[a], fibs[a]]
    
    aa = func(a-1)
    bb = func(a-2)

    fibs[a] = aa[1] + bb[1]
    calls[a] = aa[0] + bb[0] + 1
    return [calls[a], fibs[a]]

for _ in range(int(input())):
    a = int(input())
    print('fib(%d) = %d calls = %d' %(a, func(a)[0]-1, func(a)[1]))