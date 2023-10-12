#include "pch.h"
#include "../assignment1/BidirectionalList.h"

using namespace std;

namespace ex01_DataStructure
{
	namespace chapter01
	{

		// ID:0_0
		TEST(DataNum, NullList) {
			BidirectionalList list;
			EXPECT_EQ(0, list.NumData());
		}

		// ID:0_1
		TEST(DataNum, InsertBackSuccess) {
			BidirectionalList list;
			BidirectionalList::Record rec = { "1", "a" };
			BidirectionalList::Iterator ite = list.Begin();

			list.Insert(ite, rec);
			EXPECT_EQ(1, list.NumData());
		}

		// ID:0_2
		TEST(DataNum, InsertBackFail) {
			// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
			//BidirectionalList list;
			//BidirectionalList::Iterator ite = list.End();
			//BidirectionalList::Record rec = { "1", "a" };

			//list.Insert(ite, rec);
			//EXPECT_EQ(0,list.NumData());
		}


		// ID:0_3
		TEST(DataNum, DataAddSuccess)
		{
			BidirectionalList list;
			BidirectionalList::Record rec = { "1", "a" };
			BidirectionalList::Iterator ite = list.Begin();

			list.Insert(ite, rec);
			EXPECT_EQ(1, list.NumData());
		}


		// ID:0_4
		TEST(DataNum, DataAddFail)
		{// �������m�ۂ̎��s���̂ݎ��s���邽�߃X�L�b�v
		}


		// ID:0_5
		TEST(DataNum, DatadeleteSaccess)
		{
			BidirectionalList list;

			BidirectionalList::Record rec = { "1", "a" };
			BidirectionalList::Iterator ite = list.Begin();
			// �f�[�^�̑}��
			list.Insert(ite, rec);
			BidirectionalList::Iterator it = list.Begin();
			list.Delete(it);

			EXPECT_EQ(0, list.NumData());

		}


		// ID:0_6
		TEST(DataNum, DataDeleteFail)
		{
			BidirectionalList list;
			BidirectionalList::Record rec = { "1", "a" };
			BidirectionalList::Iterator ite = list.Begin();
			// �f�[�^�̑}��
			list.Insert(ite, rec);
			BidirectionalList::Iterator it = nullptr;
			// �f�[�^���폜
			list.Delete(it);
			EXPECT_EQ(1, list.NumData());
		}


		// ID:0_7
		TEST(DataNum, DeleteToNulList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator it = list.Begin();
			// �󃊃X�g�̒����폜
			EXPECT_FALSE(list.Delete(it));
			EXPECT_EQ(0, list.NumData());
		}
		// ID:0_8
		TEST(DataNum, IsItAMethodOfConst)
		{
#define TT_TET_GETDATA_NUM_WHEN_CONST
#if defined TT_TET_GETDATA_NUM_WHEN_CONST
			const BidirectionalList list;
			EXPECT_EQ(0, list.NumData());
#endif // defined TT_TET_GETDATA_NUM_WHEN_CONST
			SUCCEED();
		}

		// ID:0_9
		TEST(Add, InsertToNulList)
		{
			BidirectionalList list;
			BidirectionalList::Record rec = { "1", "a" };
			BidirectionalList::Iterator ite = list.Begin();
			EXPECT_EQ(true, list.Insert(ite, rec));

		}

		// ID:0_10
		TEST(Add, SetHeadIteratortoList)
		{
			// �f�[�^�}��
			BidirectionalList list;
			BidirectionalList::Record rec = { "1", "a" };
			BidirectionalList::Iterator it = list.Begin();
			list.Insert(it, rec);
			it = list.Begin();
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(it, rec2);
			it = list.Begin();
			BidirectionalList::Record rec3 = { "3", "c" };
			list.Insert(it, rec3);

			// �擪�v�f�̓���ւ�肪�����������m�F
			BidirectionalList::Iterator it2 = list.Begin();
			it2 = list.Begin();
			EXPECT_TRUE((*it2).score == "3");
			EXPECT_TRUE((*it2).userName == "c");
			++it2;
			EXPECT_TRUE((*it2).score == "2");
			EXPECT_TRUE((*it2).userName == "b");
			++it2;
			EXPECT_TRUE((*it2).score == "1");
			EXPECT_TRUE((*it2).userName == "a");

		}

