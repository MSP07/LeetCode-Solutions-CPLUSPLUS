/*approach
  string,sorting
  we check whether the curr and prev strings are anagrams
  by sorting them and checking whether they are equal if so
  we remove the curr element from the array and finally return the array*/
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1;i<words.size();i++){
            string curr = words[i];
            sort(curr.begin(),curr.end());
            string prev = words[i-1];
            sort(prev.begin(),prev.end());
            if(curr==prev){
                words.erase(words.begin()+i);
                i--;
            }
        }
        return words;
    }
};
