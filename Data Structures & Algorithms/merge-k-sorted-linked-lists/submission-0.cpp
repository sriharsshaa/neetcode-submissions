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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        for(ListNode* head:lists){
            while(head){
                nums.push_back(head->val);
                head=head->next;
            }
        }
        sort(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(0);
        ListNode* ans=dummy;
        for(int x:nums){
            ans->next=new ListNode(x);
            ans=ans->next;
        }
        return dummy->next;
    }
};
