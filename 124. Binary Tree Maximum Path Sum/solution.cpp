#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    pair<int, int> recursivelySolve(TreeNode* rootNode){
        pair<int, int> result; //first is for the maximum value left, second is for the maximum value if node is used
        result.second = rootNode->val;
        pair<int, int> partialResultLeft;
        partialResultLeft.first = INT_MIN;
        partialResultLeft.second = INT_MIN;
        if(rootNode->left != NULL){
            partialResultLeft = recursivelySolve(rootNode->left);
        }
        
        
        pair<int, int> partialResultRight;
        partialResultRight.first = INT_MIN;
        partialResultRight.second = INT_MIN;
        if(rootNode->right != NULL){
            partialResultRight = recursivelySolve(rootNode->right); 
        }
        partialResultLeft.second = max(0, partialResultLeft.second);
        partialResultRight.second = max(0, partialResultRight.second);
        result.second = max(result.second + partialResultLeft.second, result.second +partialResultRight.second);
        result.first = max(rootNode->val+partialResultLeft.second+partialResultRight.second, max(partialResultLeft.first, partialResultRight.first));
        return result;
    }

    int maxPathSum(TreeNode* root) {
        pair<int, int> res = recursivelySolve(root);
        return res.first; 
    }
};