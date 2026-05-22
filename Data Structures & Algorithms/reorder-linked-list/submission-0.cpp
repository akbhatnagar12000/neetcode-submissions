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
    ListNode* reverseLL(ListNode* head)
    {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* currHead = reverseLL(head->next);
        head->next=nullptr;
        ListNode* curr = currHead;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=head;
        return currHead;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return;
        }
        ListNode* slow = head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next=nullptr;
        secondHalf = reverseLL(secondHalf);
        bool pick=true;
        ListNode* curr = head;
        ListNode* running = nullptr;
        while(curr || secondHalf){
            if(pick){
                if(curr)
                {
                    if(!running){
                        running=curr;
                    }
                    else{
                        running->next=curr;
                        running=running->next;
                    }
                    curr=curr->next;
                }
                else{
                    running->next = secondHalf;
                    return;
                }
            }
            else{
                if(secondHalf)
                {
                    running->next=secondHalf;
                    secondHalf=secondHalf->next;
                }
                else{
                    running->next = curr;
                    return;
                }
                running=running->next;
            }
            pick=!pick;
        }
    }
};
