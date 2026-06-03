class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;

        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});

        string ans;

        while(!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            // Would create xxx?
            if(ans.size() >= 2 &&
               ans.back() == ch1 &&
               ans[ans.size()-2] == ch1) {

                if(pq.empty()) break;

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                cnt2--;

                if(cnt2 > 0)
                    pq.push({cnt2, ch2});

                pq.push({cnt1, ch1});
            }
            else {
                ans += ch1;
                cnt1--;

                if(cnt1 > 0)
                    pq.push({cnt1, ch1});
            }
        }

        return ans;
    }
};