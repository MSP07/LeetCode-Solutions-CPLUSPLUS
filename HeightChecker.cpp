/*approach
  make another array with same elements
  sort it and check for given condition with increasing the var*/
class Solution{
    int heightChecker(vector<int>& heights){
        vector<int>expected = heights;
        sort(expected.begin(),expected.end());
        int cnt = 0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i])cnt++;
        }
        return cnt;
    }
};
