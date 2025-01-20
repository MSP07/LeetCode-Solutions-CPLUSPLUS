/*apporach
  bit manipulation
  to achieve the given goal we can simply perform
  XOR on all elements and return if the final ans is 0
  if so we have same or even bits so that will return true else false*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int xorr = 0;
        for(auto ele:derived){
            xorr ^= ele;
        }
        return xorr == 0;
    }
};
