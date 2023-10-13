/**********************************************************************************//**
	@file           BidirectionalList.h
	@brief          双方向リスト作成
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
	//! 成績データ
	struct Record
	{
		//! スコア
		std::string score;     
		//! ユーザー名
		std::string userName;  
	};

private:
	struct Node
	{
		// 成績データ
		Record m_record; 
		// 次のノードへのポインタ
		Node* m_next;   
		// 前のノードへのポインタ
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
		Const_Iterator& operator++()  { m_node = m_node->m_next; return *this; }		// 前置			
		Const_Iterator& operator--()  { m_node = m_node->m_prev; return *this; }		// 前置
		Const_Iterator& operator++(int) { Const_Iterator temp = *this; ++(*this); return temp; }	// 後置
		Const_Iterator& operator--(int) { Const_Iterator temp = *this; --(*this); return temp; }	// 後置
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
	* @brief リストのサイズを返す
	* @details constメソッド
	*/
	int GetSize() const;


	/**
	* @fn bool Insert
	* @brief イテレータで指定された位置にデータを挿入
	* @param[in]  イテレータ, 成績情報
	* @param[out] 挿入で来たかどうか
	* @return bool 挿入結果
	*/
	bool Insert(Const_Iterator& ite, const Record& rec);


	/**
	* @fn bool Delete
	* @brief イテレータで指定位置のデータを削除
	* @param[in]  イテレータ
	* @param[out] 削除で来たかどうか
	* @return bool 削除結果
	*/
	bool Delete(Const_Iterator& ite);		


	/**
	* @fn Iterator Begi
	* @brief 先頭イテレータを返す
	* @param[out] 先頭イテレータ
	* @return Iterator 先頭イテレータ
	* @details constメソッド
	*/
	Iterator Begin() const;	


	/**
	* @fn Iterator Begi
	* @brief 先頭のconstイテレータを返す
	* @param[out] 先頭constイテレータ
	* @return ConstIterato 先頭constイテレータ
	* @details constメソッド
	*/
	Const_Iterator ConstBegin() const;	


	/**
	* @fn Iterator Begi
	* @brief 末尾イテレータを返す
	* @param[out] 末尾イテレータ
	* @return Iterator 末尾イテレータ
	* @details constメソッド
	*/
	Iterator End() const;


	/**
	* @fn Iterator Begi
	* @brief 先頭のconstイテレータを返す
	* @param[out] 末尾constイテレータ
	* @return ConstIterator 末尾constイテレータ
	* @details constメソッド
	*/
	Const_Iterator ConstEnd() const;					
};

#endif