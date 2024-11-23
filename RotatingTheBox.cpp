/*approach
  two pointers, matrix
  we iterate and on each row we start the last element and we keep that as the empty one
  now we iterate backwards in the row and if we come across an obstacle we mark that as our new empty
  else if we come across a stone then we make that element as '.' and the nearest empty(that we have marked)
  will be changed to stone. After the whole rearranging of stones we create a new matrix that is 90 degrees
  to this matrix and return it*/
class Solution{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box){
        int n = box.size();
        int m = box[0].size();
        for(int i=0;i<n;i++){
            int empty = m-1;
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='*'){
                    empty = j-1;
                }else if(box[i][j]=='#'){
                    box[i][j] = '.';
                    box[i][empty--] = '#';
                }
            }
        }
        vector<vector<char>>matrix(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[j][n-i-1] = box[i][j];
            }
        }
        return matrix;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
