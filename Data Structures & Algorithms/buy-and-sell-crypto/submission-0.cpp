class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = 1e9;
        for(int x: prices) {
            maxProfit = max(maxProfit, x - minPrice);
            minPrice = min(minPrice, x);
        }
        return maxProfit;
    }
};
