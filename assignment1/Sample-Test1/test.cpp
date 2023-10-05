#include "pch.h"
#include "../assignment1/BidirectionalList.h"

//TEST(DataNum, )
//{
//
//}

// ID:0_0
TEST(DataNum, NullList) {
	BidirectionalList list;
	int ret = list.NumData();
	EXPECT_EQ(ret,0);
}

// ID:0_1
TEST(DataNum, PushBackSuccess){
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator* it = new BidirectionalList::Iterator(inner1.m_node);
	list.Push(it);

	int ret = list.NumData();

	delete it;
	EXPECT_EQ(ret, 1);
}

// ID:0_2
TEST(DataNum, PushBackFail){
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);

	BidirectionalList::Iterator* it = nullptr;

	list.Push(it);

	int ret = 0;
	ret = list.NumData();
	EXPECT_EQ(0, ret);
}


// ID:0_3
TEST(DataNum, DataAddSuccess)
{
	BidirectionalList list;

	// データの挿入テスト
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner::Node inner;
	inner.m_record = record1;

	BidirectionalList::Iterator ite1(&inner);
	list.Push(&ite1);
	BidirectionalList::Iterator insertedIte = list.Begin();
	
	EXPECT_EQ((*insertedIte).score, "1");
	EXPECT_EQ((*insertedIte).userName, "a");

	// リストのデータ数を確認
	EXPECT_EQ(list.NumData(), 1);

	BidirectionalList::Iterator it = list.Begin();
	EXPECT_EQ((*it).score, "1");
	EXPECT_EQ((*it).userName, "a");

}

// ID:0_4
TEST(DataNum, DataAddFail)
{
    BidirectionalList list;

    // 空のイテレータを作成
    BidirectionalList::Iterator emptyIte(nullptr);

    // データの挿入が失敗することを確認
	list.Push(&emptyIte);
	int ret = list.NumData();
    EXPECT_EQ(ret, 0);
}


// ID:0_5
TEST(DataNum, DatadeleteSaccess)
{
	BidirectionalList list;

	// 空のイテレータを作成
	BidirectionalList::Iterator emptyIte(nullptr);

	// データの挿入
	list.Push(&emptyIte);

	// データの削除を行い、戻り値として1が返ることを確認
	list.Pop(&emptyIte);
	int ret = list.NumData();
	EXPECT_EQ(ret, 0);
}


// ID:0_6
TEST(DataNum, DataDeleteFail)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it = new BidirectionalList::Iterator(inner1.m_node);
	it->m_node = inner1.m_node;
	list.Push(it);

    // データを削除して成功を確認
    BidirectionalList::Iterator removedIte = list.Begin();
    list.Pop(&removedIte);

    BidirectionalList::Iterator failedRemoveIte = list.Begin();
	EXPECT_EQ(list.Pop(&failedRemoveIte),1);
	delete it;

}

// ID:0_7
TEST(DataNum, DeleteToNulList)
{
	BidirectionalList list;

	// 空のリストからデータの削除を試みる
	BidirectionalList::Iterator removedIte = list.Begin();
	EXPECT_EQ(list.Pop(&removedIte),0);

}


// ID:0_9
TEST(Add, PushToNulList)
{
	BidirectionalList list;

	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it = new BidirectionalList::Iterator(inner1.m_node);
	it->m_node = inner1.m_node;
	EXPECT_EQ(list.Push(it),true);


	EXPECT_EQ(list.NumData(), 1);

	// 挿入した位置の前後に要素が挿入されたことを確認
	BidirectionalList::Iterator ite = list.Begin();
	EXPECT_EQ((*ite).score, "1");
	EXPECT_EQ((*ite).userName, "a");
	delete it;
}
// ID:0_10
TEST(Add, SetHeadIteratortoList)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it = new BidirectionalList::Iterator(inner1.m_node);
	it->m_node = inner1.m_node;
	list.Push(it);

	BidirectionalList::Inner::Node::Record record2 = { "2", "b" };
	BidirectionalList::Inner inner2(record2);
	BidirectionalList::Iterator*it2 = new BidirectionalList::Iterator(inner2.m_node);
	it2->m_node = inner2.m_node;
	list.Push(it2);

	EXPECT_EQ(list.NumData(), 2);


	BidirectionalList::Inner::Node::Record record3 = { "3", "c" };
	BidirectionalList::Inner inner3(record3);
	BidirectionalList::Iterator *it3 = new BidirectionalList::Iterator(inner3.m_node);
	it3->m_node = inner3.m_node;
	EXPECT_EQ(list.Push(it3),true);

	EXPECT_EQ(list.NumData(), 3);

	// 先頭に挿入した要素が新しい先頭になり、元々の先頭要素が2番目になることを確認
	BidirectionalList::Iterator ite = list.Begin();
	EXPECT_EQ((*ite).score,"3");
	EXPECT_EQ((*ite).userName, "c");

	++ite;
	EXPECT_EQ((*ite).score, "1");
	EXPECT_EQ((*ite).userName, "a");

	++it;
	EXPECT_EQ((*it).m_node->m_record.score, "2");
	EXPECT_EQ((*it).m_node->m_record.userName, "b");
	delete it2;
	delete it3;
	delete it;
}

