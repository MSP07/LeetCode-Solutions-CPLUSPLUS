/*approach
  string
  keep a temp string inside and if it is divisble by 3 add Fizz first then divisible by 5
  then add Buzz if it is divisible by both 3 and 5 then this method will take care of itself
  so need for another check and if temp is same then we append the i in form of string and finally
  return the answer vector*/
class Solution{
public:
    vector<string> fizzBuzz(int n){
        vector<string>answer;
        for(int i=1;i<=n;++i){
            string temp = "";
            if(i%3==0)temp+="Fizz";
            if(i%5==0)temp+="Buzz";
            if(temp=="")temp+=to_string(i);
            answer.push_back(temp);
        }
        return answer;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
