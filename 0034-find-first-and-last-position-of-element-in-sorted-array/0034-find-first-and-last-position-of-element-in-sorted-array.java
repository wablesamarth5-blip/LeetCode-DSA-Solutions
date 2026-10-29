class Solution {
    public int[] searchRange(int[] nums, int target) {
        
       return new int[]
       {binsearch(nums,target,true),
        binsearch(nums,target,false)};
    }


    public int binsearch(int[] nums,int target,boolean first)
    {
        int left=0;
        int right=nums.length-1;
        int answer=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
         
            if(nums[mid]==target)
            {
                 answer=mid;

                 if(first) right=mid-1;  //search towards left
                 else left=mid+1;   // search towards right
            }

            else if(nums[mid]<target)
            {
                left=mid+1;
            }

            else
            {
                right=mid-1;
            }
        }

        return answer;
    }
}