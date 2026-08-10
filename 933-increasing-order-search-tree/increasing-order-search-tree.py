class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummy = curr =TreeNode(None)
        def dfs(root):
            if not root: return
            nonlocal curr
            dfs(root.left)
            curr.right = root
            curr = root
            curr.left = None
            dfs(root.right)
            
        dfs(root)
        return dummy.right