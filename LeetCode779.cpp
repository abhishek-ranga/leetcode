class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0) return (kthGrammar(n-1,k/2)==0) ? 1 : 0;
        else return (kthGrammar(n-1,(k+1)/2)==0) ? 0 : 1;
    }
};

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0){ // flip
            int prevAns = kthGrammar(n-1,k/2);
            if(prevAns==0) return 1;
            else return 0;
        }
        else{ // same
            int prevAns = kthGrammar(n-1,(k+1)/2);
            return prevAns;
        }
    }
};