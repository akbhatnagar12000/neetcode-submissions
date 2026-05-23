class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node* curr = head;

        // Step 1: Insert copied nodes
        while(curr) {
            Node* temp = new Node(curr->val);

            temp->next = curr->next;
            curr->next = temp;

            curr = temp->next;
        }

        // Step 2: Copy random pointers
        curr = head;

        while(curr) {
            if(curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // Step 3: Separate the lists
        curr = head;
        Node* copyHead = head->next;

        while(curr) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if(copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};