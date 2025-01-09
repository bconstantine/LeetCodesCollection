#include <iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2){
            return head;
        }
        int totalNode = 0;
        ListNode* firstNode = new ListNode(0, head);
        ListNode* prev = firstNode;
        ListNode* traverseNode = head;
        while(traverseNode != NULL){
            totalNode += 1;
            traverseNode = traverseNode ->next;
        }
        
        while(totalNode >= k){
            ListNode* curr = prev->next;
            ListNode* nextNode = curr ->next;
            for(int i = 1; i < k; i++){
                curr->next = nextNode -> next;
                nextNode -> next = prev->next;
                prev->next = nextNode;
                nextNode = curr->next;
            }
            prev = curr;
            totalNode -= k;
        }
        return firstNode->next;
    }
};