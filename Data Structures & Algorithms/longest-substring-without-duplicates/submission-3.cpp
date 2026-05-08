class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<char> st;
        // int maxLen = 0;
        // int l = 0;
        // for(int r=0; r<s.size(); r++) {
        //     while(st.find(s[r]) != st.end()) {
        //         st.erase(s[l++]);
        //     }
        //     maxLen = max(maxLen, r - l + 1);
        //     st.insert(s[r]);
        // }
        // return maxLen;

        // more optimal
        // instead of moving the left pointer step by step
        // we can jump it one ahead of the last occurrence of upcoming character
        unordered_map<char, int> mp;
        int maxLen = 0, l = 0;
        for(int r=0; r<s.size(); r++) {
            if(mp.find(s[r]) != mp.end()) {
                if(mp[s[r]] >= l) l = mp[s[r]] + 1;
            }
            maxLen = max(maxLen, r - l + 1);
            mp[s[r]] = r;
        }
        return maxLen;
    }
};
