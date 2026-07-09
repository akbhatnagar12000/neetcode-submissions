class Solution {
    unordered_map<string,char>mp;
    unordered_map<int,int>dp;
    int solveRec(string&s, int idx){
        if(idx==s.length()){
            return 1;
        }
        if(dp.find(idx)!=dp.end()){
            return dp[idx];
        }
        string temp="";
        int ans = 0;
        for(int i=idx;i<s.length();i++){
            temp.push_back(s[i]);
            if(mp.find(temp)!=mp.end()){
                ans+=solveRec(s,i+1);
            }
        }
        return dp[idx]=ans;
    }
public:
    int numDecodings(string s) {
        mp["1"]='A';mp["2"]='B';mp["3"]='C';mp["4"]='D';mp["5"]='E';
        mp["6"]='F';mp["7"]='G';mp["8"]='H';mp["9"]='I';mp["10"]='J';
        mp["11"]='K';mp["12"]='L';mp["13"]='M';mp["14"]='N';mp["15"]='O';
        mp["16"]='P';mp["17"]='Q';mp["18"]='R';mp["19"]='S';mp["20"]='T';
        mp["21"]='U';mp["22"]='V';mp["23"]='W';mp["24"]='X';mp["25"]='Y';
        mp["26"]='Z';
        return solveRec(s,0);
    }
};
