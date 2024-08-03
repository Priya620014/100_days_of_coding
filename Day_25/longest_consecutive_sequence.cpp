class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> um;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            um[nums[i]]++;
        }
        int len=0;
        for(int i=0;i<n;i++)
        {
            int start=nums[i];
            if(um.count(start-1)==0)
            {
                int cnt=0;
                while(um.count(start))
                {
                    cnt++;
                    start+=1;
                }
                if(cnt>len)
                {
                    len=cnt;
                }
            }
        }
        return len;
    }
};