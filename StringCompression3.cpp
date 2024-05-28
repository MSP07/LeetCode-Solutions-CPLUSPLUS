//approach
//we use 2 pointers approach
//intialise both pointers to the first element and iterate through it while checking the given conditions
//if it satisfies increase the pointer to next and count
//if not then add the current count to ans with word[i] and keep i=j
//finally return the string in which ans is stored
class Solution{
public:
    string compressedString(string word){
        int n = word.length(), i = 0, j = 0,count = 0;
        string comp = "";
        while(j<n){
            count = 0;
            while(j<n && word[i]==word[j] && count<9){
                j++;
                count++;
            }
            comp += to_string(count) + word[i];
            i=j;
        }
        return comp;
    }
};
