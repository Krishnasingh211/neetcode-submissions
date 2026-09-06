class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0;int j=n-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(target==nums[mid]) return mid;
            if(nums[i] <= nums[mid]) {
                // Is the target inside this sorted left half?
                if(target >= nums[i] && target < nums[mid]) {
                    j = mid - 1; // It is, so search left
                } else {
                    i = mid + 1; // It isn't, so search right
                }
            } 
            // CHECK 2: If the left isn't sorted, the RIGHT half MUST be sorted.
            else {
                // Is the target inside this sorted right half?
                if(target > nums[mid] && target <= nums[j]) {
                    i = mid + 1; // It is, so search right
                } else {
                    j = mid - 1; // It isn't, so search left
                }
            }

        }
        return -1;
        
    }
};
