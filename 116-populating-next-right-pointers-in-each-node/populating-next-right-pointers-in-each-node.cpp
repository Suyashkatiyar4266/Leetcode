class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            
            int level_size = q.size();

            for (int i = 1; i <= level_size; i++) {

                Node* node = q.front();
                q.pop();

                // Connect current node to next node
                if (i == level_size) {
                    node->next = NULL;
                }
                else {
                    node->next = q.front();
                }

                // Push left child
                if (node->left != NULL) {
                    q.push(node->left);
                }

                // Push right child
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};