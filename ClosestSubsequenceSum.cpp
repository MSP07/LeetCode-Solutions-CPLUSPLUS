/*approach
  binary search
  we divide the given array into two parts in the middle
  then we calculate the values in both the parts
  from the leftPart we calculate the nearest value that can make the val in leftPart the minDiff to goal
  we use lower_bound to implement this then we calculate the val in rightPart that can make the val in leftPart
  the minDiff w.r.t goal and finally return it*/
class Solution{
private:
    auto genSubsets(vector<int>& arr){
        vector<int>subSets={0};
        for(int num:arr){
            int size = subSets.size();
            for(int i=0;i<size;++i){
                subSets.push_back(subSets[i]+num);
            }
        }
        return subSets;
    }
public: 
    int minAbsDifference(vector<int>& nums,int goal){
        int n = nums.size();

        vector<int>left(nums.begin(),nums.begin()+n/2);
        vector<int>right(nums.begin()+n/2,nums.end());

        vector<int>leftPart = genSubsets(left);
        vector<int>rightPart = genSubsets(right);

        sort(rightPart.begin(),rightPart.end());

        int minDiff = abs(goal);

        for(int num:leftPart){
            int remaining = goal - num;

            auto it = lower_bound(rightPart.begin(),rightPart.end(),remaining);

            if(it != rightPart.end()){
                minDiff = min(minDiff,abs(remaining - *it));
            }

            if(it != rightPart.begin()){
                minDiff = min(minDiff,abs(remaining-*prev(it)));
            }
        }
        return minDiff;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
