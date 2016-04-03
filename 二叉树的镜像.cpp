#include <iostream>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		Mirror(pRoot->left); 
		Mirror(pRoot->right);
		TreeNode* temp = pRoot->right;
		pRoot->right = pRoot->left;
		pRoot->left = temp;
	}
};