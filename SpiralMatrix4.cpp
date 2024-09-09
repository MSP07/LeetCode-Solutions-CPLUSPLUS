/*approach
  we do the normal spiral matrix method traverse and add vals to answer
  and finally return the answer*/
class Solution{
public:
    vector<vector<int>> spiralMatrix(int m,int n,ListNode* curr){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        int top = 0, bottom = n-1, left = 0, right = m-1;
        while(curr){
            for(int i=left;i<=right&&curr;++i){
                matrix[i][top] = curr->val;
                curr = curr->next;
            }
            top++;
            for(int i=top;i<=bottom&&curr;++i){
                matrix[right][i] = curr->val;
                curr = curr->next;
            }
            right--;
            for(int i=right;i>=left&&curr;i--){
                matrix[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;
            for(int i=bottom;i>=top&&curr;i--){
                matrix[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        return matrix;
    }
};
