/*approach
  string, simulation, math
  we use the formula to multiply complex numbers (a+bi)*(c+di) = (ac-bd)real part + (ad+bc)img part
  so we calculate the real part and convert it to int and similarly for imaginary part perform the op
  and return the real + img part as string*/
class Solution{
private:
    vector<int>find(string& s){
        int n = s.size(),i=0;
        for(int j=0;j<n;j++){
            if(s[j]=='+'){
                i=j;
                break;
            }
        }
        return {stoi(s.substr(0,i)),stoi(s.substr(i+1,n-i-2))};
    }
public:
    string complexNumberMultiply(string num1,string num2){
        vector<int>a = find(num1);
        vector<int>b = find(num2);
        int real = a[0]*b[0]-a[1]*b[1];
        int img = a[0]*b[1]+a[1]*b[0];
        return to_string(real)+"+"+to_string(img)+"i";
    }
};
