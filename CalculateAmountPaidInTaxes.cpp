/*approach
  simualtion
  if the income of the particular member is greater than prevUpper limit then
  we need to add tax we do that by calculating the total amt and multiplying it by the percent
  if income <= prevUpper we break the loop if not we update the prevUpper and iterate and finally
  return the tax*/
class Solution{
public:
    double calculateTax(vector<vector<int>>& brackets,int income){
        double tax = 0.0;
        int prevUpper = 0;
        for(auto& bracket:brackets){
            int upper = bracket[0], percent = bracket[1];
            if(income>prevUpper){
                int amt = min(income,upper)-prevUpper;
                tax += amt*(percent/100.0);
            }
            if(income<=prevUpper){
                break;
            }
            prevUpper = upper;
        }
        return tax;
    }
};
