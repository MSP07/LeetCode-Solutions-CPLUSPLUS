//approach
//we will only iterate between the min and max of given array
//for each of the element we will iterate through whole given array checking whether the nums[i] <= element then the flower is ready
//simultaneously we increase a cnt variable and check whether the cnt == k we increase a bouquet
//if we encounter a nums[i] > day then we make cnt to 0
//we finally return the low pointer as the low and high pointer always ends up in the opposite polarities.
class Solution{
private:
    bool isPossible(vector<int>& bloomDay,int m,int k,int day){
        int cnt = 0, NoOfBouq = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
                if(cnt==k){
                    NoOfBouq++;
                    cnt = 0;
                }
            }else cnt = 0;
        }
        return NoOfBouq>=m;
    }
public:
    int minDays(vector<int>&bloomDay,int m,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long edge = (long long)m*k;
        if(edge > bloomDay.size())return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(bloomDay,m,k,mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
