class Solution {
public:
     vector<string> ans;
      string mapping[10]={
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

       void solve(string &digits,int idx,string current)
       {
           if(idx==digits.size())
           {
              ans.push_back(current);
              return;
           }

           int digit=digits[idx]-'0';

           for(char ch:mapping[digit])
           {
              //choose
              current.push_back(ch);
              //explore 
              solve(digits,idx+1,current);
              //undo
              current.pop_back();
           }
       }
      
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
        {
            return {};
        }
        solve(digits,0,"");
        return ans;
    }
};