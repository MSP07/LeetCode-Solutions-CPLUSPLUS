/*approach
  simulation, two pointers
  itearte through each row reverse it and reverse the 1's and 0's to
  0's and 1's respectively and return the matrix*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& row:image){
            for(int& num:row){
                num = (num == 1) ? 0 : 1;
            }
            reverse(row.begin(),row.end());
        }
        return image;
    }
};
