class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* curr = root;
        int sum = 0;

        while (curr != nullptr) {

            // If right subtree exists
            if (curr->right != nullptr) {

                // Find inorder successor (leftmost node in right subtree)
                TreeNode* succ = curr->right;

                while (succ->left != nullptr && succ->left != curr) {
                    succ = succ->left;
                }

                // Create thread
                if (succ->left == nullptr) {
                    succ->left = curr;
                    curr = curr->right;
                }
                else {
                    // Remove thread
                    succ->left = nullptr;

                    // Process current node
                    sum += curr->val;
                    curr->val = sum;

                    curr = curr->left;
                }
            }

            // No right subtree
            else {
                // Process current node
                sum += curr->val;
                curr->val = sum;

                curr = curr->left;
            }
        }

        return root;
    }
};