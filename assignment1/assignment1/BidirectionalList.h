#ifndef ___BIDIRECTIONAL_LIST_H___
#define ___BIDIRECTIONAL_LIST_H___

#include <iostream>
#include <string>

using namespace std;

class BidirectionalList
{
public:
	// インナークラス
	class Inner
	{
	public:
		typedef struct Node		// ノード
		{
			typedef struct Record	// 成績データ
			{
				 string score;		// スコア
				 string userName;	// ユーザー名
			};
			Record m_record;		// 成績データ
			Node* m_next;		// 先頭のノードへのポインタ
			Node* m_prev;		// 末尾のノードへのポインタ
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

	int NumData();							// データ数を取得する関数
	bool Push(Iterator* ite);				// データの挿入
	bool Pop(Iterator* ite);			// データの削除
	Iterator Begin();				// 先頭イテレータの取得
	Const_Iterator ConstBegin();	// 先頭コンストイテレータの取得
	Iterator End();				// 末尾イテレータの取得
	Const_Iterator ConstEnd();	// 末尾コンストイテレータの取得

private:
	Inner* m_Inner;
	Const_Iterator* m_constIte;
};
#endif // !___BIDIRECTIONAL_LIST_H___

