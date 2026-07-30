
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        TreeNode* cur = root;
        TreeNode* pred;
        while(cur!=NULL)
        {
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                pred = cur->left;
                while(pred->right!=NULL && pred->right!=cur)
                {
                    pred = pred->right;
                }
                if(pred->right==NULL){
                    pred->right=cur;
                    cur=cur->left;
                }
                else{
                    pred->right=NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
    
};