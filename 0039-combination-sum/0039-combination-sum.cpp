class Solution {
public:
    set<vector<int>>s;
    void combinesum(vector<int>&arr,vector<int>&combine,vector<vector<int>>&ans,int i,int target)
    {

       if(i==arr.size() || target<0)
       {
          return;
       }
       if(target==0)
       { 
          if(s.find(combine)==s.end())
          {
              ans.push_back({combine});
              s.insert(combine);
          }
         
          return;
       }
       combine.push_back(arr[i]);
       combinesum(arr,combine,ans,i+1,target-arr[i]);
       combinesum(arr,combine,ans,i,target-arr[i]);
       combine.pop_back();
       combinesum(arr,combine,ans,i+1,target);
    }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combine;
        combinesum(candidates,combine,ans,0,target);
        return ans;
    }
};