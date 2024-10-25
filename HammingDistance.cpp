class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        string temp1 = bitset<32>(x).to_string(), temp2 = bitset<32>(y).to_string();
        for(int i=0;i<temp1.size();++i){
            if(temp1[i]!=temp2[i])cnt++;
        }
        return cnt;
    }
};
