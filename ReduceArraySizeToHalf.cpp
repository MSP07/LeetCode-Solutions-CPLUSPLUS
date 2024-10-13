/*approach
  sorting,greedy,hashmap
  first we take count of all the elements frequency then we sort the frequency in decreasing order
  since our aim is to find min no removal we do this so the highest frequencies will be removed first
  then we keep count of how much elements are required to achieve a size of n/2 or lower when their frequencies
  are removed and we return it*/
class Solution{
public:
    int minSetSize(vector<int>& arr){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = arr.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;++i){
            freq[arr[i]]++;
        }
        vector<pair<int,int>>freq1(freq.begin(),freq.end());
        sort(freq1.begin(),freq1.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.second > b.second;
        });
        int count = 0;
        int sum = 0;
        for(int i=0;i<freq1.size();++i){
            ++count;
            sum += freq1[i].second;
            if(sum>=n/2)return count;
        }
        return -1;
    }
};
