/*approach
  simulation
  we start from last index and add them to answer using carry 
  finally we reverse the string and return the string*/
class Solution{
public:
    string addStrings(string num1,string num2){
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string res = "";
        while(i>=0 || j>=0 ||carry){
            int digit1 = i>=0 ? num1[i]-'0' : 0;
            int digit2 = j>=0 ? num2[j]-'0' : 0;
            int sum = digit1+digit2+carry;
            carry = sum/10;
            res += (sum%10)+'0';
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
