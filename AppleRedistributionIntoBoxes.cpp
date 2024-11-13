/*approach
  greedy, sorting
  since we need min no of boxes to hold apples we sort the capacity array in reverse order
  and we take total apples given and start putting them in the biggest capacity box and reducing the 
  total count if the total/sum becomes less than or equal to 0 then we need no more boxes so we break
  we we continue to reduce the sum by the capacity and increase the boxes and finally return the boxes*/
class Solution{
public:
    int minimumBoxes(vector<int>& apple,vector<int>& capacity){
        sort(capacity.rbegin(),capacity.rend());
        int boxes = 0;
        int sum = accumulate(apple.begin(),apple.end(),0);
        for(int i=0;i<capacity.size();++i){
            if(sum<=0)break;
            sum -= capacity[i];
            ++boxes;
        }
        return boxes;
    }
};
