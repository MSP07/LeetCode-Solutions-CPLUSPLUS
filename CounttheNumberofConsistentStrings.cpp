/*approach
  we first use a hashmap to store the chars that appear in allowed
  then we iterate through every string in words assuming that they have all the allowed chars
  so we keep flag = 1 if we come across a char that is not seen we make the flag as 0 and break that loop
  we  then add the assumed/calculated val to count and finally return the count*/
class Solution{
public:
    int countConsistentStrings(string allowed, vector<string>& words){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int arr[26] = {0};
        for(char c:allowed){
            arr[c-'a'] = 1;
        }
        int count = 0;
        for(string word:words){
            int flag = 1;
            for(char c:word){
                if(arr[c-'a']==0){
                    flag = 0;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};
