//Hare and tortoise approach(Slow and fast approach)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find starting node of cycle
                ListNode *start = head;

                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }

                return start;
            }
        }

        return NULL;
    }
};