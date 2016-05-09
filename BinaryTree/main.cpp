#include <iostream>

enum HAS_CHILD
{
	NO_CHILD,
	LEFT_CHILD,
	RIGHT_CHILD,
	TWO_CHILDREN,
};

class Node
{
public:
	Node() {}
	Node(int value) { m_value = value; }
	~Node() {}

	HAS_CHILD HasChildren()
	{
		HAS_CHILD children;
		int numChildren = 0;
		if (m_leftNode != nullptr && m_rightNode == nullptr)
		{
			numChildren = 1;
		}
		else if (m_rightNode != nullptr && m_leftNode == nullptr)
		{
			numChildren = 2;
		}
		else if (m_leftNode != nullptr && m_rightNode != nullptr)
		{
			numChildren = 3;
		}

		if (numChildren == 0)
		{
			children = NO_CHILD;
			std::cout << "Has no children.\n";
		}
		else if (numChildren == 1)
		{
			children = LEFT_CHILD;
			std::cout << "Has left child.\n";
		}
		else if (numChildren == 2)
		{
			children = RIGHT_CHILD;
			std::cout << "Has right child.\n";
		}
		else if (numChildren == 3)
		{
			children = TWO_CHILDREN;
			std::cout << "Has two children.\n";
		}
		return children;
	}

	int m_value = 0;
	Node *m_leftNode = nullptr;
	Node *m_rightNode = nullptr;
};

class BinaryTree
{
public:
	BinaryTree() { m_root = new Node(10); }

	// Return true if tree is empty 	
	bool IsEmpty()
	{
		if (m_root->m_leftNode == nullptr && m_root->m_rightNode == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Insert(int value, Node *node)
	{
		// Add value to the tree (add new node)
		if (value < node->m_value)
		{
			if (node->m_leftNode == nullptr)
			{
				Node *newNode;
				newNode = new Node(value);
				node->m_leftNode = newNode;
				std::cout << "Node " << value << " inserted left from parent " << node->m_value << "...\n";
			}
			else
			{
				std::cout << "Recursing less than node on " << node->m_value << " into node " << node->m_leftNode->m_value << " ... \n";
				Insert(value, node->m_leftNode);
			}
		}
		else if (value > node->m_value)
		{
			if (node->m_rightNode == nullptr)
			{
				Node *newNode;
				newNode = new Node(value);
				node->m_rightNode = newNode;
				std::cout << "Node " << value << " inserted right from parent " << node->m_value << "...\n";
			}
			else
			{
				std::cout << "Recursing greater than node on " << node->m_value << " into node " << node->m_rightNode->m_value << "... \n";
				Insert(value, node->m_rightNode);
			}
		}
	}

	Node* Find(int value, Node *node)
	{
		Node *null = nullptr;
		if (value < node->m_value)
		{
			std::cout << "Attempting to recurse left on node " << node->m_value << " into node next node... \n";
			if (node->m_leftNode != nullptr)
			{
				Find(value, node->m_leftNode);
			}
			else
			{
				std::cout << "Node not found.\n";
				return null;
			}
		}
		else if (value > node->m_value)
		{
			std::cout << "Attempting to recurse right on node " << node->m_value << " into node next node... \n";
			if (node->m_rightNode != nullptr)
			{
				Find(value, node->m_rightNode);
			}
			else
			{
				std::cout << "Node not found.\n";
				return null;
			}
		}
		else
		{
			std::cout << "Found node! \n";
			return node;
		}
	}

	Node* FindPrevious(int value, Node *node)
	{
		Node *null = nullptr;
		if (value == node->m_leftNode->m_value)
		{
			return node;
		}
		else if (value == node->m_rightNode->m_value)
		{
			return node;
		}
		else if (value < node->m_value)
		{
			std::cout << "Attempting to recurse left on node " << node->m_value << " into node next node... \n";
			if (node->m_leftNode != nullptr)
			{
				Find(value, node->m_leftNode);
			}
			else
			{
				std::cout << "Node not found.\n";
				return null;
			}
		}
		else if (value > node->m_value)
		{
			std::cout << "Attempting to recurse right on node " << node->m_value << " into node next node... \n";
			if (node->m_rightNode != nullptr)
			{
				Find(value, node->m_rightNode);
			}
			else
			{
				std::cout << "Node not found.\n";
				return null;
			}
		}
		else
		{
			std::cout << "Found node! \n";
			return node;
		}
	}

	Node* FindSmallest(int leftValue, Node *leftNode)
	{		
		if (leftNode->m_leftNode == nullptr)
		{
			return leftNode;
		}
		else if (leftNode->m_leftNode->m_value < leftValue)
		{
			Find(leftNode->m_leftNode->m_value, leftNode->m_leftNode);
		}
	}	

	void SetChildrenNull(int value, Node *prevNode)
	{
		if (prevNode->m_leftNode->m_value == value)
		{
			prevNode->m_leftNode = nullptr;
		}
		else if (prevNode->m_rightNode->m_value == value)
		{
			prevNode->m_rightNode = nullptr;
		}
	}

	void Remove(int value, Node *node)
	{
		Node *removeThis = Find(value, node);		
		
		if (removeThis->HasChildren() == NO_CHILD)
		{
			Node *prevNode = FindPrevious(value, node);
			SetChildrenNull(value, prevNode);
			delete removeThis;
			removeThis = nullptr;
			std::cout << "Node deleted.\n";
		}
		else if (removeThis->HasChildren() == LEFT_CHILD)
		{
			Node *prevNode = FindPrevious(value, node);
			// Work out which side to change pointers to
			
			SetChildrenNull(value, prevNode);
		}		
		else if (removeThis->HasChildren() == TWO_CHILDREN)
		{

		}
	}

	Node *m_root = nullptr;
};

int main()
{
	
	BinaryTree tree;
	tree.Insert(5, tree.m_root);
	//tree.Insert(3, tree.m_root);

	tree.Remove(5, tree.m_root);

	tree.Find(5, tree.m_root);

	
	//tree.Insert(8, tree.m_root);	

	//tree.Insert(4, tree.m_root);
	//tree.Insert(1, tree.m_root);
	//tree.Insert(7, tree.m_root);

	/*int numDel = 3;
	std::cout << "Program now deleting the node " << numDel << "...\n";
	tree.Remove(numDel, tree.m_root);

	int number = 3;
	std::cout << "Searching for " << number << "...\n";
	tree.Find(number, tree.m_root);*/



	system("PAUSE");
	return 0;
}


