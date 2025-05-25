class Solution {
public:
    TreeNode* strt = nullptr;
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& m){
        if(!root) return;
        if(root->left) m[root->left] = root;
        if(root->right) m[root->right] = root;
        markParent(root->left,m);
        markParent(root->right,m);
    }
    void find(TreeNode* root, int start){
        if(!root) return;
        if(root->val==start){
            strt = root;
            return;
        }
        find(root->left,start);
        find(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root,start);
        unordered_map<TreeNode*,TreeNode*> m;
        markParent(root,m);
        unordered_set<TreeNode*> s;
        s.insert(strt);
        queue<pair<TreeNode*,int>> q;
        q.push({strt,0});
        int maxLevel = 0;
        while(!q.empty()){
            pair<TreeNode*,int> p = q.front(); q.pop();
            int level = p.second;
            maxLevel = max(maxLevel,level);
            TreeNode* temp = p.first;
            if(temp->left){
                if(s.find(temp->left)==s.end()){
                    q.push({temp->left,level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right){
                if(s.find(temp->right)==s.end()){
                    q.push({temp->right,level+1});
                    s.insert(temp->right);
                }
            }
            if(m.find(temp)!=m.end()){
                if(s.find(m[temp])==s.end()){
                    q.push({m[temp],level+1});
                    s.insert(m[temp]);
                }
            }
        }
        return maxLevel;
    }
};