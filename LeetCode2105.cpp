class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int alice = capacityA; int bob = capacityB; int i=0, j=plants.size()-1;
        int refill = 0;
        while(i<=j){
            if(i==j){
                if(alice>=bob){
                    if(alice>=plants[i]) alice-=plants[i++];
                    else{
                        refill++;
                        alice = capacityA;
                        alice-=plants[i++];
                    }
                }
                else{
                    if(bob>=plants[j]) bob-=plants[j--];
                    else{
                        refill++;
                        bob = capacityB;
                        bob-=plants[j--];
                    }
                } 
                break;
            }
            if(alice>=plants[i]) alice-=plants[i++];
            else{
                refill++;
                alice = capacityA;
                alice-=plants[i++];
            }
            if(bob>=plants[j]) bob-=plants[j--];
            else{
                refill++;
                bob = capacityB;
                bob-=plants[j--];
            }
        }
        return refill;
    }
};