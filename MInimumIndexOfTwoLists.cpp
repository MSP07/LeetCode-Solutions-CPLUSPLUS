/*approach
  hashmap
  first iterate through list1 and take note of its strings and indices
  then iterate in list2 and if the strings of list2 are present in list1
  take sum of their indices and if that is min then result will be only that string
  else if it equal to prev min then we append it to our result and finally return the result*/
class Solution{
public:
    vector<string> findRestaurant(vector<string>& list1,vector<string>& list2){
        unordered_map<string,int>list1Index;
        vector<string>result;
        int minSum = INT_MAX;
        for(int i=0;i<list1.size();++i){
            list1Index[list1[i]] = i;
        }
        for(int j=0;j<list2.size();++j){
            if(list1Index.find(list2[j])!=list1Index.end()){
                int sum = j + list1Index[list2[j]];
                if(sum < minSum){
                    minSum = sum;
                    result = {list2[j]};
                }else if(minSum==sum){
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};
