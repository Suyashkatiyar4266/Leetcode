/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int DFS(TreeNode* root, int num) {

        if(root == NULL)
            return 0 ;

        // Form the current number
        num = num * 10 + root->val;

        // If it is a leaf node, return the number
        if(root->left == NULL && root->right == NULL)
            return num;

        // Sum of left and right subtree
        return DFS(root->left, num) + DFS(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
};