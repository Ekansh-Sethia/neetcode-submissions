class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int dist = 0;
        while(i < n){
            if(i > dist) return false;

            dist = max(dist,i+nums[i]);
            i++;
        }
        return true;
    }
};
