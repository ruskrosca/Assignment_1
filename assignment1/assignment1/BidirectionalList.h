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

/**
* @brief 双方向リストクラス
*/
class BidirectionalList
{
public:
	/**
	* @brief 成績データ
	*/
	struct Record
	{
		//! スコア
		std::string score;     
		//! ユーザー名
		std::string userName;  
	};

private:
	/**
	* @brief リスト内の要素
	*/
	struct Node
	{
		//! 成績データ
		Record m_record; 
		//! 次のノードへのポインタ
		Node* m_next;   
		//! 前のノードへのポインタ
		Node* m_prev;     

		explicit Node(const Record& rec) : m_record(rec), m_next(nullptr), m_prev(nullptr) {}
	};

	//! ダミーノード
	Node* m_dummyNode;

	//! 要素数のカウント用変数
	int m_size;

public:
	/**
	* @brief 双方向リストの要素にアクセスするイテレータクラス
	*/
	class Const_Iterator
	{
	public:
		//! ノードを示すポインタ
		Node* m_node;

		/**
		* @brief デフォルトコンストラクタ
		*/
		Const_Iterator() : m_node(nullptr) {}

		/**
		* @brief 引数付きコンストラクタ
		* @param node ノードを指定するポインタ
		*/
		Const_Iterator(Node* node) : m_node(node) {}

		/**
		* @brief 前置インクリメント演算子
		* @return 更新後のイテレータへの参照
		*/
		Const_Iterator& operator++()  { 
			assert(m_node != nullptr);
			m_node = m_node->m_next;
			return *this;
		}

		/**
		* @brief 前置デクリメント演算子
		* @return 更新後のイテレータへの参照
		*/
		Const_Iterator& operator--()  { 
			assert(m_node != nullptr);
			m_node = m_node->m_prev;
			return *this;
		}

		/**
		* @brief 後置インクリメント演算子
		* @return 更新前のイテレータへの参照
		*/
		Const_Iterator operator++(int) {
			assert(m_node != nullptr);
			Const_Iterator temp = *this;
			++(*this);
			return temp;
		}

		/**
		* @brief 後置インクリメント演算子
		* @return 更新前のイテレータへの参照
		*/
		Const_Iterator operator--(int) { 
			assert(m_node != nullptr);
			Const_Iterator temp = *this;
			--(*this);
			return temp; 
		}

		/**
		* @brief デリファレンス演算子
		* @return  成績データの参照
		*/
		const Record& operator*() {
			assert(m_node != nullptr);
			return m_node->m_record;
		}
		/**
		 * @brief 2つの Const_Iterator イテレータを比較する
		 * @param ite 比較対象の Const_Iterator
		 * @return 2つのイテレータが同じ要素を指している場合に true を返す
		 */
		bool operator==(const Const_Iterator& ite) const { return m_node == ite.m_node; }

		/**
		* @brief 2つの Const_Iterator イテレータを比較する
		* @param ite 比較対象の Const_Iterator
		* @return 2つのイテレータが異なる要素を指している場合に true を返す
		*/
		bool operator!=(const Const_Iterator& ite) const { return m_node != ite.m_node; }
	};

	/**
	* @brief Const_Iteratorを継承したIteratorクラス
	*/
	class Iterator : public Const_Iterator
	{
	public:
		/**
		* @brief デフォルトコンストラクタ
		*/
		Iterator() : Const_Iterator(nullptr) {}

		/**
		* @brief 引数付きコンストラクタ
		* @param node ノードを指定するポインタ
		*/
		Iterator(Node* node) : Const_Iterator(node) {}

		/**
		* @brief デリファレンス演算子
		* @return m_node->m_record 成績データの参照
		*/
		Record& operator*() { 
			assert(m_node != nullptr);
			return m_node->m_record; }
	};

	/**
	* @brief デフォルトコンストラクタ
	*/
	BidirectionalList();

	/**
	* @brief デストラクタ
	*/
	~BidirectionalList();

	/**
	* @brief リストのサイズを返す
	* @return int リストのサイズ
	*/
	int GetSize() const;


	/**
	* @brief イテレータで指定された位置にデータを挿入
	* @param ite 挿入する位置を指定したイテレータ
	* @param rec 成績情報
	* @param score スコア
	* @param userName ユーザー名
	* @return 挿入が成功した場合 true、 失敗した場合 false
	*/
	bool Insert(Const_Iterator& ite, const Record& rec);


	/**
	* @brief イテレータで指定位置のデータを削除
	* @param[in]  削除する位置を指定したイテレータ
	* @return 削除が成功した場合 true、 無効なイテレータ、ダミーノード場合 false
	*/
	bool Delete(Const_Iterator& ite);		


	/**
	* @brief 先頭イテレータを返す
	* @return Iterator 先頭イテレータ
	*/
	Iterator Begin() const;	


	/**
	* @brief 先頭のconstイテレータを返す
	* @return ConstIterato 先頭constイテレータ
	*/
	Const_Iterator ConstBegin() const;	


	/**
	* @brief 末尾イテレータを返す
	* @return Iterator 末尾イテレータ
	*/
	Iterator End() const;


	/**
	* @brief 先頭のconstイテレータを返す
	* @return ConstIterator 末尾constイテレータ
	*/
	Const_Iterator ConstEnd() const;					
};

#endif