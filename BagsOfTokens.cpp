//approach
//we first sort the given array
//we check whether the first element is smaller than power
//then we increase the tokencnt and keep track of max count of tokens
//if we find a element that is greater than power and we have tokens we exchange one token and increase power by the greatest element present(last element) to maximise tokencnt
//when no more element is present we break and return the tokenCnt
class Solution{
public:
    int bagOfTokenScores(vector<int>& tokens,int power){
        sort(tokens.begin(),tokens.end());
        int left = 0, right = tokens.size()-1;
        int maxTokens = 0, tokenCnt = 0;
        while(left<=right){
            if(power>=tokens[left]){
                power -= tokens[left++];
                maxTokens = max(maxTokens,++tokenCnt);
            }else if(tokenCnt>0){
                power += tokens[right--];
                tokenCnt--;
            }else{
                break;
            }
        }
        return maxTokens;
    }
};
