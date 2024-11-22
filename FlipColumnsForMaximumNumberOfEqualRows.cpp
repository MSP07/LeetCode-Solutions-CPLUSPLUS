/*approach
  hashmap
  we iterate through the given matrix and we keep the first element in each row as  
  the base and we flip the remaining element w.r.t this cell and we build up a string
  from the flipped cells and we store this strings in a hashmap and keep track of the 
  max one and finally return it*/
class Solution{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix){
        int rows = 0;
        unordered_map<string,int>hashi;
        for(const auto& row:matrix){
            string temp;
            int base = row[0];
            for(auto cell:row){
                temp += (cell==base ? '0' : '1');
            }
            hashi[temp]++;
            rows = max(rows,hashi[temp]);
        }
        return rows;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
