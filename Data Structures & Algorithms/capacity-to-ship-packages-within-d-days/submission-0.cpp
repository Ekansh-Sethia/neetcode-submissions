class Solution {
private:
    bool possible(vector<int>& weights, int days, int capacity){
        int day = 1;
        int weight = 0;
        //cout<<capacity<<" : ";
        for(int i : weights){
            if(weight + i <= capacity){
                weight = weight + i;
                //cout<<weight<<" ";
            }
            else{
                weight = i;
                day++;
                //cout<<weight<<" ";
                if(day > days) return false;
            }
        }
        //cout<<endl;
        return day <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int end = 0;
        int maxi = -1;
        for(int i : weights){
            end += i;
            maxi = max(maxi,i);
        }
        int start = maxi;

        int ans = end;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(possible(weights,days,mid)) {
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};