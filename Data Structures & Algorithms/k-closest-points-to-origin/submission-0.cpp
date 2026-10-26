class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;
    vector<vector<int>> ans;
        for(auto& p:points){
            int x=p[0];
            int y=p[1];
            int dis=x*x + y*y;
            pq.push({dis,{x,y}});
        }
        for(int i=0;i<k;i++){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            ans.push_back({x,y});
        }
        return ans;
    }
};
