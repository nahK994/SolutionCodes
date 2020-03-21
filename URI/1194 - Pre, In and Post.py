class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def postOrderPrint(a):
    if a is None:
        return
    postOrderPrint(a.left)
    postOrderPrint(a.right)
    print(a.data, end="")

for _ in range(int(input())):
    a = input()
    a = a.split()

    l = int(a[0])
    preOrder = a[1]
    inOrder = a[2]

    nodeValue = {}
    for i in range(l):
        nodeValue[ inOrder[i] ] = i
    
    head = node(preOrder[0])

    for i in range(1, l):
        root = head
        while True:
            if nodeValue[preOrder[i]] > nodeValue[root.data]:
                if root.right is None:
                    root.right = node(preOrder[i])
                    break
                else:
                    root = root.right
            else:
                if root.left is None:
                    root.left = node(preOrder[i])
                    break
                else:
                    root = root.left
    
    postOrderPrint(head)
    print()

'''
1
16 ABCDEFGHIJKLMNOP DCEBGFHAKJLINMOP

   DECGHFBKLJNPOMIA
'''