//approach
//we use a map to store all the occuring frequencies and their respective numbers
//then we iterate through the map 
//if we find the count to be >0 we iterate with it till k checking whether the next elements are greater than the current element
//if any instance becomes less than the prev count with k range then we return false
class Solution{
public:
    bool isPossibleDivide(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        for(auto it=freq.begin();it!=freq.end();it++){
            int num = it->first;
            int count = it->second;
            if(count>0){
                for(int i=0;i<k;i++){
                    if(freq[num+i]<count)return false;
                }
            }
        }
        return true;
    }
};
