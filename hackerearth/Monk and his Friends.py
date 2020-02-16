'''
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

for _ in range(int(input())):
    [N, M] = [int(s) for s in input().split() if s.isdigit()]
    arr = [int(s) for s in input().split() if s.isdigit()]
    #print("N = ", N, " M = ", M)
    #print("arr = ", arr)

    root = TreeNode(arr[0])
    for i in range(1, len(arr)):
        currentNode = root
        previousNode = None

        while currentNode is not None:
            previousNode = currentNode
            if currentNode.data == arr[i]:
                if i >= N:
                    print("YES")
                break
            elif currentNode.data > arr[i]:
                currentNode = currentNode.left
            elif currentNode.data < arr[i]:
                currentNode = currentNode.right

        if currentNode is None:
            if previousNode.data > arr[i]:
                previousNode.left = TreeNode(arr[i])
            else:
                previousNode.right = TreeNode(arr[i])
            
            if i >= N:
                print("NO")
'''

for _ in range(int(input())):
    [N, M] = [int(s) for s in input().split() if s.isdigit()]
    arr = [int(s) for s in input().split() if s.isdigit()]

    mp = {a:True for a in arr[:N]}

    for i in arr[N:]:
        if i in mp:
            print("YES")
        else:
            print("NO")
            mp[i] = True