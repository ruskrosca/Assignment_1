#ifndef ___BIDIRECTIONAL_LIST_H___
#define ___BIDIRECTIONAL_LIST_H___

#include <iostream>
#include <string>

using namespace std;

class BidirectionalList
{
public:
	// �C���i�[�N���X
	class Inner
	{
	public:
		typedef struct Node		// �m�[�h
		{
			typedef struct Record	// ���уf�[�^
			{
				 string score;		// �X�R�A
				 string userName;	// ���[�U�[��
			};
			Record m_record;		// ���уf�[�^
			Node* m_next;		// �擪�̃m�[�h�ւ̃|�C���^
			Node* m_prev;		// �����̃m�[�h�ւ̃|�C���^
		};
		Node* m_node;
	public:
		Inner()
		{
			m_node = nullptr;
		}

		Inner(Node::Record &record)
		{
			m_node = new Node;
			m_node->m_prev = nullptr;
			m_node->m_next = nullptr;
			m_node->m_record.score = record.score;
			m_node->m_record.userName = record.userName;
		}

		~Inner()
		{
			delete m_node;
		}
	};

	class Const_Iterator
	{

	public:
		Inner::Node* m_node;
		Const_Iterator(Inner::Node* node) : m_node(node) {}
		Const_Iterator& operator++() { m_node = m_node->m_next; return *this; }
		Const_Iterator& operator--() { m_node = m_node->m_prev; return *this; }
		const Inner::Node::Record& operator*() { return m_node->m_record; }
		Const_Iterator& operator=(const Const_Iterator& ite)
		{
			if (this != &ite)
			{
				m_node = ite.m_node;
			}
			return *this;
		}
		bool operator==(const Const_Iterator & ite) const { return m_node == ite.m_node; }
		bool operator!=(const Const_Iterator & ite) const { return m_node != ite.m_node; }		
	};

	class Iterator : public Const_Iterator
	{
	public:
		Inner::Node* m_node;
		Iterator(Inner::Node* node) : Const_Iterator(node), m_node(node) {}
		Inner::Node::Record& operator*() { return  m_node->m_record; }
	};

	

public:
	BidirectionalList();
	~BidirectionalList();

	int NumData();							// �f�[�^�����擾����֐�
	bool Push(Iterator* ite);				// �f�[�^�̑}��
	bool Pop(Iterator* ite);			// �f�[�^�̍폜
	Iterator Begin();				// �擪�C�e���[�^�̎擾
	Const_Iterator ConstBegin();	// �擪�R���X�g�C�e���[�^�̎擾
	Iterator End();				// �����C�e���[�^�̎擾
	Const_Iterator ConstEnd();	// �����R���X�g�C�e���[�^�̎擾

private:
	Inner* m_Inner;
	Const_Iterator* m_constIte;
};
#endif // !___BIDIRECTIONAL_LIST_H___

