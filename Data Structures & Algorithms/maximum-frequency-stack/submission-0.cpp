class FreqStack {
    unordered_map<int,int> freq;
    int timer = 0;

    // {frequency, timestamp, value}
    priority_queue<tuple<int,int,int>> pq;

public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;

        pq.push({freq[val], timer++, val});
    }
    
    int pop() {
        auto [f, t, val] = pq.top();
        pq.pop();

        freq[val]--;

        if(freq[val] == 0)
            freq.erase(val);

        return val;
    }
};