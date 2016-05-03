#include <iostream>

int main()
{
    return 0;
}

class Node
{
public:
	int m_value = 0;
	Node *m_leftNode = nullptr;
	Node *m_rightNode = nullptr;
};

class BinaryTree
{
public:
	BinaryTree() { m_root = new Node; }

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

	void Insert(int value)
	{
		// WIP -- Add value to the tree (add new node)
	}

	void Find(int value)
	{
		// WIP -- Search through the nodes for the value
	}

	Node *m_root = nullptr;
	bool m_empty;
};