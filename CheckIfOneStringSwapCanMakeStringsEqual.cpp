/*apprpach
  hashmap, counting
  since we can make atmost one swap then the two stirngs should have
  only two diff chars more than that we return false and so we store the
  indices of diff chars in the string and after swapping we return whether 
  they are equal or not*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        vector<int>indices;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                indices.push_back(i);
            }
        }
        if(indices.size()!=2)return false;
        swap(s1[indices[0]],s1[indices[1]]);
        return s1 == s2;
    }
};
