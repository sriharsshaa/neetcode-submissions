class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int x:nums1) ans.push_back(x);
        for(int x:nums2) ans.push_back(x);
        sort(ans.begin(),ans.end());
        int n=ans.size();
        if(n%2!=0) return (double) ans[n/2];
        return ((double)ans[n/2-1]+ans[n/2])/2.0;
    }
};
/*
Algorithm
1. Combine both arrays into one array.
2. Sort the combined array in ascending order.
3. Calculate the total number of elements n.
4. If n is odd, return the middle element at index n / 2.
5. If n is even, return the average of the two middle elements at indices n / 2 - 1 and n / 2.
*/