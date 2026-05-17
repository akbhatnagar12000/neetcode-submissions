class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {

            // process token when '/' or end reached
            if (i == path.size() || path[i] == '/') {

                if (curr == "" || curr == ".") {
                    // ignore
                }
                else if (curr == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else {
                    st.push_back(curr);
                }

                curr = "";
            }
            else {
                curr += path[i];
            }
        }

        // build answer
        string res = "";

        for (string &dir : st) {
            res += "/" + dir;
        }

        return res.empty() ? "/" : res;
    }
};