// ID:0_11
TEST(Add, SetTailIteratortoList)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it = new BidirectionalList::Iterator(inner1.m_node);
	it->m_node = inner1.m_node;
	list.Push(it);

	BidirectionalList::Inner::Node::Record record2 = { "2", "b" };
	BidirectionalList::Inner inner2(record2);
	BidirectionalList::Iterator *it2 = new BidirectionalList::Iterator(inner2.m_node);
	it2->m_node = inner2.m_node;
	list.Push(it2);

	EXPECT_EQ(list.NumData(), 2);

	BidirectionalList::Iterator endIte = list.End();

	BidirectionalList::Inner::Node::Record record3 = { "3", "c" };
	BidirectionalList::Inner inner3(record3);
	BidirectionalList::Iterator *it3 = new BidirectionalList::Iterator(inner3.m_node);
	it3->m_node = inner3.m_node;
	EXPECT_EQ(list.Push(it3),true);

	EXPECT_EQ(list.NumData(), 3);

	BidirectionalList::Iterator ite = list.Begin();
	++ite;
	++ite;
	EXPECT_EQ((*ite).score, "3");
	EXPECT_EQ((*ite).userName, "c");
	delete it3;
	delete it2;
	delete it;
}
// ID:0_12
TEST(Add, SetIteratortoList)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it = new BidirectionalList::Iterator(inner1.m_node);
	it->m_node = inner1.m_node;
	list.Push(it);

	BidirectionalList::Inner::Node::Record record2 = { "2", "b" };
	BidirectionalList::Inner inner2(record2);
	BidirectionalList::Iterator *it2 = new BidirectionalList::Iterator(inner2.m_node);
	it2->m_node = inner2.m_node;
	list.Push(it2);


	EXPECT_EQ(list.NumData(), 2);

	BidirectionalList::Inner::Node::Record record3 = { "3", "c" };
	BidirectionalList::Inner inner3(record3);
	BidirectionalList::Iterator *it3 = new BidirectionalList::Iterator(inner3.m_node);
	it3->m_node = inner3.m_node;
	EXPECT_EQ(list.Push(it3),true);

	EXPECT_EQ(list.NumData(), 3);

	BidirectionalList::Iterator ite = list.Begin();
	EXPECT_EQ((*ite).score, "1");
	EXPECT_EQ((*ite).userName, "a");

	++ite;
	EXPECT_EQ((*ite).score, "3");
	EXPECT_EQ((*ite).userName, "c");

	++ite;
	EXPECT_EQ((*ite).score, "2");
	EXPECT_EQ((*ite).userName, "b");

	delete it3;
	delete it2;
	delete it;
}
// ID:0_13
TEST(Add, PushToConst)
{

}
// ID:0_14
TEST(Add, AddToNullList)
{
	BidirectionalList list;
	BidirectionalList::Iterator invalidIte(nullptr);
	EXPECT_EQ(list.Push(&invalidIte),false);
}

