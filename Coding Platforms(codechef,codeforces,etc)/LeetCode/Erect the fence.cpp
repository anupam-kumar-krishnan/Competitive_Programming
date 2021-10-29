class Solution {
public:
int crossProduct(vector<int> A, vector<int> B, vector<int> C) {
        int BAx = A[0] - B[0];
        int BAy = A[1] - B[1];
        int BCx = C[0] - B[0];
        int BCy = C[1] - B[1];
        return BAx * BCy - BAy * BCx;
    }
    
    int dist(vector<int> A, vector<int> B) {
        return (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]);
    }
    
    bool check(vector<vector<int>>& res, vector<int> p) {
        for (vector<int> r : res) {
            if (r[0] == p[0] && r[1] == p[1]) return false;
        }
        return true;
    }
    
    
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> res;
        vector<int> first = trees[0];
        int firstIdx = 0, n = trees.size();
        for (int i = 1; i < n; ++i) {
            if (trees[i][0] < first[0]) {
                first = trees[i];
                firstIdx = i;
            }
        }
        res.push_back(first);
        vector<int> cur = first;
        int curIdx = firstIdx;
        while (true) {
            vector<int> next = trees[0];
            int nextIdx = 0;
            for (int i = 1; i < n; ++i) {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, trees[i], next);
                if (nextIdx == curIdx || cross > 0 || (cross == 0 && dist(trees[i], cur) > dist(next, cur))) {
                    next = trees[i];
                    nextIdx = i;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, trees[i], next);
                if (cross == 0) {
                    if (check(res, trees[i])) res.push_back(trees[i]);
                }
            }
            cur = next;
            curIdx = nextIdx;
            if (curIdx == firstIdx) break;
        }
        return res;
    }
    
  
};
