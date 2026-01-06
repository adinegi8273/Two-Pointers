

// Problem 1 - Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105


// class Solution {
// public:
//     int trap(vector<int>& height) {
        

//         int left = 0,right = height.size()-1;

//         int res = 0;
//         int left_max = height[left],right_max = height[right];
//         while(left <= right){
            
//             left_max = max(left_max, height[left]);
//             right_max = max(right_max,height[right]);

//             if(height[left] < height[right]){
//                 //we should move the left pointer
//                 //before moving we have to store the units of water which will be trapped
//                 res = res + (min(left_max,right_max) - height[left]);
//                 left++;
//             }
//             else{
//                 //that means eiohter hieght of right building become smaller or equal to the left one
//                 res = res + (min(left_max,right_max) - height[right]);
//                 right--;
//             }
//         }

//         return res;
//     }
// };

// --------------------------------------------------------------------------------------------------------------

// Problem 2 - Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
        
        
//         int left = 0,right = height.size()-1;

//         int res = 0;

//         while(left < right){

//             res = max(res, (right-left)*min(height[left],height[right]));

//             //here we have to decide to move which pointer
//             //we must move that pointer which is pointing to a smaller buidling
//             if(height[left] < height[right]){
//                 left++;
//             }
//             else{
//                 right--;
//             }
//         }

//         return res;
//     }
// };

// ------------------------------------------------------------------------------------------------------------------

// Problem 3 - Next Permutation

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100


// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
        
//         int n = nums.size();
//         int i;
//         for(i=n-1;i>0;i--){
            
//             if(nums[i-1] < nums[i]){
//                 //i should finding out the index at which an integer is present which is just greater than the current number

//                 int elem = nums[i-1];

//                 //find the index which is jsut greater than the current value
//                 for(int j = n-1;j>=i;j--){
//                     if(nums[j] > elem){
//                         // ihave found out the first element just greater than the elem
//                         swap(nums[i-1],nums[j]);
//                         break;
//                     }
//                 }

//                 break;
//             }

//         }
//         reverse(nums.begin()+i,nums.end());
//     }
// };


// ----------------------------------------------------------------------------------------------------------------------

// Problem 4 - Sort Array By Parity II

// Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
// Return any answer array that satisfies this condition.

 

// Example 1:

// Input: nums = [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
// Example 2:

// Input: nums = [2,3]
// Output: [2,3]
 

// Constraints:

// 2 <= nums.length <= 2 * 104
// nums.length is even.
// Half of the integers in nums are even.
// 0 <= nums[i] <= 1000
 

// Follow Up: Could you solve it in-place?

// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& nums) {
        

//         int even = 0,odd = 1;

//         int n = nums.size();
//         vector<int> res(n);
//         for(int i=0;i<n;i++){
            
//             if(nums[i] % 2 == 1){
//                 //odd number then place it at the odd indice
//                 res[odd] = nums[i];
//                 odd += 2;//move to the next odd indice
//             }
//             else{
//                 res[even] = nums[i];
//                 even += 2;
//             }
//         }

//         return res;
//     }
// };

