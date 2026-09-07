class Solution {
private:
    TreeNode* xparent = NULL;
    TreeNode* yparent = NULL;

    int xdepth = -1;
    int ydepth = -1;

    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y) {

        if (root == NULL)
            return;

        // If current node is x
        if (root->val == x) {
            xparent = parent;
            xdepth = depth;
        }

        // If current node is y
        if (root->val == y) {
            yparent = parent;
            ydepth = depth;
        }

        // Traverse left
        dfs(root->left, root, depth + 1, x, y);

        // Traverse right
        dfs(root->right, root, depth + 1, x, y);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {

        dfs(root, NULL, 0, x, y);

        if (xparent != yparent && xdepth == ydepth)
            return true;

        return false;
    }
};