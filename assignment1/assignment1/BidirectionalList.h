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
		std::string score;     // スコア
		std::string userName;  // ユーザー名
	};

protected:
	struct Node
	{
		Record m_record;  // 成績データ
		Node* m_next;     // 次のノードへのポインタ
		Node* m_prev;     // 前のノードへのポインタ

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
		Const_Iterator& operator++() { m_node = m_node->m_next; return *this; }		// 後置			
		Const_Iterator& operator--() { m_node = m_node->m_prev; return *this; }		// 後置
		Const_Iterator operator++(int) { Const_Iterator temp = *this; ++(*this); return temp; }	// 前置
		Const_Iterator operator--(int) { Const_Iterator temp = *this; --(*this); return temp; }	// 前置
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

	int NumData() const;									// リスト内のデータ数を返す
	bool Insert(Const_Iterator& ite, const Record& rec);	// 指定位置にデータを挿入
	bool Delete(Const_Iterator& ite);						// 指定位置のデータを削除
	Iterator Begin();										// 先頭イテレータを返す
	Const_Iterator ConstBegin() const;						// 先頭のconstイテレータを返す
	Iterator End();											// 末尾イテレータを返す
	Const_Iterator ConstEnd() const;						// 末尾のconstイテレータを返す
};

#endif