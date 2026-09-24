class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;
        // expected sum
        long long expected_sum = (N *(N + 1)) / 2;
        long long expected_sq_sum = N * (N + 1) * (2 * N + 1) / 6;
        long long actualsum = 0;
        long long actual_sq_sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                long long val = grid[i][j];
                actualsum += val;
                actual_sq_sum += (val * val);
            }
        }
        long long diff1 = (actualsum - expected_sum);
        long long diff2 = (actual_sq_sum - expected_sq_sum);
        long long sum1 = diff2 / diff1;
        int a = (diff1 + sum1) / 2;
        int b = (sum1 - diff1) / 2;
        return{a, b};
    }
};