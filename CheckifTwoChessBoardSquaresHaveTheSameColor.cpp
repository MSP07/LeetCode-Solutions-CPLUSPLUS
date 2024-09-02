/*approach
  each squares color depends on whether odd or even so we use that 
  we convert the given data to 1-8 on both strings and return the answer accordingly*/
class Solution{
public:
    bool checkTwoChessboards(string coordinate1,string coordinate2){
        auto columnToIndex = [](char column){
            return column - 'a' + 1;
        };
        int row1 = coordinate1[1] - '0'; 
        int col1 = columnToIndex(coordinate1[0]);
        int row2 = coordinate2[1] - '0';
        int col2 = columnToIndex(coordinate2[1]);

        int sum1 = col1 + row1;
        int sum2 = col2 + row2;

        return (sum1%2==0) == (sum2%2==0);
    }
};
