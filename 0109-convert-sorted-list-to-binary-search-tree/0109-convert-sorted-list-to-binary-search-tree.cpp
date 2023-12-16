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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedVectorToBST(vector<int>& arr, int start, int end){
        if(start > end) return nullptr;
        
        int mid = (start+end)>>1;
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left = sortedVectorToBST(arr, start, mid-1);
        root->right = sortedVectorToBST(arr, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        
        int n = arr.size();
        
        return sortedVectorToBST(arr, 0, n-1);
    }
};