#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> memo;

    bool solve(vector<int>& stones, int idx, int prevJump) {
        if (idx == n - 1) return true;
        if (memo[idx][prevJump] != -1) return memo[idx][prevJump];

        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; ++nextJump) {
            if (nextJump <= 0) continue;

            int nextPos = stones[idx] + nextJump;
            auto it = lower_bound(stones.begin() + idx + 1, stones.end(), nextPos);

            if (it != stones.end() && *it == nextPos) {
                int nextIdx = it - stones.begin();
                if (solve(stones, nextIdx, nextJump)) {
                    return memo[idx][prevJump] = 1;
                }
            }
        }

        return memo[idx][prevJump] = 0;
    }

public:
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) return false;

        memo.assign(n, vector<int>(n + 1, -1));
        return solve(stones, 1, 1);
    }
};
