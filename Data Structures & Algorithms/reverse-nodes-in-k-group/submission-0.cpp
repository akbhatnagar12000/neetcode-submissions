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
    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* nextg = reverseLL(head->next);
        head->next = nullptr;
        ListNode* curr = nextg;
        while(curr->next){
            curr=curr->next;
        }
        curr->next = head;
        return nextg;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int counter = 0;
        for(int i=0;i<k && curr;i++){
            prev = curr;
            counter++;
            curr=curr->next;
        }
        if(counter < k)
            return head;
        prev->next = nullptr;
        ListNode* tail = head;
        head = reverseLL(head);
        curr = reverseKGroup(curr,k);
        tail->next = curr;
        return head;
    }
};
