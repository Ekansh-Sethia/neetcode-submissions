class Solution {
private:
    bool check(unordered_map<char,int>& mpS1, unordered_map<char,int>& mpS2){
        for(auto &i : mpS1){
            if(i.second > mpS2[i.first]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;

        unordered_map<char,int> mpS1, mpS2;
        for(char ch : s1) mpS1[ch]++;

        for(int i = 0; i < n; i++){
            mpS2[s2[i]]++;
        }
        if(check(mpS1,mpS2)) return true;

        int i = 0;
        int j = n;

        while(j < m){
            mpS2[s2[i]]--;
            i++;

            mpS2[s2[j]]++;
            j++;

        if(check(mpS1,mpS2)) return true;

        }

        return false;

    }
};
