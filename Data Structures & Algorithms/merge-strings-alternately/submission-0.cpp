class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int i=0,j=0;
        while(i<word1.length() && j<word2.length()){
            if(res.length()%2==0){
                res.push_back(word1[i]);
                i++;
            }
            else{
                res.push_back(word2[j]);
                j++;
            }
        }
        while(i<word1.length()){
            res.push_back(word1[i]);
            i++;
        }
        while(j<word2.length()){
            res.push_back(word2[j]);
            j++;
        }
        return res;
    }
};