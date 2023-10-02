#include<iostream>
#include<vector>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    int len(ListNode* head) {
        
        if(head == NULL) return 0;
        if(head -> next == NULL) return 1;
        int count = 0;

        while(head != NULL) {
            count++;
            head = head -> next;
        }
        return count;

    }

    ListNode* solve(ListNode* head, int k, int size) {

        if(size < k) 
            return head;

        if(head == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int c = 0;

        while(curr != NULL && c < k) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            c++;
        } 

        if(forward != NULL) {
            head -> next = solve(forward, k, size-k);
        }

        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = len(head);
        return solve(head, k, n);
    }
};