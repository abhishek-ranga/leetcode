class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=1, fidx=-1, sidx=-1;
        ListNode *a=head, *b=head->next, *c=head->next->next;
        while(c){
            if(b->val>a->val&&b->val>c->val||(b->val<a->val&&b->val<c->val)){
                if(fidx==-1) fidx=idx; else sidx=idx;
            }
            a=a->next; b=b->next; c=c->next; idx++;
        }
        if(sidx==-1) return {-1,-1};
        int mx = sidx-fidx;
        int mn = INT_MAX;
        idx=1; fidx=-1; sidx=-1; a=head; b=head->next; c=head->next->next;
        while(c){
            if(b->val>a->val&&b->val>c->val||(b->val<a->val&&b->val<c->val)){
                fidx=sidx;
                sidx=idx;
                if(fidx!=-1) mn = min(mn,sidx-fidx);
            }
            a=a->next; b=b->next; c=c->next; idx++;
        }
        return{mn,mx};
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=1, fidx=-1, sidx=-1, f=-1, s=-1; int mn = INT_MAX;
        ListNode *a=head, *b=head->next, *c=head->next->next;
        while(c){
            if(b->val>a->val&&b->val>c->val||(b->val<a->val&&b->val<c->val)){
                if(fidx==-1) fidx=idx; else sidx=idx;
                f=s;
                s=idx;
                if(f!=-1) mn = min(mn,s-f);
            }
            a=a->next; b=b->next; c=c->next; idx++;
        }
        if(sidx==-1) return {-1,-1};
        int mx = sidx-fidx;
        return{mn,mx};
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int n=0; ListNode* temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }
        vector<int> pos(n);
        // pos[0]=0; pos[n-1]=0;
        temp = head; int index=1;
        while(temp && temp->next && temp->next->next && index<n){
            if(temp->next->val > temp->val && temp->next->val > temp->next->next->val){
                pos[index] = 1;
            }
            if(temp->next->val < temp->val && temp->next->val < temp->next->next->val){
                pos[index] = -1;
            }
            temp = temp->next;
            index++;
        }
        int mx = INT_MIN, mn = INT_MAX;
        for(int i=0; i<pos.size(); i++){
            for(int j=i+1; j<pos.size(); j++){
                if(i!=j && pos[i]!=0 && pos[j]!=0){
                    mx = max(mx,abs(j-i));
                    mn = min(mn,abs(j-i));
                }
            }
        }
        if(mx==INT_MIN || mn==INT_MAX) return{-1,-1};
        return{mn,mx};
    }
};