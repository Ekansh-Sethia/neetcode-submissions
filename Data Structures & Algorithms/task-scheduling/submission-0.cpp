class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char ch : tasks){
            mp[ch]++;
        }
        int ans = 0;
        int x = mp.size();
        while(x > 0){
            int cnt = 0;
            for(auto it = mp.begin(); it != mp.end(); ) {
                it->second--;
                if(it->second == 0){
                    x--;
                    it = mp.erase(it);
                    }
                else
                    it++;
                cnt++;
            }
            ans += cnt;
            if (!mp.empty()) {
                ans += max(0, n - cnt + 1);
            }
        }
        return ans;

    }
};
