class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, currSum = 0;
        for(int x: nums) {
            currSum += x;
            maxi = max(maxi, currSum);
            if(currSum < 0) currSum = 0;
        }

        return maxi;
    }
};
