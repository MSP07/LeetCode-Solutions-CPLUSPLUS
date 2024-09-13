/*approach
  we take it as individual nums by converting it to string
  and we keep track of when each digit occurs last then we start from 9 to 0
  if the any of the higher digits comes in the back then we swap them and return them
  else if that is not possible we return the original number itself*/
class Solution{
public:
    int maximumSwap(int num){
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int>last(10,-1);
        for(int i=0;i<n;++i){
            last[numStr[i]-'0'] = i;
        }
        for(int i=0;i<n;++i){
            for(int d=9;d>numStr[i]-'0';d--){
                if(last[d]>i){
                    swap(numStr[i],numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};
