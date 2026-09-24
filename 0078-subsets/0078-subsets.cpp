class Solution {
public:

     void Solve(vector<int>&nums,int index,vector<int>current,vector<vector<int>> &ans)
    {
        //every current subset is a valid answer
        ans.push_back(current);
        for(int i=index;i<nums.size();i++)
        {
            //choose
            current.push_back(nums[i]);
            //explore
            Solve(nums,i+1,current,ans);
            //backtrack
            current.pop_back();
        }

       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int> current;
        Solve(nums,0,current,ans);
        return ans;

    }
};