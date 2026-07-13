class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        vector<int> ans;

        for(int ast : asteroids){
             bool destroyed = false;
            
            while (!st.empty() && st.top() > 0 && ast < 0) {
                if (st.top() < abs(ast)) {
                    st.pop(); 
                    continue;
                } 
                else if (st.top() == abs(ast)) {
                    st.pop(); 
                    destroyed = true;
                    break;
                } 
                else {
                    st.top() > abs(ast); 
                    destroyed = true;
                    break;
                }
            }
            
            if(!destroyed) {
                st.push(ast);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};