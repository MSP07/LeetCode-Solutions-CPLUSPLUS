/*approach
  since log n time complexity is needed we use the binary search approach
  similar to h index we find a point left at 0 right at n-1  calculating mid
  if n-mid <= citations[mid] there can be a shrinkage possible so right = mid-1
  else left = mid+1 finally we return n-left as due to opp polarity concept left and
  right interchange and our answer will be related to left*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = citations.size();
        int left = 0, right = citations.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(n-mid <= citations[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return n-left;
    }
};
