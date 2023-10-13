/**********************************************************************************//**
	@file           BidirectionalList.cpp
	@brief          �o�������X�g�쐬
	@author			RyosukeNarsushima
*//***********************************************************************************/
#include "BidirectionalList.h"

BidirectionalList::BidirectionalList()
{
	m_dummyNode = new Node(Record{ "", "" });
	m_dummyNode->m_next = m_dummyNode;
	m_dummyNode->m_prev = m_dummyNode;
	m_size = 0;
}

BidirectionalList::~BidirectionalList()
{
	Node* current = m_dummyNode->m_next;
	while (current != m_dummyNode)
	{
		Node* temp = current;
		current = current->m_next;
		delete temp;
	}
	delete m_dummyNode;
}

/**
* @fn int GetSize
* @brief ���X�g�̃T�C�Y��Ԃ�
* @details const���\�b�h
*/
int BidirectionalList::GetSize() const
{
	return m_size;
}

/**
* @fn bool Insert
* @brief �C�e���[�^�Ŏw�肳�ꂽ�ʒu�Ƀf�[�^��}��
* @param[in]  �C�e���[�^, ���я��
* @param[out] �}���ŗ������ǂ���
* @return bool �}������
*/
bool BidirectionalList::Insert(Const_Iterator& ite, const Record& rec)
{
	if (!ite.m_node)
	{
		Node* newNode = new Node(rec);
		newNode->m_next = m_dummyNode->m_next;
		newNode->m_prev = m_dummyNode;
		if (m_dummyNode->m_next) {
			m_dummyNode->m_next->m_prev = newNode;
		}
		m_dummyNode->m_next = newNode;
		m_size++;
		return true; 
	}

	Node* currentNode = ite.m_node;
	Node* newNode = new Node(rec);

	newNode->m_next = currentNode;
	newNode->m_prev = currentNode->m_prev;

	if (currentNode->m_prev)
	{
		currentNode->m_prev->m_next = newNode;
	}
	else
	{
		m_dummyNode->m_next = newNode;
	}

	currentNode->m_prev = newNode;
	m_size++;

	return true;  
}

/**
* @fn bool Delete
* @brief �C�e���[�^�Ŏw��ʒu�̃f�[�^���폜
* @param[in]  �C�e���[�^
* @param[out] �폜�ŗ������ǂ���
* @return bool �폜����
*/
bool BidirectionalList::Delete(Const_Iterator& ite)
{
	Node* nodeDelete = ite.m_node;

	if (!nodeDelete || nodeDelete == m_dummyNode)
	{
		return false;
	}

	nodeDelete->m_prev->m_next = nodeDelete->m_next;
	nodeDelete->m_next->m_prev = nodeDelete->m_prev;
	delete nodeDelete;
	m_size--;
	return true;
}

/**
* @fn Iterator Begie
* @brief �擪�C�e���[�^��Ԃ�
* @param[out] �擪�C�e���[�^
* @return bool �擪�C�e���[�^
* @details const���\�b�h
*/
BidirectionalList::Iterator BidirectionalList::Begin() const
{
	if (m_dummyNode->m_next != m_dummyNode)
	{
		return Iterator(m_dummyNode->m_next);
	}
	else
	{
		return Iterator(nullptr);
	}
}

/**
* @fn Const_Iterator�@ConstBegin
* @brief �擪��const�C�e���[�^��Ԃ�
* @param[out] �擪const�C�e���[�^
* @return ConstIterato �擪const�C�e���[�^
* @details const���\�b�h
*/
BidirectionalList::Const_Iterator BidirectionalList::ConstBegin() const
{
	if (m_dummyNode->m_next != m_dummyNode)
	{
		return Const_Iterator(m_dummyNode->m_next);
	}
	else
	{
		return Const_Iterator(nullptr);
	}
}

/**
* @fn Iterator End
* @brief �����C�e���[�^��Ԃ�
* @param[out] �����C�e���[�^
* @return Iterator �����C�e���[�^
* @details const���\�b�h
*/
BidirectionalList::Iterator BidirectionalList::End() const
{
	if (m_dummyNode->m_prev != m_dummyNode)
	{
		return Iterator(m_dummyNode);
	}
	else
	{
		return Iterator(nullptr);
	}
}

/**
* @fn Const_Iterator ConstEnd
* @brief ������const�C�e���[�^��Ԃ�
* @param[out] ����const�C�e���[�^
* @return ConstIterator ����const�C�e���[�^
* @details const���\�b�h
*/
BidirectionalList::Const_Iterator BidirectionalList::ConstEnd() const
{
	if (m_dummyNode->m_prev != m_dummyNode)
	{
		return Const_Iterator(m_dummyNode);
	}
	else
	{
		return Const_Iterator(nullptr);
	}
}