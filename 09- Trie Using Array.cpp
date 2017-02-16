//in the name of God

#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

const int sz = 26;

struct Trie {
	Trie *child[sz];
	bool isLeaf;
	Trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}
	void Insert(char *str) {
		if (*str == '\0')
			isLeaf = 1;
		else {
			int cur = *str - 97;
			if (child[cur] == 0)
				child[cur] = new Trie();
			child[cur]->Insert(str + 1);
		}
	}
	bool WordExist(char *str) {
		if (*str == '\0')
			return isLeaf;
		int cur = *str - 97;
		if (child[cur] == 0)
			return false;
		return child[cur]->WordExist(str + 1);
	}
	bool PrefixExist(char* str) {
		if (*str == '\0')
			return true;
		int cur = *str - 97;
		if (child[cur] == 0)
			return false;
		return child[cur]->PrefixExist(str + 1);
	}
};

int main() {
	Trie *root = new Trie();
	root->Insert("abcd");
	root->Insert("xyz");
	root->Insert("abf");
	root->Insert("xn");
	root->Insert("ab");
	root->Insert("bcd");
	cout << root->WordExist("xyz") << endl;
	cout << root->WordExist("xy") << endl;
	cout << root->PrefixExist("xy") << endl;
	return 0;
}