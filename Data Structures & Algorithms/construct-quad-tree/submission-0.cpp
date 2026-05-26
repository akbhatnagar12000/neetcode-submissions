/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    bool isSame(vector<vector<int>>& grid,
                int rs, int re,
                int cs, int ce) {

        int val = grid[rs][cs];

        for(int i = rs; i <= re; i++) {
            for(int j = cs; j <= ce; j++) {
                if(grid[i][j] != val)
                    return false;
            }
        }

        return true;
    }

    Node* solve(vector<vector<int>>& grid,
                int rs, int re,
                int cs, int ce) {

        // If all values are same -> leaf node
        if(isSame(grid, rs, re, cs, ce)) {
            return new Node(grid[rs][cs], true);
        }

        Node* root = new Node(1, false);

        int rm = (rs + re) / 2;
        int cm = (cs + ce) / 2;

        root->topLeft =
            solve(grid, rs, rm, cs, cm);

        root->topRight =
            solve(grid, rs, rm, cm + 1, ce);

        root->bottomLeft =
            solve(grid, rm + 1, re, cs, cm);

        root->bottomRight =
            solve(grid, rm + 1, re, cm + 1, ce);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return solve(grid, 0, n - 1, 0, n - 1);
    }
};