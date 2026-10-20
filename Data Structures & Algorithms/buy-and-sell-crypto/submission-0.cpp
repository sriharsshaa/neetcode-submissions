class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP=INT_MAX;
        int maxPr=0;
        for(int p:prices){
            if(p<minP) minP=p;
            else if(p-minP>maxPr) maxPr=p-minP;
        }
        return maxPr;
    }
};
