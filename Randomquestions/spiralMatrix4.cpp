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
        vector<vector<int> >ans(m, vector<int>(n, -1));
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        int id = 0;

        ListNode*it = head;

        while(top <= down && left <= right) {
            if(id == 0) {
                for(int i=left; i<=right && it; i++) {
                    ans[top][i] = it->val;
                    it = it->next; 
                }
                top++;
            }

            if(id == 1) {
                // top to down
                for(int i=top; i<=down && it; i++) {
                    ans[i][right] = it->val;
                    it = it->next;
                }

                right--;
            }

            if(id == 2) {
                // right to left
                for(int i=right; i>=left && it; i--) {
                    ans[down][i] = it->val;
                    it = it->next; 
                }

                down--;
            }

            if(id == 3) {
                for(int i=down; i>=top && it; i--) {
                    ans[i][left] = it->val;
                    it = it->next;
                }

                left++;
            }

            id = (id+1)%4;
        }




        return ans;





    //     int row = 0;
    //     int col = 0;
        
    //     for(int i=startCol; i<=endCol && it; i++) {
    //         ans[row][i] = it->val;
    //         it = it->next;
    //     }
        
    //     startRow++;
    //     row = startRow;
    //     for(int i=startRow; i<endRow && it; i++) {
    //         ans[i][col] = it->val;
    //         it = it->next;
    //     }

    //     endCol--;
    //     row =
    //     for(int i=endCol; i>= startCol && it; i--) {
    //         ans[row][i] = it->val;
    //         it = it->next; 
    //     }
        
    //     endRow--;

    //     for(int i=endRow; i>= startRow && it; i--) {
    //         ans[i][col] = it->val;
    //         it = it->next;
    //     }

    //     startCol++;

    //     return ans;
    }
};