/*approach
  if both arrays have same element then reversal and
  making it equal is possible so we sort the two arrays
  and check for diff elements if there exist diff elements then
  we return false as making it equal is not possible. else we
  return true*/
class Solution{
public:
    bool canBeEqual(vector<int>& target,vector<int>& arr){
        if(target.size() != arr.size())return false;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        for(int i=0;i<target.size();++i){
            if(arr[i]!=target[i]){
                return false;
            }
        }
        return true;
    }
};
