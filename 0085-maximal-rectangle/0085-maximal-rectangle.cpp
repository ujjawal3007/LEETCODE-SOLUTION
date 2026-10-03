class Solution {
public:
int largestrectangle(vector<int>& heights) {
    stack<int> st;
    int maxarea = 0;
    int n = heights.size();
    for(int i = 0; i <= n; i++) {
        int currheight = (i == n) ? 0 : heights[i];
    
    while(!st.empty() && currheight < heights[st.top()]) {
        int h = heights[st.top()];
        st.pop();
        int w = st.empty() ? i : i - st.top() - 1;
        int area = h * w;
        maxarea = max(maxarea, area);
    }
    st.push(i);
    }
    return maxarea;
}


    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxrectangle = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxrectangle = max(maxrectangle, largestrectangle(heights));
        }
        return maxrectangle;
    }
};