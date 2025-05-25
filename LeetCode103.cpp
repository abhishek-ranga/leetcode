class Solution {
public:
    void displayTree(TreeNode* a, int levelReach, int idx, vector<vector<int>>& ans ){
        if(a==NULL) return;
        if(levelReach==0){
            ans[idx].push_back(a->val);
            return;
        }
        if(idx%2==0)displayTree(a->left, levelReach-1, idx, ans);
        displayTree(a->right, levelReach-1, idx, ans);
        if(idx%2!=0)displayTree(a->left, levelReach-1, idx, ans);
    }
    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        else return 1 + max(Levels(root->left),Levels(root->right));
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level = Levels(root);
        vector<vector<int>> ans(level);
        for(int i=0; i<level; i++){
            displayTree(root,i,i,ans);
        }
        return ans;
    }
};