// ID:0_16
TEST(Delete, PopBackFromEmptyList)
{
	BidirectionalList list;

	// リストが空であることを確認
	EXPECT_EQ(list.NumData(), 0);

	// 空のリストから要素を削除しても何も起こらないことを確認
	BidirectionalList::Iterator ite(nullptr);
	EXPECT_EQ(list.Pop(&ite),false);

	// リストが空であることを再確認
	EXPECT_EQ(list.NumData(), 0);
}
// ID:0_17
TEST(Delete, SetIteratorFrontFromlist)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it1 = new BidirectionalList::Iterator(inner1.m_node);
	it1->m_node = inner1.m_node;
	list.Push(it1);

	BidirectionalList::Inner::Node::Record record2 = { "2", "b" };
	BidirectionalList::Inner inner2(record2);
	BidirectionalList::Iterator *it2 = new BidirectionalList::Iterator(inner2.m_node);
	it2->m_node = inner2.m_node;
	list.Push(it2);

	// リストのデータ数が2であることを確認
	EXPECT_EQ(list.NumData(), 2);

	// 先頭イテレータを取得
	BidirectionalList::Iterator frontIte = list.Begin();

	// 先頭要素を削除
	EXPECT_EQ(list.Pop(&frontIte),true);

	// リストのデータ数が1であることを確認
	EXPECT_EQ(list.NumData(), 1);

	// リストの要素を確認
	BidirectionalList::Iterator ite = list.Begin();
	EXPECT_EQ((*ite).score, "2");
	EXPECT_EQ((*ite).userName, "b");
	delete it2;
	delete it1;
}
// ID:0_18
TEST(Delete, SetIteratorTailFromlist)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it1 = new BidirectionalList::Iterator(inner1.m_node);
	it1->m_node = inner1.m_node;
	list.Push(it1);

	BidirectionalList::Inner::Node::Record record2 = { "2", "b" };
	BidirectionalList::Inner inner2(record2);
	BidirectionalList::Iterator *it2 = new BidirectionalList::Iterator(inner2.m_node);
	it2->m_node = inner2.m_node;
	list.Push(it2);

	EXPECT_EQ(list.NumData(), 2);

	// 末尾イテレータを取得
	BidirectionalList::Iterator backIte = list.End();

	// 末尾要素を削除しても何も起こらないことを確認
	EXPECT_EQ(list.Pop(&backIte), false);

	EXPECT_EQ(list.NumData(), 2);

	BidirectionalList::Iterator ite = list.Begin();
	EXPECT_EQ((*ite).score, "1");
	EXPECT_EQ((*ite).userName, "a");

	++ite;
	EXPECT_EQ((*ite).score, "2");
	EXPECT_EQ((*ite).userName, "b");
	delete it2;
	delete it1;
}

// ID:0_19
TEST(Delete, SetIteratorFromlist)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1", "a" };
	BidirectionalList::Inner inner1(record1);
	BidirectionalList::Iterator *it = new BidirectionalList::Iterator(inner1.m_node);
	it->m_node = inner1.m_node;
	list.Push(it);

	BidirectionalList::Inner::Node::Record record2 = { "2", "b" };
	BidirectionalList::Inner inner2(record2);
	BidirectionalList::Iterator *it2 = new BidirectionalList::Iterator(inner2.m_node);
	it2->m_node = inner2.m_node;
	list.Push(it2);

	ASSERT_EQ(list.NumData(), 2);

	// 末尾イテレーターを取得
	BidirectionalList::Iterator backIte = list.End();

	// 末尾要素を削除しても何も起こらないことを確認
	EXPECT_EQ(list.Pop(&backIte),true);


	ASSERT_EQ(list.NumData(), 2);

	BidirectionalList::Iterator ite = list.Begin();
	ASSERT_EQ((*ite).score, "1");
	ASSERT_EQ((*ite).userName, "a");

	++it;
	ASSERT_EQ((*ite).score, "2");
	ASSERT_EQ((*ite).userName, "b");

	delete it2;
	delete it;
}
// ID:0_20
TEST(Delete, DeleteConstIterator)
{
}

// ID:0_21
TEST(Delete, AddNullDelete)
{
	BidirectionalList list;
	BidirectionalList::Iterator invalidIte(nullptr);
	EXPECT_EQ(list.Push(&invalidIte), false);
	EXPECT_EQ(list.Pop(&invalidIte), false);
}

// ID:0_23
TEST(GetHeadIterator, NullList)
{
	BidirectionalList list;
	BidirectionalList::Iterator it = list.Begin();
	EXPECT_EQ(list.Begin(), it);
}

// ID:0_24
TEST(GetHeadIterator, CallTInTwoLIst)
{
	BidirectionalList list;

	BidirectionalList::Inner::Node::Record record = { "1", "a" };
	BidirectionalList::Inner inner(record);
	BidirectionalList::Iterator* it = new BidirectionalList::Iterator(inner.m_node);
	list.Push(it);

	BidirectionalList::Iterator headIterator = list.Begin();

	// 先頭イテレータが正しい要素か確認
	EXPECT_EQ((*headIterator).score, "1");
	EXPECT_EQ((*headIterator).userName, "a");
	delete it;
}

