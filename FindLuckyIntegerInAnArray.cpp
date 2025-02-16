/*approach
  hashmap,counting
  we keep a hashmap to keep track of the no of times 
  a number has occured in the array and we iterate in that
  hashmap and if num == count then we keep track of the max one*/
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>hashi;
        for(int num:arr){
            hashi[num]++;
        }
        int maxi = -1;
        for(auto [num,cnt] : hashi){
            if(num==cnt){
                maxi = max(maxi,num);
            }
        }
        return maxi;
    }
};
