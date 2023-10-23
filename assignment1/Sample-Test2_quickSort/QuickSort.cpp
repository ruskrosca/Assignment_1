#include "pch.h"
#include "../assignment1/BidirectionalList.h"
#include "../assignment1/Record.h"

namespace chapter01
{
	/**********************************************************************************//**
	@brief		�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋����e�X�g
	@details	ID:���X�g-0\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
				�G���[�܂߂āA�����N����Ȃ���ΐ����ł��B\n
	*//***********************************************************************************/
	TEST(QuickSort, NullList) {
		BidirectionalList<Record> list;
		// false���Ԃ��Ă���ΐ���
		EXPECT_FALSE(list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.userName < b.userName; }));
	}

	/**********************************************************************************//**
	@brief		�v�f��1���������X�g�Ƀ\�[�g�����s�������̋����e�X�g
	@details	ID:���X�g-1\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				�v�f��1���������X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
				�G���[�܂߂āA�����N����Ȃ���ΐ����ł��B\n
	*//***********************************************************************************/
	TEST(QuickSort, OneElementList) {
		BidirectionalList<Record> list;
		Record rec{ 1,"ga" };
		BidirectionalList<Record>::Iterator it = list.begin();
		list.Insert(it, rec);

		// false���Ԃ��Ă���ΐ���
		EXPECT_FALSE(list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,
			[](const Record& a, const Record& b) {return a.userName < b.userName; }));
	}

	/**********************************************************************************//**
	@brief		2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋����e�X�g
	@details	ID:���X�g-2\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
				�v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ��ׂΐ����ł��B\n
				�擪���珇�ɃC�e���[�^�Ŋm�F���A�m�[�h�̍����ւ�������ɍs���Ă��邩�`�F�b�N����B\n
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
	@brief		�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋����e�X�g
	@details	ID:���X�g-3\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋������m�F���Ă��܂��B\n
				�v�f���\�[�g����ĕ��ׂΐ����ł��B\n
				�����v�f�̏����͕ۏ؂���܂���B\n
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
	@brief		����ς݃��X�g�Ƀ\�[�g�����s�������̋����e�X�g
	@details	ID:���X�g-4\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				������ς݃��X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
				�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ���ΐ����ł��B\n
				�d���v�f�Ȃ��̐���ς݃��X�g���g���܂��B\n
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
	@brief		��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋����e�X�g
	@details	ID:���X�g-5\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋������m�F���Ă��܂��B\n
				�v�f���\�[�g����ĕ��ׂΐ����ł��B\n
				�d���v�f�Ȃ��̐���ς݃��X�g���g���܂��B\n
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
	@brief		�L�[�w������Ȃ�����(nullptr��n����)���̋����e�X�g
	@details	ID:���X�g-6\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				�L�[�w������Ȃ�����(nullptr��n����)���̋������m�F���Ă��܂��B\n
				�G���[�܂߂āA�����N����Ȃ���ΐ����ł��B\n
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
	@brief		�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋����e�X�g
	@details	ID:���X�g-7\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋������m�F���Ă��܂��B\n
				�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
				�R���p�C���G���[���`�F�b�N�B�����e�X�g�����Ȃ�\n
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
			[](const int& a, const int& b) {return a < b; });	// �����ŃG���[�ɂȂ�܂�

#endif // defined TT_TEST_INSERT_WHEN_CONST
		SUCCEED();

	}

	/**********************************************************************************//**
	@brief		��const�̃��\�b�h�ł��邩�̃e�X�g
	@details	ID:���X�g-8\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
				��const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
				�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
				const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B\n
				�����e�X�g�����Ȃ��Ă悢�B\n
	*//***********************************************************************************/
	TEST(QuickSort, IsItAMethodOfConst) {
		//#define TT_TEST_INSERT_WHEN_CONST
#if defined TT_TEST_INSERT_WHEN_CONST
		const BidirectionalList<Record> list;
		BidirectionalList<Record>::Const_Iterator it = list.ConstBegin();
		Record rec = { 1, "a" };
		list.QuickSort(list.ConstBegin(), list.ConstEnd(), true,		// �����ŃG���[�ɂȂ�܂�
			[](const Record& a, const Record& b) {return a.score < b.score; });	

#endif // defined TT_TEST_INSERT_WHEN_CONST
		SUCCEED();
	}

}

