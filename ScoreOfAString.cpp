//approach
//we use the two pointers approach where initially left pointer will be at the first element and right pointer at second element
//we will iterate till the left not reaching the last element and add abs(s[left]-s[right]) to a variabe
//when loop terminates we return that variable
class Solution{
public:
    int scoreOfString(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        int left = 0 , right = 1;
        while(left!=s.length()-1){
            ans += (abs(s[left]-s[right]));
            left++;
            right++;
        }
        return ans;
    }
};
