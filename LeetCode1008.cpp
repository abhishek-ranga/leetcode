class Solution {
public:
    TreeNode* build(vector<int>& pre, int preLo, int preHi, vector<int>& in, int inLo, int inHi){
        if(preLo>preHi) return nullptr;
        TreeNode* root = new TreeNode(pre[preLo]);
        if(preLo==preHi) return root;
        int i = inLo;
        while(i<=inHi){
            if(in[i]==pre[preLo]) break;
            i++;
        }
        int leftCount = i-inLo; int rightCount = inHi-i;
        root->left = build(pre,preLo+1,preLo+leftCount,in,inLo,inHi-1);
        root->right = build(pre,preLo+leftCount+1,preHi,in,i+1,inHi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in = pre; sort(in.begin(),in.end());
        return build(pre,0,pre.size()-1,in,0,in.size()-1);
    }
};