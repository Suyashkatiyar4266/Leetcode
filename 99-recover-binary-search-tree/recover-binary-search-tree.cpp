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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    vector<int> find_XY(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
        bool flag = false;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                y = nums[i + 1];

                if (!flag) {
                    x = nums[i];
                    flag = true;
                } else {
                    break;
                }
            }
        }

        return {x, y};
    }

    void recover(TreeNode* root, int& count, int x, int y) {
        if (root == nullptr || count == 0)
            return;

        if (root->val == x || root->val == y) {
            root->val = (root->val == x) ? y : x;
            count--;
        }

        recover(root->left, count, x, y);
        recover(root->right, count, x, y);
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);

        vector<int> swapped = find_XY(nums);

        int count = 2;
        recover(root, count, swapped[0], swapped[1]);
    }
};