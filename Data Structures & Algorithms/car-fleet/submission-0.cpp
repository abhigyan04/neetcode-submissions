class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> posSpeed;
        for(int i = 0 ; i < n ; i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.rbegin(), posSpeed.rend());
        int fleets = 1;
        double prevTime = (double)(target - posSpeed[0].first) / posSpeed[0].second;
        for(int i = 1 ; i < n ; i++) {
            double currTime = (double)(target - posSpeed[i].first) / posSpeed[i].second;
            if(currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};
