class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        vector<pair<int, int>> arr;
        int n = position.size();
        for(int i=0; i<n; i++) arr.push_back({position[i], speed[i]});
        sort(arr.begin(), arr.end());

        int totalCount = 0;
        vector<double> times;
        for(int i=0; i<n; i++) {
            times.push_back((double)(target - arr[i].first) / arr[i].second);
        }

        double maxTimeSoFar = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(times[i] > maxTimeSoFar) {
                totalCount++;
                maxTimeSoFar = times[i];
            }
        }

        return totalCount;
    }
};