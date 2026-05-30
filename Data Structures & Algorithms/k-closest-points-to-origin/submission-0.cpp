class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            int d1 = a[0] * a[0] + a[1] * a[1];
            int d2 = b[0] * b[0] + b[1] * b[1];
            return d1 > d2; // min-heap
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

        for (auto& x : points) {
            pq.push(x);
        }

        vector<vector<int>> res;
        while (k--) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};