		// ID:0_11
		TEST(Add, SetTailIteratortoList)
		{
			// �f�[�^�̑}��
			BidirectionalList list;
			BidirectionalList::Record rec = { "1", "a" };
			BidirectionalList::Iterator it = list.End();
			list.Insert(it, rec);
			it = list.End();
			--it;
			BidirectionalList::Record rec2 = { "2", "b" };
			// ����������
			list.Insert(it, rec2);
			it = list.End();
			--it;
			--it;
			BidirectionalList::Record rec3 = { "3", "c" };
			// ����������
			list.Insert(it, rec3);

			// ���Ԃ��m�F
			it = list.End();
			--it;
			EXPECT_TRUE((*it).score == "1");
			EXPECT_TRUE((*it).userName == "a");
			--it;
			EXPECT_TRUE((*it).score == "2");
			EXPECT_TRUE((*it).userName == "b");
			--it;
			EXPECT_TRUE((*it).score == "3");
			EXPECT_TRUE((*it).userName == "c");

		}

		// ID:0_12
		TEST(Add, SetIteratortoList)
		{
			// �f�[�^�}��
			BidirectionalList list;
			BidirectionalList::Record record1 = { "1", "a" };
			BidirectionalList::Record record2 = { "2", "b" };
			BidirectionalList::Record record3 = { "3", "c" };
			BidirectionalList::Iterator it = list.Begin();
			// �擪
			list.Insert(it, record1);
			it = list.Begin();
			EXPECT_EQ((*it).score, "1");
			EXPECT_EQ((*it).userName, "a");

			++it;
			// �擪�̎�
			list.Insert(it, record2);
			it = list.Begin();
			EXPECT_EQ((*it).score, "1");
			EXPECT_EQ((*it).userName, "a");
			++it;
			EXPECT_EQ((*it).score, "2");
			EXPECT_EQ((*it).userName, "b");

			it = list.Begin();
			++it;

			// �}�����ꂽ��̃f�[�^�̊�
			list.Insert(it, record3);

			// ���񏇂��m�F
			BidirectionalList::Iterator ite = list.Begin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");

			++ite;
			EXPECT_EQ((*ite).score, "3");
			EXPECT_EQ((*ite).userName, "c");

			++ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
		}

		// ID:0_13
		TEST(Add, InsertToConst)
		{
			BidirectionalList list;
			BidirectionalList::Record record1 = { "1", "a" };
			BidirectionalList::Record record2 = { "2", "b" };
			BidirectionalList::Record record3 = { "3", "c" };
			BidirectionalList::Const_Iterator cite = list.ConstBegin();
			// �擪�f�[�^�̑}��
			list.Insert(cite, record1);
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, "1");
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			// ���ɑ}��
			list.Insert(cite, record2);
			// ����̐���m�F
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, "1");
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			EXPECT_EQ((*cite).score, "2");
			EXPECT_EQ((*cite).userName, "b");


			cite = list.ConstBegin();
			++cite;
			// �^�񒆂Ƀf�[�^�}��
			list.Insert(cite, record3);
			cite = list.ConstBegin();
			// �ŏI�I�Ȑ���m�F
			EXPECT_EQ((*cite).score, "1");
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			EXPECT_EQ((*cite).score, "3");
			EXPECT_EQ((*cite).userName, "c");
			++cite;
			EXPECT_EQ((*cite).score, "2");
			EXPECT_EQ((*cite).userName, "b");
		}

		// ID:0_14
		TEST(Add, AddToNullList)
		{
			BidirectionalList list;
			BidirectionalList list2;
			BidirectionalList::Iterator it = list.Begin();	
			BidirectionalList::Iterator it2 = list2.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list2.Insert(it2, rec);
			// �ʃ��X�g�̏���n��
			EXPECT_FALSE(false, list2.Delete(it));
		}
		// ID:0_15
		TEST(Add, IsItAMethodOfConst)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(it, rec);//�����ŃG���[

