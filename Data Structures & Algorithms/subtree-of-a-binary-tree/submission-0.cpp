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
    
    bool isSame(TreeNode* root,TreeNode* subRoot){
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,subRoot});
        while(!q.empty()){
            auto [L,R]=q.front();
            q.pop();
            if(!L&&!R) continue;
            if(!L||!R) return false;
            if(L->val!=R->val) return false;
            q.push({L->left,R->left});
            q.push({L->right,R->right});
        }
        return true;

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr && subRoot) return false;
        TreeNode* cursub=subRoot;
        queue<TreeNode*>node;
        node.push(root);
        while(!node.empty()){
            TreeNode* x=node.front();
            node.pop();
            if(x->val==cursub->val){
                if(isSame(x,cursub)) return true;
            }
            if(x->left) node.push(x->left);
            if(x->right) node.push(x->right);
        }
        return false;
        
    }
};