/*approach
  we keep a seen vector and a temp vector where we manipulate the cells vector and return it
  so as returning constant space. we iterate till n is there we keep temp[i] = 1 if prev and next element are equal
  and if the temp is already in seen then we have a repeating pattern so we return the seen[n%seen.size()] else we add the 
  current to seen vector and finally make cells to temp and return the cells finally if n happens to be small*/
class Solution{
public:
    vector<int> prisonAfterNDays(vector<int>& cells,int n){
        vector<int>temp(8);
        vector<vector<int>>seen;
        while(n--){
            for(int i=1;i<7;++i){
                temp[i] = seen[i-1] == seen[i+1];
            }
            if(seen.size() && seen.front()==temp)return seen[n%seen.size()];
            else seen.push_back(temp);
            cells = temp;
        }
        return cells;
    }
};
