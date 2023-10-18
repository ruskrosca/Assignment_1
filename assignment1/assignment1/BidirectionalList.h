/**********************************************************************************//**
	@file           BidirectionalList.h
	@brief          �o�������X�g�쐬
	@author			RyosukeNarsushima
*//***********************************************************************************/
#ifndef ___BIDIRECTIONAL_LIST_H___
#define ___BIDIRECTIONAL_LIST_H___

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

/**
* @brief ���уf�[�^
*/
struct Record
{
	//! �X�R�A
	std::string score;
	//! ���[�U�[��
	std::string userName;
};


/**
* @brief �o�������X�g�N���X
*/
template<typename Record> 
class BidirectionalList
{
private:
	/**
	* @brief ���X�g���̗v�f
	*/
	struct Node
	{
		//! ���уf�[�^
		Record m_record; 
		//! ���̃m�[�h�ւ̃|�C���^
		Node* m_next;   
		//! �O�̃m�[�h�ւ̃|�C���^
		Node* m_prev;     

		/**
		* @brief �����t���R���X�g���N�^
		* @param rec ���уf�[�^ 
		* @param score �X�R�A
		* @param userName ���[�U�[��
		*/
		inline explicit Node(const Record& rec);
	};

	//! �_�~�[�m�[�h
	Node* m_dummyNode;

	//! �v�f���̃J�E���g�p�ϐ�
	int m_size;

public:
	/**
	* @brief �o�������X�g�̗v�f�ɃA�N�Z�X����C�e���[�^�N���X
	*/
	class Const_Iterator
	{
	public:
		//! �m�[�h�������|�C���^
		Node* m_node;

		//! ���X�g�̃|�C���^
		const BidirectionalList* m_list;

		/**
		* @brief �f�t�H���g�R���X�g���N�^
		*/
		inline Const_Iterator();

		/**
		* @brief �����t���R���X�g���N�^
		* @param node �m�[�h���w�肷��|�C���^
		* @param list �C�e���[�^�̏������Ă��郊�X�g�̏��
		*/
		inline explicit Const_Iterator(Node* node, const BidirectionalList* list);

		/**
		* @brief �O�u�C���N�������g���Z�q
		* @return �X�V��̃C�e���[�^�ւ̎Q��
		*/
		inline Const_Iterator& operator++();

		/**
		* @brief �O�u�f�N�������g���Z�q
		* @return �X�V��̃C�e���[�^�ւ̎Q��
		*/
		inline Const_Iterator& operator--();

		/**
		* @brief ��u�C���N�������g���Z�q
		* @return �X�V�O�̃C�e���[�^�ւ̎Q��
		*/
		inline Const_Iterator operator++(int);

		/**
		* @brief ��u�f�N�������g���Z�q
		* @return �X�V�O�̃C�e���[�^�ւ̎Q��
		*/
		inline Const_Iterator operator--(int);

		/**
		* @brief �f���t�@�����X���Z�q
		* @return  ���уf�[�^�̎Q��
		*/
		inline const Record& operator*();
		/**
		 * @brief 2�� Const_Iterator �C�e���[�^���r����
		 * @param ite ��r�Ώۂ� Const_Iterator
		 * @return 2�̃C�e���[�^�������v�f���w���Ă���ꍇ�� true ��Ԃ�
		 */
		inline bool operator==(const Const_Iterator& ite) const;

		/**
		* @brief 2�� Const_Iterator �C�e���[�^���r����
		* @param ite ��r�Ώۂ� Const_Iterator
		* @return 2�̃C�e���[�^���قȂ�v�f���w���Ă���ꍇ�� true ��Ԃ�
		*/
		inline bool operator!=(const Const_Iterator& ite) const;
	};

	/**
	* @brief Const_Iterator���p������Iterator�N���X
	*/
	class Iterator : public Const_Iterator
	{
	public:
		/**
		* @brief �f�t�H���g�R���X�g���N�^
		*/
		inline Iterator() : Const_Iterator();

		/**
		* @brief �����t���R���X�g���N�^
		* @param node �m�[�h���w�肷��|�C���^
		* @param list �C�e���[�^�̏������Ă��郊�X�g�̏��
		*/
		inline explicit Iterator(Node* node, const BidirectionalList* list);

		/**
		* @brief �f���t�@�����X���Z�q
		* @return m_node->m_record ���уf�[�^�̎Q��
		*/
		inline Record& operator*();
	};

	/**
	* @brief �f�t�H���g�R���X�g���N�^
	*/
	inline BidirectionalList();

	/**
	* @brief �R�s�[�̋֎~���s��
	*/
	inline BidirectionalList(const BidirectionalList&) = delete;

	/**
	* @brief �f�X�g���N�^
	*/
	inline ~BidirectionalList();

	/**
	* @brief ���X�g�̃T�C�Y��Ԃ�
	* @return int ���X�g�̃T�C�Y
	*/
	inline int GetSize() const;


	/**
	* @brief �C�e���[�^�Ŏw�肳�ꂽ�ʒu�Ƀf�[�^��}��
	* @param ite �}������ʒu���w�肵���C�e���[�^
	* @param rec ���я��
	* @param score �X�R�A
	* @param userName ���[�U�[��
	* @return �}�������������ꍇ true�A ���s�����ꍇ false
	*/
	inline bool Insert(Const_Iterator& ite, const Record& rec);


	/**
	* @brief �C�e���[�^�Ŏw��ʒu�̃f�[�^���폜
	* @param[in]  �폜����ʒu���w�肵���C�e���[�^
	* @return �폜�����������ꍇ true�A �����ȃC�e���[�^�A�_�~�[�m�[�h�ꍇ false
	*/
	inline bool Delete(Const_Iterator& ite);


	/**
	* @brief �擪�C�e���[�^��Ԃ�
	* @return Iterator �擪�C�e���[�^
	*/
	inline Iterator Begin() const;


	/**
	* @brief �擪��const�C�e���[�^��Ԃ�
	* @return ConstIterato �擪const�C�e���[�^
	*/
	inline Const_Iterator ConstBegin() const;


	/**
	* @brief �����C�e���[�^��Ԃ�
	* @return Iterator �����C�e���[�^
	*/
	inline Iterator End() const;


	/**
	* @brief �擪��const�C�e���[�^��Ԃ�
	* @return ConstIterator ����const�C�e���[�^
	*/
	inline Const_Iterator ConstEnd() const;

};
#include "BidirectionalList.inl"
#endif


