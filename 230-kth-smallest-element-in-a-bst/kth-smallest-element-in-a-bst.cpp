// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         inorder(root,ans);
//         return ans[k-1];
//     }
//     void inorder(TreeNode *root, vector<int> &ans)
//     {
//         if (root == NULL)
//         return;
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right, ans);
//     }
// };


//2nd APPROACH

class Solution {
public:
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while(curr!=NULL || !st.empty())
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr=st.top();
            st.pop();
            k--;
            if(k==0)
            return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};
