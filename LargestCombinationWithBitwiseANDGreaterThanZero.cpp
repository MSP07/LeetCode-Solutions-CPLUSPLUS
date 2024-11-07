/*approach
  bit manipulation
  since 24 bits is the limit(10^7) for every bit we try out and operation
  from the candidates and whichever can form bitwise AND we take the count
  then keep track of the max one and finally return it*/
class Solution{
public:
    int largestCombination(vector<int>& candidates){
        int maxCombo = 0;
        for(int i=0;i<24;++i){
            int count = 0;
            for(int num:candidates){
                if(num&(1<<i)){
                    ++count;
                }
            }
            maxCombo = max(maxCombo,count);
        }
        return maxCombo;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}(); 
