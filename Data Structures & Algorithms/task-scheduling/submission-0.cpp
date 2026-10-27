class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(int t:tasks) freq[t]++;
        int maxF=0;
        int maxC=0;
        for(auto &it:freq){
            maxF=max(maxF,it.second);
        }
        for(auto &it:freq){
            if(maxF==it.second) maxC++;
        }
        return max((int)tasks.size(),(n+1)*(maxF-1)+maxC);
    }
};
