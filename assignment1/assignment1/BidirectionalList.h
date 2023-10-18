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
* @brief 成績データ
*/
struct Record
{
	//! スコア
	std::string score;
	//! ユーザー名
	std::string userName;
};


/**
* @brief 双方向リストクラス
*/
template<typename Record> 
class BidirectionalList
{
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

		/**
		* @brief 引数付きコンストラクタ
		* @param rec 成績データ 
		* @param score スコア
		* @param userName ユーザー名
		*/
		inline explicit Node(const Record& rec);
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

		//! リストのポインタ
		const BidirectionalList* m_list;

		/**
		* @brief デフォルトコンストラクタ
		*/
		inline Const_Iterator();

		/**
		* @brief 引数付きコンストラクタ
		* @param node ノードを指定するポインタ
		* @param list イテレータの所属しているリストの情報
		*/
		inline explicit Const_Iterator(Node* node, const BidirectionalList* list);

		/**
		* @brief 前置インクリメント演算子
		* @return 更新後のイテレータへの参照
		*/
		inline Const_Iterator& operator++();

		/**
		* @brief 前置デクリメント演算子
		* @return 更新後のイテレータへの参照
		*/
		inline Const_Iterator& operator--();

		/**
		* @brief 後置インクリメント演算子
		* @return 更新前のイテレータへの参照
		*/
		inline Const_Iterator operator++(int);

		/**
		* @brief 後置デクリメント演算子
		* @return 更新前のイテレータへの参照
		*/
		inline Const_Iterator operator--(int);

		/**
		* @brief デリファレンス演算子
		* @return  成績データの参照
		*/
		inline const Record& operator*();
		/**
		 * @brief 2つの Const_Iterator イテレータを比較する
		 * @param ite 比較対象の Const_Iterator
		 * @return 2つのイテレータが同じ要素を指している場合に true を返す
		 */
		inline bool operator==(const Const_Iterator& ite) const;

		/**
		* @brief 2つの Const_Iterator イテレータを比較する
		* @param ite 比較対象の Const_Iterator
		* @return 2つのイテレータが異なる要素を指している場合に true を返す
		*/
		inline bool operator!=(const Const_Iterator& ite) const;
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
		inline Iterator() : Const_Iterator();

		/**
		* @brief 引数付きコンストラクタ
		* @param node ノードを指定するポインタ
		* @param list イテレータの所属しているリストの情報
		*/
		inline explicit Iterator(Node* node, const BidirectionalList* list);

		/**
		* @brief デリファレンス演算子
		* @return m_node->m_record 成績データの参照
		*/
		inline Record& operator*();
	};

	/**
	* @brief デフォルトコンストラクタ
	*/
	inline BidirectionalList();

	/**
	* @brief コピーの禁止を行う
	*/
	inline BidirectionalList(const BidirectionalList&) = delete;

	/**
	* @brief デストラクタ
	*/
	inline ~BidirectionalList();

	/**
	* @brief リストのサイズを返す
	* @return int リストのサイズ
	*/
	inline int GetSize() const;


	/**
	* @brief イテレータで指定された位置にデータを挿入
	* @param ite 挿入する位置を指定したイテレータ
	* @param rec 成績情報
	* @param score スコア
	* @param userName ユーザー名
	* @return 挿入が成功した場合 true、 失敗した場合 false
	*/
	inline bool Insert(Const_Iterator& ite, const Record& rec);


	/**
	* @brief イテレータで指定位置のデータを削除
	* @param[in]  削除する位置を指定したイテレータ
	* @return 削除が成功した場合 true、 無効なイテレータ、ダミーノード場合 false
	*/
	inline bool Delete(Const_Iterator& ite);


	/**
	* @brief 先頭イテレータを返す
	* @return Iterator 先頭イテレータ
	*/
	inline Iterator Begin() const;


	/**
	* @brief 先頭のconstイテレータを返す
	* @return ConstIterato 先頭constイテレータ
	*/
	inline Const_Iterator ConstBegin() const;


	/**
	* @brief 末尾イテレータを返す
	* @return Iterator 末尾イテレータ
	*/
	inline Iterator End() const;


	/**
	* @brief 先頭のconstイテレータを返す
	* @return ConstIterator 末尾constイテレータ
	*/
	inline Const_Iterator ConstEnd() const;

};
#include "BidirectionalList.inl"
#endif


