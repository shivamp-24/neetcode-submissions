class Solution {
private:
    bool possible(int mid, vector<int> &piles, int h) {
        int reqHours = 0;
        for(int x: piles) {
            reqHours += (x + mid - 1) / mid;
        }
        return reqHours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid, res;
        while(low <= high) {
            mid = low + (high - low) / 2;

            if(possible(mid, piles, h)) {
                res = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return res;
    }
};
