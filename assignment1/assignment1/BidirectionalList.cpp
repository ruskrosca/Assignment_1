#include "BidirectionalList.h"

BidirectionalList::BidirectionalList()
{
	m_dummyNode = new Node(Record{ "", "" });
	m_dummyNode->m_next = m_dummyNode;
	m_dummyNode->m_prev = m_dummyNode;
	m_dataNum = 0;
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

int BidirectionalList::NumData() const
{
	return m_dataNum;
}

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
		m_dataNum++;
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
	m_dataNum++;
	return true;  
}

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
	m_dataNum--;
	return true;
}

BidirectionalList::Iterator BidirectionalList::Begin()
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

BidirectionalList::Iterator BidirectionalList::End()
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