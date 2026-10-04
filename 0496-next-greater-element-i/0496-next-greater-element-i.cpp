#include<stack>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
       vector<int> ans;
       stack<int> st;
       unordered_map<int,int> mp;

       for(int j=nums2.size()-1;j>=0;j--)
       {
         
            //remove all the elements that cannot be the answer
            while(!st.empty() && nums2[j]>=st.top())
            {
                st.pop();
            }

            //if stack is empty no greater elemnt exist

            if(st.empty())
            {
                mp[nums2[j]]=-1;
            }

            else
            {
                mp[nums2[j]]=st.top();
            }

            st.push(nums2[j]);
       }


       for(int x:nums1)
       {
        ans.push_back(mp[x]);
       }

       return ans;

    }
};