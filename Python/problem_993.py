# Definition for a binary tree node.
from collections import deque

class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        queue = deque([root])
        x_found = False
        y_found = False

        while(queue):
            size = len(queue)
            
            for _ in range(size):
                node = queue.popleft()

                if node.left and node.right:
                    if (node.left.val == x and node.right.val == y) or (node.left.val == y and node.right.val == x):
                        return False
                
                if node.left:
                    if (node.left.val == x): x_found = True
                    if (node.left.val == y): y_found = True
                    queue.append(node.left)
                
                if node.right:
                    if (node.right.val == x): x_found = True
                    if (node.right.val == y): y_found = True
                    queue.append(node.right)

            if x_found and y_found: return True
            if x_found or y_found: return False

        return False

        