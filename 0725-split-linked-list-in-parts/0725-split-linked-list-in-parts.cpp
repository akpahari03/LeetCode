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
    int findLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        int length = findLength(head);

        int eachNode = length/k;
        int extraNode = length%k;

        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++) {
            ans[i] = curr;
            for(int j=1;j <= eachNode + (extraNode > 0 ? 1 : 0);j++) {
                prev=curr;
                curr=curr->next;
            }
            if(prev != NULL) prev->next = NULL;
            extraNode--;
        }
        return ans;
    }
};