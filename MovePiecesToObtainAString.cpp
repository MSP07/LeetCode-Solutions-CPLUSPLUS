/*approach
  two pointers, string
  if there are '_' we skip them and incr the pointers 
  if we reach the end then both are same so we return true
  else we check for conditions such as whether char can be shifted to left
  or right if 'L' and 'R' are there respectively and if both chars are same or not
  which will prevent the string from forming target and we return false after checking
  all these conditions if none of them raise red flags we return true*/
class Solution{
public:
    bool canChange(string start,string target){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = start.size();
        int i=0,j=0;
        while(i<n || j<n){
            while(i<n && start[i]=='_')i++;
            while(j<n && target[j]=='_')j++;
            if(i==n && j==n)return true;
            if(i==n || j==n)return false;
            if(start[i]!=target[j])return false;
            if(start[i]=='L' && i<j)return false;
            if(start[i]=='R' && i>j)return false;
            i++;
            j++;
        }
        return true;
    }
};
