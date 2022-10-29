class Solution {
private:
    
    void solve(string digits, string output,int index,vector<string> &ans,string map[])
    {
        //definging the base case such that the when index goes out of bound just stop the recursive step
        if(index>=digits.size())
        {
            ans.push_back(output);
            return ;
        }
        
        //converting the string digit into integer digit
        
        int num = digits[index] - '0';
        
        //taking the string value of nums that are mapped to map[num] in order ot make the pnc
        string value = map[num];
        
        
        for(int i = 0;i<value.length();i++)
        {
            output.push_back(value[i]);
            
            solve(digits,output,index+1,ans,map);
            
            //bacltracking step
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
    
        
        vector <string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        string output;
        int index = 0;
        
        //storing the the keypad index from 0 to 9 in such a way that the array index are mappped to the values of digits in the array.
        
        string map[10] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits , output , index , ans, map);
        
        return ans;
    }
};
