class UnionFind {
private:
    vector<int> Parent, Size;

public:
    UnionFind(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return false;
        }
        if (Size[pu] < Size[pv]) {
            swap(pu, pv);
        }
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) {
            return true;
        }
        for (int num : nums) {
            if (num == 1) {
                return false;
            }
        }

        int MAX = *max_element(nums.begin(), nums.end());
        vector<int> sieve(MAX + 1, 0);
        for (int p = 2; p * p <= MAX; p++) {
            if (sieve[p] == 0) {
                for (int composite = p * p; composite <= MAX; composite += p) {
                    sieve[composite] = p;
                }
            }
        }

        UnionFind uf(N + MAX + 1);
        for (int i = 0; i < N; i++) {
            int num = nums[i];
            if (sieve[num] == 0) { // num is prime
                uf.unionSet(i, N + num);
                continue;
            }

            while (num > 1) {
                int prime = sieve[num] != 0 ? sieve[num] : num;
                uf.unionSet(i, N + prime);
                while (num % prime == 0) {
                    num /= prime;
                }
            }
        }

        int root = uf.find(0);
        for (int i = 1; i < N; i++) {
            if (uf.find(i) != root) {
                return false;
            }
        }
        return true;
    }
};