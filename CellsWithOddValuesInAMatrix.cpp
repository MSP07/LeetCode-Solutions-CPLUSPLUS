/*approach
  simulation
  we simply follow the given rules and keep row and col seperately
  we increase the row[given index], col[given index] and from these row and col
  we calculate the no of odds and return it*/
class Solution{
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0); 
        vector<int> col(n, 0); 
        for (const auto& index : indices) {
            row[index[0]]++;
            col[index[1]]++;
        }
        int oddRows = 0, oddCols = 0;
        for (int r : row) {
            if (r % 2 != 0) oddRows++;
        }
        for (int c : col) {
            if (c % 2 != 0) oddCols++;
        }
        return oddRows * (n - oddCols) + oddCols * (m - oddRows);
    }
};
