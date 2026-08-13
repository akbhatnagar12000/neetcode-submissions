class Solution {
    map<pair<int,int>, bool> mp;

    bool solveRec(string& s, string& p, int i, int j) {

        // Both string and pattern are exhausted
        if (i < 0 && j < 0) {
            return true;
        }

        // Pattern exhausted but string remains
        if (j < 0) {
            return false;
        }

        // String exhausted
        // Remaining pattern must be something like a*b*c*
        if (i < 0) {
            if (j >= 1 && p[j] == '*') {
                return solveRec(s, p, i, j - 2);
            }
            return false;
        }

        if (mp.find({i, j}) != mp.end()) {
            return mp[{i, j}];
        }

        bool ans = false;

        // '*' applies to p[j-1]
        if (p[j] == '*') {

            // Option 1: Use zero occurrences of p[j-1]
            ans |= solveRec(s, p, i, j - 2);

            // Option 2: Use one/more occurrences
            if (p[j - 1] == '.' || p[j - 1] == s[i]) {
                ans |= solveRec(s, p, i - 1, j);
            }
        }

        // Normal character / '.'
        else if (p[j] == '.' || p[j] == s[i]) {
            ans |= solveRec(s, p, i - 1, j - 1);
        }

        return mp[{i, j}] = ans;
    }

public:
    bool isMatch(string s, string p) {
        mp.clear();
        return solveRec(s, p, s.length() - 1, p.length() - 1);
    }
};