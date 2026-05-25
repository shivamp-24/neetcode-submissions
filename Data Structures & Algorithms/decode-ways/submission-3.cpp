class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0') return 0;
        if(n == 1) return 1;
        vector<int> dp(n, 0);
        // dp[i] -> number of ways to decode string s[0...i]
        dp[0] = (s[0] == '0') ? 0 : 1;
        dp[1] = (dp[0] == 0) ? 0 : (stoi(s.substr(0, 2)) <= 26 ? (s[1] == '0' ? 1 : 2) : (s[1] == '0' ? 0 : 1));
        cout << stoi(s.substr(0, 2)) << endl;

        for(int i=2; i<n; i++) {
            // pick one digit
            int pickOne = 0;
            if(s[i] != '0') pickOne = dp[i-1];

            //pick two digit
            int pickTwo = 0;
            if(s[i-1] != '0' && stoi(s.substr(i-1, 2)) <= 26) pickTwo = dp[i-2];

            dp[i] = max(dp[i], pickOne + pickTwo);
        }
        for(int x: dp) cout << x << " ";
        return dp[n-1];
    }
};
