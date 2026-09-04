class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        ans=[]
        nums.sort()
        for i in range(n-2):
            if(i>0 and nums[i]==nums[i-1]):
                continue
            if(nums[i]>0):
                break    
            sum=-1*nums[i]
            j=i+1
            k=n-1
            while(j<k):
                res=nums[j]+nums[k]
                if res==sum:
                    ans.append([nums[i],nums[j],nums[k]])
                    j+=1
                    k-=1
                    while(j<k and nums[j]==nums[j-1]):
                        j+=1
                    while(j<k and nums[k]==nums[k+1]):
                        k-=1    
                elif(res<sum):
                    j+=1
                else:
                    k-=1
        return ans            

