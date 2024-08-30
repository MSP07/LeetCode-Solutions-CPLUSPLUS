/*approach
  dp/combinatorics approach
  we start from first vowel and iterate till ore string reaches n then we return
  we backtrack by popping last char to try diff combinations and each time it reaches n
  we increase vowelCount and finally return the vowelCount
  in dp we write a recursion function with the logic if n is 0 we only have one vowel that is a
  and we take count as try chars from current ind and reducing n and memoizing this approach*/
class Solution{
private:
    //iterative combinatorics approach
    void countVowels(int ind,int n,vector<char>& vowels,string& ans,int& vowelCount){
        if(ans.size()==n){
            ++vowelCount;
            return;
        }
        for(int i=ind;i<vowels.size();++i){
            ans.push_back(vowels[i]);
            countVowels(i,n,vowels,ans,vowelCount);
            ans.pop_back();
        }
    }
    //dp approach
    int countVowels1(int i,int n,vector<vector<int>>& dp){
        if(n==0)return 1;
        if(dp[i][n] != -1)return dp[i][n];
        int vowelCount = 0;
        for(int ind=i;ind<5;++ind){
            vowelCount += countVowels1(ind,n-1,dp);
        }
        return dp[i][n] = vowelCount;
    }
public:
    int countVowelStrings(int n){
        //iterative combinatorics approach
        vector<char>vowels = {'a','e','i','o','u'};
        string ans = "";
        int vowelCount = 0;
        countVowels(0,n,vowels,ans,vowelCount);
        return vowelCount;
        //dp approach
        vector<vector<int>>dp(5,vector<int>(n+1,-1));
        return countVowels1(0,n,dp);
    }
};
