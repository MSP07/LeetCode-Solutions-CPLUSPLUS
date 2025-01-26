/*approach
  sorting
  first we sort the num with their indices not to lose track
  and then we group and store them in new array with the help of
  limit and then we sort with indices again to make sure lexographically
  they remain same and finaly with that we assign values and return ans array*/
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<pair<int, int>> indexedNums; 
        for (int i = 0; i < n; i++) {
            indexedNums.push_back({nums[i], i});
        }
        sort(indexedNums.begin(), indexedNums.end());
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            vector<int> indices, values;
            while (j < n && (j == i || indexedNums[j].first - indexedNums[j - 1].first <= limit)){
                indices.push_back(indexedNums[j].second);
                values.push_back(indexedNums[j].first);
                j++;
            }
            sort(indices.begin(), indices.end());
            for (int k = 0; k < indices.size(); k++) {
                result[indices[k]] = values[k];
            }
            i = j;
        }
        return result;
    }
};
