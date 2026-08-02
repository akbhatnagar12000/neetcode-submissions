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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* curr=head;
        ListNode* nextCurr=head->next;
        while(nextCurr){
            int g = __gcd(curr->val,nextCurr->val);
            ListNode* temp = new ListNode(g);
            curr->next = temp;
            temp->next = nextCurr;
            curr=nextCurr;
            nextCurr=nextCurr->next;
        }
        return head;
    }
};