class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> cars;
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.rbegin(),cars.rend());
        int fleets=0;
        double prevT=0;
        for(auto &c:cars){
            if(c.second>prevT){
                fleets++;
                prevT=c.second;
            }
        }
        return fleets;
    }
};

/*
Algorithm: Car Fleet
1. Create pairs of each car's pos and speed.
2. Sort the cars by pos in desc order (closest to the target first).
3. Trav the sorted cars and calc each car's time to reach the target:
time = {target-pos}/{speed}

4. Maintain the time of the fleet ahead of the current car.
5. If the current car takes more time than the fleet ahead, it forms a new fleet. Increment the fleet count and update the fleet time.
6. Otherwise, the current car catches up with the fleet ahead and joins it.
7. Return the total num of fleets.

TC: (O(nlog n)) due to sorting.
SC: (O(n)) for storing the position-speed pairs.

*/
