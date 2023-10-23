/**********************************************************************************//**
	@file           test.cpp
	@brief          GoogleTest�e�X�g�R�[�h
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
		//=================================== �f�[�^���̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-0\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataNum, NullList) {
			BidirectionalList<Record> list;
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataNum, InsertBackSuccess) {
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();

			list.Insert(ite, rec);
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataNum, InsertBackFail) {
			// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
			//BidirectionalList list;
			//BidirectionalList::Iterator ite = list.End();
			//Record rec = { 1, "a" };

			//list.Insert(ite, rec);
			//EXPECT_EQ(0,list.GetSize());
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-3\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
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
			@brief		�f�[�^�̑}���Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-4\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataNum, DataAddFail)
		{// �������m�ۂ̎��s���̂ݎ��s���邽�߃X�L�b�v
		}


		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-5\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataNum, DatadeleteSaccess)
		{
			BidirectionalList<Record> list;

			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();
			// �f�[�^�̑}��
			list.Insert(ite, rec);
			BidirectionalList<Record>::Iterator it = list.Begin();
			list.Delete(it);

			EXPECT_EQ(0, list.GetSize());

		}


		/**********************************************************************************//**
			@brief		�f�[�^�̍폜�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-6\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�ł���ΐ����ł��B\n
						�f�[�^��}��������A�폜�����ꍇ���e�X�g���܂��B\n
		*//***********************************************************************************/
		TEST(DataNum, DataDeleteFail)
		{
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator ite = list.Begin();
			// �f�[�^�̑}��
			list.Insert(ite, rec);
			BidirectionalList<Record>::Iterator it;
			// �f�[�^���폜
			list.Delete(it);
			EXPECT_EQ(1, list.GetSize());
		}


		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-7\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
						�}�C�i�X�ɂȂ�Ȃ����ǂ����m�F���܂��B\n
		*//***********************************************************************************/
		TEST(DataNum, DeleteToNulList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			// �󃊃X�g�̒����폜
			EXPECT_FALSE(list.Delete(it));
			EXPECT_EQ(0, list.GetSize());
		}
		
		/**********************************************************************************//**
			@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-8(�蓮)\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
						TT_TEST_GET_DATA_NUM_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
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

		//=================================== �f�[�^�̑}�� ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-9\n
						���X�g�擪�A���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�擪�A�����ɗv�f���ǉ�����Ă���ΐ����ł��B\n
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
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-10\n
						���X�g�擪�̃f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�擪�ɗv�f���}������A���X�擪�������v�f���Q�ԖڂɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(Add, SetHeadIteratortoList)
		{
			// �f�[�^�}��
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

			// �擪�v�f�̓���ւ�肪�����������m�F
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
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋����e�X�g
			@details	ID:���X�g-11\n
						���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�C�e���[�^�̎w���ʒu�ɗv�f���}�������ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(Add, SetTailIteratortoList)
		{
			// �f�[�^�̑}��
			BidirectionalList<Record> list;
			Record rec = { 1, "a" };
			BidirectionalList<Record>::Iterator it = list.End();
			list.Insert(it, rec);
			it = list.End();
			--it;
			Record rec2 = { 2, "b" };
			// ����������
			list.Insert(it, rec2);
			it = list.End();
			--it;
			--it;
			Record rec3 = { 3, "c" };
			// ����������
			list.Insert(it, rec3);

			// ���Ԃ��m�F
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
			@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����e�X�g
			@details	ID:���X�g-12\n
						���X�g�̃f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ����ΐ����ł��B\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩�B�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂�\n
		*//***********************************************************************************/
		TEST(Add, SetIteratortoList)
		{
			// �f�[�^�}��
			BidirectionalList<Record> list;
			Record record1 = { 1, "a" };
			Record record2 = { 2, "b" };
			Record record3 = { 3, "c" };
			BidirectionalList<Record>::Iterator it = list.Begin();
			// �擪
			list.Insert(it, record1);
			it = list.Begin();
			EXPECT_EQ((*it).score, 1);
			EXPECT_EQ((*it).userName, "a");

			++it;
			// �擪�̎�
			list.Insert(it, record2);
			it = list.Begin();
			EXPECT_EQ((*it).score, 1);
			EXPECT_EQ((*it).userName, "a");
			++it;
			EXPECT_EQ((*it).score, 2);
			EXPECT_EQ((*it).userName, "b");

			it = list.Begin();
			++it;
			// �}�����ꂽ��̃f�[�^�̊�
			list.Insert(it, record3);

			// ���񏇂��m�F
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
			@brief		ConstIterator���w�肵�đ}�����s�����ۂ̋����e�X�g
			@details	ID:���X�g-13\n
						�f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ����ΐ����ł��B\n
						�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩�B�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂�\n
		*//***********************************************************************************/

		TEST(Add, InsertToConst)
		{
			BidirectionalList<Record> list;
			Record record1 = { 1, "a" };
			Record record2 = { 2, "b" };
			Record record3 = { 3, "c" };
			BidirectionalList<Record>::Const_Iterator cite = list.ConstBegin();
			// �擪�f�[�^�̑}��
			list.Insert(cite, record1);
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, 1);
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			// ���ɑ}��
			list.Insert(cite, record2);
			// ����̐���m�F
			cite = list.ConstBegin();
			EXPECT_EQ((*cite).score, 1);
			EXPECT_EQ((*cite).userName, "a");
			++cite;
			EXPECT_EQ((*cite).score, 2);
			EXPECT_EQ((*cite).userName, "b");


			cite = list.ConstBegin();
			++cite;
			// �^�񒆂Ƀf�[�^�}��
			list.Insert(cite, record3);
			cite = list.ConstBegin();
			// �ŏI�I�Ȑ���m�F
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
			@brief		�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋����e�X�g
			@details	ID:���X�g-14\n
						���X�g�擪�̃f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�����N����Ȃ���ΐ����ł��B\n
						���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^��n�����ۂ̋����Ȃ�\n
		*//***********************************************************************************/
		TEST(Add, AddToNullList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it;
			Record rec = { 1, "a" };
			// ���X�g�̎Q�Ƃ������C�e���[�^��n��
			EXPECT_EQ(false, list.Insert(it, rec));
		}

		/**********************************************************************************//**
		@brief		���X�g�����̃f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
		@details	ID:���X�g-15(�蓮)\n
					���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
					��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
					�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
					TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n

		@return		�Ȃ�
		*//***********************************************************************************/
		TEST(Add, IsItAMethodOfConst)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			Record rec = { 1, "a" };
			list.Insert(it, rec);//�����ŃG���[

