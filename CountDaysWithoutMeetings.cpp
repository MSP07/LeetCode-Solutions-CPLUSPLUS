bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) { 
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = m.size();
        sort(m.begin(), m.end(), cmp); 
        int count = 0;
        count += abs(m[0][0] - 1);
        for(int i = 1; i < n; i++){
            if(m[i][0] <= m[i-1][1]){ 
                if(m[i][1] < m[i-1][1]) m[i][1] = m[i - 1][1]; 
            }else{ 
                int dy = m[i][0] - m[i-1][1];
                count += dy - 1; 
            }
        }
        count += abs(m[n-1][1] - days);
        return count;
    }
};
