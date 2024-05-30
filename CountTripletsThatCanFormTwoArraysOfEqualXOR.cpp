//approach
//we form prefixXOR array with n+1 size, prefixXor[i+1] = prefixXor[i]^arr[i]
//then we run loop for j and k to find prefixXor[j] == prefixXor[k] and update count += k-j-1 and we return cnt
class Solution{
public:
    int countTriplets(vector<int>& arr){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = arr.size();
        int cnt = 0;
        vector<int>prefixXor(n+1,0);
        for(int i=0;i<n;i++){
            prefixXor[i+1]=prefixXor[i]^arr[i];
        }
        for(int j=0;j<n;j++){
            for(int k=j+1;k<=n;k++){
                if(prefixXor[j]==prefixXor[k])cnt += k-j-1;
            }
        }
        return cnt;
    }
};
