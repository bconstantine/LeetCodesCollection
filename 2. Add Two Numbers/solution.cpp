#include <bits/stdc++.h>
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
    ListNode* reversingALinkedList(ListNode* originalLinkedListHead){
        //change in place
        ListNode* dummyNode = new ListNode(0, originalLinkedListHead);
        ListNode* traverseNode = originalLinkedListHead;
        ListNode* next = traverseNode->next;
        while(next != NULL){
            ListNode* temp = dummyNode->next;
            dummyNode->next = next;
            traverseNode->next=next->next;
            next->next = temp;

            next = traverseNode->next;
        }
        return dummyNode->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //l1 = reversingALinkedList(l1);
        //l2 = reversingALinkedList(l2);
        ListNode* traverseL1 = l1;
        ListNode* traverseL2 = l2;
        ListNode* l1Prev = NULL; 
        int appendNext = 0;
        while(traverseL1 != NULL && traverseL2 != NULL){
            //cout << "Val: " << traverseL1->val << "\n";
            traverseL1->val = traverseL1->val + traverseL2->val + appendNext;
            //cout << "Val: " << traverseL1->val << "\n";
            if(traverseL1->val / 10){
                traverseL1->val = traverseL1->val % 10;
                appendNext = 1;
            }else{
                appendNext = 0;
            }
            l1Prev = traverseL1;
            traverseL1 = traverseL1->next;
            traverseL2 = traverseL2->next;
        }
        if(traverseL2){
            if(l1Prev != NULL){
                l1Prev->next = traverseL2;
            }
            traverseL1 = traverseL2;
        }
        while(traverseL1 != NULL && appendNext){
            traverseL1->val += appendNext;
            if(traverseL1->val / 10){
                traverseL1->val = traverseL1->val % 10;
                appendNext = 1;
            }else{
                appendNext = 0;
            }
            l1Prev = traverseL1;
            traverseL1 = traverseL1->next;
        }

        //l1 = reversingALinkedList(l1);
        if(appendNext){
            ListNode* trailing1 = new ListNode(1);
            l1Prev->next = trailing1;
        }
        return l1; 
    }
};