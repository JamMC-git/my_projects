class Solution 
{
    public:
       int removeDuplicates(vector<int>& nums) 
       {
               if(nums.size() > 2)
            {
                int writePos = 2;
                for(int i = 2; i < nums.size(); i++)
                {
                    if(nums[i] != nums[writePos-2])
                    {
                        nums[writePos]=nums[i];
                        writePos++;
                    }
                }
            }
               return writePos;
       }
};
