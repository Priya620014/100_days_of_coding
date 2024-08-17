// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n=nums.size();
//         int ans;
//         for(int i=0;i<n;i++)
//         {
//             if(i!=nums[i]&&nums[i]<=n)
//             {
//                 ans=i;
//                 break;
//             }
            
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(i!=nums[i])
//             {
//                 ans=i;
//             }
//         }
//    return ans;
  //  }
  class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n+1,-1);
        for(int i =0;i<nums.size();i++){
            v[nums[i]] = nums[i];
        }
        for(int i =0;i<v.size();i++){
            if(v[i]==-1)return i;
        }
        return 0;
    }
};


//};