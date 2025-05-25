class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int count=0, ans=money;
        for(int i=0; i<prices.size(); i++){
            if(money>=prices[i]){
                money-=prices[i];
                count++;
            }
            if(count==2) return money;
        }
        return ans;
    }
};