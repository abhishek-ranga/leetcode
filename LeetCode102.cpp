class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

class Solution { // isme nahi jaana pad raha
public:
    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        else return 1 + max(Levels(root->left),Levels(root->right));
    }
    void lvlOrder(TreeNode* root, vector<vector<int>>& ans, int level){
        if(root==NULL) return ;
        ans[level].push_back(root->val);
        lvlOrder(root->left,ans,level+1);
        lvlOrder(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = Levels(root);
        vector<vector<int>> ans(n);
        lvlOrder(root,ans,0);
        return ans;
    }
};

class Solution { // isme hume harr baar pure tree mein jaana pad raha hai for each level
public:
    void displayTree(TreeNode* a, int levelReach, int idx, vector<vector<int>>& ans ){
        if(a==NULL) return;
        if(levelReach==0){
            ans[idx].push_back(a->val);
            return;
        }
        displayTree(a->left, levelReach-1, idx, ans);
        displayTree(a->right, levelReach-1, idx, ans);
    }
    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        else return 1 + max(Levels(root->left),Levels(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = Levels(root);
        vector<vector<int>> ans(level);
        for(int i=0; i<level; i++){
            displayTree(root,i,i,ans);
        }
        return ans;
    }
};