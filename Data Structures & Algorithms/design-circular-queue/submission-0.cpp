class MyCircularQueue {
private:
    struct Node{
        int val;
        Node *next, *prev;
        Node(int v){
            val = v;
            next=prev=nullptr;
        }
    };
    Node *front,*rear;
    int cap;
    int sz;
public:
    MyCircularQueue(int k) {
        front=rear=nullptr;
        cap=k;
        sz=0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            sz++;
            front=rear=new Node(value);
            front->next=front;
            front->prev=front;
            return true;
        }
        Node * temp = new Node(value);
        rear->next=temp;
        temp->prev=rear;
        temp->next=front;
        front->prev=temp;
        rear=temp;
        sz++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(rear==front){
            delete front;
            sz=0;
            return true;
        }
        Node* toDelete = front;
        toDelete->next->prev=rear;
        rear->next=toDelete->next;
        front=front->next;
        sz--;
        delete toDelete;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return front->val;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return rear->val;
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        if (sz==cap){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */