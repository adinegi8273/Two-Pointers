

// This pattern of two pointer is indeed very popular and also known as Mergining two arrays or parallel traversal in teh two arrays

// Problem 1 - Merge Sorted Array

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

// Constraints:

// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -109 <= nums1[i], nums2[j] <= 109
 

// Follow up: Can you come up with an algorithm that runs in O(m + n) time?


// Appraoch 1 - 

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        

//         int ptr = 0,index = 0;

//         vector<int> res;

//         while(ptr < n && index < m){

//             //push baxk elements in nums2 which are lesser or equal ton current nums1[indx]

//             while(ptr < n && nums2[ptr] <= nums1[index]){
//                 res.push_back(nums2[ptr]);
//                 ptr++;
//             }

//             //now put the similar elemts of nums 1 in res
//             int j = index;
//             while(j < m && nums1[index] == nums1[j]){
//                 res.push_back(nums1[index]);
//                 j++;
//             }

//             index = j;//this is updated index
//         }

//         //poush back the remianing elememnt
//         while(index < m){
//             res.push_back(nums1[index++]);
//         }

//         while(ptr < n){
//             res.push_back(nums2[ptr++]);
//         }

//         for(int i=0;i<m+n;i++){
//             nums1[i] = res[i];
//         }

//         //time complexity of O(m+n) and space complexity of O(m+n)
//     }
// };


//Approach 2 - 

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
//         vector<int> res;

//         int ptr1=0,ptr2 = 0;

//         while(ptr1 < m && ptr2 < n){
            
//             if(nums1[ptr1] <= nums2[ptr2]) res.push_back(nums1[ptr1++]);
//             else res.push_back(nums2[ptr2++]);
//         }

//         while(ptr1 < m){
//             res.push_back(nums1[ptr1++]);
//         }

//         while(ptr2 < n){
//             res.push_back(nums2[ptr2++]);
//         }

//         for(int i=0;i<m+n;i++){
//             nums1[i] = res[i];
//         }

//     }
// };


// -----------------------------------------------------------------------------------------------------------

// Problem 2 - Intersection of Two Arrays II

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000
 

// Follow up:

// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
//         unordered_map<int,int> mpp;
//         int m = nums1.size();
//         int n = nums2.size();

//         vector<int> res;

//         for(int i=0;i<n;i++){
//             mpp[nums2[i]]++;
//         }

//         for(int i=0;i<m;i++){

//             if(mpp.count(nums1[i])){
//                 //present means common
//                 res.push_back(nums1[i]);
//                 mpp[nums1[i]]--;

//                 if(mpp[nums1[i]] == 0) mpp.erase(nums1[i]);
//             }

//         }

//         return res;
//     }
// };

// -----------------------------------------------------------------------------------------------------------


// Problem 3 - Longest Uncommon Subsequence II

// Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.
// An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
// A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
// For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
 
// Example 1:

// Input: strs = ["aba","cdc","eae"]
// Output: 3
// Example 2:

// Input: strs = ["aaa","aaa","aa"]
// Output: -1
 

// Constraints:

// 2 <= strs.length <= 50
// 1 <= strs[i].length <= 10
// strs[i] consists of lowercase English letters.

// class Solution {
// public:

//     bool solve(string& s,string& t){//since we are not changing the two strings just comparing
        
//         //check whether s is subequnce of t or not
//         //use 2 pointers approach

//         int i = 0,j = 0;

//         while(i<s.size() && j < t.size()){

//             if(s[i] == t[j]){
//                 i++;j++;
//             }
//             else{
//                 j++;
//             }
//         }

//         if(i == s.size()) return true;//because s is subsequnce of t
//         return false;
//     }
    
//     int findLUSlength(vector<string>& strs) {
        
        
//         int n= strs.size();

//         unordered_map<string,int> mpp;

//         vector<string> new_strs;//this has the strings sorted also and distinct one also

//         for(string str:strs){

//             if(!mpp.count(str)){
//                 //dinstict string
//                 new_strs.push_back(str);
//             }

//             mpp[str]++;
//         }

//         //sort this new_strs in descending order

//         auto lamda = [](string& a,string& b){
//             return a.size()>b.size();
//         };

//         sort(new_strs.begin(),new_strs.end(),lamda);

//         for(int i=0;i<new_strs.size();i++){
            
