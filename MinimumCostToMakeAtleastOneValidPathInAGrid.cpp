class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> deltas = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        const int R = grid.size();
        const int C = grid[0].size();

        vector<int> cost_grid(R*C, 999999);
        deque<int> q;
        q.push_back(0);
        cost_grid[0] = 0;

        while (!q.empty()) {
            int i = q.front() >> 8;
            int j = q.front() & 0xff;
            q.pop_front();

            if (i == R - 1 && j == C - 1) return cost_grid[i*C+j];
            const int cost = cost_grid[i*C+j];
            const int dir = grid[i][j] - 1;
            for (int l = 0; l < deltas.size(); ++l) {
                const int new_cost = cost + 1 - (l == dir);
                const int ii = i + deltas[l].first;
                const int jj = j + deltas[l].second;
                const int c_i = ii*C + jj;
                if (ii < 0 || ii >= R || jj < 0 || jj >= C || cost_grid[c_i] <= new_cost) {
                    continue;
                }
                cost_grid[c_i] = new_cost;
                if (l == dir) {
                    q.push_front(ii << 8 | jj);
                } else {
                    q.push_back(ii << 8 | jj);
                }
            }
        }
        return -1;
    }
};
