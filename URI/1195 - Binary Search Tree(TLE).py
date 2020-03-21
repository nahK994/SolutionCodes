class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def inOrderPrint(a):
    if a is None:
        return
    inOrderPrint(a.left)
    print(" ", a.data, end="")
    inOrderPrint(a.right)

def preOrderPrint(a):
    if a is None:
        return
    print(" ", a.data, end="")
    preOrderPrint(a.left)
    preOrderPrint(a.right)

def postOrderPrint(a):
    if a is None:
        return
    postOrderPrint(a.left)
    postOrderPrint(a.right)
    print(" ", a.data, end="")



test = int(input())
for loop in range(1, test+1):
    a = input()
    l = int(a)
    datas = [int(i) for i in input().split() if i.isdigit()]
    
    head = node(datas[0])

    for i in range(1, l):
        root = head
        while True:
            if datas[i] >= root.data:
                if root.right is None:
                    root.right = node(datas[i])
                    break
                else:
                    root = root.right
            else:
                if root.left is None:
                    root.left = node(datas[i])
                    break
                else:
                    root = root.left
    
    print('Case %d:' %loop)
    
    print('Pre.:', end="")
    preOrderPrint(head)
    print()

    print('In..:', end="")
    inOrderPrint(head)
    print()
    
    print('Post:', end="")
    postOrderPrint(head)
    print()

    print()