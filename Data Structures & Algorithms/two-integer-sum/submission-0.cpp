class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(!mp.count(nums[i])){
                mp[nums[i]] = i;
            }
        }
        for(auto i : mp){
            int x = i.first;
            if(mp.count(target-x) && mp[target-x] != mp[x]){
                int a = i.second;
                int b = mp[target-x];

                if(a < b) return {a,b};
                else return {b,a};
            }
        }
        return {};
    }
};
