/**********************************************************************************//**
	@file           BidirectionalList.inl
	@brief          双方向リスト作成
	@author			RyosukeNarsushima
*//***********************************************************************************/
#include "BidirectionalList.h"

/**
* @brief コンストラクタ
*/
template<typename T>
inline BidirectionalList<T>::Node::Node()
	: m_data(), m_next(nullptr), m_prev(nullptr){}

/**
* @brief 引数付きコンストラクタ
* @param data データ
*/
template<typename T>
inline BidirectionalList<T>::Node::Node(const T & data)
	: m_data(data), m_next(nullptr), m_prev(nullptr){}

/**
* @brief デフォルトコンストラクタ
*/
template<typename T>
inline BidirectionalList<T>::Const_Iterator::Const_Iterator()
	: m_node(nullptr), m_list(nullptr) {}

/**
* @brief 引数付きコンストラクタ
* @param node ノードを指定するポインタ
* @param list イテレータの所属しているリストの情報
*/
template<typename T>
inline BidirectionalList<T>::Const_Iterator::Const_Iterator(Node * node, const BidirectionalList * list)
	: m_node(node), m_list(list) {}

/**
* @brief 前置インクリメント演算子
* @return 更新後のイテレータへの参照
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator & BidirectionalList<T>::Const_Iterator::operator++()
{
	assert(m_node != nullptr);
	m_node = m_node->m_next;
	return *this;
}

/**
* @brief 前置デクリメント演算子
* @return 更新後のイテレータへの参照
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator & BidirectionalList<T>::Const_Iterator::operator--()
{
	assert(m_node != nullptr);
	m_node = m_node->m_prev;
	return *this;
}

/**
* @brief 後置インクリメント演算子
* @return 更新前のイテレータへの参照
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::Const_Iterator::operator++(int)
{
	assert(m_node != nullptr);
	Const_Iterator temp = *this;
	++(*this);
	return temp;
}

/**
* @brief 後置デクリメント演算子
* @return 更新前のイテレータへの参照
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::Const_Iterator::operator--(int)
{
	assert(m_node != nullptr);
	Const_Iterator temp = *this;
	--(*this);
	return temp;
}

/**
* @brief デリファレンス演算子
* @return  成績データの参照
*/
template<typename T>
inline const T & BidirectionalList<T>::Const_Iterator::operator*() const
{
	assert(m_node != nullptr);
	return m_node->m_data;
}

/**
* @brief 2つの Const_Iterator イテレータを比較する
* @param ite 比較対象の Const_Iterator
* @return 2つのイテレータが同じ要素を指している場合に true を返す
*/
template<typename T>
inline bool BidirectionalList<T>::Const_Iterator::operator==(const Const_Iterator & ite) const
{
	return m_node == ite.m_node;
}

/**
* @brief 2つの Const_Iterator イテレータを比較する
* @param ite 比較対象の Const_Iterator
* @return 2つのイテレータが異なる要素を指している場合に true を返す
*/
template<typename T>
inline bool BidirectionalList<T>::Const_Iterator::operator!=(const Const_Iterator & ite) const
{
	return m_node != ite.m_node;
}

/**
* @brief デフォルトコンストラクタ
*/
template<typename T>
inline BidirectionalList<T>::Iterator::Iterator()
	: Const_Iterator(){}

/**
* @brief 引数付きコンストラクタ
* @param node ノードを指定するポインタ
* @param list イテレータの所属しているリストの情報
*/
template<typename T>
inline BidirectionalList<T>::Iterator::Iterator(Node * node, const BidirectionalList * list)
	: Const_Iterator(node, list) {}

/**
* @brief デリファレンス演算子
* @return m_node->m_data 成績データの参照
*/
template<typename T>
inline T & BidirectionalList<T>::Iterator::operator*()
{
	assert(Const_Iterator::m_node != nullptr);
	return Const_Iterator::m_node->m_data;
}


/**
* @brief デフォルトコンストラクタ
*/
template<typename T>
inline BidirectionalList<T>::BidirectionalList()
{
	m_dummyNode = new Node();
	m_dummyNode->m_next = m_dummyNode;
	m_dummyNode->m_prev = m_dummyNode;
	m_size = 0;
}


/**
* @brief デストラクタ
*/
template<typename T>
inline BidirectionalList<T>::~BidirectionalList()
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
template<typename T>
inline int BidirectionalList<T>::GetSize() const
{
	return m_size;
}

/**
* @brief イテレータで指定された位置にデータを挿入
* @param ite 挿入する位置を指定したイテレータ
* @param data データ
、 失敗した場合(不正なイテレータの場合) false
*/
template<typename T>
inline bool BidirectionalList<T>::Insert(Const_Iterator & ite, const T & data)
{
	// 不正なイテレータを除外
	if (ite.m_list != this) return false;

	Node* newNode = new Node(data);

	// 空イテレータかどうかを確認
	// 空ならダミーノードを、普通ならite.nodeを挿入
	newNode->m_next = (ite.m_node != nullptr) ? ite.m_node : m_dummyNode->m_next;
	newNode->m_prev = (ite.m_node != nullptr) ? ite.m_node->m_prev : m_dummyNode;


	if (newNode->m_next)
	{
		newNode->m_next->m_prev = newNode;
	}
	// 前にノードがあるか
	if (newNode->m_prev)
	{
		// 次のノードを新しいノードに設定する
		newNode->m_prev->m_next = newNode;
	}
	else
	{
		// ダミーノードの次を新しいノードに設定する
		m_dummyNode->m_next = newNode;
	}

	m_size++;
	return true;
}

/**
* @brief イテレータで指定位置のデータを削除
* @param[in]  削除する位置を指定したイテレータ
* @return 削除が成功した場合 true、 無効なイテレータ、ダミーノード場合 false
*/
template<typename T>
inline bool BidirectionalList<T>::Delete(Const_Iterator & ite)
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
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::Begin() const
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
* @brief 先頭イテレータを返す
* @return Iterator 先頭イテレータ
*/
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::begin() const
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
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::ConstBegin() const
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
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::End() const
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
* @brief 末尾イテレータを返す
* @return Iterator 末尾イテレータ
* `
*/
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::end() const
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
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::ConstEnd() const
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