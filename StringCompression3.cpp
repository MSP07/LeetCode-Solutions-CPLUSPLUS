//approach
//we use 2 pointers approach
//intialise both pointers to the first element and iterate through it while checking the given conditions
//if it satisfies increase the pointer to next and count
//if not then add the current count to ans with word[i] and keep i=j
//finally return the string in which ans is stored
class Solution{
public:
    string compressedString(string word){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = word.length();
        string comp;
        comp.reserve(n);
        int i = 0;
        while(i<n){
            char curr = word[i];
            int count = 0;
            while(i<n && word[i]==curr && count<9){
                i++;
                count++;
            }
            comp += to_string(count) + word[i];
        }
        return comp;
    }
};
