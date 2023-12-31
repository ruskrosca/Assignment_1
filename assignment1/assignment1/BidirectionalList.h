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
#include <functional>

using namespace std;

/**
* @brief 双方向リストクラス
* @tparam T 任意のデータ型を指定できる
*/
template<typename T>
class BidirectionalList
{
private:
	/**
	* @brief リスト内の要素
	*/
	struct Node
	{
		//! データ
		T m_data;
		//! 次のノードへのポインタ
		Node* m_next;
		//! 前のノードへのポインタ
		Node* m_prev;

		/**
		* @brief コンストラクタ
		*/
		inline explicit Node();

		/**
		* @brief 引数付きコンストラクタ
		* @param data データ
		*/
		inline explicit Node(const T& data);
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
		friend class BidirectionalList;

	private:
		//! ノードを示すポインタ
		Node* m_node;

		//! リストのポインタ
		const BidirectionalList* m_list;

	public:
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
		* @return  データの参照
		*/
		inline const T& operator*() const;
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
		inline Iterator();

		/**
		* @brief 引数付きコンストラクタ
		* @param node ノードを指定するポインタ
		* @param list イテレータの所属しているリストの情報
		*/
		inline explicit Iterator(Node* node, const BidirectionalList* list);

		/**
		* @brief デリファレンス演算子
		* @return m_node->m_record データの参照
		*/
		inline T& operator*();
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
	* @param data データ
	* @return 挿入が成功した場合 true、 失敗した場合 false
	*/
	inline bool Insert(Const_Iterator& ite, const T& data);


	/**
	* @brief イテレータで指定位置のデータを削除
	* @param[in]  削除する位置を指定したイテレータ
	* @return 削除が成功した場合 true、 無効なイテレータ、ダミーノード場合 false
	*/
	inline bool Delete(Const_Iterator& ite);

	/**
	* @brief クイックソート呼び出し関数
	* @param[in]  iteLeft ソートする範囲の先頭イテレータ
	* @param[in]  iteRight ソートする範囲の末尾イテレータ
	* @param[in]  asc_des true : 昇順, false : 降順
	* @param[in]  key ソートで使用するキー
	* @detaile 参考にしたサイト https://cpprefjp.github.io/reference/algorithm/sort.html
	* @detaile 参考にしたサイト http://www1.cts.ne.jp/~clab/hsample/Sort/Sort9.html
	* @detaile 参考にしたサイト https://shinog.jp/computer/clanguage/%E5%86%8D%E5%B8%B0%E5%87%A6%E7%90%86%E3%82%92%E4%BD%BF%E7%94%A8%E3%81%97%E3%81%A6%E9%85%8D%E5%88%97%E5%86%85%E3%81%AE%E6%95%B0%E5%80%A4%E3%82%92%E6%95%B4%E5%88%97%E3%81%95%E3%81%9B%E3%82%8B_2%EF%BC%88/
	*/
	inline bool QuickSort(Const_Iterator iteLeft, Const_Iterator iteRight,
		bool asc_des,function<bool(const T&, const T&)> key);

	/**
	* @brief 先頭イテレータを返す
	* @return Iterator 先頭イテレータ
	*/
	inline Iterator Begin() const;

	/**
	* @brief 先頭イテレータを返す
	* @return Iterator 先頭イテレータ
	*/
	inline Iterator begin() const;

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
	* @brief 末尾イテレータを返す
	* @return Iterator 末尾イテレータ
	* @
	*/
	inline Iterator end() const;


	/**
	* @brief 先頭のconstイテレータを返す
	* @return ConstIterator 末尾constイテレータ
	*/
	inline Const_Iterator ConstEnd() const;

private:

	/**
	* @brief クイックソートを実行する内部関数
	* @param[in]  iteLeft ソートする範囲の先頭イテレータ
	* @param[in]  iteRight ソートする範囲の末尾イテレータ
	* @param[in]  asc_des true : 昇順, false : 降順
	* @param[in]  key ソートで使用するキー
	*/
	inline void Sort(Const_Iterator  iteLeft, Const_Iterator  iteRight, bool asc_des,
		function<bool(const T&, const T&)> key);

	/**
	* @brief クイックソートのための境目を見つける関数
	* @param[in]  iteLeft ソートする範囲の先頭イテレータ
	* @param[in]  iteRight ソートする範囲の末尾イテレータ
	* @param[in]  asc_des true : 昇順, false : 降順
	* @param[in]  key ソートで使用するキー
	* @return 境目のイテレータ
	*/
	inline Const_Iterator Partition(Const_Iterator iteLeft, Const_Iterator iteRight,
		bool asc_des, function<bool(const T&, const T&)> key);
};
#include "BidirectionalList.inl"
#endif