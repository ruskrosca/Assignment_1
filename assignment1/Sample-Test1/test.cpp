/**********************************************************************************//**
	@file           test.cpp
	@brief          GoogleTestテストコード
	@author			RyosukeNarsushima 
*//***********************************************************************************/

#include "pch.h"
#include "../assignment1/BidirectionalList.h"
#include "../assignment1/Record.h"

using namespace std;

namespace ex01_DataStructure
{
	namespace chapter01
	{
		//=================================== データ数の取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合のデータ数の取得テスト
			@details	ID:リスト-0\n
						データ数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(DataNum, NullList) {
			BidirectionalList<Record> list;
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-1\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入を行った際の戻り値を確認しています。\n
						データ数が1であれば成功です。\n
		*//***********************************************************************************/
		TEST(DataNum, InsertBackSuccess) {
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();

			list.Insert(ite, rec);
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
			@details	ID:リスト-1\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(DataNum, InsertBackFail) {
			// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
			//BidirectionalList list;
			//BidirectionalList::Iterator ite = list.End();
			//Record rec = { 1, "a" };

			//list.Insert(ite, rec);
			//EXPECT_EQ(0,list.GetSize());
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-3\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が1であれば成功です。\n
		*//***********************************************************************************/
		TEST(DataNum, DataAddSuccess)
		{
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();

			list.Insert(ite, rec);
			EXPECT_EQ(1, list.GetSize());
		}


		/**********************************************************************************//**
			@brief		データの挿入に失敗した際のデータ数の取得テスト
			@details	ID:リスト-4\n
						データ数の取得機能のテストです。\n
						データの挿入に失敗した際の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(DataNum, DataAddFail)
		{// メモリ確保の失敗時のみ失敗するためスキップ
		}


		/**********************************************************************************//**
			@brief		データの削除を行った際のデータ数の取得テスト
			@details	ID:リスト-5\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(DataNum, DatadeleteSaccess)
		{
			BidirectionalList<Record> list;

			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();
			// データの挿入
			list.Insert(ite, rec);
			BidirectionalList<Record>::Iterator it = list.Begin();
			list.Delete(it);

			EXPECT_EQ(0, list.GetSize());

		}


		/**********************************************************************************//**
			@brief		データの削除が失敗した際のデータ数の取得テスト
			@details	ID:リスト-6\n
						データ数の取得機能のテストです。\n
						データの削除が失敗した際の戻り値を確認しています。\n
						データ数が1であれば成功です。\n
						データを挿入した後、削除した場合をテストします。\n
		*//***********************************************************************************/
		TEST(DataNum, DataDeleteFail)
		{
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();
			// データの挿入
			list.Insert(ite, rec);
			BidirectionalList<Record>::Iterator it;
			// データを削除
			list.Delete(it);
			EXPECT_EQ(1, list.GetSize());
		}


		/**********************************************************************************//**
			@brief		リストが空である場合に、データの削除を行った際のデータ数の取得テスト
			@details	ID:リスト-7\n
						データ数の取得機能のテストです。\n
						リストが空である場合に、データの削除を行った際の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
						マイナスにならないかどうか確認します。\n
		*//***********************************************************************************/
		TEST(DataNum, DeleteToNulList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			// 空リストの中を削除
			EXPECT_FALSE(list.Delete(it));
			EXPECT_EQ(0, list.GetSize());
		}
		
		/**********************************************************************************//**
			@brief		データ数の取得機能について、constのメソッドであるかのテスト
			@details	ID:リスト-8(手動)\n
						データ数の取得機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(DataNum, IsItAMethodOfConst)
		{
#define TT_TET_GETDATA_NUM_WHEN_CONST
#if defined TT_TET_GETDATA_NUM_WHEN_CONST
			const BidirectionalList<Record> list;
			EXPECT_EQ(0, list.GetSize());
#endif // defined TT_TET_GETDATA_NUM_WHEN_CONST
			SUCCEED();
		}

		//=================================== データの挿入 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、挿入した際の挙動テスト
			@details	ID:リスト-9\n
						リスト先頭、リスト末尾のデータ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						先頭、末尾に要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(Add, InsertToNulList)
		{
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();
			EXPECT_EQ(true, list.Insert(ite, rec));

			BidirectionalList<Record> list2;
			Record rec2 = { 1, "a" };
			BidirectionalList<Record>::Iterator ite2 = list.End();
			EXPECT_EQ(true, list.Insert(ite2, rec));

		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動テスト
			@details	ID:リスト-10\n
						リスト先頭のデータ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						先頭に要素が挿入され、元々先頭だった要素が２番目になれば成功です。\n
		*//***********************************************************************************/
		TEST(Add, SetHeadIteratortoList)
		{
			// データ挿入
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator it = list.Begin();
			list.Insert(it, rec);
			it = list.Begin();
			Record rec2 = { 2, "b" };
			list.Insert(it, rec2);
			it = list.Begin();
			Record rec3 = { 3, "c" };
			list.Insert(it, rec3);

			// 先頭要素の入れ替わりが発生したか確認
			BidirectionalList<Record>::Iterator it2 = list.Begin();
			it2 = list.Begin();
			EXPECT_TRUE((*it2).score == 3);
			EXPECT_TRUE((*it2).userName == "c");
			++it2;
			EXPECT_TRUE((*it2).score == 2);
			EXPECT_TRUE((*it2).userName == "b");
			++it2;
			EXPECT_TRUE((*it2).score == 1);
			EXPECT_TRUE((*it2).userName == "a");

		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動テスト
			@details	ID:リスト-11\n
						リスト末尾のデータ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入されれば成功です。\n
		*//***********************************************************************************/
		TEST(Add, SetTailIteratortoList)
		{
			// データの挿入
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator it = list.End();
			list.Insert(it, rec);
			it = list.End();
			--it;
			Record rec2 = { 2, "b" };
			// 末尾から一個後
			list.Insert(it, rec2);
			it = list.End();
			--it;
			--it;
			Record rec3 = { 3, "c" };
			// 末尾から二個後
			list.Insert(it, rec3);

			// 順番を確認
			it = list.End();
			--it;
			EXPECT_TRUE((*it).score == 1);
			EXPECT_TRUE((*it).userName == "a");
			--it;
			EXPECT_TRUE((*it).score == 2);
			EXPECT_TRUE((*it).userName == "b");
			--it;
			EXPECT_TRUE((*it).score == 3);
			EXPECT_TRUE((*it).userName == "c");

		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動テスト
			@details	ID:リスト-12\n
						リストのデータ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれれば成功です。\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか。要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします\n
		*//***********************************************************************************/
		TEST(Add, SetIteratortoList)
		{
			// データ挿入
			BidirectionalList<Record> list;
			Record record1 = { 1, "a" };
			Record record2 = { 2, "b" };
			Record record3 = { 3, "c" };
			BidirectionalList<Record>::Iterator it = list.Begin();
			// 先頭
			list.Insert(it, record1);
			it = list.Begin();
			EXPECT_EQ((*it).score, 1);
			EXPECT_EQ((*it).userName, "a");

			++it;
			// 先頭の次
			list.Insert(it, record2);
			it = list.Begin();
			EXPECT_EQ((*it).score, 1);
			EXPECT_EQ((*it).userName, "a");
			++it;
			EXPECT_EQ((*it).score, 2);
			EXPECT_EQ((*it).userName, "b");

			it = list.Begin();
			++it;
			// 挿入された二つのデータの間
			list.Insert(it, record3);

			// 整列順を確認
			BidirectionalList<Record>::Iterator ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			++ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");

			++ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
		}

		/**********************************************************************************//**
			@brief		ConstIteratorを指定して挿入を行った際の挙動テスト
			@details	ID:リスト-13\n
						データ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれれば成功です。\n
						格納済みの要素に影響がないか、期待される位置に要素が格納されているか。要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします\n
		*//***********************************************************************************/

		TEST(Add, InsertToConst)
		{
			BidirectionalList<Record> list;
			Record record1 = { 1, "a" };
			Record record2 = { 2, "b" };
			Record record3 = { 3, "c" };
			BidirectionalList<Record>::Const_Iterator cite = list.ConstBegin();
			// 先頭データの挿入
			list.Insert(cite, record1);
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, 1);
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			// 次に挿入
			list.Insert(cite, record2);
			// 現状の整列確認
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, 1);
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			EXPECT_EQ((*cite).score, 2);
			EXPECT_EQ((*cite).userName, "b");


			cite = list.ConstBegin();
			++cite;
			// 真ん中にデータ挿入
			list.Insert(cite, record3);
			cite = list.ConstBegin();
			// 最終的な整列確認
			EXPECT_EQ((*cite).score, 1);
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			EXPECT_EQ((*cite).score, 3);
			EXPECT_EQ((*cite).userName, "c");
			++cite;
			EXPECT_EQ((*cite).score, 2);
			EXPECT_EQ((*cite).userName, "b");
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡して、挿入した場合の挙動テスト
			@details	ID:リスト-14\n
						リスト先頭のデータ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						何も起こらなければ成功です。\n
						リストの参照がないイテレータ、別リストの要素を指すイテレータを渡した際の挙動など\n
		*//***********************************************************************************/
		TEST(Add, AddToNullList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it;
			Record rec = { 1, "a" };
			// リストの参照が無いイテレータを渡す
			EXPECT_EQ(false, list.Insert(it, rec));
		}

		/**********************************************************************************//**
		@brief		リスト末尾のデータ追加について、非constが保障されているかのテスト
		@details	ID:リスト-15(手動)\n
					リスト末尾のデータ追加テストです。\n
					非constが保障されているかを確認しています。\n
					有効にしてコンパイルエラーになれば成功です。\n
					TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n

		@return		なし
		*//***********************************************************************************/
		TEST(Add, IsItAMethodOfConst)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			Record rec = { 1, "a" };
			list.Insert(it, rec);//ここでエラー

#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
				@brief		リストが空である場合に、削除を行った際の挙動テスト
				@details	ID:リスト-16\n
							空リストのデータ削除テストです。\n
							リストが空である場合に追加した際の挙動を確認しています。\n
							何も起こらなければ成功です。\n
							先頭イテレータ、末尾イテレータを引数で渡した場合について、個別に挙動をチェックする。\n
		*//***********************************************************************************/
		TEST(Delete, DeleteBackFromEmptyList)
		{
			BidirectionalList<Record> list;

			// リストが空か
			EXPECT_EQ(list.GetSize(), 0);

			// 何も起こらないか
			BidirectionalList<Record>::Iterator ite = list.Begin();
			EXPECT_EQ(list.Delete(ite), false);

			ite = list.End();
			EXPECT_EQ(list.Delete(ite), false);

		}

		/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動テスト
				@details	ID:リスト-17\n
							リスト先頭のデータ削除テストです。\n
							リストが空である場合に追加した際の挙動を確認しています。\n
							先頭要素の削除されれば成功です。\n
							先頭イテレータ、末尾イテレータを引数で渡した場合について、個別に挙動をチェックする。\n
		*//***********************************************************************************/
		TEST(Delete, SetIteratorFrontFromlist)
		{
			//データの挿入
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);

			ite = list.Begin();
			// 次のデータ挿入
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);

			ite = list.Begin();
			// 先頭のデータ削除
			EXPECT_EQ(true, list.Delete(ite));
			
			// 今の先頭のデータを確認
			ite = list.Begin();
			EXPECT_TRUE((*ite).score == 1);
			EXPECT_TRUE((*ite).userName == "a");
		}

		/**********************************************************************************//**
				@brief		リリストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動テスト
				@details	ID:リスト-18\n
							リスト末尾のデータ削除テストです。\n
							リストが空である場合に追加した際の挙動を確認しています。\n
							何も起こらなければ成功です。\n
							末尾はダミーノードです。\n
		*//***********************************************************************************/
		TEST(Delete, SetIteratorTailFromlist)
		{
			// データ挿入
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(it, rec);

			// 次のデータを挿入
			Record rec2 = { 2, "b" };
			it = list.End();
			list.Insert(it, rec2);

			// 末尾データを削除(ダミーノードを削除)
			BidirectionalList<Record>::Iterator ite = list.End();
			EXPECT_EQ(false, list.Delete(ite));
		}

		/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動テスト
				@details	ID:リスト-19\n
							リスト先頭でも末尾でもないのデータ削除テストです。\n
							リストが空である場合に追加した際の挙動を確認しています。\n
							指定要素の削除されれば成功です。\n
							格納済みの要素に影響がないか、期待される位置に要素が格納されている。\n
		*//***********************************************************************************/
		TEST(Delete, SetIteratorFromlist)
		{
			BidirectionalList<Record> list;
			Record record1 = { 1, "a" };
			Record record2 = { 2, "b" };
			Record record3 = { 3, "c" };
			BidirectionalList<Record>::Iterator it = list.Begin();
			list.Insert(it, record1);
			it = list.Begin();
			++it;
			list.Insert(it, record2);
			it = list.Begin();
			++it;
			list.Insert(it, record3);

			EXPECT_EQ(list.GetSize(), 3);

			BidirectionalList<Record>::Iterator ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			++ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");

			++ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

			ite = list.Begin();
			++ite;
			list.Delete(ite);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			++ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

		}

		/**********************************************************************************//**
		@brief		ConstIteratorを指定して削除を行った際の挙動テスト
		@details	ID:リスト-20\n
					ConstIteratorを指定したデータ削除テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					指定要素の削除されれば成功です。\n
					格納済みの要素に影響がないか、期待される位置に要素が格納されている。\n
		*//***********************************************************************************/

		TEST(Delete, DeleteConstIterator)
		{
			BidirectionalList<Record> list;
			Record record1 = { 1, "a" };
			Record record2 = { 2, "b" };
			Record record3 = { 3, "c" };
			BidirectionalList<Record>::Const_Iterator cite = list.ConstBegin();
			list.Insert(cite, record1);
			cite = list.Begin();
			++cite;
			list.Insert(cite, record2);
			cite = list.Begin();
			++cite;
			++cite;
			list.Insert(cite, record3);
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, 1);
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			EXPECT_EQ((*cite).score, 2);
			EXPECT_EQ((*cite).userName, "b");
			++cite;
			EXPECT_EQ((*cite).score, 3);
			EXPECT_EQ((*cite).userName, "c");

			cite = list.ConstBegin();
			list.Delete(cite);
			cite = list.ConstBegin();

			EXPECT_EQ((*cite).score, 2);
			EXPECT_EQ((*cite).userName, "b");
			++cite;
			EXPECT_EQ((*cite).score, 3);
			EXPECT_EQ((*cite).userName, "c");

		}

		/**********************************************************************************//**
		@brief		不正なイテレータを渡して、削除した場合の挙動テスト
		@details	ID:リスト-21\n
					不正なイテレータを指定したデータ削除テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					何も起こらなければ成功です。\n
					リストの参照がないイテレータ、別リストの要素を指すイテレータを渡した際の挙動など。\n
		*//***********************************************************************************/
		TEST(Delete, AddNullDelete)
		{
			BidirectionalList<Record> list;
			Record record1 = { 1,"a" };
			BidirectionalList<Record>::Iterator it;

			list.Insert(it, record1);
			// 別リストの情報を渡す
			EXPECT_FALSE(list.Delete(it));
		}

		/**********************************************************************************//**
		@brief		リスト末尾のデータ追加について、非constが保障されているかのテスト
		@details	ID:リスト-22(手動)\n
					非constが保障されているかを確認しています。\n
					有効にしてコンパイルエラーになれば成功です。\n
					TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n

		@return		なし
		*//***********************************************************************************/
		TEST(Delete, IsItAMethodOfConst)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			Record rec = { 1, "a" };
			list.Insert(it, rec);//ここでエラー
			it = list.ConstBegin();
			list.Push_Back(it);//ここでエラー
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
		@brief		リストが空である場合に、呼び出した際の挙動テスト
		@details	ID:リスト-23\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					ダミーノードを指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetHeadIterator, NullList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			EXPECT_EQ(list.Begin(), it);
		}

