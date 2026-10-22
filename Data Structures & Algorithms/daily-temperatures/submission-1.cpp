class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int idx=st.top();st.pop();
                ans[idx]=i-idx;
            }
            st.push(i);
        }
        return ans;
    }
};

/*
Algorithm: Daily Temperatures (Monotonic Stack)
    1. Initialize an empty stack to store the indices of temp.
    2. Create an answer arr ans of size n, with 0. This means if no warmer day exists, the answer remains 0.
    3. Trav the temp array from left to right using index i.
    4. While the stack is !empty and temperatures[i]>temperatures[st.top()]
    - Pop the top index and store it in idx.
    - Calc the no of days to wait: ans[idx] = i - idx.
    5. Push the current index i onto the stack.
    6. Return the ans array. Indices remaining in the stack have no warmer day ahead, so their answers 0.

TC: (O(n)) — each index is pushed and popped at most once.
SC: (O(n)) — the stack and ans arr can each store up to n elements.
*/
