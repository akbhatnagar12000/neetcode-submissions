class Solution {
    vector<string>res;
    string temp;
    unordered_map<int,vector<char>>mp;
public:
    void solveRec(string&digits, int idx){
        if(idx==digits.length()){
            res.push_back(temp);
            return;
        }
        for(auto c:mp[digits[idx]-'0']){
            temp.push_back(c);
            solveRec(digits,idx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return{};
        }
        mp[2].push_back('a');
        mp[2].push_back('b');
        mp[2].push_back('c');
        mp[3].push_back('d');
        mp[3].push_back('e');
        mp[3].push_back('f');
        mp[4].push_back('g');
        mp[4].push_back('h');
        mp[4].push_back('i');
        mp[5].push_back('j');
        mp[5].push_back('k');
        mp[5].push_back('l');
        mp[6].push_back('m');
        mp[6].push_back('n');
        mp[6].push_back('o');
        mp[7].push_back('p');
        mp[7].push_back('q');
        mp[7].push_back('r');
        mp[7].push_back('s');
        mp[8].push_back('t');
        mp[8].push_back('u');
        mp[8].push_back('v');
        mp[9].push_back('w');
        mp[9].push_back('x');
        mp[9].push_back('y');
        mp[9].push_back('z');

        solveRec(digits,0);

        return res;
    }
};
