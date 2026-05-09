class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        multiset<int> st;
        int l = 0, longest = 0;
        for(int r=0; r<n; r++) {
            if(mp.find(s[r]) != mp.end()) {
                st.erase(st.find(mp[s[r]]));
            }
            mp[s[r]]++;
            st.insert(mp[s[r]]);

            int len = r - l + 1;
            int maxi = *(--st.end());

            while(len - maxi > k) {
                st.erase(st.find(mp[s[l]]));
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                else st.insert(mp[s[l]]);

                len--;
                maxi = *(--st.end());

                l++;
            }

            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
