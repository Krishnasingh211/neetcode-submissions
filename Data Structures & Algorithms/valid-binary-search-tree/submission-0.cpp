class Solution {
public:
    void iino(TreeNode* root,vector<int>&ans){
        if(!root) return;
        iino(root->left,ans);
        ans.push_back(root->val);
        iino(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int>ans;
        iino(root,ans);
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]) return false;
        }
        return true;
    }
};