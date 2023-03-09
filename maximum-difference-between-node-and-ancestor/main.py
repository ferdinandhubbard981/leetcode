# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def combineArr(arr1, arr2):
        for element in arr2:
            arr1.append(element)
        
    def getRowNodes(self, row, nodes):
        if not self:
            return
        if row == 0:
            nodes.append(self)
        else:
            nodes, self.getRowNodes(row-1, nodes)
        
    
    def constructTree(self, nodeVals):
        # assign root node
        self.val = nodeVals[0]
        index = 1
        row = 0
        while index < len(nodeVals):
            # get row nodes
            nodes = []
            nodes = self.getRowNodes(row, nodes)
            row += 1
            # assign children
            for node in nodes:
                if nodeVals[index] != None:
                    node.left = TreeNode(nodeVals[index])
                index += 1
                if nodeVals[index] != None:
                    node.right = TreeNode(nodeVals[index])
                index += 1
        return self
        
        
# find maximum value v such that v = a.val - b.val && a is ancestor(b)
class Solution(object):
    
    def helper(self, root, max_val, min_val):
        if not root:
            return
        # update result
        self.result = max(self.result, max_val - root.val)
        # get max
        max_val = max(max_val, root.val)
        # get min
        min_val = min(min_val, root.val)
        # call left node
        self.helper(root.left, max_val, min_val)
        # call right node
        self.helper(root.right, max_val, min_val)
        
    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return
        self.result = 0
        self.helper(root, root.val, root.val)
        return self.result
        
                
            
            
            
        

def main():
    input = [8,3,10,1,6,None,14,None,None,4,7,13]
    instance = Solution()
    root = TreeNode()
    root.constructTree(input)
    print(instance.maxAncestorDiff(root))
    

if __name__ == "__main__":
    main()