class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        long long ans = 0;

        while(left < right){
            ans += (long long)nums[right] - nums[left];
            left++;
            right--;
        }
        return ans;
    }
};