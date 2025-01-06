/*approach
  prefixsum
  this can be solved using two for loops with the condition when boxes[j] == '1'
  we add the abs(i-j) to temp var and answer[i] = var, to do this more efficiently 
  we can run the linear search two times from left to right and from right to left
  and we first assign answer[i] to operations add up the indices where the boxes[i] == '1' 
  from left to right once then  re allocate the temp variables to initial state and do the 
  same from right to left and finally return the answer array*/
class Solution{
public:
    vector<int> minOperations(string boxes){
        int op = 0, balls = 0;
        int n = boxes.size();
        vector<int>answer(n);
        for(int i=0;i<n;i++){
            answer[i] += op;
            balls += (boxes[i]=='1');
            op += balls;
        }
        op=0;balls=0;
        for(int i=n-1;i>=0;i--){
            answer[i] += op;
            balls += (boxes[i]=='1');
            op += balls;
        }
        return answer;
    }
};
