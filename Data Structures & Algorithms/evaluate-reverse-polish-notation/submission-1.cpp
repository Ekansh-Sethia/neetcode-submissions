class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> op = {"+", "-", "*", "/"};
        for(int i = 0; i<tokens.size(); i++){
            string let = tokens[i];
            if(op.count(let)){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(let == "+") st.push(x+y);
                else if (let == "-") st.push(y-x);
                else if (let == "*") st.push(x*y);
                else st.push(y/x);
            }
            else{
                int x = stoi(let);
                st.push(x);
            }
        }
        return st.top();
    }
};
