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
		if (value < node->m_value)
		{
			std::cout << "Recursing less than node on " << node->m_value << " into node " << node->m_leftNode->m_value << " ... \n";
			Find(value, node->m_leftNode);
		}
		else if (value > node->m_value)
		{
			std::cout << "Recursing greater than node on " << node->m_value << " into node " << node->m_rightNode->m_value << "... \n";
			Find(value, node->m_rightNode);
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

	void Remove(int value, Node *node)
	{
		if (value < node->m_value)
		{
			Node *nodeLeft = node->m_leftNode;			
			
			//int leftVal = node->m_leftNode->m_value;
			//Node *leftLeftNode = node->m_leftNode->m_leftNode;
			//Node *leftRightNode = node->m_leftNode->m_rightNode;

			if (nodeLeft->m_value == value && (nodeLeft->m_leftNode == nullptr && nodeLeft->m_rightNode == nullptr))
			{
				std::cout << "Found. Deleting node " << value << "... \n";
				delete node->m_leftNode;
				node->m_leftNode = nullptr;
				std::cout << "Node deleted.\n";				
			}
			else if (nodeLeft->m_value == value && (nodeLeft->m_leftNode != nullptr && nodeLeft->m_rightNode == nullptr))
			{
				std::cout << "Found. Deleting node " << value << "... \n";
				Node *temp = node->m_leftNode;
				node->m_leftNode = nodeLeft->m_leftNode;
				delete temp;
				std::cout << "Node deleted.\n";				
			}
			else if (nodeLeft->m_value == value && (nodeLeft->m_leftNode == nullptr && nodeLeft->m_rightNode != nullptr))
			{
				std::cout << "Found. Deleting node " << value << "... \n";
				Node *temp = node->m_leftNode;
				node->m_leftNode = nodeLeft->m_rightNode;
				delete temp;
				std::cout << "Node deleted.\n";				
			}
			else if (nodeLeft->m_value == value && (nodeLeft->m_leftNode != nullptr && nodeLeft->m_rightNode != nullptr))
			{				
				bool greaterThan = false;
				Node *toMove = FindSmallest(node->m_leftNode->m_rightNode->m_value, node->m_leftNode->m_rightNode);
				if (toMove->m_value < node->m_value)
				{
					greaterThan = false;
				}
				else
				{
					greaterThan = true;
				}
				node->m_value = toMove->m_value;
				if (greaterThan == true)
				{
					Remove(toMove->m_value, node->m_rightNode);					
				}
				else
				{
					Remove(toMove->m_value, node->m_leftNode);
				}
				
			}
			else
			{
				std::cout << "Recursing less than node on " << node->m_value << " into node " << nodeLeft->m_value << " ... \n";
				Remove(value, node->m_leftNode);
			}
		}
		else if (value > node->m_value)
		{
			if (value < node->m_value)
			{
				Node * nodeRight = node->m_rightNode;
				if (nodeRight->m_value == value && (nodeRight->m_leftNode == nullptr && nodeRight->m_rightNode == nullptr))
				{
					std::cout << "Found. Deleting node " << value << "... \n";
					delete node->m_rightNode;
					node->m_rightNode = nullptr;
					std::cout << "Node deleted.\n";
				}
				else if (nodeRight->m_value == value && (nodeRight->m_leftNode != nullptr && nodeRight->m_rightNode == nullptr))
				{
					std::cout << "Found. Deleting node " << value << "... \n";
					Node *temp = node->m_rightNode;
					node->m_rightNode = nodeRight->m_leftNode;
					delete temp;
					std::cout << "Node deleted.\n";
				}
				else if (nodeRight->m_value == value && (nodeRight->m_leftNode == nullptr && nodeRight->m_rightNode != nullptr))
				{
					std::cout << "Found. Deleting node " << value << "... \n";
					Node *temp = node->m_rightNode;
					node->m_rightNode = nodeRight->m_rightNode;
					delete temp;
					std::cout << "Node deleted.\n";
				}
				else if (nodeRight->m_value == value && (nodeRight->m_leftNode != nullptr && nodeRight->m_rightNode != nullptr))
				{
					int rightVal = node->m_rightNode->m_value;
					Node *rightLeftNode = node->m_rightNode->m_leftNode;
					Node *rightRightNode = node->m_rightNode->m_rightNode;
				}
			}
		}
		else
		{

		}

	}

	Node *m_root = nullptr;
};

int main()
{
	BinaryTree tree;
	tree.Insert(5, tree.m_root);
	tree.Insert(3, tree.m_root);
	tree.Insert(8, tree.m_root);
	tree.Insert(4, tree.m_root);
	tree.Insert(1, tree.m_root);
	tree.Insert(7, tree.m_root);

	//Node *findNode = tree.Find(8, tree.m_root);

	int numDel = 3;
	std::cout << "Program now deleting the node " << numDel << "...\n";
	tree.Remove(numDel, tree.m_root);

	/*int number = 8;
	std::cout << "Searching for " << number << "...\n";
	tree.Find(number, tree.m_root);*/

	/*
	tree.Insert(15, tree.m_root);
	tree.Insert(13, tree.m_root);
	tree.Insert(12, tree.m_root);
	tree.Insert(9, tree.m_root);
	tree.Insert(53, tree.m_root);
	tree.Insert(21, tree.m_root);

	int number = 12;
	std::cout << "Searching for " << number << "...\n";
	tree.Find(number, tree.m_root);*/


	system("PAUSE");
	return 0;
}


