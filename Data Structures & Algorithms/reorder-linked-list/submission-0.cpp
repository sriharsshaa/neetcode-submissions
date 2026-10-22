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
ListNode* findMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=nullptr;
    ListNode* nxt=nullptr;
    while(curr!=nullptr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return;
        ListNode* mid=findMid(head);
        ListNode* rev=reverse(mid->next);
        mid->next=nullptr;
        ListNode* first=head;
        ListNode* second=rev;
        while(second!=nullptr){
            ListNode* nextFirst=first->next;
            ListNode* nextSecond=second->next;
            first->next=second;
            second->next=nextFirst;

            first=nextFirst;
            second=nextSecond;
        }
    }
};

/*

1. Find the middle of the linked list.
2. Reverse the second half.
3. Merge both halves alternately.

*/
