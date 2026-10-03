class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;
        while(i < n) {
            char currentchar = chars[i];
            int count = 0;
            while(i < n && chars[i] == currentchar) {
                count++;
                i++;
            }
            chars[write++] = currentchar;
            if(count > 1) {
                string countstr = to_string(count);
                for(char c : countstr) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};