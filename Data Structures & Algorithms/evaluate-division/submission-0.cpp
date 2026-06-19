class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>mp;
        for(int i=0;i<values.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],(double)values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/(double)values[i]});
        }
        vector<double>res;
        for(auto q:queries){
            string from = q[0];
            string to = q[1];
            // cout<<from<<" "<<to<<"\n";
            if(mp.find(from)==mp.end() || mp.find(to)==mp.end()){
                // cout<<"Haha\n";
                res.push_back(-1.0);
                continue;
            }
            if(from==to){
                res.push_back(1.0);
                continue;
            }
            double ans = -1.0;
            queue<pair<string,double>> qu;
            unordered_set<string> vis;

            qu.push({from,1.0});
            vis.insert(from);

            while(!qu.empty()){
                auto [node,val] = qu.front();
                qu.pop();

                if(node == to){
                    ans = val;
                    break;
                }

                for(auto &[nbr,wt] : mp[node]){
                    if(!vis.count(nbr)){
                        vis.insert(nbr);
                        qu.push({nbr,val * wt});
                    }
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};