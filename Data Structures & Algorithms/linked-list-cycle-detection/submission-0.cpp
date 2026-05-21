/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow=head,*fast=head;
        do{
            if(fast && fast->next){
                fast=fast->next->next;
            }
            else{
                return false;
            }
            if(slow)
                slow=slow->next;
            else
                return false;
        }while(slow!=fast);

        return true;
    }
};
