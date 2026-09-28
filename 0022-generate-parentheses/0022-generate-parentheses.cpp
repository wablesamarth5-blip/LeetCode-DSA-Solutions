class Solution {
public:

    vector<string> ans;

    void solve(int n,int open,int close,string current)
    {
        if(current.size()==2*n)
        {
            ans.push_back(current);
            return;
        }
        if(open<n)
        {
            solve(n,open+1,close,current+"(");
        }

        if(close<open)
        {
            solve(n,open,close+1,current+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        
       solve(n,0,0,"");
       return ans;
    
    }
};