		/**********************************************************************************//**
		@brief		リストに要素が一つある場合に、呼び出した際の挙動テスト
		@details	ID:リスト-24\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetHeadIterator, CalloneElementList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);


			ite = list.Begin();
			// 先頭イテレータが正しい要素か
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
		@details	ID:リスト-25\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetHeadIterator, CallTwoElementsList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);


			// 先頭のイテレータ画正しい要素を指しているか
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		データの挿入を行った後に、呼び出した際の挙動テスト
		@details	ID:リスト-26\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetHeadIterator, CalltoAfterAddData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

			ite = list.Begin();
			++ite;
			Record record3 = { 3, "c" };
			list.Insert(ite, record3);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");
			++ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
		}

		/**********************************************************************************//**
		@brief		データの削除を行った後に、呼び出した際の挙動テスト
		@details	ID:リスト-27\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetHeadIterator, CalltoAfterDeleteData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;

			Record record2 = { 2, "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			++ite;
			++ite;
			Record record3 = { 3, "c" };
			list.Insert(ite, record3);

			ite = list.Begin();
			list.Delete(ite);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
			++ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");

			ite = list.Begin();
			ite++;
			list.Delete(ite);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

			list.Delete(ite);
			ite = list.Begin();
			EXPECT_EQ(0, list.GetSize());

		}

		/**********************************************************************************//**
		@brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック

		@details	ID:リスト-28\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					コンパイルエラーになることを確認します。\n
					TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/

		TEST(GetHeadIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Iterator it = list.ConstBegin();//ここでエラー
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


		/**********************************************************************************//**
		@brief		リストが空である場合に、先頭コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-29\n
					先頭コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					ダミーノードを指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstHeadIterator, CallEmptyList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator it = list.ConstBegin();
			EXPECT_EQ(list.ConstBegin(), it);
		}

		/**********************************************************************************//**
		@brief		リストに要素が一つある場合に、先頭コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-30\n
					先頭コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstHeadIterator, CalloneElementList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.ConstBegin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);

			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		リストに二つ以上の要素がある場合に、先頭コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-31\n
					先頭コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/

		TEST(GetConstHeadIterator, CallTweElementList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);


			// 先頭のイテレータが正しい要素を指しているか
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		データの挿入を行った後に、先頭コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-32\n
					先頭コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetConstHeadIterator, CalltoAfterAddData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.ConstBegin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			ite = list.ConstBegin();
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);
			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

			ite = list.ConstBegin();
			++ite;
			Record record3 = { 3, "c" };
			list.Insert(ite, record3);
			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");
			++ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
		}

		
		/**********************************************************************************//**
		@brief		データの削除を行った後に、呼び出した際の挙動テスト
		@details	ID:リスト-33\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					先頭要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetConstHeadIterator, CalltoAfterDeleteData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator cite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(cite, record1);
			cite = list.Begin();
			++cite;

			Record record2 = { 2, "b" };
			list.Insert(cite, record2);
			cite = list.Begin();
			++cite;
			++cite;

			Record record3 = { 3, "c" };
			list.Insert(cite, record3);

			cite = list.Begin();
			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ((*cite).score, 2);
			EXPECT_EQ((*cite).userName, "b");
			++cite;
			EXPECT_EQ((*cite).score, 3);
			EXPECT_EQ((*cite).userName, "c");

			cite = list.Begin();
			cite++;
			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ((*cite).score, 2);
			EXPECT_EQ((*cite).userName, "b");

			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
		@brief		constのメソッドであるかをチェック

		@details	ID:リスト-34\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					constのリストから呼び出して、コンパイルエラーとならないかを確認します。\n
		*//***********************************************************************************/
		TEST(GetConstHeadIterator, IsItAMethodOfConst)
		{
#define TT_TET_GETDATA_NUM_WHEN_CONST
#if defined TT_TET_GETDATA_NUM_WHEN_CONST
			const BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator cit = list.ConstBegin();

#endif // defined TT_TET_GETDATA_NUM_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
		@brief		リストが空である場合に、末尾イテレータを呼び出した際の挙動テスト
		@details	ID:リスト-35\n
					末尾イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					ダミーノードを指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetTailIterator, NullList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.End();
			EXPECT_EQ(list.End(), it);
		}

