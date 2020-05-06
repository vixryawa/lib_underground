#pragma once
#include<iostream>
using namespace std;

#include"TNode.h"
#include"CasStation.h"

template <class T>
class TTree {
public:
	TNode<T>* Root;

	TTree() : Root(0) {}

	~TTree() {
		DestroyNode(Root);
	}

	static void DestroyNode(TNode<T>* node) {
		if (node) {
			if (!node->leftThread)
				DestroyNode(node->Left);
			if (!node->rightThread)
				DestroyNode(node->Right);
			delete node;
		}
	}

	void Insert(T x);
	void print_tree_();
	void print_tree(TNode<T>* p, int level);
	void find_neighbours(T x);
	TNode<T>* Search(T x, TNode<T>* p);
	TNode<T>* Search_(T x);


};


//������� ������ ����
template <class T>
void TTree<T>::Insert(T x) {
	// ��������� �� �� �����,
	// ���� ����� �������� ����� ����
	TNode<T>** cur = &Root;
	// ����, ����� ����� � ������������ �����
	TNode<T>* l_neighbour = nullptr;
	// ����, ����� ����� � ������������ ������
	TNode<T>* r_neighbour = nullptr;

	while (true) {
		// ���� *cur==nullptr, �� ���� ���������
		// �������� � ���� � ��������.
		if (*cur == nullptr) {
			// ������ ����� ����
			*cur = new TNode<T>(x);
			// ������ ��� ���� �������� � ������
			// �� ������, ���� ������ ��� ������� �� ������
			// ���� ������� ���� � �������� (��� �����)
			// ��� �������� (��� ������) ����������.
			if (l_neighbour != nullptr) {
				(*cur)->leftThread = true;
				(*cur)->Left = l_neighbour;
				// ���� � ����� ������ ���� ��������,
				// ���� ��������� � �� ������� ����
				if (l_neighbour->rightThread) {
					l_neighbour->Right = (*cur);
				}
			}
			if (r_neighbour != nullptr) {
				(*cur)->rightThread = true;
				(*cur)->Right = r_neighbour;
				if (r_neighbour->leftThread) {
					r_neighbour->Left = (*cur);
				}
			}
			return; // ������� ���������
		}

		// *curr!=nullptr, �.�. ������ �� � ����;
		// ���� ��� ���� ��������� � �����, �� �������
		if ((*cur)->Key == x)
			return; // ��������� ������ �� �����

		// ���� ���������, � ����� ��������� ������� ���������
		// ���� �����; ��� ���� ���� ������, ��� ���������
		// left � right ����� ���� ����������.
		if (x < (*cur)->Key) { // ���� ����� ���� ������ ��������,
			// �������� � ����� ����������.
			if ((*cur)->leftThread) {
				// ���� ����� --- ��������,
				// �� *cur --- ���� ������, � (*cur)->Left ---
				// ��� ����, ������� ������ x, �.�. ����� l_neighbour:
				l_neighbour = (*cur)->Left;
				r_neighbour = (*cur); // ������ ��� x ����� l_neighbour � cur
				(*cur)->leftThread = false; // ������ ��� �� ��������
				(*cur)->Left = nullptr; // ����� �� ��������� �������� ��������� �������
				cur = &((*cur)->Left); // ��������� � ��������� ��������
			}
			else {
				// ����� --- ����������, �� ��������. ����� ���������
				// �� ���, ����� ��� ���� r_neighbour
				r_neighbour = *cur;
				cur = &((*cur)->Left);
			}
		}
		else { // � ������ �� ��������� �����������
			if ((*cur)->rightThread) {
				r_neighbour = (*cur)->Right;
				l_neighbour = (*cur);
				(*cur)->rightThread = false;
				(*cur)->Right = nullptr;
				cur = &((*cur)->Right);
			}
			else {
				l_neighbour = *cur;
				cur = &((*cur)->Right);
			}
		}
	}
}


template <class T>
void TTree<T>::print_tree_() {
	print_tree(Root, 0);
}

template <class T>
void TTree<T>::print_tree(TNode<T>* p, int level) {
	if (p) {
		if (!p->leftThread)
			TTree<T>::print_tree(p->Left, level + 1);
		for (int i = 0; i < level; i++) printf("     ");
		cout << p->Key << endl;
		if (!p->rightThread)
			TTree<T>::print_tree(p->Right, level + 1);
	}
}

template <class T>
TNode<T>* TTree<T>::Search_(T x) {
	return Search(x, Root);
}

//!������� ������ ������� � ������
template <class T>
TNode<T>* TTree<T>::Search(T x, TNode<T>* p) {
	if ((p->Key == x) || (p == nullptr)) {  //!���� �����, �� ���������� ������ ����
		//cout << p->Key << endl;
		return p;
	}
	if ((x < p->Key) && (p->leftThread == false)) //! ���� �������� ������, �� �������� ����� � ����� ��������� 
		return TTree<T>::Search(x, p->Left);
	if ((x > p->Key) && (p->rightThread == false))				//! ���� �������� ������, �� �������� ����� � ������ ��������� 
		return TTree<T>::Search(x, p->Right);
}

//������� ������ ��������� �������
template <class T>
void TTree<T>::find_neighbours(T x) {
	TNode<T>* p = Search(x, Root); //������� ������ ���� ������������� ������ �������
	cout << "Staions closest to the station " << p->Key;
	cout << " are " << (p->Left)->Key;
	cout << " and " << (p->Right)->Key << endl;
	//	printf("Mins away: %i %i\n", ((p->Left)->Key).get_upper(), x.get_upper());
	//	cout << "Mins away: " << ((p->Left)->Key).get_upper() << " " << (p->Key).get_upper() << endl;
}