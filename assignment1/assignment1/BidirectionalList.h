/**********************************************************************************//**
	@file           BidirectionalList.h
	@brief          �o�������X�g�쐬
	@author			RyosukeNarsushima
*//***********************************************************************************/
#ifndef ___BIDIRECTIONAL_LIST_H___
#define ___BIDIRECTIONAL_LIST_H___

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class BidirectionalList
{
public:
	//! ���уf�[�^
	struct Record
	{
		//! �X�R�A
		std::string score;     
		//! ���[�U�[��
		std::string userName;  
	};

private:
	struct Node
	{
		// ���уf�[�^
		Record m_record; 
		// ���̃m�[�h�ւ̃|�C���^
		Node* m_next;   
		// �O�̃m�[�h�ւ̃|�C���^
		Node* m_prev;     

		Node(const Record& rec) : m_record(rec), m_next(nullptr), m_prev(nullptr) {}
	};

	Node* m_dummyNode;
	int m_size;

public:
	class Const_Iterator
	{
	public:
		Node* m_node;

		Const_Iterator(Node* node) : m_node(node) {}
		Const_Iterator& operator++()  { m_node = m_node->m_next; return *this; }		// �O�u			
		Const_Iterator& operator--()  { m_node = m_node->m_prev; return *this; }		// �O�u
		Const_Iterator& operator++(int) { Const_Iterator temp = *this; ++(*this); return temp; }	// ��u
		Const_Iterator& operator--(int) { Const_Iterator temp = *this; --(*this); return temp; }	// ��u
		Record& operator*() const{
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

	/**
	* @fn int GetSize
	* @brief ���X�g�̃T�C�Y��Ԃ�
	* @details const���\�b�h
	*/
	int GetSize() const;


	/**
	* @fn bool Insert
	* @brief �C�e���[�^�Ŏw�肳�ꂽ�ʒu�Ƀf�[�^��}��
	* @param[in]  �C�e���[�^, ���я��
	* @param[out] �}���ŗ������ǂ���
	* @return bool �}������
	*/
	bool Insert(Const_Iterator& ite, const Record& rec);


	/**
	* @fn bool Delete
	* @brief �C�e���[�^�Ŏw��ʒu�̃f�[�^���폜
	* @param[in]  �C�e���[�^
	* @param[out] �폜�ŗ������ǂ���
	* @return bool �폜����
	*/
	bool Delete(Const_Iterator& ite);		


	/**
	* @fn Iterator Begi
	* @brief �擪�C�e���[�^��Ԃ�
	* @param[out] �擪�C�e���[�^
	* @return Iterator �擪�C�e���[�^
	* @details const���\�b�h
	*/
	Iterator Begin() const;	


	/**
	* @fn Iterator Begi
	* @brief �擪��const�C�e���[�^��Ԃ�
	* @param[out] �擪const�C�e���[�^
	* @return ConstIterato �擪const�C�e���[�^
	* @details const���\�b�h
	*/
	Const_Iterator ConstBegin() const;	


	/**
	* @fn Iterator Begi
	* @brief �����C�e���[�^��Ԃ�
	* @param[out] �����C�e���[�^
	* @return Iterator �����C�e���[�^
	* @details const���\�b�h
	*/
	Iterator End() const;


	/**
	* @fn Iterator Begi
	* @brief �擪��const�C�e���[�^��Ԃ�
	* @param[out] ����const�C�e���[�^
	* @return ConstIterator ����const�C�e���[�^
	* @details const���\�b�h
	*/
	Const_Iterator ConstEnd() const;					
};

#endif