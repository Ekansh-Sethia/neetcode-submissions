class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        st.push(n-1);
        vector<int> ans(n,0);
        for(int i = n-2; i >= 0; i--){
            int cur = temperatures[i];
            while(!st.empty() && temperatures[st.top()] <= cur){
                st.pop();
            }
            if(st.empty()) ans[i] = 0;
            else{
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};
