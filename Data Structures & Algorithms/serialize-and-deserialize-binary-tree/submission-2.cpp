class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if(node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else {
                s += "N,";
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            getline(ss, str, ',');
            if(str != "N") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(ss, str, ',');
            if(str != "N") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};