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
    // ListNode* reverseLL(ListNode* l){
    //     if(l==nullptr || l->next==nullptr) return l;
    //     ListNode* ln = reverseLL(l->next);
    //     l->next = nullptr;
    //     ListNode* curr = ln;
    //     while(curr->next){
    //         curr=curr->next;
    //     }
    //     curr->next = l;
    //     return ln;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while(l1 && l1->val==0){
            l1=l1->next;
        }
        while(l2 && l2->val==0){
            l2=l2->next;
        }
        // ListNode* rl1 = reverseLL(l1);
        // ListNode* rl2 = reverseLL(l2);
        ListNode* rl1 = l1;
        ListNode* rl2 = l2;
        ListNode* res = nullptr;
        ListNode* curr = nullptr;
        int sum = 0, carry = 0;
        while(rl1 && rl2){
            int sum = carry + (rl1->val) + (rl2->val);
            carry = sum/10;
            sum=sum%10;
            ListNode* temp = new ListNode(sum);
            if(!res){
                res=temp;
                curr=temp;
            }
            else{
                curr->next=temp;
                curr=curr->next;
            }
            rl1=rl1->next;
            rl2=rl2->next;
        }

        while(rl1){
            int sum = carry + rl1->val;
            carry = sum/10;
            sum=sum%10;
            ListNode* temp = new ListNode(sum);
            if(!res){
                res=temp;
                curr=temp;
            }
            else{
                curr->next=temp;
                curr=curr->next;
            }
            rl1=rl1->next;
        }

        while(rl2){
            int sum = carry + rl2->val;
            carry = sum/10;
            sum=sum%10;
            ListNode* temp = new ListNode(sum);
            if(!res){
                res=temp;
                curr=temp;
            }
            else{
                curr->next=temp;
                curr=curr->next;
            }
            rl2=rl2->next;
        }
        while (carry){
            ListNode* temp = new ListNode(carry%10);
            if(!res){
                res=temp;
                curr=temp;
            }
            else{
                curr->next=temp;
                curr=curr->next;
            }
            carry=carry/10;
        }
        if(res==nullptr){
            return new ListNode(0);
        }
        return res;
    }
};
