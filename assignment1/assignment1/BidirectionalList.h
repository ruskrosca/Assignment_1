#ifndef ___BIDIRECTIONAL_LIST_H___
#define ___BIDIRECTIONAL_LIST_H___

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class BidirectionalList
{
public:
	struct Record
	{
		std::string score;     // �X�R�A
		std::string userName;  // ���[�U�[��
	};

protected:
	struct Node
	{
		Record m_record;  // ���уf�[�^
		Node* m_next;     // ���̃m�[�h�ւ̃|�C���^
		Node* m_prev;     // �O�̃m�[�h�ւ̃|�C���^

		Node(const Record& rec) : m_record(rec), m_next(nullptr), m_prev(nullptr) {}
	};

	Node* m_dummyNode;
	int m_dataNum;

public:
	class Const_Iterator
	{
	public:
		Node* m_node;

		Const_Iterator(Node* node) : m_node(node) {}
		Const_Iterator& operator++() { m_node = m_node->m_next; return *this; }		// ��u			
		Const_Iterator& operator--() { m_node = m_node->m_prev; return *this; }		// ��u
		Const_Iterator operator++(int) { Const_Iterator temp = *this; ++(*this); return temp; }	// �O�u
		Const_Iterator operator--(int) { Const_Iterator temp = *this; --(*this); return temp; }	// �O�u
		const Record& operator*() {
			assert(m_node != nullptr);
			return m_node->m_record;
		}
		bool operator==(const Const_Iterator& ite) const { return m_node == ite.m_node; }
		bool operator!=(const Const_Iterator& ite) const { return m_node != ite.m_node; }
	};

	class Iterator : public Const_Iterator
	{
	public:
		Iterator(Node* node) : Const_Iterator(node) {}
		Record& operator*() { 
			assert(m_node != nullptr);
			return m_node->m_record; }
	};

	BidirectionalList();
	~BidirectionalList();

	int NumData() const;									// ���X�g���̃f�[�^����Ԃ�
	bool Insert(Const_Iterator& ite, const Record& rec);	// �w��ʒu�Ƀf�[�^��}��
	bool Delete(Const_Iterator& ite);						// �w��ʒu�̃f�[�^���폜
	Iterator Begin();										// �擪�C�e���[�^��Ԃ�
	Const_Iterator ConstBegin() const;						// �擪��const�C�e���[�^��Ԃ�
	Iterator End();											// �����C�e���[�^��Ԃ�
	Const_Iterator ConstEnd() const;						// ������const�C�e���[�^��Ԃ�
};

#endif