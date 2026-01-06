
// Problem 1 - Palindrome Linked List

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// Example 1:

// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
 

// Follow up: Could you do it in O(n) time and O(1) space?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {

//         if(head->next == NULL) return true;//only one integer is pallindromic in nature

//         struct ListNode *slow,*fast;

//         slow = head;
//         fast = head;
        
//         vector<int> arr;

//         while(fast != NULL && fast->next != NULL){
//             arr.push_back(slow->val);
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         if(fast != NULL ) arr.push_back(slow->val);
//         //at this step slow is pointing at middle
//         int index = 0;
//         reverse(arr.begin(),arr.end());
//         while(slow != NULL){

//             if(arr[index++] != slow->val) return false;
//             slow = slow ->next;
//         }

//         return true;
//     }
// };


// ------------------------------------------------------------------------------------------------------------

// Problem 2 - Circular Array Loop

// You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

// If nums[i] is positive, move nums[i] steps forward, and
// If nums[i] is negative, move abs(nums[i]) steps backward.
// Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

// A cycle in the array consists of a sequence of indices seq of length k where:

// Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
// Every nums[seq[j]] is either all positive or all negative.
// k > 1
// Return true if there is a cycle in nums, or false otherwise.

// Example 1:

// Input: nums = [2,-1,1,2,2]
// Output: true
// Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
// We can see the cycle 0 --> 2 --> 3 --> 0 --> ..., and all of its nodes are white (jumping in the same direction).
// Example 2:


// Input: nums = [-1,-2,-3,-4,-5,6]
// Output: false
// Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
// The only cycle is of size 1, so we return false.
// Example 3:


// Input: nums = [1,-1,5,1,4]
// Output: true
// Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
// We can see the cycle 0 --> 1 --> 0 --> ..., and while it is of size > 1, it has a node jumping forward and a node jumping backward, so it is not a cycle.
// We can see the cycle 3 --> 4 --> 3 --> ..., and all of its nodes are white (jumping in the same direction).
 

// Constraints:

// 1 <= nums.length <= 5000
// -1000 <= nums[i] <= 1000
// nums[i] != 0
 

// Follow up: Could you solve it in O(n) time complexity and O(1) extra space complexity?

// class Solution {
// public:

//     int normalize(int index,int n){

//         if(index < 0){
//             index = n + (-1 * abs(index)%n);
//         }
//         else{
//             index = index % n; 
//         }

//         return index;
//     }

//     bool onlyOneElement(int index,int n,vector<int>& nums){

//         int temp = index;
//         temp = temp + nums[temp];
//         temp = normalize(temp,n);
//         if(temp == index) return true;
//         return false;
//     }

//     bool circularArrayLoop(vector<int>& nums) {
        
        
//         int n = nums.size();

//         if(n == 1) return false;
        
//         vector<int> valid(n,1);//this will help me reject the nodes which are proven to be not a starting point of any cykle

//         int slow,fast;

//         for(int i=0;i<n;i++){

//             if(valid[i] == 0) continue;

//             //consider this as a possivle starting point

//             slow = i;fast = i;

//             int dir = (nums[i] < 0)?-1:1;

//             bool start = true;
    
//             while(slow != fast || start){
                
//                 start = false;

//                 slow = slow + nums[slow];
//                 fast = fast + nums[fast];

//                 slow = normalize(slow,n);
//                 fast = normalize(fast,n);

//                 if((nums[fast]/dir) < 0) break;//opposite direction

//                 fast = fast + nums[fast];//here fast will move one more step
//                 fast = normalize(fast,n);

//                 if((nums[fast]/dir) < 0) break;

//                 valid[slow] = 0;valid[fast] = 0;
//             }

//             //now check if there is only one element in the sequence or not
//             if((nums[fast]/dir) > 0){
//                 if(onlyOneElement(slow,n,nums)){
//                     continue;
//                 }
//                 return true;
//             }
//         }

//         return false;

//     }
// };

// ---------------------------------------------------------------------------------------------------------------

// Problem 3 - 1040. Moving Stones Until Consecutive II

// There are some stones in different positions on the X-axis. You are given an integer array stones, the positions of the stones.
// Call a stone an endpoint stone if it has the smallest or largest position. In one move, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
// In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.
// The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
// Return an integer array answer of length 2 where:
// answer[0] is the minimum number of moves you can play, and
// answer[1] is the maximum number of moves you can play.
 
