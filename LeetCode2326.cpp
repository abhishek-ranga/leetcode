class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int minrow = 0, maxrow = m-1, mincol = 0, maxcol = n-1;
        ListNode* temp = head;
        while(minrow<=maxrow && mincol<=maxcol){
            for(int j=mincol; j<=maxcol; j++){
                if(temp==NULL) return matrix;
                matrix[minrow][j] = temp->val;
                temp = temp->next;
            }
            minrow++;
            if(minrow>maxrow) break;
            for(int i=minrow; i<=maxrow; i++){
                if(temp==NULL) return matrix;
                matrix[i][maxcol] = temp->val;
                temp = temp->next;
            }
            maxcol--;
            if(mincol>maxcol) break;
            for(int j=maxcol; j>=mincol; j--){
                if(temp==NULL) return matrix;
                matrix[maxrow][j] = temp->val;
                temp = temp->next;
            }
            maxrow--;
            if(minrow>maxrow) break;
            for(int i=maxrow; i>=minrow; i--){
                if(temp==NULL) return matrix;
                matrix[i][mincol] = temp->val;
                temp = temp->next;
            }
            mincol++;
            if(mincol>maxcol) break;
        }
        return matrix;
    }
};