		/**********************************************************************************//**
		@brief		リストに要素が一つある場合に、末尾イテレータを呼び出した際の挙動テスト
		@details	ID:リスト-36\n
					末尾イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetTailIterator, CalloneElementList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;

			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		リストに二つ以上の要素がある場合に、末尾イテレータを呼び出した際の挙動テスト
		@details	ID:リスト-37\n
					末尾イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetTailIterator, CallTwoElementsList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);


			// 末尾のイテレータが正しい要素を指しているか
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
		}

		/**********************************************************************************//**
		@brief		データの挿入を行った後に、末尾イテレータを呼び出した際の挙動テスト
		@details	ID:リスト-38\n
					末尾イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetTailIterator, CalltoAfterAddData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			ite = list.Begin();
			++ite;
			Record record3 = { 3, "c" };
			list.Insert(ite, record3);
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		データの削除を行った後に、末尾イテレータ呼び出した際の挙動テスト
		@details	ID:リスト-39\n
					末尾イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetTailIterator, CalltoAfterDeleteData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			++ite;
			Record record3 = { 3, "c" };
			list.Insert(ite, record3);

			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			ite = list.End();
			--ite;
			--ite;
			list.Delete(ite);
			--ite;
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			ite = list.End();
			--ite;
			--ite;
			list.Delete(ite);
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

			ite = list.End();
			--ite;
			list.Delete(ite);
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
		@brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック

		@details	ID:リスト-40\n
					先頭イテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					コンパイルエラーになることを確認します。\n
					TT_TEST_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(GetTailIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Iterator it = list.ConstEnd();//ここでエラー
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
		@brief		リストが空である場合に、末尾コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-41\n
					末尾コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					ダミーノードを指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstTailIterator, CallEmptyList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator it = list.ConstEnd();
			EXPECT_EQ(list.ConstEnd(), it);
		}

		/**********************************************************************************//**
		@brief		リストに要素が一つある場合に、末尾コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-42\n
					末尾コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstTailIterator, CalloneElementList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.ConstBegin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);

			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		リストに二つ以上の要素がある場合に、末尾コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-43\n
					末尾コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstTailIterator, CallTweElementList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.ConstBegin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);

			// 末尾のイテレータが正しい要素か
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

		}

		/**********************************************************************************//**
		@brief		データの挿入を行った後に、末尾コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-44\n
					末尾コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetConstTailIterator, CalltoAfterAddData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.ConstEnd();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");

			ite = list.ConstEnd();
			--ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

			ite = list.End();
			--ite;
			Record record3 = { 3, "c" };
			list.Insert(ite, record3);
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
			--ite;
			EXPECT_EQ((*ite).score, 3);
			EXPECT_EQ((*ite).userName, "c");
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
		}

		/**********************************************************************************//**
		@brief		データの削除を行った後に、末尾コンストイテレータを呼び出した際の挙動テスト
		@details	ID:リスト-45\n
					末尾コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					末尾要素を指すイテレータが返れば成功です。\n
					要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。\n
		*//***********************************************************************************/
		TEST(GetConstTailIterator, CalltoAfterDeleteData)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			Record record2 = { 2, "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			++ite;
			Record record3 = { 3, "c" };
			list.Insert(ite, record3);
			ite = list.End();
			--ite;
			list.Delete(ite);

			BidirectionalList<Record>::Const_Iterator cite = list.ConstEnd();
			--cite;
			EXPECT_EQ((*cite).score, 3);
			EXPECT_EQ((*cite).userName, "c");
			--cite;
			EXPECT_EQ((*cite).score, 1);
			EXPECT_EQ((*cite).userName, "a");

			ite = list.End();
			--ite;
			--ite;
			list.Delete(ite);
			cite = list.ConstEnd();
			--cite;
			EXPECT_EQ((*cite).score, 3);
			EXPECT_EQ((*cite).userName, "c");

			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
		@brief		constのメソッドであるかをチェック

		@details	ID:リスト-46\n
					末尾コンストイテレータの取得テストです。\n
					リストが空である場合に追加した際の挙動を確認しています。\n
					constのリストから呼び出して、コンパイルエラーとならないかを確認します。\n
		*//***********************************************************************************/
		TEST(GetConstTailIterator, IsItAMethodOfConst)
		{
#define TT_TET_GETDATA_NUM_WHEN_CONST
#if defined TT_TET_GETDATA_NUM_WHEN_CONST
			const BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator cit = list.ConstEnd();

#endif // defined TT_TET_GETDATA_NUM_WHEN_CONST
			SUCCEED();
		}
	}

