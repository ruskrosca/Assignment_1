/**********************************************************************************//**
	@file           BidirectionalList.cpp
	@brief          双方向リスト作成
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
* @brief リストのサイズを返す
* @details constメソッド
*/
int BidirectionalList::GetSize() const
{
	return m_size;
}

/**
* @fn bool Insert
* @brief イテレータで指定された位置にデータを挿入
* @param[in]  イテレータ, 成績情報
* @param[out] 挿入で来たかどうか
* @return bool 挿入結果
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
* @brief イテレータで指定位置のデータを削除
* @param[in]  イテレータ
* @param[out] 削除で来たかどうか
* @return bool 削除結果
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
* @brief 先頭イテレータを返す
* @param[out] 先頭イテレータ
* @return bool 先頭イテレータ
* @details constメソッド
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
* @fn Const_Iterator　ConstBegin
* @brief 先頭のconstイテレータを返す
* @param[out] 先頭constイテレータ
* @return ConstIterato 先頭constイテレータ
* @details constメソッド
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
* @brief 末尾イテレータを返す
* @param[out] 末尾イテレータ
* @return Iterator 末尾イテレータ
* @details constメソッド
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
* @brief 末尾のconstイテレータを返す
* @param[out] 末尾constイテレータ
* @return ConstIterator 末尾constイテレータ
* @details constメソッド
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