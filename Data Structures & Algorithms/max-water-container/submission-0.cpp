class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int mx=0;
        while(left<right){
            int h=min(heights[left],heights[right]);
            int w=right-left;
            int area=h*w;
            mx=max(mx,area);
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return mx;
    }
};
