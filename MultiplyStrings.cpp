/*approach
  we do normal multiplication method
  we take 2 pointers and iterate from last while multiplying the last two numbers
  and add the sum if there is any carry left over and add required details to our lookup vector
  then we iterate through the lookup vector and we push back our answer without any leading zeroes
  and without the answer array being empty and finally return the answer string*/
class Solution{
public:
    string multiply(string num1,string num2){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n1 = num1.size(), n2 = num2.size();
        vector<int>result(n1+n2,0);

        for(int i = n1-1;i>=0;--i){
            for(int j = n2-1;j>=0;--j){
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum = mul + result[i+j+1];
                result[i+j] += sum/10;
                result[i+j+1] = sum%10;
            }
        }

        string product;
        for(int num:result){
            if(!(product.empty() && num==0)){
                product.push_back(num+'0');
            }
        }
        return product.empty() ? "0" : product;
    }
};
