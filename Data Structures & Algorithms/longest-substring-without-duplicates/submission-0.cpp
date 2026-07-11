class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_set<char> st;
        int ans = 0;
        while(j < n){
            while(i <= j && st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            st.insert(s[j]);
            j++;
        }
        return ans;
    }
};
