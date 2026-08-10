class Solution {
public:
    void inorder(TreeNode* root , vector<int>& elem){
        if(root == nullptr)
        return ;

        inorder(root->left,elem);
        elem.push_back(root->val);
        inorder(root->right,elem);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> elem;
        inorder(root,elem);
        
        TreeNode* temp = new TreeNode(0);
        TreeNode* curr = temp;

        for(auto x : elem){
            curr->right = new TreeNode(x);
            curr = curr->right;
        }
        return temp->right;
    }
};