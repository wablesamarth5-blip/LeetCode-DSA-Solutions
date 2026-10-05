class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for(int asteroid:asteroids)
        {
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && asteroid<0)
            {

                if(st.top()<-asteroid)
                {
                    st.pop();  //top has been destroyed
                    continue;
                }

                else if(st.top()==-asteroid)
                {
                    st.pop();  //both has been destroyed
                }
              
              destroyed=true;
              break;
                
            }
           
           if(!destroyed)
           {
              st.push(asteroid);
           }

        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};