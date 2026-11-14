class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg=0,tc=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            tg+=gas[i];
            tc+=cost[i];
        }
        if(tg<tc) return -1;
        int cg=0,st=0;
        for(int i=0;i<n;i++){
            cg+=gas[i]-cost[i];
            if(cg<0){
                st=i+1;
                cg=0;
            }
        }
        return st;
    }
};