#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		// ID:0_16
		TEST(Delete, DeleteBackFromEmptyList)
		{
			BidirectionalList list;

			// ���X�g����
			EXPECT_EQ(list.NumData(), 0);

			// �����N����Ȃ���
			BidirectionalList::Iterator ite = list.Begin();
			EXPECT_EQ(list.Delete(ite), false);

		}

		// ID:0_17
		TEST(Delete, SetIteratorFrontFromlist)
		{
			//�f�[�^�̑}��
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(ite, rec);

			ite = list.Begin();
			// ���̃f�[�^�}��
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(ite, rec2);

			ite = list.Begin();
			// �擪�̃f�[�^�폜
			EXPECT_EQ(true, list.Delete(ite));
			
			// ���̐擪�̃f�[�^���m�F
			ite = list.Begin();
			EXPECT_TRUE((*ite).score == "1");
			EXPECT_TRUE((*ite).userName == "a");
		}

		// ID:0_18
		TEST(Delete, SetIteratorTailFromlist)
		{
			// �f�[�^�}��
			BidirectionalList list;
			BidirectionalList::Iterator it = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(it, rec);

			// ���̃f�[�^��}��
			BidirectionalList::Record rec2 = { "2", "b" };
			it = list.End();
			list.Insert(it, rec2);

			// �����f�[�^���폜(�_�~�[�m�[�h���폜)
			BidirectionalList::Iterator ite = list.End();
			EXPECT_EQ(false, list.Delete(ite));
		}

		// ID:0_19

		TEST(Delete, SetIteratorFromlist)
		{
			BidirectionalList list;
			BidirectionalList::Record record1 = { "1", "a" };
			BidirectionalList::Record record2 = { "2", "b" };
			BidirectionalList::Record record3 = { "3", "c" };
			BidirectionalList::Iterator it = list.Begin();
			list.Insert(it, record1);
			it = list.Begin();
			++it;
			list.Insert(it, record2);
			it = list.Begin();
			++it;
			list.Insert(it, record3);

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
		}

		// ID:0_20
		TEST(Delete, DeleteConstIterator)
		{
			BidirectionalList list;
			BidirectionalList::Record record1 = { "1", "a" };
			BidirectionalList::Record record2 = { "2", "b" };
			BidirectionalList::Record record3 = { "3", "c" };
			BidirectionalList::Const_Iterator cite = list.ConstBegin();
			list.Insert(cite, record1);
			cite = list.Begin();
			++cite;
			list.Insert(cite, record2);
			cite = list.Begin();
			++cite;
			++cite;
			list.Insert(cite, record3);
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, "1");
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			EXPECT_EQ((*cite).score, "2");
			EXPECT_EQ((*cite).userName, "b");
			++cite;
			EXPECT_EQ((*cite).score, "3");
			EXPECT_EQ((*cite).userName, "c");

			cite = list.ConstBegin();

			list.Delete(cite);

		}

		// ID:0_21
		TEST(Delete, AddNullDelete)
		{
			BidirectionalList list;
			BidirectionalList::Record record1 = { "1","a" };
			BidirectionalList::Iterator it = nullptr;

			list.Insert(it, record1);

		}
		// ID:0_22
		TEST(Delete, IsItAMethodOfConst)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(it, rec);//�����ŃG���[
			it = list.ConstBegin();
			list.Push_Back(it);//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


		// ID:0_23
		TEST(GetHeadIterator, NullList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator it = list.Begin();
			EXPECT_EQ(list.Begin(), it);
		}

		// ID:0_24
		TEST(GetHeadIterator, CalloneElementList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);


			ite = list.Begin();
			// �擪�C�e���[�^���������v�f��
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:0_25
		TEST(GetHeadIterator, CallTwoElementsList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);


			// �擪�̃C�e���[�^�搳�����v�f���w���Ă��邩
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:0_26
		TEST(GetHeadIterator, CalltoAfterAddData)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");

			ite = list.Begin();
			++ite;
			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(ite, record3);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, "3");
			EXPECT_EQ((*ite).userName, "c");
			++ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
		}

		// ID:0_27
		TEST(GetHeadIterator, CalltoAfterDeleteData)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;

			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			++ite;
			++ite;
			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(ite, record3);

			ite = list.Begin();
			list.Delete(ite);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
			++ite;
			EXPECT_EQ((*ite).score, "3");
			EXPECT_EQ((*ite).userName, "c");

			ite = list.Begin();
			ite++;
			list.Delete(ite);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");

			list.Delete(ite);
			ite = list.Begin();
			EXPECT_EQ(0, list.NumData());

		}

		// ID:0_28
		TEST(GetHeadIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Iterator it = list.ConstBegin();//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
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
			BidirectionalList::Const_Iterator ite = list.ConstBegin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);

			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:0_31
		TEST(GetConstHeadIterator, CallTweElementList)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);


			// �擪�̃C�e���[�^���������v�f���w���Ă��邩
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:0_32
		TEST(GetConstHeadIterator, CalltoAfterAddData)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.ConstBegin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");

			ite = list.ConstBegin();
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);
			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");

			ite = list.ConstBegin();
			++ite;
			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(ite, record3);
			ite = list.ConstBegin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			EXPECT_EQ((*ite).score, "3");
			EXPECT_EQ((*ite).userName, "c");
			++ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
		}

		// ID:0_33
		TEST(GetConstHeadIterator, CalltoAfterDeleteData)
		{
			BidirectionalList list;
			BidirectionalList::Iterator cite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(cite, record1);
			cite = list.Begin();
			++cite;

			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(cite, record2);
			cite = list.Begin();
			++cite;
			++cite;

			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(cite, record3);

			cite = list.Begin();
			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ((*cite).score, "2");
			EXPECT_EQ((*cite).userName, "b");
			++cite;
			EXPECT_EQ((*cite).score, "3");
			EXPECT_EQ((*cite).userName, "c");

			cite = list.Begin();
			cite++;
			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ((*cite).score, "2");
			EXPECT_EQ((*cite).userName, "b");

			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ(0, list.NumData());
		}

		// ID:0_34
		TEST(GetConstHeadIterator, IsItAMethodOfConst)
		{
#define TT_TET_GETDATA_NUM_WHEN_CONST
#if defined TT_TET_GETDATA_NUM_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator cit = list.ConstBegin();

#endif // defined TT_TET_GETDATA_NUM_WHEN_CONST
			SUCCEED();
		}

		// ID:0_35
		TEST(GetTailIterator, NullList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator it = list.End();
			EXPECT_EQ(list.End(), it);
		}

		// ID:0_36
		TEST(GetTailIterator, CalloneElementList)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;

			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:0_37
		TEST(GetTailIterator, CallTwoElementsList)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);


			// �����̃C�e���[�^���������v�f���w���Ă��邩
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
		}

		// ID:0_38
		TEST(GetTailIterator, CalltoAfterAddData)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");

			ite = list.Begin();
			++ite;
			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(ite, record3);
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, "3");
			EXPECT_EQ((*ite).userName, "c");
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:0_39
		TEST(GetTailIterator, CalltoAfterDeleteData)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(ite, record3);

			ite = list.End();
			--ite;
			--ite;
			list.Delete(ite);
			--ite;
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");

			ite = list.End();
			--ite;
			--ite;
			list.Delete(ite);
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");

			ite = list.End();
			--ite;
			list.Delete(ite);
			EXPECT_EQ(0, list.NumData());
		}

		// ID:0_40
		TEST(GetTailIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Iterator it = list.ConstEnd();//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		// ID:0_41
		TEST(GetConstTailIterator, CallEmptyList)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstEnd();
			EXPECT_EQ(list.ConstEnd(), it);
		}

		// ID:0_42
		TEST(GetConstTailIterator, CalloneElementList)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.ConstBegin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);

			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:0_43
		TEST(GetConstTailIterator, CallTweElementList)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.ConstBegin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);


			// �����̃C�e���[�^���������v�f��
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");

		}

		// ID:0_44
		TEST(GetConstTailIterator, CalltoAfterAddData)
		{
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.ConstEnd();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");

			ite = list.ConstEnd();
			--ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");

			ite = list.End();
			--ite;
			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(ite, record3);
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
			--ite;
			EXPECT_EQ((*ite).score, "3");
			EXPECT_EQ((*ite).userName, "c");
			--ite;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
		}
		// ID:0_45
		TEST(GetConstTailIterator, CalltoAfterDeleteData)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record record1 = { "1", "a" };
			list.Insert(ite, record1);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record2 = { "2", "b" };
			list.Insert(ite, record2);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record record3 = { "3", "c" };
			list.Insert(ite, record3);
			ite = list.End();
			--ite;
			list.Delete(ite);

			BidirectionalList::Const_Iterator cite = list.ConstEnd();
			--cite;
			EXPECT_EQ((*cite).score, "3");
			EXPECT_EQ((*cite).userName, "c");
			--cite;
			EXPECT_EQ((*cite).score, "1");
			EXPECT_EQ((*cite).userName, "a");

			ite = list.End();
			--ite;
			--ite;
			list.Delete(ite);
			cite = list.ConstEnd();
			--cite;
			EXPECT_EQ((*cite).score, "3");
			EXPECT_EQ((*cite).userName, "c");

			list.Delete(cite);
			cite = list.Begin();
			EXPECT_EQ(0, list.NumData());
		}

		// ID:0_46
		TEST(GetConstTailIterator, IsItAMethodOfConst)
		{
#define TT_TET_GETDATA_NUM_WHEN_CONST
#if defined TT_TET_GETDATA_NUM_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator cit = list.ConstEnd();

#endif // defined TT_TET_GETDATA_NUM_WHEN_CONST
			SUCCEED();
		}
	}

	namespace chapter02
	{
		// ID:1_0
		TEST(GetElementToIterator, CalltoList)
		{
			BidirectionalList::Iterator it(nullptr);
			ASSERT_DEATH((*it), ".*");
		}

		// ID:1_1
		TEST(GetElementToIterator, CallToNoList)
		{
			BidirectionalList List;
			BidirectionalList::Iterator it = List.Begin();
			BidirectionalList::Record record = { "1","a" };
			List.Insert(it, record);
			it = List.Begin();

			BidirectionalList::Record rec = { "2","b" };

			(*it).score = rec.score;
			(*it).userName = rec.userName;

			EXPECT_EQ((*it).score, "2");
			EXPECT_EQ((*it).userName, "b");
		}

		// ID:1_2
		TEST(GetElementToIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(rec, it);
			it = list.ConstBegin();
			(*it).score = "3";//�����ŃG���[
			(*it).userName = "c";//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


		// ID:1_3
		TEST(GetElementToIterator, CallOnEmtyList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator it = list.Begin();
			ASSERT_DEATH((*it),".*");
		}


		// ID:1_4
		TEST(GetElementToIterator, CalOnIterator)
		{
			BidirectionalList list;
			BidirectionalList::Iterator it = list.End();

			ASSERT_DEATH((*it), ".*");
		}
		// ID:1_5
		TEST(IteratorToTailOfTheList, CalltoList)
		{
			BidirectionalList::Iterator it(nullptr);

			ASSERT_DEATH({ ++it; }, ".*");
		}

		// ID:1_6
		TEST(IteratorToTailOfTheList, CallFirstIteratorWhenListIsEmpty)
		{
			BidirectionalList list;
			BidirectionalList::Iterator it = list.Begin();

			ASSERT_DEATH({ ++it; }, ".*");
		}

		// ID:1_7
		TEST(IteratorToTailOfTheList, CallOnATailIterator)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.End();
			ASSERT_DEATH(++ite, ".*");
		}

		// ID:1_8
		TEST(IteratorToTailOfTheList, CallTwoElemtsList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(ite, rec2);

			ite = list.Begin();
			EXPECT_EQ((*ite).score, rec.score);
			EXPECT_EQ((*ite).userName, rec.userName);
			ite++;
			EXPECT_EQ((*ite).score, rec2.score);
			EXPECT_EQ((*ite).userName, rec2.userName);
		}

		// ID:1_9
		TEST(IteratorToTailOfTheList, PerformingAPreIncrement)
		{
			bool result = false;
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(ite, rec2);
			BidirectionalList::Record rec3 = { "3", "c" };
			list.Insert(ite, rec3);
			ite = list.Begin();
			BidirectionalList::Record beforRec = *ite;
			++ite;
			BidirectionalList::Record beforRec2 = *ite;
			++ite;
			BidirectionalList::Record beforRec3 = *ite;
			++ite;

			if (beforRec.score == rec.score && beforRec.userName == rec.userName &&
				beforRec2.score == rec2.score && beforRec2.userName == rec2.userName &&
				beforRec3.score == rec3.score && beforRec3.userName == rec3.userName)
			{
				result = true;
			}

			EXPECT_EQ(true, result);
		}

		// ID:1_10
		TEST(IteratorToTailOfTheList, PostfixIncrementsArePerformed)
		{
			bool result = false;
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			ite++;
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(ite, rec2);
			BidirectionalList::Record rec3 = { "3", "c" };
			list.Insert(ite, rec3);
			ite = list.Begin();
			BidirectionalList::Record beforRec = *ite;
			ite++;
			BidirectionalList::Record beforRec2 = *ite;
			ite++;
			BidirectionalList::Record beforRec3 = *ite;
			ite++;

			if (beforRec.score == rec.score && beforRec.userName == rec.userName &&
				beforRec2.score == rec2.score && beforRec2.userName == rec2.userName &&
				beforRec3.score == rec3.score && beforRec3.userName == rec3.userName)
			{
				result = true;
			}

			EXPECT_EQ(true, result);
		}

		// ID:1_11
		TEST(IteratorToHeadOfTheList, CalltoList)
		{
			BidirectionalList::Iterator it(nullptr);

			ASSERT_DEATH({ --it; }, ".*");
		}
		// ID:1_12
		TEST(IteratorToHeadOfTheList, CallFirstIteratorWhenListIsEmpty)
		{
			BidirectionalList list;
			BidirectionalList::Iterator it = list.End();

			ASSERT_DEATH({ --it; }, ".*");
		}

		// ID:1_13
		TEST(IteratorToHeadOfTheList, CallOnATailIterator)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();

			ASSERT_DEATH(--ite, ".*");
		}

		// ID:1_14
		TEST(IteratorToHeadOfTheList, CallTwoElemtsList)
		{
			BidirectionalList list;
			BidirectionalList::Iterator ite = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(ite, rec);
			ite = list.Begin();
			++ite;
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(ite, rec2);

			ite = list.End();
			ite--;
			EXPECT_EQ((*ite).score, "2");
			EXPECT_EQ((*ite).userName, "b");
			ite--;
			EXPECT_EQ((*ite).score, "1");
			EXPECT_EQ((*ite).userName, "a");
		}

		// ID:1_15
		TEST(IteratorToHeadOfTheList, PerformingAPreIncrement)
		{
			bool result = false;
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.End();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(ite, rec);
			ite = list.End();
			--ite;
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(ite, rec2);
			ite = list.End();
			--ite;
			--ite;
			BidirectionalList::Record rec3 = { "3", "c" };
			list.Insert(ite, rec3);
			ite = list.End();
			--ite;
			BidirectionalList::Record beforRec = *ite;
			--ite;
			BidirectionalList::Record beforRec2 = *ite;
			--ite;
			BidirectionalList::Record beforRec3 = *ite;


			if (beforRec.score == rec.score && beforRec.userName == rec.userName &&
				beforRec2.score == rec2.score && beforRec2.userName == rec2.userName &&
				beforRec3.score == rec3.score && beforRec3.userName == rec3.userName)
			{
				result = true;
			}

			EXPECT_EQ(true, result);
		}

		// ID:1_16
		TEST(IteratorToHeadOfTheList, PostfixIncrementsArePerformed)
		{
			bool result = false;
			BidirectionalList list;
			BidirectionalList::Const_Iterator ite = list.End();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(ite, rec);
			ite = list.End();
			ite--;
			BidirectionalList::Record rec2 = { "2", "b" };
			list.Insert(ite, rec2);
			ite = list.End();
			ite--;
			ite--;
			BidirectionalList::Record rec3 = { "3", "c" };
			list.Insert(ite, rec3);

			ite = list.End();
			ite--;
			BidirectionalList::Record beforRec = *ite;
			ite--;
			BidirectionalList::Record beforRec2 = *ite;
			ite--;
			BidirectionalList::Record beforRec3 = *ite;

			if (beforRec.score == rec.score && beforRec.userName == rec.userName &&
				beforRec2.score == rec2.score && beforRec2.userName == rec2.userName &&
				beforRec3.score == rec3.score && beforRec3.userName == rec3.userName)
			{
				result = true;
			}

			EXPECT_EQ(true, result);
		}

		// ID:1_17
		TEST(IteratorToHeadOfTheList, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator cit = list.ConstBegin();
			BidirectionalList::Iterator it = cit;//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		// ID:1_18
		TEST(CopyIterator, CopyIterator)
		{
			BidirectionalList list;
			BidirectionalList::Iterator origin = list.Begin();
			BidirectionalList::Record rec = { "1","a" };
			list.Insert(origin, rec);
			origin = list.Begin();
			BidirectionalList::Iterator copyIt(origin);
			EXPECT_EQ((*origin).score, (*copyIt).score);
			EXPECT_EQ((*origin).userName, (*origin).userName);
		}

		// ID:1_19
		TEST(CopyIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator cit = list.ConstBegin();
			BidirectionalList::Iterator it = list.Begin;
			it = cit;//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		// ID:1_20
		TEST(AssignmentIterator, AsseignmentIterator)
		{
			BidirectionalList list;
			BidirectionalList::Iterator origin = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(origin, rec);
			origin = list.Begin();

			BidirectionalList::Iterator assigned = origin;

			EXPECT_EQ((*origin).score, (*assigned).score);
			EXPECT_EQ((*origin).userName, (*assigned).userName);

		}
		// ID:1_21
		TEST(TwoIteratorIdenticalOrComparisons, FirstIteratorWithLastIteratorListIsEmpty)
		{
			BidirectionalList list;

			BidirectionalList::Iterator beginIt = list.Begin();
			BidirectionalList::Iterator endIt = list.End();

			EXPECT_TRUE(beginIt == endIt);

		}


		// ID:1_22
		TEST(TwoIteratorIdenticalOrComparisons, IdenticcalIterator)
		{
			BidirectionalList list;

			BidirectionalList::Iterator it1 = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(it1, rec);

			it1 = list.Begin();
			BidirectionalList::Iterator it2 = it1;

			EXPECT_TRUE(it1 == it2);

		}
		// ID:1_23
		TEST(TwoIteratorIdenticalOrComparisons, DifferentIterator)
		{
			BidirectionalList list;
			BidirectionalList list2;
			BidirectionalList::Iterator it1 = list.Begin();
			BidirectionalList::Iterator it2 = list2.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(it1, rec);
			list2.Insert(it2, rec);
			it1 = list.Begin();
			it2 = list2.Begin();
			EXPECT_FALSE(it1 == it2);

		}

		// ID:1_24
		TEST(TwoIteratorDifferentOrComparisons, FirstIteratorWithLastIteratorListIsEmpty)
		{
			BidirectionalList list;

			BidirectionalList::Iterator beginIter = list.Begin();
			BidirectionalList::Iterator endIter = list.End();

			EXPECT_FALSE(beginIter != endIter);
		}
		// ID:1_25
		TEST(TwoIteratorDifferentOrComparisons, IdenticcalIterator)
		{
			BidirectionalList list;

			BidirectionalList::Iterator it1 = list.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(it1, rec);

			it1 = list.Begin();
			BidirectionalList::Iterator it2 = it1;

			EXPECT_FALSE(it1 != it2);

		}
		// ID:1_26
		TEST(TwoIteratorDifferentOrComparisons, DifferentIterator)
		{
			BidirectionalList list;
			BidirectionalList list2;
			BidirectionalList::Iterator it1 = list.Begin();
			BidirectionalList::Iterator it2 = list2.Begin();
			BidirectionalList::Record rec = { "1", "a" };
			list.Insert(it1, rec);
			list2.Insert(it2, rec);

			it1 = list.Begin();
			it2 = list2.Begin();

			EXPECT_TRUE(it1 != it2);

		}
	}
}