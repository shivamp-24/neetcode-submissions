class Solution {
private:
    int findDistance(vector<int> &coord) {
        int x = coord[0], y = coord[1];
        return x*x + y*y;
    }
    int partition(vector<vector<int>> &points, int l, int r) {
        int i = l;
        int pivotDistance = findDistance(points[r]);
        for(int j=l; j<r; j++) {
            if(findDistance(points[j]) <= pivotDistance) {
                // we can move this j to the left
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[r]);

        return i;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<pair<int, vector<int>>> pq;
        // for(auto it: points) {
        //     int x = it[0], y = it[1];
        //     int dist = x*x + y*y;

        //     pq.push({dist, it});
        //     if(pq.size() > k) pq.pop();
        // }
        // vector<vector<int>> res;
        // while(!pq.empty()) {
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return res;

        // O(n) approach
        // using quick select
        // goal is to readjust the array points to contain the smallest k-points at the start
        // hence choose a pivot index
        // all elements on left of pviot are smaller and all elements on right of pivot are greater
        // when pivot == k, that means there are k smallest elements on left of pivot
        // that is our goal
        int n = points.size();
        int l = 0, r = n - 1;
        int pivot = n;
        while(pivot != k) {
            pivot = partition(points, l, r);

            if(pivot > k) r = pivot - 1;
            else l = pivot + 1; 
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
