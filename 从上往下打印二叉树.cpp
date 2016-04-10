#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
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
private:
	vector<int> ans;
	queue<TreeNode*> queue;
public:
	vector<int> PrintFromTopToBottom(TreeNode *root) {
		/*
		if (root == NULL)
			return ans;
			*/		
		queue.push(root);
		while (!queue.empty())
		{
			TreeNode* temp = queue.back();
			queue.pop();
			if (temp == NULL)
				continue;
			else 
			{
				ans.push_back(temp->val);
				queue.push(temp->left);
				queue.push(temp->right);

			}

		}
		return ans;
	}
};