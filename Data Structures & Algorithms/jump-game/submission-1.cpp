class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<bool> dp(n, false); // dp[i] -> whether it possbile to reach index i
        // dp[0] = true;
        // for(int i=1; i<n; i++) {
        //     for(int j=0; j<i; j++) {
        //         if(dp[j] && (j + nums[j]) >= i) {
        //             dp[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return dp[n-1];

        // O(n) T.C.
        int maxReach = nums[0];
        for(int i=1; i<n; i++) {
            if(maxReach < i) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
