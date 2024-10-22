/*approach
  backtrack,hashmap
  goal is to maximise the unique substring count such that all the unique substrings form the 
  original substring. we first start by taking substrings by iterating through the given string
  and then we add that to our hashmap if it is not already present then we update the maxi by 
  1 + fn(ind,s,hashi) as we have found a substring that could be possibly answer and we proceed with
  that as our 1 of the substrings and calculate then to explore diff possibilities we explore diff
  substrings by removing that same substring from the hashmap and updating the maxi*/
class Solution{
private:
    int backtrack(int i,string& s,unordered_set<string>& hashi){
        if(i==s.size())return 0;
        int maxSplits = 0;
        for(int ind=i+1;ind<=s.size();ind++){
            string temp = s.substr(i,ind-i);
            if(!hashi.count(temp)){
                hashi.insert(temp);
                maxSplits = max(maxSplits,1+backtrack(ind,s,hashi));
                hashi.erase(temp);
            }
        }
        return maxSplits;
    }
public:
    int maxUniqueSplit(string s){
        unordered_set<string>hashi;
        return backtrack(0,s,hashi);
    }
};
