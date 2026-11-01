// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

//  //Iterative reversal 
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         int count = 0;
//         // Check whether k nodes are available or not 
//         while(temp != NULL && count < k){
//             temp = temp->next;
//             count++;
//         }
//         if(count < k)
//             return head;
        
//         // Reverse k nodes
//         ListNode* prev = NULL;
//         ListNode* curr =head;

//         for(int i = 0; i < k; i++){
//             ListNode* nextNode = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextNode;
//         }

//         //Connect remaining groups
//         head->next = reverseKGroup(curr,k);
//         return prev;
//     }
// };


//Iterative using dummy node 
class Solution{
    public:
    ListNode* reverseKGroup(ListNode*head, int k){
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while(true){
            //Find kth node
            ListNode* kth = groupPrev;
            for(int i = 0; i < k && kth != NULL; i++){
                kth = kth->next;
            }
            //Less than k nodes remaining
            if(kth == NULL)
                break;
            ListNode* groupNext = kth->next;
            //Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext){
                ListNode* nextNode=curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
        // Connect reversed group 
        ListNode* temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
        }
        return dummy.next;
    }
};