#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋����e�X�g
				@details	ID:���X�g-16\n
							�󃊃X�g�̃f�[�^�폜�e�X�g�ł��B\n
							���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
							�����N����Ȃ���ΐ����ł��B\n
							�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N����B\n
		*//***********************************************************************************/
		TEST(Delete, DeleteBackFromEmptyList)
		{
			BidirectionalList<Record> list;

			// ���X�g����
			EXPECT_EQ(list.GetSize(), 0);

			// �����N����Ȃ���
			BidirectionalList<Record>::Iterator ite = list.Begin();
			EXPECT_EQ(list.Delete(ite), false);

			ite = list.End();
			EXPECT_EQ(list.Delete(ite), false);

		}

		/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋����e�X�g
				@details	ID:���X�g-17\n
							���X�g�擪�̃f�[�^�폜�e�X�g�ł��B\n
							���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
							�擪�v�f�̍폜�����ΐ����ł��B\n
							�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N����B\n
		*//***********************************************************************************/
		TEST(Delete, SetIteratorFrontFromlist)
		{
			//�f�[�^�̑}��
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(ite, rec);

			ite = list.Begin();
			// ���̃f�[�^�}��
			Record rec2 = { 2, "b" };
			list.Insert(ite, rec2);

			ite = list.Begin();
			// �擪�̃f�[�^�폜
			EXPECT_EQ(true, list.Delete(ite));
			
			// ���̐擪�̃f�[�^���m�F
			ite = list.Begin();
			EXPECT_TRUE((*ite).score == 1);
			EXPECT_TRUE((*ite).userName == "a");
		}

		/**********************************************************************************//**
				@brief		�����X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋����e�X�g
				@details	ID:���X�g-18\n
							���X�g�����̃f�[�^�폜�e�X�g�ł��B\n
							���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
							�����N����Ȃ���ΐ����ł��B\n
							�����̓_�~�[�m�[�h�ł��B\n
		*//***********************************************************************************/
		TEST(Delete, SetIteratorTailFromlist)
		{
			// �f�[�^�}��
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			Record rec = { 1, "a" };
			list.Insert(it, rec);

			// ���̃f�[�^��}��
			Record rec2 = { 2, "b" };
			it = list.End();
			list.Insert(it, rec2);

			// �����f�[�^���폜(�_�~�[�m�[�h���폜)
			BidirectionalList<Record>::Iterator ite = list.End();
			EXPECT_EQ(false, list.Delete(ite));
		}

		/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋����e�X�g
				@details	ID:���X�g-19\n
							���X�g�擪�ł������ł��Ȃ��̃f�[�^�폜�e�X�g�ł��B\n
							���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
							�w��v�f�̍폜�����ΐ����ł��B\n
							�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă���B\n
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
		@brief		ConstIterator���w�肵�č폜���s�����ۂ̋����e�X�g
		@details	ID:���X�g-20\n
					ConstIterator���w�肵���f�[�^�폜�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�w��v�f�̍폜�����ΐ����ł��B\n
					�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă���B\n
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
		@brief		�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋����e�X�g
		@details	ID:���X�g-21\n
					�s���ȃC�e���[�^���w�肵���f�[�^�폜�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����N����Ȃ���ΐ����ł��B\n
					���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^��n�����ۂ̋����ȂǁB\n
		*//***********************************************************************************/
		TEST(Delete, AddNullDelete)
		{
			BidirectionalList<Record> list;
			Record record1 = { 1,"a" };
			BidirectionalList<Record>::Iterator it;

			list.Insert(it, record1);
			// �ʃ��X�g�̏���n��
			EXPECT_FALSE(list.Delete(it));
		}

		/**********************************************************************************//**
		@brief		���X�g�����̃f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
		@details	ID:���X�g-22(�蓮)\n
					��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
					�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
					TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n

		@return		�Ȃ�
		*//***********************************************************************************/
		TEST(Delete, IsItAMethodOfConst)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Const_Iterator it = list.ConstBegin();
			Record rec = { 1, "a" };
			list.Insert(it, rec);//�����ŃG���[
			it = list.ConstBegin();
			list.Push_Back(it);//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
		@brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-23\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetHeadIterator, NullList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			EXPECT_EQ(list.Begin(), it);
		}

		/**********************************************************************************//**
		@brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-24\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetHeadIterator, CalloneElementList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator ite = list.Begin();
			Record record1 = { 1, "a" };
			list.Insert(ite, record1);


			ite = list.Begin();
			// �擪�C�e���[�^���������v�f��
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-25\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
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


			// �擪�̃C�e���[�^�搳�����v�f���w���Ă��邩
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-26\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-27\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N

		@details	ID:���X�g-28\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�R���p�C���G���[�ɂȂ邱�Ƃ��m�F���܂��B\n
					TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
		*//***********************************************************************************/

		TEST(GetHeadIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Iterator it = list.ConstBegin();//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


		/**********************************************************************************//**
		@brief		���X�g����ł���ꍇ�ɁA�擪�R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-29\n
					�擪�R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetConstHeadIterator, CallEmptyList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator it = list.ConstBegin();
			EXPECT_EQ(list.ConstBegin(), it);
		}

		/**********************************************************************************//**
		@brief		���X�g�ɗv�f�������ꍇ�ɁA�擪�R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-30\n
					�擪�R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
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
		@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�擪�R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-31\n
					�擪�R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
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


			// �擪�̃C�e���[�^���������v�f���w���Ă��邩
			ite = list.Begin();
			EXPECT_EQ((*ite).score, 1);
			EXPECT_EQ((*ite).userName, "a");
		}

		/**********************************************************************************//**
		@brief		�f�[�^�̑}�����s������ɁA�擪�R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-32\n
					�擪�R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-33\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		const�̃��\�b�h�ł��邩���`�F�b�N

		@details	ID:���X�g-34\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������m�F���܂��B\n
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
		@brief		���X�g����ł���ꍇ�ɁA�����C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-35\n
					�����C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetTailIterator, NullList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.End();
			EXPECT_EQ(list.End(), it);
		}

		/**********************************************************************************//**
		@brief		���X�g�ɗv�f�������ꍇ�ɁA�����C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-36\n
					�����C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
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
		@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�����C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-37\n
					�����C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
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


			// �����̃C�e���[�^���������v�f���w���Ă��邩
			ite = list.End();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");
		}

		/**********************************************************************************//**
		@brief		�f�[�^�̑}�����s������ɁA�����C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-38\n
					�����C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		�f�[�^�̍폜���s������ɁA�����C�e���[�^�Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-39\n
					�����C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N

		@details	ID:���X�g-40\n
					�擪�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�R���p�C���G���[�ɂȂ邱�Ƃ��m�F���܂��B\n
					TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
		*//***********************************************************************************/
		TEST(GetTailIterator, GetIteratorIsNotConstIterator)
		{
			//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
			const BidirectionalList list;
			BidirectionalList::Iterator it = list.ConstEnd();//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
		@brief		���X�g����ł���ꍇ�ɁA�����R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-41\n
					�����R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�_�~�[�m�[�h���w���C�e���[�^���Ԃ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetConstTailIterator, CallEmptyList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Const_Iterator it = list.ConstEnd();
			EXPECT_EQ(list.ConstEnd(), it);
		}

		/**********************************************************************************//**
		@brief		���X�g�ɗv�f�������ꍇ�ɁA�����R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-42\n
					�����R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
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
		@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�����R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-43\n
					�����R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
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

			// �����̃C�e���[�^���������v�f��
			ite = list.ConstEnd();
			--ite;
			EXPECT_EQ((*ite).score, 2);
			EXPECT_EQ((*ite).userName, "b");

		}

		/**********************************************************************************//**
		@brief		�f�[�^�̑}�����s������ɁA�����R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-44\n
					�����R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		�f�[�^�̍폜���s������ɁA�����R���X�g�C�e���[�^���Ăяo�����ۂ̋����e�X�g
		@details	ID:���X�g-45\n
					�����R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					�����v�f���w���C�e���[�^���Ԃ�ΐ����ł��B\n
					�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B\n
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
		@brief		const�̃��\�b�h�ł��邩���`�F�b�N

		@details	ID:���X�g-46\n
					�����R���X�g�C�e���[�^�̎擾�e�X�g�ł��B\n
					���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
					const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������m�F���܂��B\n
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
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-0\n
						�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B\n
						Assert���������琬���ł��B\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, CalltoList)
		{
			BidirectionalList<Record>::Iterator it;
			EXPECT_DEATH((*it), ".*");
		}

		/**********************************************************************************//**
			@brief		Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s����̃e�X�g
			@details	ID:Iterator-1\n
						�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B\n
						�l�̑�����s���ꐬ���ł��B\n
						�����ɍēx�Ăяo���A�l���ύX����Ă��邱�Ƃ��m�F�B\n
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
		@brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N

		@details	ID:���X�g-2\n
					�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B\n
					�R���p�C���G���[�ɂȂ邱�Ƃ��m�F���܂��B\n
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
			(*it).score = 3;//�����ŃG���[
			(*it).userName = "c";//�����ŃG���[
#endif // defined TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-3\n
						�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B\n
						Assert��������ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, CallOnEmtyList)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.Begin();
			EXPECT_DEATH(*it,".*");
		}


		/**********************************************************************************//**
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-4\n
						�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B\n
						Assert��������ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetElementToIterator, CalOnIterator)
		{
			BidirectionalList<Record> list;
			BidirectionalList<Record>::Iterator it = list.End();

			ASSERT_DEATH((*it), ".*");

		}

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-�T\n
						�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						Assert��������ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(IteratorToTailOfTheList, CalltoList)
		{
			BidirectionalList<Record>::Iterator it;

			ASSERT_DEATH({ ++it; }, ".*");

			BidirectionalList<Record>::Iterator it2;

			ASSERT_DEATH({ it2++; }, ".*");
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-6\n
						�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						Assert��������ΐ����ł��B\n
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
			@brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-7\n
						�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						Assert��������ΐ����ł��B\n
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
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
			@details	ID:Iterator-8\n
						�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						���̗v�f���w���Ă���ΐ����ł��B\n
						���X�g�̐擪���疖���܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F����B\n
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
			@brief		�O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�e�X�g
			@details	ID:Iterator-9\n
						�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						���̗v�f���w���Ă���ΐ����ł��B\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F���܂�\n
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
			@brief		��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�e�X�g
			@details	ID:Iterator-10\n
						�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						���̗v�f���w���Ă���ΐ����ł��B\n
						�C���N�������g�Ăяo�����̒l�ƁA�C���N�������g���s��̒l�̗������m�F���܂��B\n
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
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-11\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						Assert�������Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(IteratorToHeadOfTheList, CalltoList)
		{
			BidirectionalList<Record>::Iterator it;

			ASSERT_DEATH({ --it; }, ".*");

			BidirectionalList<Record>::Iterator it2;

			ASSERT_DEATH({ it2--; }, ".*");
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-12\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						Assert�������Ă���ΐ����ł��B\n
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
			@brief		�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-13\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						Assert�������Ă���ΐ����ł��B\n
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
			@brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-14\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						�O�̗v�f���w���Ă���ΐ����ł��B\n
						���X�g�̖�������擪�܂ŌĂяo�����s���A���҂���Ă���v�f���i�[����Ă��邩���m�F����B\n
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
			@brief		�O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�e�X�g
			@details	ID:Iterator-15\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						�O�̗v�f���w���Ă���ΐ����ł��B\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F����B\n
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
			@brief		��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )�e�X�g
			@details	ID:Iterator-16\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B\n
						�O�̗v�f���w���Ă���ΐ����ł��B\n
						�f�N�������g�Ăяo�����̒l�ƁA�f�N�������g���s��̒l�̗������m�F����B\n
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
			@brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
			@details	ID:Iterator-17\n
						�C�e���[�^�̃R�s�[���s���e�X�g�ł��B\n
						�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
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

		/**********************************************************************************//**
			@brief		�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N����e�X�g
			@details	ID:Iterator-18\n
						�C�e���[�^�̃R�s�[���s���e�X�g�ł��B\n
						�R�s�[���Ɠ����������琬���ł��B\n
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
				@brief		Iterator��ConstIterator�����ł��Ȃ������`�F�b�N����e�X�g
				@details	ID:Iterator-19\n
							�C�e���[�^�̑�����s���e�X�g�ł��B\n
							�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
			*//***********************************************************************************/
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

		/**********************************************************************************//**
				@brief		�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N����e�X�g
				@details	ID:Iterator-20\n
							�C�e���[�^�̑�����s���e�X�g�ł��B\n
							�R�s�[���Ɠ�������ΐ����ł��B\n
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
		@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N����e�X�g
		@details	ID:Iterator-21\n
					��̃C�e���[�^������̂��̂ł��邩�A��r���s���e�X�g�ł��B\n
					��̃C�e���[�^������̂��̂ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(TwoIteratorIdenticalOrComparisons, FirstIteratorWithLastIteratorListIsEmpty)
		{
			BidirectionalList<Record> list;

			BidirectionalList<Record>::Iterator beginIt = list.Begin();
			BidirectionalList<Record>::Iterator endIt = list.End();

			EXPECT_TRUE(beginIt == endIt);

		}


		/**********************************************************************************//**
		@brief		����̃C�e���[�^���r�����ۂ̋����e�X�g
		@details	ID:Iterator-22\n
					��̃C�e���[�^������̂��̂ł��邩�A��r���s���e�X�g�ł��B\n
					��̃C�e���[�^������̂��̂ł���ΐ����ł��B\n
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
		@brief		�قȂ�C�e���[�^���r�����ۂ̋����e�X�g
		@details	ID:Iterator-22\n
					��̃C�e���[�^������̂��̂ł��邩�A��r���s���e�X�g�ł��B\n
					��̃C�e���[�^���قȂ�̂��̂ł���ΐ����ł��B\n
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
		@brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋����e�X�g
		@details	ID:Iterator-22\n
					��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���e�X�g�ł��B\n
					��̃C�e���[�^���قȂ�̂��̂ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(TwoIteratorDifferentOrComparisons, FirstIteratorWithLastIteratorListIsEmpty)
		{
			BidirectionalList<Record> list;

			BidirectionalList<Record>::Iterator beginIter = list.Begin();
			BidirectionalList<Record>::Iterator endIter = list.End();

			EXPECT_FALSE(beginIter != endIter);
		}

		/**********************************************************************************//**
		@brief		����̃C�e���[�^���r�����ۂ̋����e�X�g
		@details	ID:Iterator-22\n
					��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���e�X�g�ł��B\n
					��̃C�e���[�^���قȂ�̂��̂ł���ΐ����ł��B\n
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
		@brief		�قȂ�C�e���[�^���r�����ۂ̋����e�X�g
		@details	ID:Iterator-22\n
					��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���e�X�g�ł��B\n
					��̃C�e���[�^���قȂ�̂��̂ł���ΐ����ł��B\n
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