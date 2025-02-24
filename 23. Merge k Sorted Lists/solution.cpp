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
        ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
            ListNode* head = NULL;
            ListNode* prev = NULL;
            while(l1!= NULL && l2 != NULL){
                if(l1->val <= l2->val){
                    if(prev != NULL){
                        prev->next = l1;
                    }else{
                        head = l1;
                    }
                    prev = l1;
                    l1=l1->next;
                }else{
                    if(prev != NULL){
                        prev->next = l2;
                    }else{
                        head = l2;
                    }
                    prev = l2;
                    l2 = l2->next;
                }
            }
            
            while(l1 != NULL){
                if(prev != NULL){
                    prev->next = l1;
                }else{
                    head = l1;
                }
                prev = l1;
                l1=l1->next;
            }
            while(l2 != NULL){
                if(prev != NULL){
                    prev->next = l2;
                }else{
                    head = l2;
                }
                prev = l2;
                l2=l2->next;
            }
            if(prev != NULL){
                prev->next = NULL;
            }
            return head;
        }
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode* ans = divideAndConquerMergeList(lists, 0, lists.size()-1);
            return ans;
        }
    
        ListNode* divideAndConquerMergeList(vector<ListNode*> &lists, int listStartIdx, int listEndIdx){
            if(listStartIdx > listEndIdx){
                return NULL;
            }
            if(listStartIdx == listEndIdx){
                return lists[listStartIdx];
            }
            
            int partitionIdx = (listStartIdx+listEndIdx)/2;
            ListNode* l1 = divideAndConquerMergeList(lists, listStartIdx, partitionIdx);
            ListNode* l2 = divideAndConquerMergeList(lists, partitionIdx + 1, listEndIdx);
            ListNode* ans = mergeTwoList(l1, l2);
            return ans;
        }
    };