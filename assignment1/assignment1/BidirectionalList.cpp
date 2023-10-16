/**********************************************************************************//**
	@file           BidirectionalList.cpp
	@brief          双方向リスト作成
	@author			RyosukeNarsushima
*//***********************************************************************************/
#include "BidirectionalList.h"

/**
* @brief デフォルトコンストラクタ
*/
BidirectionalList::BidirectionalList()
{
	m_dummyNode = new Node(Record{ "", "" });
	m_dummyNode->m_next = m_dummyNode;
	m_dummyNode->m_prev = m_dummyNode;
	m_size = 0;
}

/**
* @brief デストラクタ
*/
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
* @brief リストのサイズを返す
	* @return int リストのサイズ
*/
int BidirectionalList::GetSize() const
{
	return m_size;
}

/**
* @brief イテレータで指定された位置にデータを挿入
* @param ite 挿入する位置を指定したイテレータ
* @param rec 成績情報
* @param score スコア
* @param userName ユーザー名
* @return 挿入が成功した場合 true、 失敗した場合 false
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
* @brief イテレータで指定位置のデータを削除
* @param[in]  削除する位置を指定したイテレータ
* @return 削除が成功した場合 true、 無効なイテレータ、ダミーノード場合 false
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
* @brief 先頭イテレータを返す
* @return bool 先頭イテレータ
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
* @brief 先頭のconstイテレータを返す
* @return ConstIterato 先頭constイテレータ
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
* @brief 末尾イテレータを返す
* @return Iterator 末尾イテレータ
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
* @brief 末尾のconstイテレータを返す
* @return ConstIterator 末尾constイテレータ
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