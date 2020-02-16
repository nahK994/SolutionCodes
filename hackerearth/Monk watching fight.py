class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

N = int(input())
arr = [int(s) for s in input().split() if s.isdigit()]

ans = 1
root = TreeNode(arr[0])
for i in range(1, len(arr)):
    currentNode = root
    previousNode = None
    height = 1

    while currentNode is not None:
        previousNode = currentNode
        height += 1
        if currentNode.data >= arr[i]:
            currentNode = currentNode.left
        elif currentNode.data < arr[i]:
            currentNode = currentNode.right

    if currentNode is None:
        if previousNode.data >= arr[i]:
            previousNode.left = TreeNode(arr[i])
        else:
            previousNode.right = TreeNode(arr[i])

        if ans < height:
            ans = height

print(ans)