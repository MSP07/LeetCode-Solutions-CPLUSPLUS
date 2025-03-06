/*approach
  hashmap, simulation
  iterate through each vector in grid and keep the count of the num in a hashmap of size n*n + 1
  again iterate through the hashmap and if count is 0 it is missing and if count is 2 it is repeating
  we finally return that {repeating,missing}*/
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeating = 0, missing = 0;
        vector<int>freq(n*n+1,0);
        for(auto gr:grid){
            for(int num:gr){
                freq[num] += 1;
            }
        }
        for(int i=1;i<freq.size();i++){
            if(missing && repeating)break;
            if(freq[i]==0){
                missing = i;
            }else if(freq[i]==2){
                repeating = i;
            }
        }
        return {repeating,missing};
    }
};
