class Solution {
bool check(unordered_map<char,int> &mpT, unordered_map<char,int> &mpS){
    for(auto &i : mpT){
        if(i.second > mpS[i.first]) return false;
    }
    return true;
}
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        int n = s.length();
        int st = 0, e = n;
        int i = 0, j = 0;
        int mini = INT_MAX;
        unordered_map<char,int> mpT, mpS;
        for(char ch : t) mpT[ch]++;

        while(j < n){
            mpS[s[j]]++;

            while(i <= j && check(mpT,mpS)){
                if(j - i + 1 < mini){
                    st = i;
                    e = j;
                    mini = e - st + 1;
                }
                mpS[s[i]]--;
                i++;
            }
            j++;
        }

        return mini != INT_MAX ? s.substr(st,(e-st+1)) : "";
    }
};
