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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mp(nums.begin(),nums.end());

        while(head!=NULL && mp.find(head->val) != mp.end()) {
            ListNode* temp = head;
            head=head->next;
            delete temp;
        }
        
        ListNode* curr = head;
        while(curr!=NULL && curr->next!=NULL) {
            if(mp.find(curr->next->val) != mp.end()) {
                ListNode* temp = curr->next;
                curr->next=curr->next->next;
                delete temp;
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};