/*approach
  hashing and sorting
  we first sort the array in another vector then add the rank w.r.t smallest to largest element
  we use hashmap to prevent same elements getting diff ranks and finally we create and return 
  another vector with the help of this hashmap*/
class Solution{
public:
    vector<int> arrayRankTransform(vector<int>& arr){
        if(arr.empty())return {};
        vector<int>nums = arr;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>rankSet;
        int rank = 1;
        for(int i=0;i<nums.size();++i){
            if(rankSet.find(nums[i])==rankSet.end()){
                rankSet[nums[i]] = rank++;
            }
        }  
        vector<int>ans;
        for(int num:arr){
            ans.push_back(rankSet[num]);
        }
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
