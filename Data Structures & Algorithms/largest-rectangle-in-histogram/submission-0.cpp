class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ma=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            int h=(i==n)?0:heights[i];
            while(!st.empty() && h<heights[st.top()]){
                int hh=heights[st.top()];
                st.pop();
                int w=st.empty()?i:i-st.top()-1;
                ma=max(ma,hh*w);
            }
            st.push(i);
        }
        return ma;
    }
};
/*

Algorithm: Largest Rectangle in Histogram
1. Initialize ma = 0 to store the max rectangle area and an empty stack st to store indices of histogram bars.
2. Trav the histogram from index 0 to n (inclusive).
3. For each index i, set the current height h to heights[i]. If i == n, set h = 0 to process all remaining bars in the stack.
4. While the stack is not empty and the current height is smaller than the height at the top index of the stack:
   - Store the top bar's height in hh and pop its index.
   - Calcu the width:
     - If the stack is empty, w = i.
     - Otherwise, w = i - st.top() - 1.
   - Calc the area as hh * w and update ma with the maximum area.
5. Push the current index i onto the stack.
6. Return ma, the largest rectangle area.

TC: (O(n)) — each index is pushed and popped at most once.
SC: (O(n)) — the stack can store up to n+1 indices.

*/