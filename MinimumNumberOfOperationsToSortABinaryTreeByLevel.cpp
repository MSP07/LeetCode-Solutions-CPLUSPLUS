/*approach
  bfs, sorting
  Sorting an array by swapping involves detecting cycles of misplaced elements and performing the minimum swaps required to fix them.
  This is done in each level and the highest position is found out and replaced. BFS is used to process the tree level by level, ensuring
  we can extract and process node values level-wise*/
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if (!root) return 0;
        auto minSwapsToSort = [](vector<int>& nums) {
            int n = nums.size();
            vector<pair<int, int>> arr(n);
            for(int i = 0; i < n; ++i){
                arr[i] = {nums[i], i};
            }
            sort(arr.begin(), arr.end());
            vector<bool> visited(n, false);
            int swaps = 0;
            for(int i = 0;i<n;++i){
                if (visited[i] || arr[i].second == i) continue;
                int cycleSize = 0;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = arr[j].second;
                    ++cycleSize;
                }
                if (cycleSize > 1) swaps += (cycleSize - 1);
            }
            return swaps;
        };
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            totalSwaps += minSwapsToSort(levelValues);
        }
        return totalSwaps;
    }
};
