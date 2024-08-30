/*approach
  we simply write down the condition jumbo = 4ts + 1cs
  small = 2cs + 1cs from this equations we calculate that
  4j+2s = ts and 1j+1s = cs with this information we calculate
  jumbo and small returning empty {} for edge cases and remainig
  returning the calculated {jumbo,small}*/
class Solution{
public:
    vector<int> numOfBurgers(int tomatoSlices,int cheeseSlices){
        if(tomatoSlices%2 != 0 || tomatoSlices < 2*cheeseSlices || tomatoSlices>4*cheeseSlices){
            return {};
        }
        int jumbo = (tomatoSlices-2*cheeseSlices)/2;
        int small = cheeseSlices - jumbo;
        return {jumbo,small};
    }
};
