class CountSquares {
    map<pair<int,int>,int>mp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];
        int ans = 0;
        for(auto p:mp){
            int x = p.first.first;
            int y = p.first.second;

            // (x,y) and (qx,qy) must be diagonal corners
            if (abs(x - qx) != abs(y - qy) || x == qx || y == qy)
                continue;

            if(mp.find({qx,y})!=mp.end() && mp.find({x,qy})!=mp.end()){
                ans+=p.second*mp[{qx,y}]*mp[{x,qy}];
            }
        }
        return ans;
    }
};
