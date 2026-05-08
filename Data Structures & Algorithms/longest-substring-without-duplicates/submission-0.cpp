class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLen = 0;
        int l = 0;
        for(int r=0; r<s.size(); r++) {
            while(st.find(s[r]) != st.end()) {
                st.erase(s[l++]);
            }
            maxLen = max(maxLen, r - l + 1);
            st.insert(s[r]);
        }
        return maxLen;
    }
};
