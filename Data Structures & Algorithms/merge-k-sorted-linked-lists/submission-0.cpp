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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto x:lists){
            if(x)
                pq.push({x->val,x});
        }
        
        ListNode* head=nullptr;
        ListNode* curr=nullptr;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(!head){
                head=curr=x.second;
            }
            else{
                curr->next = x.second;
                curr=curr->next;
            }
            if(x.second->next){
                pq.push({x.second->next->val,x.second->next});
            }
        }
        return head;
    }
};
