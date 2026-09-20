class Solution {
public:
    vector<vector<int>>ans;
    int n;
    
    void f(int i,vector<int>&nums,vector<int>&temp,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n || target<0) return;
        temp.push_back(nums[i]);
        f(i,nums,temp,target-nums[i]);
        temp.pop_back();
        f(i+1,nums,temp,target);
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        vector<int>temp;
        f(0,nums,temp,target);
        return ans;
    }
};