	namespace chapter02
	{
		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-0\n
						イテレータの指す要素を取得するテストです。\n
						Assert発生したら成功です。\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, CalltoList)
		{
			BidirectionalList<Record>::Iterator it;
			EXPECT_DEATH((*it), ".*");
		}

		/**********************************************************************************//**
			@brief		Iteratorから取得した要素に対して、値の代入が行えるのテスト
			@details	ID:Iterator-1\n
						イテレータの指す要素を取得するテストです。\n
						値の代入が行えれ成功です。\n
						代入後に再度呼び出し、値が変更されていることを確認。\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, CallToNoList)
		{
			BidirectionalList<Record> List;
			BidirectionalList<Record>::Iterator it = List.Begin();
			Record record = { 1,"a" };
			List.Insert(it, record);
			it = List.Begin();

			Record rec = { 2,"b" };

			(*it).score = rec.score;
			(*it).userName = rec.userName;

			EXPECT_EQ((*it).score, 2);
			EXPECT_EQ((*it).userName, "b");
		}

		/**********************************************************************************//**
		@brief		ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック

		@details	ID:リスト-2\n
					イテレータの指す要素を取得するテストです。\n
					コンパイルエラーになることを確認します。\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			Record rec = { 1, "a" };
			list.Insert(rec, it);
			it = list.ConstBegin();
			(*it).score = 3;//ここでエラー
			(*it).userName = "c";//ここでエラー
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-3\n
						イテレータの指す要素を取得するテストです。\n
						Assert発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, CallOnEmtyList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			EXPECT_DEATH(*it,".*");
		}


		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-4\n
						イテレータの指す要素を取得するテストです。\n
						Assert発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, CalOnIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.End();

			ASSERT_DEATH((*it), ".*");

		}

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-５\n
						イテレータをリストの末尾に向かって一つ進めるテストです。\n
						Assert発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorToTailOfTheList, CalltoList)
		{
			BidirectionalList<Record>::Iterator it;

			ASSERT_DEATH({ ++it; }, ".*");

			BidirectionalList<Record>::Iterator it2;

			ASSERT_DEATH({ it2++; }, ".*");
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-6\n
						イテレータをリストの末尾に向かって一つ進めるテストです。\n
						Assert発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorToTailOfTheList, CallFirstIteratorWhenListIsEmpty)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();

			ASSERT_DEATH({ ++it; }, ".*");

			BidirectionalList<Record>::Iterator it2 = list.Begin();

			ASSERT_DEATH({ it2++; }, ".*");
		}

		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-7\n
						イテレータをリストの末尾に向かって一つ進めるテストです。\n
						Assert発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorToTailOfTheList, CallOnATailIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.End();
			ASSERT_DEATH(++ite, ".*");

			BidirectionalList<Record>::Iterator ite2 = list.End();
			ASSERT_DEATH(ite2++, ".*");
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
			@details	ID:Iterator-8\n
						イテレータをリストの末尾に向かって一つ進めるテストです。\n
						次の要素を指していれば成功です。\n
						リストの先頭から末尾まで呼び出しを行い、期待されている要素が格納されているかを確認する。\n
		*//***********************************************************************************/
		TEST(IteratorToTailOfTheList, CallTwoElemtsList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			++ite;
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);

