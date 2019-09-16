#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

#define EXP 0.0000001

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val_) :val(val_), left(NULL), right(NULL) {}
};

bool isNum(string str) {
	stringstream sin(str);
	int d;
	char c;
	if (!(sin >> d))
		return false;
	if (sin >> c)
		return false;

	return true;
}

int s2int(const string& s) {
	stringstream ss;
	ss << s;
	int ret;
	ss >> ret;
	return ret;
}

vector<string> split(const string& s, const string& delmiter) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()){
		int flag = 0;
		while (i != s.size() && flag == 0){
			flag = 1;
			for (string_size x = 0; x < delmiter.size(); ++x) {
				if (s[i] == delmiter[x]){
					++i;
					flag = 0;
					break;
				}
			}
		}

		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0){
			for (string_size x = 0; x < delmiter.size(); ++x) {
				if (s[j] == delmiter[x]){
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				++j;
		}//end while
		if (i != j){
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

Node* createBTree(vector<string>& v, int index) {
	Node* node = NULL;

	if (index < v.size()) {
		if (isNum(v[index]) == false) {
			return NULL;
		}
		node = new Node(s2int(v[index]));
		node->left = createBTree(v, index * 2 + 1);
		node->right = createBTree(v, index * 2 + 2);
		return node;
	}
	return node;
}

int levelOrder(Node* root) {
	//请完成代码
	//层序遍历
	std::queue<Node *> q1;
	std::queue<Node *> q2;
	Node *cur = root;
	if (cur != nullptr)
		q1.push(cur);
	double max = 0;
	int level = 0;
	double sum = 0;
	int num = 0;
	int ret = 0;
	while (!q1.empty() || !q2.empty())
	{
		while (!q1.empty())
		{
			Node *top = q1.front();
			q1.pop();
			if (top->left != nullptr)
				q2.push(top->left);
			if (top->right != nullptr)
				q2.push(top->right);
			sum += top->val;
			num++;
		}
		++level;
		double tmp = sum / num;
		if ((max - tmp)<EXP)
		{
			max = sum / num;
			ret = level;
		}
		sum = 0;
		num = 0;
		q1.swap(q2);
	}
	return ret;
}

int main() {
	string inString;
	int len = 0;
	cin >> inString;
	//vector<string> res = split(inString, " ");
	vector<string> res;
	if (isNum(inString)) {
		len = s2int(inString);
	}
	for (int i = 0; i < len; i++) {
		cin >> inString;
		res.push_back(inString);
	}
	/*
	for (int i = 0; i < res.size(); i++) {
	cout<<res[i]<<"	";
	}
	cout<<endl;
	*/
	Node* root = createBTree(res, 0);

	int ret = levelOrder(root);
	cout << ret << endl;
	return 0;
}
