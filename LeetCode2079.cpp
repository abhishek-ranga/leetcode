class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps=0; int water = capacity;
        for(int i=0; i<plants.size(); i++){
            if(water>=plants[i]){
                water-=plants[i];
                steps++;
            }
            else{
                steps+=(2*i)+1;
                water = capacity;
                water-=plants[i];
            }
        }
        return steps;
    }
};