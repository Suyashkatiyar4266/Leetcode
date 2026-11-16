
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;

        for (ListNode* curr = head; curr != nullptr;
             curr = curr->next) {

            int nextGreater = 0;
            ListNode* temp = curr->next;

            while (temp != nullptr) {
                if (temp->val > curr->val) {
                    nextGreater = temp->val;
                    break;
                }
                temp = temp->next;
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
