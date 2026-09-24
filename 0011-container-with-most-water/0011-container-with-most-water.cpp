class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size() - 1;
        int maxwater = 0;
        while(lp < rp) {
            int wid = rp - lp;
            int ht = min(height[lp], height[rp]);

            int currwater = wid * ht;
            maxwater = max(maxwater, currwater);
            if(height[lp] < height[rp]) {
                lp++;
            }
            else{
                rp--;
            }
        }
        return maxwater;
    }
};