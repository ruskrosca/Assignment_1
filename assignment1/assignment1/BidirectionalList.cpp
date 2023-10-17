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
	// ダミーノードを指すまで回す
	while (current != m_dummyNode)
	{
		Node* temp = current;
		current = current->m_next;
		// ノードの削除
		delete temp;
	}
	// ダミーノードの削除
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
* @return 挿入が成功した場合 true、 失敗した場合(不正なイテレータの場合) false
*/
bool BidirectionalList::Insert(Const_Iterator& ite, const Record& rec)
{
	// 不正なイテレータを除外
	if (ite.m_list != this) return false;

	if (!ite.m_node)
	{
		// 新しいノードの作成
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

	// イテレータの位置に新しいノードを挿入
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

	// 不正なイテレータ、ダミーノード, 異なるリストの要素を除外
	if (!nodeDelete || nodeDelete == m_dummyNode ||
		ite.m_list != this)
	{
		return false;
	}
	
	// 削除するノードの前後をつなげる
	nodeDelete->m_prev->m_next = nodeDelete->m_next;
	nodeDelete->m_next->m_prev = nodeDelete->m_prev;
	// ノード削除
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
	// リストが空じゃないか
	if (m_dummyNode->m_next != m_dummyNode)
	{
		// 先頭イテレータを返す
		return Iterator(m_dummyNode->m_next, this);
	}
	else
	{
		// 空の先頭イテレータを返す
		return Iterator(nullptr, this);
	}
}

/**
* @brief 先頭のconstイテレータを返す
* @return ConstIterato 先頭constイテレータ
*/
BidirectionalList::Const_Iterator BidirectionalList::ConstBegin() const
{
	// リストが空じゃないか
	if (m_dummyNode->m_next != m_dummyNode)
	{
		// 先頭constイテレータを返す
		return Const_Iterator(m_dummyNode->m_next, this);
	}
	else
	{
		// 空の先頭constイテレータを返す
		return Const_Iterator(nullptr, this);
	}
}

/**
* @brief 末尾イテレータを返す
* @return Iterator 末尾イテレータ
*/
BidirectionalList::Iterator BidirectionalList::End() const
{
	// リストが空じゃないか
	if (m_dummyNode->m_prev != m_dummyNode)
	{
		// 末尾イテレータを返す
		return Iterator(m_dummyNode, this);
	}
	else
	{
		// 空の末尾イテレータを返す
		return Iterator(nullptr, this);
	}
}

/**
* @brief 末尾のconstイテレータを返す
* @return ConstIterator 末尾constイテレータ
*/
BidirectionalList::Const_Iterator BidirectionalList::ConstEnd() const
{
	// リストが空じゃないか
	if (m_dummyNode->m_prev != m_dummyNode)
	{
		// 末尾constイテレータを返す
		return Const_Iterator(m_dummyNode, this);
	}
	else
	{
		// 空の末尾constイテレータを返す
		return Const_Iterator(nullptr, this);
	}
}