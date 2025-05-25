class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k){
        int n = energy.size(), ans = INT_MIN;
        // Merge energy of every kth magician with its predecessor,
        // starting from the end of the line and moving backwards.
        for(int j = n - k - 1; j >= 0; j--){
            energy[j] += energy[j + k];
        }
        // Find the maximum energy accumulated after merging energies
        // and traversing through the line of magicians.
        for(int i = 0; i < n; i++){
            ans = max(ans, energy[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> net(n);
        int mx = INT_MIN;
        if(k==1){
            net[n-1]=energy[n-1];
            mx = net[n-1];
            for(int i=n-2; i>=0; i--){
                net[i]=energy[i]+net[i+1];
                if(net[i]>mx) mx=net[i];
            }
        }
        else{
            for(int i=0; i<n; i++){
                int j=i;
                while(j<n){
                    net[i]+=energy[j];
                    j+=k;
                }
                if(net[i]>mx) mx = net[i];
            }
        }  
        return mx;
    }
};