			ite = list.Begin();
			EXPECT_EQ((*ite).score, rec.score);
			EXPECT_EQ((*ite).userName, rec.userName);
			++ite;
			EXPECT_EQ((*ite).score, rec2.score);
			EXPECT_EQ((*ite).userName, rec2.userName);

			ite = list.Begin();
			EXPECT_EQ((*ite).score, rec.score);
			EXPECT_EQ((*ite).userName, rec.userName);
			ite++;
			EXPECT_EQ((*ite).score, rec2.score);
			EXPECT_EQ((*ite).userName, rec2.userName);
		}

		/**********************************************************************************//**
			@brief		前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )テスト
			@details	ID:Iterator-9\n
						イテレータをリストの末尾に向かって一つ進めるテストです。\n
						次の要素を指していれば成功です。\n
						インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認します\n
		*//***********************************************************************************/
		TEST(IteratorToTailOfTheList, PerformingAPreIncrement)
		{
			bool result = false;
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			++ite;
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);
			ite = list.Begin();
			++ite;
			Record rec3 = *++ite;
			Record rec4 = *ite;


			EXPECT_TRUE(rec3.score == rec4.score);
		}

		/**********************************************************************************//**
			@brief		後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )テスト
			@details	ID:Iterator-10\n
						イテレータをリストの末尾に向かって一つ進めるテストです。\n
						次の要素を指していれば成功です。\n
						インクリメント呼び出し時の値と、インクリメント実行後の値の両方を確認します。\n
		*//***********************************************************************************/
		TEST(IteratorToTailOfTheList, PostfixIncrementsArePerformed)
		{
			bool result = false;
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			ite++;
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);
			ite = list.Begin();
			ite++;
			Record rec3 = *ite++;
			Record rec4 = *ite;

			EXPECT_TRUE(rec3.score != rec4.score);
		}

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-11\n
						イテレータをリストの先頭に向かって一つ進めるテストです。\n
						Assert発生していれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, CalltoList)
		{
			BidirectionalList<Record>::Iterator it;

			ASSERT_DEATH({ --it; }, ".*");

			BidirectionalList<Record>::Iterator it2;

			ASSERT_DEATH({ it2--; }, ".*");
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-12\n
						イテレータをリストの先頭に向かって一つ進めるテストです。\n
						Assert発生していれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, CallFirstIteratorWhenListIsEmpty)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.End();

			ASSERT_DEATH({ --it; }, ".*");

			BidirectionalList<Record>::Iterator it2 = list.End();

			ASSERT_DEATH({ it2--; }, ".*");
		}

		/**********************************************************************************//**
			@brief		先頭イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-13\n
						イテレータをリストの先頭に向かって一つ進めるテストです。\n
						Assert発生していれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, CallOnATailIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();

			ASSERT_DEATH(--ite, ".*");

			BidirectionalList<Record>::Iterator ite2 = list.Begin();

			ASSERT_DEATH(ite2--, ".*");
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動テスト
			@details	ID:Iterator-14\n
						イテレータをリストの先頭に向かって一つ進めるテストです。\n
						前の要素を指していれば成功です。\n
						リストの末尾から先頭まで呼び出しを行い、期待されている要素が格納されているかを確認する。\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, CallTwoElemtsList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			++ite;
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);

			ite = list.End();
			ite--;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
			ite--;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");


			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
			@brief		前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )テスト
			@details	ID:Iterator-15\n
						イテレータをリストの先頭に向かって一つ進めるテストです。\n
						前の要素を指していれば成功です。\n
						デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認する。\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, PerformingAPreIncrement)
		{
			bool result = false;
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.End();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);
			ite = list.End();
			--ite;
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);
			ite = list.End();
			--ite;
			Record rec3 = *--ite;
			Record rec4 = *ite;

			EXPECT_TRUE(rec3.score == rec4.score);
		}

		/**********************************************************************************//**
			@brief		後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )テスト
			@details	ID:Iterator-16\n
						イテレータをリストの先頭に向かって一つ進めるテストです。\n
						前の要素を指していれば成功です。\n
						デクリメント呼び出し時の値と、デクリメント実行後の値の両方を確認する。\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, PostfixIncrementsArePerformed)
		{
			bool result = false;
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator ite = list.End();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);
			ite = list.End();
			ite--;
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);

			ite = list.End();
			ite--;
			Record rec3 = *ite--;
			Record rec4 = *ite;


			EXPECT_TRUE(rec3.score != rec4.score);
		}

		/**********************************************************************************//**
			@brief		ConstIteratorから、Iteratorのコピーが作成されないかをチェック
			@details	ID:Iterator-17\n
						イテレータのコピーを行うテストです。\n
						コンパイルエラーになれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator cit = list.ConstBegin();
			BidirectionalList::Iterator it = cit;//ここでエラー
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		コピーコンストラクト後の値がコピー元と等しいことをチェックするテスト
			@details	ID:Iterator-18\n
						イテレータのコピーを行うテストです。\n
						コピー元と等しかったら成功です。\n
		*//***********************************************************************************/
		TEST(CopyIterator, CopyIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator origin = list.Begin();
			Record rec = { 1,"a" };
			list.Insert(origin, rec);
			origin = list.Begin();
			BidirectionalList<Record>::Iterator copyIt(origin);
			EXPECT_EQ((*origin).score, (*copyIt).score);
			EXPECT_EQ((*origin).userName, (*origin).userName);
		}

		/**********************************************************************************//**
				@brief		IteratorにConstIteratorを代入できない事をチェックするテスト
				@details	ID:Iterator-19\n
							イテレータの代入を行うテストです。\n
							コンパイルエラーになれば成功です。\n
			*//***********************************************************************************/
		TEST(CopyIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator cit = list.ConstBegin();
			BidirectionalList::Iterator it = list.Begin;
			it = cit;//ここでエラー
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
				@brief		代入後の値がコピー元と等しいことをチェックするテスト
				@details	ID:Iterator-20\n
							イテレータの代入を行うテストです。\n
							コピー元と等しければ成功です。\n
			*//***********************************************************************************/
		TEST(AssignmentIterator, AsseignmentIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator origin = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(origin, rec);
			origin = list.Begin();

			BidirectionalList<Record>::Iterator assigned = origin;

			EXPECT_EQ((*origin).score, (*assigned).score);
			EXPECT_EQ((*origin).userName, (*assigned).userName);

		}

		/**********************************************************************************//**
		@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェックするテスト
		@details	ID:Iterator-21\n
					二つのイテレータが同一のものであるか、比較を行うテストです。\n
					二つのイテレータが同一のものであれば成功です。\n
		*//***********************************************************************************/
		TEST(TwoIteratorIdenticalOrComparisons, FirstIteratorWithLastIteratorListIsEmpty)
		{
			BidirectionalList<Record> list;

			BidirectionalList<Record>::Iterator beginIt = list.Begin();
			BidirectionalList<Record>::Iterator endIt = list.End();

			EXPECT_TRUE(beginIt == endIt);

		}


		/**********************************************************************************//**
		@brief		同一のイテレータを比較した際の挙動テスト
		@details	ID:Iterator-22\n
					二つのイテレータが同一のものであるか、比較を行うテストです。\n
					二つのイテレータが同一のものであれば成功です。\n
		*//***********************************************************************************/
		TEST(TwoIteratorIdenticalOrComparisons, IdenticcalIterator)
		{
			BidirectionalList<Record> list;

			BidirectionalList<Record>::Iterator it1 = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(it1, rec);

			it1 = list.Begin();
			BidirectionalList<Record>::Iterator it2 = it1;

			EXPECT_TRUE(it1 == it2);

		}

		/**********************************************************************************//**
		@brief		異なるイテレータを比較した際の挙動テスト
		@details	ID:Iterator-22\n
					二つのイテレータが同一のものであるか、比較を行うテストです。\n
					二つのイテレータが異なるのものであれば成功です。\n
		*//***********************************************************************************/
		TEST(TwoIteratorIdenticalOrComparisons, DifferentIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record> list2;
			BidirectionalList<Record>::Iterator it1 = list.Begin();
			BidirectionalList<Record>::Iterator it2 = list2.Begin();
			Record rec = { 1, "a" };
			list.Insert(it1, rec);
			list2.Insert(it2, rec);
			it1 = list.Begin();
			it2 = list2.Begin();
			EXPECT_FALSE(it1 == it2);

		}

		/**********************************************************************************//**
		@brief		リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動テスト
		@details	ID:Iterator-22\n
					二つのイテレータが異なるものであるか、比較を行うテストです。\n
					二つのイテレータが異なるのものであれば成功です。\n
		*//***********************************************************************************/
		TEST(TwoIteratorDifferentOrComparisons, FirstIteratorWithLastIteratorListIsEmpty)
		{
			BidirectionalList<Record> list;

			BidirectionalList<Record>::Iterator beginIter = list.Begin();
			BidirectionalList<Record>::Iterator endIter = list.End();

			EXPECT_FALSE(beginIter != endIter);
		}

		/**********************************************************************************//**
		@brief		同一のイテレータを比較した際の挙動テスト
		@details	ID:Iterator-22\n
					二つのイテレータが異なるものであるか、比較を行うテストです。\n
					二つのイテレータが異なるのものであれば成功です。\n
		*//***********************************************************************************/
		TEST(TwoIteratorDifferentOrComparisons, IdenticcalIterator)
		{
			BidirectionalList<Record> list;

			BidirectionalList<Record>::Iterator it1 = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(it1, rec);

			it1 = list.Begin();
			BidirectionalList<Record>::Iterator it2 = it1;

			EXPECT_FALSE(it1 != it2);

		}

		/**********************************************************************************//**
		@brief		異なるイテレータを比較した際の挙動テスト
		@details	ID:Iterator-22\n
					二つのイテレータが異なるものであるか、比較を行うテストです。\n
					二つのイテレータが異なるのものであれば成功です。\n
		*//***********************************************************************************/
		TEST(TwoIteratorDifferentOrComparisons, DifferentIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record> list2;
			BidirectionalList<Record>::Iterator it1 = list.Begin();
			BidirectionalList<Record>::Iterator it2 = list2.Begin();
			Record rec = { 1, "a" };
			list.Insert(it1, rec);
			list2.Insert(it2, rec);

			it1 = list.Begin();
			it2 = list2.Begin();

			EXPECT_TRUE(it1 != it2);
		}
	}
}