//             if(mpp[new_strs[i]] > 1) continue;//this subsequnce is the not an uncommon

//             //compare thsi string with the sttings which are of greater length than this

//             bool flag = false;
//             string str = new_strs[i];
//             for(int j=0;j<i;j++){


//                 if(solve(str,new_strs[j])){
//                    flag = true;
//                    break; 
//                 }
//             }

//             if(flag == true) continue;//this string is coming as a subsequnce in one of teh strings henvce uncommon

//             return str.size();
//         }

//         return -1;
//     }
// };

// ----------------------------------------------------------------------------------------------------------

// Problem 4 - Find Median from Data Stream

// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
 

// Constraints:

// -105 <= num <= 105
// There will be at least one element in the data structure before calling findMedian.
// At most 5 * 104 calls will be made to addNum and findMedian.
 

// Follow up:

// If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

// class MedianFinder {
// public:
//     priority_queue<int> max_heap;
//     priority_queue<int,vector<int>,greater<int>> min_heap;
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         min_heap.push(num);
                
//                 if(min_heap.size()-max_heap.size() > 1){
//                     max_heap.push(min_heap.top());
//                     min_heap.pop();
//                 }
                
//                 //ensure the minimum value of min heap should be greater than the maximum value
//                 if(!max_heap.empty() && min_heap.top() < max_heap.top()){
//                     min_heap.push(max_heap.top());
//                     max_heap.pop();
//                     max_heap.push(min_heap.top());
//                     min_heap.pop();
//                 }
//     }
    
//     double findMedian() {
//         //to find the median determine the number of elements
//                 if(min_heap.size() == max_heap.size()){
//                     //the median is the average of min_heap top and max_heaps top
//                     return ((double)(min_heap.top()+max_heap.top())/2);
//                 }
//                 return min_heap.top();
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// --------------------------------------------------------------------------------------------------------------------------

// Problem 5 - Ways to Split Array Into Three Subarrays

// A split of an integer array is good if:
// The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
// The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
// Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
 
// Example 1:

// Input: nums = [1,1,1]
// Output: 1
// Explanation: The only good way to split nums is [1] [1] [1].
// Example 2:

// Input: nums = [1,2,2,2,5,0]
// Output: 3
// Explanation: There are three good ways of splitting nums:
// [1] [2] [2,2,5,0]
// [1] [2,2] [2,5,0]
// [1,2] [2,2] [5,0]
// Example 3:

// Input: nums = [3,2,1]
// Output: 0
// Explanation: There is no good way to split nums.
 

// Constraints:

// 3 <= nums.length <= 105
// 0 <= nums[i] <= 104

// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int findMin(int left,int low,int high,vector<int>& prefix){
        
//         int ans = -1;
//         int n = prefix.size();
//         while(low <= high){

//             int j = low + floor((high-low)/2);

//             int mid = prefix[j-1] - left;
//             int right = prefix[n-1] - prefix[j-1];

//             if(left > mid){
//                 low = j+1;
//             }
//             else if(right < mid){
//                 high = j-1;
//             }
//             else{

//                 ans = j;
//                 high = j-1;
//             }
//         }

//         return ans;
//     }

//     int findMax(int left,int low,int high,vector<int>& prefix){
        
//         int ans = -1;
//         int n = prefix.size();
//         while(low <= high){

//             int j = low + floor((high-low)/2);

//             int mid = prefix[j-1] - left;
//             int right = prefix[n-1] - prefix[j-1];

//             if(left > mid){
//                 low = j+1;
//             }
//             else if(right < mid){
//                 high = j-1;
//             }
//             else{

//                 ans = j;
//                 low = j + 1;
//             }
//         }

//         return ans;
//     }
//     int waysToSplit(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> prefix(n,0);//O(N)
//         prefix[0]= nums[0];

//         for(int i=1;i<n;i++) prefix[i] = prefix[i-1]+nums[i];

//         int res_cnt = 0;
//         for(int i=0;i<n-2;i++){

//             int left = prefix[i];

//             int right_min = findMin(left,i+2,n-1,prefix);//O(logN)
//             int right_max = findMax(left,i+2,n-1,prefix);//O(logN)

//             if(right_min == -1) continue;
//             res_cnt = (res_cnt + (right_max-right_min+1))%mod;
//         }

//         return res_cnt%mod;
//     }

//     //time complexity is O(NlogN) and space complexity is O(N)
// };

