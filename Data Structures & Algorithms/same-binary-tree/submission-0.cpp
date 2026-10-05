/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return issame(p,q)==1;
        
    }
    int issame(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return 1;
         if(p == NULL || q == NULL)
            return 0;
        if(p->val!=q->val) return 0;     
            
        return issame(p->left,q->left) && issame(p->right,q->right);
    }

};