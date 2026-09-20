class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void f(int i, vector<int>& nums, vector<int>& temp, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int j = i; j < n; j++) {

            if(j > i && nums[j] == nums[j-1])
                continue;

            if(nums[j] > target)
                break;

            temp.push_back(nums[j]);

            f(j + 1, nums, temp, target - nums[j]);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        n = candidates.size();
        vector<int> temp;

        f(0, candidates, temp, target);

        return ans;
    }
};