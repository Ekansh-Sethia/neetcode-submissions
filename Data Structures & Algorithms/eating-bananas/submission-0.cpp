class Solution {
private:
    bool possibleWithinH(vector<int>& piles, int k, int h){
        int tot = 0;
        for(int i : piles){
            while(i > 0){
                i -= k;
                tot++;
            }
        }
        return tot <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;
        for(int i : piles) maxi = max(maxi,i);
        int st = 1;
        int end = maxi;
        int ans = maxi;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(possibleWithinH(piles,mid,h)){
                ans = mid;
                end = mid - 1;
            }
            else st = mid+1;
        }

        return ans;
    }
};
