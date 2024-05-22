class Solution{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
        int size = grid[0].size();
        int n = size*size;
        vector<int>freq(n+1,0);
        vector<int>ans;
        for(auto it:grid){
            for(int i=0;i<it.size();i++){
                if(freq[it[i]]==0)freq[it[i]]++;
                else ans.push_back(it[i]);
            }
        }
        for(int i=0;i<=n;i++){
            if(freq[i]==0 && i!=0) ans.push_back(i);
        }
        return ans;
    }
};
