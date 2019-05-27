#ifndef _sbst_h
#define _sbst_h

#include <cstddef>
#include <string>

enum Direction {LEFT = 0, RIGHT, UNSET};

class SBST {

struct Node;

public:
	SBST(const std::string& text);
	~SBST();
	Node* search(const std::string& prefix);

	void print();

private:
	struct Node {
		size_t index;
		size_t m;
		Direction d;
		Node* left;
		Node* right;

		Node(size_t index, size_t m = 0, Direction d = UNSET, 
			Node* left = nullptr, Node* right = nullptr):
			index(index), m(m), d(d), left(left), right(right) {}
	};

	struct Details {
		Node** location;
		size_t llcp;
		size_t rlcp;
	};

	void postorder(Node* root, int indent);
	size_t longestCommonPrefix(const std::string& prefix, std::size_t index, std::size_t m_i);
	std::pair<size_t, size_t> find(const std::string& prefix);


	Node* root;
	std::string text;
};

#endif