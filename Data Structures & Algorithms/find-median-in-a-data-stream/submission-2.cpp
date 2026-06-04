class MedianFinder {
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    int sz;
public:
    MedianFinder() {
        sz=0;
    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
        }
        else if(left.size()==right.size()){
            auto x = left.top();
            if(num<x){
                left.push(num);
            }
            else{
                right.push(num);
                auto y = right.top();
                right.pop();
                left.push(y);
            }
        }
        else{
            auto x = left.top();
            if(num<x){
                left.pop();
                right.push(x);
                left.push(num);
            }
            else{
                right.push(num);
            }
        }
        sz++;
    }
    
    double findMedian() {
        if(sz%2){
            return (double)left.top();
        }
        else{
            return ((double)left.top()+(double)right.top())/2.0;
        }
    }
};
