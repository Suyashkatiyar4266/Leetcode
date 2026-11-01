// // mathematical observation
// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//         int lo = ranges::min(nums), moves=0;
//         for(int x: nums) moves += x - lo;
//         return moves;
//     }
// };


// //Sorting approach
// class Solution{
//     public:
//     int minMoves(vector<int>& nums){
//         sort(nums.begin(),nums.end());
//         int moves = 0;
//         for(int i = 1; i<nums.size();i++){
//             moves += nums[i] - nums[0];
//         }
//         return moves;
//     }
// };


//Using accumulated() and min_element()
class Solution{
    public:
    int minMoves(vector<int>& nums){
        int mn = *min_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        return sum-(nums.size()*mn);
    }
};