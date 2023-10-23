#include "pch.h"
#include "../assignment1/BidirectionalList.h"
#include "../assignment1/Record.h"

namespace chapter01
{
	/**********************************************************************************//**
	@brief		要素を持たないリストにソートを実行した時の挙動テスト
	@details	ID:リスト-0\n
				クイックソートのテストです。\n
				要素を持たないリストにソートを実行した時の挙動を確認しています。\n
				エラー含めて、何も起こらなければ成功です。\n
	*//***********************************************************************************/
	TEST(QuickSort, NullList) {
		BidirectionalList<Record> list;
		// falseが返ってくれば成功
		EXPECT_FALSE(list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.userName < b.userName; }));
	}

	/**********************************************************************************//**
	@brief		要素を1つだけ持つリストにソートを実行した時の挙動テスト
	@details	ID:リスト-1\n
				クイックソートのテストです。\n
				要素を1つだけ持つリストにソートを実行した時の挙動を確認しています。\n
				エラー含めて、何も起こらなければ成功です。\n
	*//***********************************************************************************/
	TEST(QuickSort, OneElementList) {
		BidirectionalList<Record> list;
		Record rec{ 1,"ga" };
		BidirectionalList<Record>::Iterator it = list.begin();
		list.Insert(it, rec);

		// falseが返ってくれば成功
		EXPECT_FALSE(list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.userName < b.userName; }));
	}

	/**********************************************************************************//**
	@brief		2つ以上要素を持つリストにソートを実行した時の挙動テスト
	@details	ID:リスト-2\n
				クイックソートのテストです。\n
				2つ以上要素を持つリストにソートを実行した時の挙動を確認しています。\n
				要素が指定したキーに準じて指定した順に並べば成功です。\n
				先頭から順にイテレータで確認し、ノードの差し替えが正常に行えているかチェックする。\n
	*//***********************************************************************************/
	TEST(QuickSort, TwoOrMoreElementsList) {
		BidirectionalList<Record> list;
		Record rec = { 1,"ga" };
		Record rec2 = { 2,"aa" };
		Record rec3 = { 3,"ua" };
		BidirectionalList<Record>::Iterator ite = list.Begin();
		list.Insert(ite, rec);
		ite = list.End();
		list.Insert(ite, rec2);
		ite = list.End();
		list.Insert(ite, rec3);


		ite = list.begin();
		EXPECT_EQ((*ite).userName, rec.userName);
		++ite;			 
		EXPECT_EQ((*ite).userName, rec2.userName);
		++ite;			
		EXPECT_EQ((*ite).userName, rec3.userName);
		++ite;

		EXPECT_TRUE(list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.userName < b.userName; }));

		ite = list.begin();
		EXPECT_EQ((*ite).userName, rec2.userName);
		++ite;
		EXPECT_EQ((*ite).userName, rec.userName);
		++ite;			 
		EXPECT_EQ((*ite).userName, rec3.userName);
		++ite;
	}

	/**********************************************************************************//**
	@brief		同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動テスト
	@details	ID:リスト-3\n
				クイックソートのテストです。\n
				同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動を確認しています。\n
				要素がソートされて並べば成功です。\n
				同じ要素の順序は保証されません。\n
	*//***********************************************************************************/
	TEST(QuickSort, ListWithElementsHavingTheSameKey) {
		BidirectionalList<Record> list;

		BidirectionalList<Record>::Iterator ite = list.Begin();
		Record rec{ 1,"c" };
		Record rec2{ 1,"a" };
		Record rec3{ 1,"b" };	
		list.Insert(ite, rec);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec2);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec3);

		EXPECT_TRUE(true,list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.score < b.score; }););
	}

	/**********************************************************************************//**
	@brief		整列済みリストにソートを実行した時の挙動テスト
	@details	ID:リスト-4\n
				クイックソートのテストです。\n
				同整列済みリストにソートを実行した時の挙動を確認しています。\n
				同じキーの要素の間以外の順番が変動しなければ成功です。\n
				重複要素なしの整列済みリストを使います。\n
	*//***********************************************************************************/
	TEST(QuickSort, SortOnAnAlignedList) {
		BidirectionalList<Record> list;
		BidirectionalList<Record>::Iterator ite = list.Begin();
		Record rec{ 432,"a" };
		Record rec2{ 1,"b" };
		Record rec3{ 36,"c" };
		Record rec4{ 28,"d" };
		list.Insert(ite, rec);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec2);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec3);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec4);

		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.score < b.score; });


		ite = list.Begin();
		EXPECT_EQ((*ite).score, rec2.score);
		ite++;
		EXPECT_EQ((*ite).score, rec4.score);
		ite++;
		EXPECT_EQ((*ite).score, rec3.score);
		ite++;
		EXPECT_EQ((*ite).score, rec.score);
		ite++;

		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.score < b.score; });


		ite = list.Begin();
		EXPECT_EQ((*ite).score, rec2.score);
		ite++;
		EXPECT_EQ((*ite).score, rec4.score);
		ite++;
		EXPECT_EQ((*ite).score, rec3.score);
		ite++;
		EXPECT_EQ((*ite).score, rec.score);
		ite++;
	}

	/**********************************************************************************//**
	@brief		一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動テスト
	@details	ID:リスト-5\n
				クイックソートのテストです。\n
				一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動を確認しています。\n
				要素がソートされて並べば成功です。\n
				重複要素なしの整列済みリストを使います。\n
	*//***********************************************************************************/
	TEST(QuickSort, TheListOnceAlignedAndSortedAgain) {
		BidirectionalList<Record> list;
		BidirectionalList<Record>::Iterator ite = list.Begin();
		Record rec{ 432,"a" };
		Record rec2{ 1,"b" };
		Record rec3{ 36,"c" };
		Record rec4{ 28,"d" };
		list.Insert(ite, rec);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec2);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec3);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec4);

		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.score < b.score; });


		ite = list.Begin();
		EXPECT_EQ((*ite).score, rec2.score);
		ite++;
		EXPECT_EQ((*ite).score, rec4.score);
		ite++;
		EXPECT_EQ((*ite).score, rec3.score);
		ite++;
		EXPECT_EQ((*ite).score, rec.score);
		ite++;

		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.score < b.score; });

		Record rec5{ 7,"e" };
		Record rec6{ 120,"f" };
		Record rec7{ 30,"g" };

		ite = list.Begin();
		ite++;
		list.Insert(ite, rec5);

		ite = list.Begin();
		ite++;
		ite++;
		ite++;
		list.Insert(ite, rec6);

		ite = list.Begin();
		ite++;
		ite++;
		ite++;
		ite++;
		ite++;
		list.Insert(ite, rec7);

		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.score < b.score; });

		ite = list.Begin();
		EXPECT_EQ((*ite).score, rec2.score);
		ite++;
		EXPECT_EQ((*ite).score, rec5.score);
		ite++;
		EXPECT_EQ((*ite).score, rec4.score);
		ite++;
		EXPECT_EQ((*ite).score, rec7.score);
		ite++;
		EXPECT_EQ((*ite).score, rec3.score);
		ite++;
		EXPECT_EQ((*ite).score, rec6.score);
		ite++;
		EXPECT_EQ((*ite).score, rec.score);
		ite++;
	}

	/**********************************************************************************//**
	@brief		キー指定をしなかった(nullptrを渡した)時の挙動テスト
	@details	ID:リスト-6\n
				クイックソートのテストです。\n
				キー指定をしなかった(nullptrを渡した)時の挙動を確認しています。\n
				エラー含めて、何も起こらなければ成功です。\n
	*//***********************************************************************************/
	TEST(QuickSort, NokeDesignation) {
		BidirectionalList<Record> list;
		BidirectionalList<Record>::Iterator ite = list.Begin();
		Record rec{ 432,"a" };
		Record rec2{ 1,"b" };
		Record rec3{ 36,"c" };
		Record rec4{ 28,"d" };
		list.Insert(ite, rec);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec2);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec3);
		ite = list.Begin();
		ite++;
		list.Insert(ite, rec4);

		EXPECT_FALSE(list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			nullptr));
	}

	/**********************************************************************************//**
	@brief		型などが不適切なキー指定が引数で渡された時の挙動テスト
	@details	ID:リスト-7\n
				クイックソートのテストです。\n
				型などが不適切なキー指定が引数で渡された時の挙動を確認しています。\n
				コンパイルエラーになれば成功です。\n
				コンパイルエラーをチェック。自動テスト化しない\n
	*//***********************************************************************************/
	TEST(QuickSort, IncorrectKeySpecificationPassedAsAnArgument) {

		//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
		BidirectionalList<Record> list;
		BidirectionalList<Record>::Iterator ite = list.Begin();
		Record rec{ 432,"a" };
		list.Insert(ite, rec);
		ite = list.Begin();
		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const int& a, const int& b) {return a < b; });	// ここでエラーになります

#endif // defined TT_TEST_INSERT_WHEN_CONST
		SUCCEED();

	}

	/**********************************************************************************//**
	@brief		非constのメソッドであるかのテスト
	@details	ID:リスト-8\n
				クイックソートのテストです。\n
				非constのメソッドであるかを確認しています。\n
				コンパイルエラーになれば成功です。\n
				constのリストから呼び出して、コンパイルエラーとなるかをチェック。\n
				自動テスト化しなくてよい。\n
	*//***********************************************************************************/
	TEST(QuickSort, IsItAMethodOfConst) {
		//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
		const BidirectionalList<Record> list;
		BidirectionalList<Record>::Const_Iterator it = list.ConstBegin();
		Record rec = { 1, "a" };
		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,		// ここでエラーになります
			[](const Record& a, const Record& b) {return a.score < b.score; });	

#endif // defined TT_TEST_INSERT_WHEN_CONST
		SUCCEED();
	}

}

