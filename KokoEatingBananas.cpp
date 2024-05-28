class Solution{
private:
    bool caneat(vector<int>& piles,int h,int k){
        int hoursTaken = 0;
        for(int pile:piles){
            hoursTaken += ceil((double)pile/k);
        }
        return hoursTaken<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles,int h){
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(low<high){
            int mid = low + (high-low)/2;
            if(caneat(piles,h,mid))high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