// Example 1:

// Input: stones = [7,4,9]
// Output: [1,2]
// Explanation: We can move 4 -> 8 for one move to finish the game.
// Or, we can move 9 -> 5, 4 -> 6 for two moves to finish the game.
// Example 2:

// Input: stones = [6,5,4,3,10]
// Output: [2,3]
// Explanation: We can move 3 -> 8 then 10 -> 7 to finish the game.
// Or, we can move 3 -> 7, 4 -> 8, 5 -> 9 to finish the game.
// Notice we cannot move 10 -> 2 to finish the game, because that would be an illegal move.
 

// Constraints:

// 3 <= stones.length <= 104
// 1 <= stones[i] <= 109
// All the values of stones are unique.


// class Solution {
// public:
//     vector<int> numMovesStonesII(vector<int>& stones) {
        
//         //sort the stones

//         sort(stones.begin(),stones.end());

//         //first of all check if they are already consequtive

//         bool flag =true;

//         int n = stones.size();

//         for(int i=1;i<n;i++){
//             if(stones[i]-stones[i-1] > 1){
//                 flag=false;
//                 break;
//             }
//         }

//         if(flag == true) return {0,0};//0 moves reqyired since they are already adjancent

//         int min_moves,max_moves;

//         //determine min moves and max moves
        
//         int total = 0;
//         for(int i=1;i<n;i++){
//             total += (stones[i] - stones[i-1] - 1);
//         }

//         max_moves = 1 + (total - (min(stones[1]-stones[0]-1, stones[n-1]-stones[n-2]-1) + 1));


//         //determine the minimum number of moves

//         int l = 0,r;

//         while(l<n){

//             r = l;

//             while(r < n && stones[r]-stones[l]+1 <= n){
//                 r++;
//             }

//             if(r-l == n-1 && stones[l] + (n-1) != stones[r-1]){
//                 //thiss is the special case
//                 min_moves = min(min_moves,2);
//             }
//             else min_moves = min(min_moves, n-(r-l));

//             l++;
//         }
        
//         return {min_moves,max_moves};

//     }
// };


// -----------------------------------------------------------------------------------------------------------


// Problem 4 - Remove Duplicates from Sorted List II

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
        
//         //if there are no node or only one node in linked lists then return head

//         if(head == NULL || head->next == NULL) return head;

//         ListNode* dummy = new ListNode(0,head);
        
//         ListNode *prev,*curr;

//         prev = dummy;
//         curr = head->next;
//         int cnt = 0;//this cnt will help determine if a node in between curr and prev is coming one time or not
//         while(curr != NULL){

//             if(prev->next->val == curr->val){
//                 cnt++;
//                 curr = curr->next;
//             }
//             else{

//                 //first check whether there are any duplicate values present between prev and curr
//                 if(cnt == 0){//no duplicate between prev and curr
//                     prev = prev->next;
//                 }
//                 else{
//                     //ho sakta hai ki ye element jo naya dekha uske bhi duplicate present hon
//                     prev->next = curr;
//                 }

//                 curr = curr->next;
//                 cnt = 0;//start cnt a new number between prev and curr
//             }
//         }

//         if(cnt == 0){
//             //it means at the end you encountererd a distinct integer
//             prev = prev->next;
//         }

//         prev->next = NULL;
//         head = dummy->next;//may be to a new head
//         dummy->next = NULL;

//         return head;
//     }
// };


// ------------------------------------------------------------------------------------------------------------------

// Problem 5 - Longest Mountain in Array

// You may recall that an array arr is a mountain array if and only if:
// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

// Example 1:

// Input: arr = [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
// Example 2:

// Input: arr = [2,2,2]
// Output: 0
// Explanation: There is no mountain.
 

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104
 

// Follow up:

// Can you solve it using only one pass?
// Can you solve it in O(1) space?

// class Solution {
// public:
//     int longestMountain(vector<int>& arr) {
        

//         int n = arr.size();

//         int start=-1;
//         bool prev=true,curr;
//         int res = 0;
//         for(int i=1;i<n;i++){
            
//             if(arr[i] > arr[i-1]){
//                 curr = true;//represents increasung
                
//                 if(prev == false && curr == true){
//                     //this is a special case
//                     res = max(res, i-start);
//                     start = i-1;
//                 }
//             }
//             else{
//                 curr = false;
//             }

//             prev = curr;
//         }

//         return res;
//     }
// };

