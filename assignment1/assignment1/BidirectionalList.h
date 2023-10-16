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
* @brief �o�������X�g�N���X
*/
class BidirectionalList
{
public:
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

		explicit Node(const Record& rec) : m_record(rec), m_next(nullptr), m_prev(nullptr) {}
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

		/**
		* @brief �f�t�H���g�R���X�g���N�^
		*/
		Const_Iterator() : m_node(nullptr) {}

		/**
		* @brief �����t���R���X�g���N�^
		* @param node �m�[�h���w�肷��|�C���^
		*/
		Const_Iterator(Node* node) : m_node(node) {}

		/**
		* @brief �O�u�C���N�������g���Z�q
		* @return �X�V��̃C�e���[�^�ւ̎Q��
		*/
		Const_Iterator& operator++()  { 
			assert(m_node != nullptr);
			m_node = m_node->m_next;
			return *this;
		}

		/**
		* @brief �O�u�f�N�������g���Z�q
		* @return �X�V��̃C�e���[�^�ւ̎Q��
		*/
		Const_Iterator& operator--()  { 
			assert(m_node != nullptr);
			m_node = m_node->m_prev;
			return *this;
		}

		/**
		* @brief ��u�C���N�������g���Z�q
		* @return �X�V�O�̃C�e���[�^�ւ̎Q��
		*/
		Const_Iterator operator++(int) {
			assert(m_node != nullptr);
			Const_Iterator temp = *this;
			++(*this);
			return temp;
		}

		/**
		* @brief ��u�C���N�������g���Z�q
		* @return �X�V�O�̃C�e���[�^�ւ̎Q��
		*/
		Const_Iterator operator--(int) { 
			assert(m_node != nullptr);
			Const_Iterator temp = *this;
			--(*this);
			return temp; 
		}

		/**
		* @brief �f���t�@�����X���Z�q
		* @return  ���уf�[�^�̎Q��
		*/
		const Record& operator*() {
			assert(m_node != nullptr);
			return m_node->m_record;
		}
		/**
		 * @brief 2�� Const_Iterator �C�e���[�^���r����
		 * @param ite ��r�Ώۂ� Const_Iterator
		 * @return 2�̃C�e���[�^�������v�f���w���Ă���ꍇ�� true ��Ԃ�
		 */
		bool operator==(const Const_Iterator& ite) const { return m_node == ite.m_node; }

		/**
		* @brief 2�� Const_Iterator �C�e���[�^���r����
		* @param ite ��r�Ώۂ� Const_Iterator
		* @return 2�̃C�e���[�^���قȂ�v�f���w���Ă���ꍇ�� true ��Ԃ�
		*/
		bool operator!=(const Const_Iterator& ite) const { return m_node != ite.m_node; }
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
		Iterator() : Const_Iterator(nullptr) {}

		/**
		* @brief �����t���R���X�g���N�^
		* @param node �m�[�h���w�肷��|�C���^
		*/
		Iterator(Node* node) : Const_Iterator(node) {}

		/**
		* @brief �f���t�@�����X���Z�q
		* @return m_node->m_record ���уf�[�^�̎Q��
		*/
		Record& operator*() { 
			assert(m_node != nullptr);
			return m_node->m_record; }
	};

	/**
	* @brief �f�t�H���g�R���X�g���N�^
	*/
	BidirectionalList();

	/**
	* @brief �f�X�g���N�^
	*/
	~BidirectionalList();

	/**
	* @brief ���X�g�̃T�C�Y��Ԃ�
	* @return int ���X�g�̃T�C�Y
	*/
	int GetSize() const;


	/**
	* @brief �C�e���[�^�Ŏw�肳�ꂽ�ʒu�Ƀf�[�^��}��
	* @param ite �}������ʒu���w�肵���C�e���[�^
	* @param rec ���я��
	* @param score �X�R�A
	* @param userName ���[�U�[��
	* @return �}�������������ꍇ true�A ���s�����ꍇ false
	*/
	bool Insert(Const_Iterator& ite, const Record& rec);


	/**
	* @brief �C�e���[�^�Ŏw��ʒu�̃f�[�^���폜
	* @param[in]  �폜����ʒu���w�肵���C�e���[�^
	* @return �폜�����������ꍇ true�A �����ȃC�e���[�^�A�_�~�[�m�[�h�ꍇ false
	*/
	bool Delete(Const_Iterator& ite);		


	/**
	* @brief �擪�C�e���[�^��Ԃ�
	* @return Iterator �擪�C�e���[�^
	*/
	Iterator Begin() const;	


	/**
	* @brief �擪��const�C�e���[�^��Ԃ�
	* @return ConstIterato �擪const�C�e���[�^
	*/
	Const_Iterator ConstBegin() const;	


	/**
	* @brief �����C�e���[�^��Ԃ�
	* @return Iterator �����C�e���[�^
	*/
	Iterator End() const;


	/**
	* @brief �擪��const�C�e���[�^��Ԃ�
	* @return ConstIterator ����const�C�e���[�^
	*/
	Const_Iterator ConstEnd() const;					
};

#endif