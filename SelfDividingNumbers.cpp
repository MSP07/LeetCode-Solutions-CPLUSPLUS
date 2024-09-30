/*approach
  simulation
  we check whether the numbers in btn left and right (inclusive) satisfies
  given condition by checking for each number with division and modulo operator
  and add them to our answer and return them*/
class Solution{
private:
    bool isSelfDividing(int num){
        int num1 = num;
        while(num>0){
            int temp = num%10;
            if(temp==0)return false;
            if(num1%temp)return false;
            num /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left,int right){
        vector<int>ans;
        for(int i=left;i<right;++i){
            if(isSelfDividing(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
