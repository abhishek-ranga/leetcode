class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        for(int i=0; i<operations.size(); i++){
            char ch = operations[i][0];
            if(ch=='+'){
                int val1 = record.top(); record.pop();
                int val2 = record.top(); record.pop();
                record.push(val2); record.push(val1);
                int ans = val1+val2; record.push(ans);
            }
            else if(ch=='D'){
                int val = record.top();
                int ans = 2*val;
                record.push(ans);
            }
            else if(ch=='C') record.pop();
            else{
                int num = stoi(operations[i]);
                record.push(num);
            }
        }
        int sum=0;
        while(record.size()!=0){
            sum+=record.top();
            record.pop();
        }
        return sum;
    };
};