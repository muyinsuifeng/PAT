#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree_son( vector<int>& preorder, int pbegin, int pend, vector<int>& inorder, int ibegin, int iend){
	if( ibegin >= iend|| pbegin >= pend) return NULL;
	int mid = preorder[pbegin];
	auto f = find( inorder.begin()+ibegin, inorder.end()+iend, mid);
	int dis = f - inorder.begin() - ibegin;
	TreeNode* head = new TreeNode(mid);
	head->left = buildTree_son( preorder, pbegin+1, pbegin+dis+1, inorder, ibegin, ibegin+dis);
	head->right = buildTree_son( preorder, pbegin+dis+1, pend, inorder, ibegin+dis+1, iend);
	return head;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree_son( preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
void PostOrderTraversal(TreeNode* head){
    TreeNode* tn = head;
    if(tn)
    {
        PostOrderTraversal(tn->left);
        PostOrderTraversal(tn->right);
        cout << tn->val << " ";       
    }
}
int main(int argc, char const *argv[]){
	stack<int> s;
	vector<int> v;
	vector<int> p;
	int n;
	cin>>n;
	n = 2*n;
	string line;
	while(n--){
		int num;
		cin >> line;
		if( line[1] == 'u') {
			cin >> num;
			p.push_back(num);
			s.push(num);
		}else{
			int tmp = s.top();
			s.pop();
			v.push_back(tmp);
		}
	}
	TreeNode* head = buildTree( p, v);
	PostOrderTraversal( head);
	return 0;
}
