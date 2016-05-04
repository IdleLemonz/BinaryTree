#include <iostream>

class Node
{
public:
	Node() {}
	Node(int value) { m_value = value; }
	~Node() {}
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
		// WIP -- Add value to the tree (add new node)
		if (value < node->m_value)
		{
			if (node->m_leftNode == nullptr)
			{				
				Node *newNode;
				newNode = new Node(value);
				node->m_leftNode = newNode;
				std::cout << "Node " << value << " inserted left from parent " << node->m_value <<"...\n";
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

	void Find(int value)
	{
		// WIP -- Search through the nodes for the value
	}

	Node *m_root = nullptr;	
};

int main()
{
	BinaryTree tree;
	tree.Insert(5, tree.m_root);
	tree.Insert(8, tree.m_root);
	tree.Insert(15, tree.m_root);
	tree.Insert(13, tree.m_root);
	tree.Insert(12, tree.m_root);
	tree.Insert(9, tree.m_root);
	tree.Insert(5, tree.m_root);
	tree.Insert(21, tree.m_root);
	system("PAUSE");
    return 0;
}


