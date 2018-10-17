#include "BST.h"
#include<stdlib.h>
#include<iostream>

using namespace std;


Node::Node() {
	left = NULL;
	right = NULL;
}
Node::Node(int x) {
	data = x;
	left = NULL;
	right = NULL;
}

BST::BST() {
	root = NULL;
}

int BST::insert(int x) {
	Node* currNode = root;
	Node* r = root;
	while (currNode) {
		r = currNode;
		if (x < currNode->data)
			currNode = currNode->left;
		else
			currNode = currNode->right;
		
	}

	if(!r)
		root = new Node(x);
	else {
		currNode = new Node(x);
		if (x < r->data)
			r->left = currNode;
		else
			r->right = currNode;
	}
	

	cout << x << " node added" << endl;

	return 1;

}
void BST::print() {
	cout << "current tree\n";

	print__private(root);
}

void BST::print__private(Node* node) {
	if (node) {
		cout << node->data << endl;
		print__private(node->left);
		print__private(node->right);
	}
}

Node* BST::findNode(int x) {
	Node* currNode = root;

	while (currNode) {
		if (x == currNode->data)
			break;

		if (x < currNode->data)
			currNode = currNode->left;
		else
			currNode = currNode->right;
	}
	if (!currNode) 
		cout << x << " node is not found" << endl;
	else
		cout << x << " node is found" << endl;

	return currNode;
}

Node* BST::findMax() {
	return findMax__private(root);
}
Node* BST::findMax__private(Node* node) {
	
	while (node)
		node = node->right;

	return node;
}
/*
void BST::deleteNode(int x) {
	Node* currNode = root;
	Node* r = root;

	while (currNode) {
		if (x == currNode->data)
			break;
		else if (x < currNode->data) {
			r = currNode;
			currNode = currNode->left;
		}
		else {
			r = currNode;
			currNode = currNode->right;
		}
	}

	if (!currNode) {
		cout << "Node is there to be deleted" << endl;
	}
	else if (currNode->left && currNode->right) {
		Node* maxLeft = currNode->left;
		Node* maxLeftRoot = currNode;

		while (maxLeft->right) {
			maxLeftRoot = maxLeft;
			maxLeft = maxLeft->right;
		}
		maxLeftRoot->right = NULL;
		Node* temp = currNode;
		maxLeft->left = currNode->left;
		maxLeft->right = currNode->right;
		
		if (x < r->data) {
			r->left = maxLeft;
		}
		else {
			r->right = maxLeft;
		}

	}
	else if (currNode->left) {
		if (x < r->data)
			r->left = currNode->left;
		else
			r->right = currNode->left;
		delete currNode;
	}
	else if (currNode->right) {
		cout << "delete 1 child right " << endl;
		if (x < r->data)
			r->left = currNode->right;
		else
			r->right = currNode->right;

		delete currNode;
	}
	else {
		if (x < r->data)
			r->left = NULL;
		else
			r->right = NULL;

		delete currNode;
	}

}*/