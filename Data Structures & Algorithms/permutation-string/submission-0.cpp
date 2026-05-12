class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        // need to check n length windows in m
        unordered_map<char, int> mp;
        for(char ch: s1) mp[ch]++;

        for(int i=0; i<m; i++) {
            mp[s2[i]]--;
            if(mp[s2[i]] == 0) mp.erase(s2[i]);
            if(i >= n) {
                mp[s2[i-n]]++;
                if(mp[s2[i-n]] == 0) mp.erase(s2[i-n]);
            }

            if(i >= n - 1 && mp.size() == 0) return true;
        }
        return false;
    }
};