// ID:0_25
TEST(GetHeadIterator, CallTwoElementsList)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1","a" };
	BidirectionalList::Inner innder1(record1);
	BidirectionalList::Iterator* it1 = new BidirectionalList::Iterator(innder1.m_node);
	list.Push(it1);
	BidirectionalList::Inner::Node::Record record2 = { "2","b" };
	BidirectionalList::Inner innder2(record2);
	BidirectionalList::Iterator* it2 = new BidirectionalList::Iterator(innder2.m_node);
	list.Push(it2);

	// 先頭のイテレータ画正しい要素を指しているか
	BidirectionalList::Iterator headIterator = list.Begin();
	EXPECT_EQ((*headIterator).score, "1");
	EXPECT_EQ((*headIterator).userName, "a");


	delete it2;
	delete it1;
}
// ID:0_26
TEST(GetHeadIterator, CalltoAfterAddData)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1","a" };
	BidirectionalList::Inner innder1(record1);
	BidirectionalList::Iterator* it1 = new BidirectionalList::Iterator(innder1.m_node);
	list.Push(it1);

	BidirectionalList::Iterator headIterator = list.Begin();
	EXPECT_EQ((*headIterator).score, "1");
	EXPECT_EQ((*headIterator).userName, "a");

	BidirectionalList::Inner::Node::Record record2 = { "2","b" };
	BidirectionalList::Inner innder2(record2);
	BidirectionalList::Iterator* it2 = new BidirectionalList::Iterator(innder2.m_node);
	list.Push(it2);

	headIterator = list.Begin();
	EXPECT_EQ((*headIterator).score, "1");
	EXPECT_EQ((*headIterator).userName, "a");

	BidirectionalList::Inner::Node::Record record3 = { "3","c" };
	BidirectionalList::Inner innder3(record3);
	BidirectionalList::Iterator* it3 = new BidirectionalList::Iterator(innder3.m_node);
	list.Push(it3);

	headIterator = list.Begin();
	EXPECT_EQ((*headIterator).score, "1");
	EXPECT_EQ((*headIterator).userName, "a");

	delete it3;
	delete it2;
	delete it1;
}

// ID:0_27
TEST(GetHeadIterator, CalltoAfterDeleteData)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1","a" };
	BidirectionalList::Inner innder1(record1);
	BidirectionalList::Iterator* it1 = new BidirectionalList::Iterator(innder1.m_node);
	list.Push(it1);

	BidirectionalList::Inner::Node::Record record2 = { "2","b" };
	BidirectionalList::Inner innder2(record2);
	BidirectionalList::Iterator* it2 = new BidirectionalList::Iterator(innder2.m_node);
	list.Push(it2);

	BidirectionalList::Inner::Node::Record record3 = { "3","c" };
	BidirectionalList::Inner innder3(record3);
	BidirectionalList::Iterator* it3 = new BidirectionalList::Iterator(innder3.m_node);
	list.Push(it3);

	list.Pop(it1);
	BidirectionalList::Iterator headIterator = list.Begin();
	EXPECT_EQ((*headIterator).score, "1");
	EXPECT_EQ((*headIterator).userName, "a");

	list.Pop(it2);
	headIterator = list.Begin();
	EXPECT_EQ((*headIterator).score, "2");
	EXPECT_EQ((*headIterator).userName, "b");

	list.Pop(it3);
	headIterator = list.Begin();
	EXPECT_EQ((*headIterator).score, "3");
	EXPECT_EQ((*headIterator).userName, "c");

	delete it3;
	delete it2;
	delete it1;
}

// ID:0_29
TEST(GetConstHeadIterator, CallEmptyList)
{
	BidirectionalList list;
    BidirectionalList::Const_Iterator it = list.ConstBegin();
    EXPECT_EQ(list.ConstBegin(), it);
}

// ID:0_30
TEST(GetConstHeadIterator, CalloneElementList)
{
	BidirectionalList list;
	BidirectionalList::Inner::Node::Record record1 = { "1","a" };
	BidirectionalList::Inner innder1(record1);
	BidirectionalList::Iterator* it1 = new BidirectionalList::Iterator(innder1.m_node);
	list.Push(it1);

	BidirectionalList::Const_Iterator ite = list.ConstBegin();
	EXPECT_EQ((*ite).score, "1");
	EXPECT_EQ((*ite).userName, "a");
	delete it1;
}

// ID:0_30
// ID:0_31
// ID:0_32
// ID:0_33
// ID:0_34
// ID:0_35
// ID:0_36
