class Solution {
private:
    vector<vector<int>> res;

    void createSubsets(int ind, vector<int> &temp, vector<int> &nums) {
        if(ind == nums.size()) {
            res.push_back(temp);
            return;
        }

        // pick
        temp.push_back(nums[ind]);
        createSubsets(ind + 1, temp, nums);

        // skip
        temp.pop_back();
        createSubsets(ind + 1, temp, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        createSubsets(0, temp, nums);

        return res;
    }
};
