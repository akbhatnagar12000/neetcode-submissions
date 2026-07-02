class Solution {
public:
    // dfs for topological sorting and cycle detection
    bool dfs(int u, vector<vector<int>> &graph, vector<int> &vis, 
                                        vector<int> &rec, string &ans) {
        
        // Mark the node as visited 
        //and part of the current recursion stack
        vis[u] = rec[u] = 1;  

        for (int v = 0; v < 26; v++) {
            if (graph[u][v]) {  
                if (!vis[v]) {  
                    
                    // Recurse and check for cycle
                    if (!dfs(v, graph, vis, rec, ans))  
                        return false;
                } else if (rec[v]) {
                    
                    // A cycle is detected if v is already 
                    //in the current recursion stack
                    return false; 
                }
            }
        }
        
        // Add the character to the result after visiting all dependencies
        ans.push_back(char('a' + u));
        
        // Remove from recursion stack
        rec[u] = 0;  
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> graph(26, vector<int>(26, 0));
        vector<int> exist(26, 0);  
        vector<int> vis(26, 0);   

        vector<int> rec(26, 0);   
        string ans = "";          

        // Mark all characters that appear in the input
        for (string word : words) {
            for (char ch : word) {
                exist[ch - 'a'] = 1;
            }
        }

        //Build the graph 
        for (int i = 0; i + 1 < words.size(); i++) {
            string &a = words[i], &b = words[i + 1];
            int n = a.size(), m = b.size(), ind = 0;

            // Find the first different character between a and b
            while (ind < n && ind < m && a[ind] == b[ind])
                ind++;

            if (ind != n && ind == m)
                return "";

            
            if (ind < n && ind < m)
                graph[a[ind] - 'a'][b[ind] - 'a'] = 1;
        }

        
        for (int i = 0; i < 26; i++) {
            if (exist[i] && !vis[i]) {
                bool x=dfs(i, graph, vis, rec, ans);
                    
                    // Return empty string if a cycle is found
                if(x==false) return "";  
                }
            }
        
        // Reverse to get the correct topological order
        reverse(ans.begin(), ans.end());  
        return ans;
    }
};
