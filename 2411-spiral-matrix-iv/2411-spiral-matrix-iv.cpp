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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int startRow = 0;
        int startCol = 0;
        int endRow = m-1;
        int endCol = n-1;
        int count = 0;

        int total = m*n;
        ListNode* curr = head;
        
        while(count<total && curr != NULL) {
            for(int i=startCol ; count<total && curr != NULL && i<=endCol ; i++) {
                matrix[startRow][i]=curr->val;
                curr = curr->next;
                count++;
            }
            startRow++;
            for(int i=startRow ; count<total && curr != NULL && i<=endRow ; i++) {
                matrix[i][endCol]=curr->val;
                curr = curr->next;
                count++;
            }
            endCol--;
            for(int i=endCol ; count<total && curr != NULL && i>=startCol ; i--) {
                matrix[endRow][i]=curr->val;
                curr = curr->next;
                count++;
            }
            endRow--;
            for(int i=endRow ; count<total && curr != NULL && i>=startRow ; i--) {
                matrix[i][startCol]=curr->val;
                curr = curr->next;
                count++;
            }
            startCol++;
        }
        return matrix;

    }
};