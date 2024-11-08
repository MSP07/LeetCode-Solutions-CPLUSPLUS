/*approach
  string, greedy, hashmap
  aim is to find how many deletions we have to do
  so i use a hashmap to keep track of it 
  first start from second element and compare prev elements char with this one
  if both char are equal or we have already computed that the char in before element as to
  be deleted(it is in the hashmap) we continue else we check whether prev one is greater than the 
  curr one if so not in lexographical order so we delete the char of prev one and so i insert it into hashmap
  and check curr string from start again(i=0) finally return the chars to be deleted in other words 
  size of the hashmap*/
class Solution{
public:
    int minDeletionSize(vector<string>& strs){
        unordered_set<int>hashi;
        for(int i=1;i<strs.size();++i){
            for(int j=0;j<strs[i].size();++j){
                if(hashi.count(j)>0 || strs[i-1][j]==strs[i][j])continue;
                if(strs[i-1][j]>strs[i][j]){
                    hashi.insert(j);
                    i=0;
                }
                break;
            }
        }
        return hashi.size();
    }
};
