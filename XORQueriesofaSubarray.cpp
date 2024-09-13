/*approach
  we make use of the prefixXor 
  we first calculate the prefixXor of the given array
  then from the given queries we start from left to right and perform
  prefixXor[right+1]^prefixXor[left] this will give us the xor value of the entire subarray
  we push that into the answer and finally return it*/
class Solution{
public:
    vector<int> xorQueries(vector<int>& arr,vector<vector<int>>& queries){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = arr.size();
        vector<int>prefixXor(n+1,0);
        for(int i=0;i<n;++i){
            prefixXor[i+1] = prefixXor[i]^arr[i];
        }
        vector<int>ans;
        for(auto& query:queries){
            int left = query[0];
            int right = query[1];
            ans.push_back(prefixXor[right+1]^prefixXor[left]);
        }
        return ans;
    }
};
