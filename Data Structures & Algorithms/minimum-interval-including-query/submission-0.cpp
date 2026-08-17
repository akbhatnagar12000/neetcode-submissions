class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        // Sort intervals by start
        sort(intervals.begin(), intervals.end());

        // {query, original_index}
        vector<pair<int, int>> qs;

        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        // Sort queries
        sort(qs.begin(), qs.end());

        // {length, end}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int i = 0;
        int n = intervals.size();

        for (auto &[q, idx] : qs) {

            // Add all intervals whose start <= query
            while (i < n && intervals[i][0] <= q) {

                int left = intervals[i][0];
                int right = intervals[i][1];

                int len = right - left + 1;

                pq.push({len, right});

                i++;
            }

            // Remove intervals which have already ended
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};