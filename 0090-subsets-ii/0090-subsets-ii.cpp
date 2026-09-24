class Solution {
public:

  void Solve(vector<int>&nums,vector<vector<int>> &ans,vector<int>current,int idx)
  {

     if (find(ans.begin(), ans.end(), current) != ans.end()) 
        {
          // current already exists
          return;
        }
    ans.push_back(current);
    for(int i=idx;i<nums.size();i++)
    {
        current.push_back(nums[i]);
        Solve(nums,ans,current,i+1);
        current.pop_back();
    }
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        Solve(nums,ans,current,0);

        return ans;
    }
};