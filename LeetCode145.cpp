class Solution {
public:
    void postOrder(TreeNode* root, vector<int>& ans){
        if(root==NULL){
            return;
        }
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        if(root->left==NULL && root->right==NULL) return {root->val};
        vector<int> ans;
        postOrder(root,ans);
        return ans;
    }
};