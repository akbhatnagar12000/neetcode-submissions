class MyHashMap {
private:
    struct ListNode {
        int key, val;
        ListNode* next;

        ListNode(int key = -1, int val = -1, ListNode* next = nullptr)
            : key(key), val(val), next(next) {}
    };

    vector<ListNode*> mp;
    int hash(int key) {
        return key % mp.size();
    }

public:
    MyHashMap() {
        mp.resize(1000);
        for (auto& bucket : mp) {
            bucket = new ListNode(0);
        }
    }

    void put(int key, int value) {
        ListNode* cur = mp[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }
        cur->next = new ListNode(key, value);
    }

    int get(int key) {
        ListNode* cur = mp[hash(key)]->next;
        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }

    void remove(int key) {
        ListNode* cur = mp[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                return;
            }
            cur = cur->next;
        }
    }
};