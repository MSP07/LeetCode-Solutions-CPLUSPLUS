/*approach
  we calculate left sum and right sum in the manner that we take all the ? as 9 others as double their val
  then we calculate left half sum and right half sum if their diff is 0 then both parts are equal so bob wins
  else alice wins*/
class Solution{
public:
    bool sumGame(string num){
        int n = num.size()/2;
        vector<int>nums;

        for(char ch:num){
            if(ch=='?'){
                nums.push_back(9);
            }else{
                nums.push_back(2*(ch-'0'));
            }
        }

        int sum_left = accumulate(nums.begin(),nums.begin()+n,0);
        int sum_right = accumulate(nums.begin()+n,nums.end(),0);

        return sum_left - sum_right != 0;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
