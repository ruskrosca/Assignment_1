#include "BidirectionalList.h"

BidirectionalList::BidirectionalList()
{
	m_Inner = nullptr;
}

BidirectionalList::~BidirectionalList()
{
	
}

// データ数を取得する関数
int BidirectionalList::NumData()
{
    int count = 0;
    Iterator it = Begin(); // Iteratorを直接初期化する
	if (it == nullptr)
	{
		return count;
	}

    while (it != End())
    {
        count++;
        ++it;
    }

    return count;
}

// データの挿入
bool BidirectionalList::Push(BidirectionalList::Iterator * ite)
{
	if (ite && ite->m_node)
	{
		Inner::Node* newNode = new Inner::Node;
		newNode = ite->m_node;
		newNode->m_next = nullptr;

		if (!m_Inner || m_Inner->m_node)
		{
			newNode->m_prev = nullptr;
			m_Inner = new Inner;
			m_Inner->m_node = newNode;
		}
		else
		{
			// リストが空でない場合、新しいノードを指定した位置に挿入
			Inner::Node* current = m_Inner->m_node;
			while (current->m_next != nullptr && current != ite->m_node)
			{
				current = current->m_next;
			}

			// 新しいノードの前後のポインタを設定
			newNode->m_prev = current->m_prev;
			newNode->m_next = current;

			if (current->m_prev != nullptr)
			{
				current->m_prev->m_next = newNode;
			}
			else
			{
				// 挿入位置が先頭の場合
				m_Inner->m_node = newNode;
			}

			current->m_prev = newNode;
		}
	}
	else
	{
		return false;
	}
	return true;
}


// データの削除
bool BidirectionalList::Pop(BidirectionalList::Iterator * ite)
{
	// 削除するデータの情報を取得
	Inner::Node* nodeDelete = ite->m_node;
	if (nodeDelete == nullptr)
		return false;

	Inner::Node* prewNode = nodeDelete->m_prev;
	Inner::Node* nextNode = nodeDelete->m_next;

	if (prewNode != nullptr)
		prewNode->m_next = nextNode;
	if (nextNode != nullptr)
		nextNode->m_prev = prewNode;
	if (nodeDelete == m_Inner->m_node)
		m_Inner->m_node = nextNode;
	delete nodeDelete;
	return true;
}

// 先頭イテレータの取得
BidirectionalList::Iterator BidirectionalList::Begin()
{
	if (m_Inner && m_Inner->m_node)
	{
		return Iterator(m_Inner->m_node);
	}
	else
	{
		return Iterator(nullptr);
	}
}

// 先頭コンストイテレータの取得
BidirectionalList::Const_Iterator BidirectionalList::ConstBegin()
{
	if (m_Inner && m_Inner->m_node)
	{
		return Const_Iterator(m_Inner->m_node);
	}
	else
	{
		return Const_Iterator(nullptr);
	}
}

// 末尾イテレータの取得
BidirectionalList::Iterator BidirectionalList::End()
{
	Inner::Node* current = m_Inner->m_node;
	while (current != nullptr && current != nullptr)
	{
		current = current->m_next;
	}
	return Iterator(current);
}

// 末尾コンストイテレータの取得
BidirectionalList::Const_Iterator BidirectionalList::ConstEnd()
{
	Inner::Node* current = m_Inner->m_node;
	while (current != nullptr && current->m_next != nullptr)
	{
		current = current->m_next;
	}
	return Const_Iterator(current);
}


