class Solution {
public:

    bool solve(vector<vector<char>>& board, string word,int row,int col,int idx)
    {
        if(idx==word.size())
        {
            return true;
        }

        if(row<0|| row>=board.size() || col<0 || col>=board[0].size())
        {
            return false;
        }
        
        if(board[row][col] != word[idx])
        {
          
          return false;

        }

        char temp=board[row][col];

        board[row][col]='#';

        bool found=(solve(board,word,row+1,col,idx+1)
        || solve(board,word,row-1,col,idx+1)||
        solve(board,word,row,col+1,idx+1) ||
        solve(board,word,row,col-1,idx+1));

       board[row][col]=temp;

       return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                     if(solve(board,word,i,j,0))
                  {
                      return true;
                  }
                }
               
            }
        }
      return false;
    }
};