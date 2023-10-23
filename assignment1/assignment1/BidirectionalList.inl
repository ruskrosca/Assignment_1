/**********************************************************************************//**
	@file           BidirectionalList.inl
	@brief          �o�������X�g�쐬
	@author			RyosukeNarsushima
*//***********************************************************************************/
#include "BidirectionalList.h"
#include <assert.h>

/**
* @brief �R���X�g���N�^
*/
template<typename T>
inline BidirectionalList<T>::Node::Node()
	: m_data(), m_next(nullptr), m_prev(nullptr){}

/**
* @brief �����t���R���X�g���N�^
* @param data �f�[�^
*/
template<typename T>
inline BidirectionalList<T>::Node::Node(const T & data)
	: m_data(data), m_next(nullptr), m_prev(nullptr){}

/**
* @brief �f�t�H���g�R���X�g���N�^
*/
template<typename T>
inline BidirectionalList<T>::Const_Iterator::Const_Iterator()
	: m_node(nullptr), m_list(nullptr) {}

/**
* @brief �����t���R���X�g���N�^
* @param node �m�[�h���w�肷��|�C���^
* @param list �C�e���[�^�̏������Ă��郊�X�g�̏��
*/
template<typename T>
inline BidirectionalList<T>::Const_Iterator::Const_Iterator(Node * node, const BidirectionalList * list)
	: m_node(node), m_list(list) {}

/**
* @brief �O�u�C���N�������g���Z�q
* @return �X�V��̃C�e���[�^�ւ̎Q��
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator & BidirectionalList<T>::Const_Iterator::operator++()
{
	assert(m_node != nullptr);
	m_node = m_node->m_next;
	return *this;
}

/**
* @brief �O�u�f�N�������g���Z�q
* @return �X�V��̃C�e���[�^�ւ̎Q��
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator & BidirectionalList<T>::Const_Iterator::operator--()
{
	assert(m_node != nullptr);
	m_node = m_node->m_prev;
	return *this;
}

/**
* @brief ��u�C���N�������g���Z�q
* @return �X�V�O�̃C�e���[�^�ւ̎Q��
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::Const_Iterator::operator++(int)
{
	assert(m_node != nullptr);
	Const_Iterator temp = *this;
	++(*this);
	return temp;
}

/**
* @brief ��u�f�N�������g���Z�q
* @return �X�V�O�̃C�e���[�^�ւ̎Q��
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::Const_Iterator::operator--(int)
{
	assert(m_node != nullptr);
	Const_Iterator temp = *this;
	--(*this);
	return temp;
}

/**
* @brief �f���t�@�����X���Z�q
* @return  ���уf�[�^�̎Q��
*/
template<typename T>
inline const T & BidirectionalList<T>::Const_Iterator::operator*() const
{
	assert(m_node != nullptr);
	return m_node->m_data;
}

/**
* @brief 2�� Const_Iterator �C�e���[�^���r����
* @param ite ��r�Ώۂ� Const_Iterator
* @return 2�̃C�e���[�^�������v�f���w���Ă���ꍇ�� true ��Ԃ�
*/
template<typename T>
inline bool BidirectionalList<T>::Const_Iterator::operator==(const Const_Iterator & ite) const
{
	return m_node == ite.m_node;
}

/**
* @brief 2�� Const_Iterator �C�e���[�^���r����
* @param ite ��r�Ώۂ� Const_Iterator
* @return 2�̃C�e���[�^���قȂ�v�f���w���Ă���ꍇ�� true ��Ԃ�
*/
template<typename T>
inline bool BidirectionalList<T>::Const_Iterator::operator!=(const Const_Iterator & ite) const
{
	return m_node != ite.m_node;
}

/**
* @brief �f�t�H���g�R���X�g���N�^
*/
template<typename T>
inline BidirectionalList<T>::Iterator::Iterator()
	: Const_Iterator(){}

/**
* @brief �����t���R���X�g���N�^
* @param node �m�[�h���w�肷��|�C���^
* @param list �C�e���[�^�̏������Ă��郊�X�g�̏��
*/
template<typename T>
inline BidirectionalList<T>::Iterator::Iterator(Node * node, const BidirectionalList * list)
	: Const_Iterator(node, list) {}

/**
* @brief �f���t�@�����X���Z�q
* @return m_node->m_data ���уf�[�^�̎Q��
*/
template<typename T>
inline T & BidirectionalList<T>::Iterator::operator*()
{
	assert(Const_Iterator::m_node != nullptr);
	return Const_Iterator::m_node->m_data;
}


/**
* @brief �f�t�H���g�R���X�g���N�^
*/
template<typename T>
inline BidirectionalList<T>::BidirectionalList()
{
	m_dummyNode = new Node();
	m_dummyNode->m_next = m_dummyNode;
	m_dummyNode->m_prev = m_dummyNode;
	m_size = 0;
}


/**
* @brief �f�X�g���N�^
*/
template<typename T>
inline BidirectionalList<T>::~BidirectionalList()
{
	Node* current = m_dummyNode->m_next;
	// �_�~�[�m�[�h���w���܂ŉ�
	while (current != m_dummyNode)
	{
		Node* temp = current;
		current = current->m_next;
		// �m�[�h�̍폜
		delete temp;
	}
	// �_�~�[�m�[�h�̍폜
	delete m_dummyNode;
}

/**
* @brief ���X�g�̃T�C�Y��Ԃ�
* @return int ���X�g�̃T�C�Y
*/
template<typename T>
inline int BidirectionalList<T>::GetSize() const
{
	return m_size;
}

/**
* @brief �C�e���[�^�Ŏw�肳�ꂽ�ʒu�Ƀf�[�^��}��
* @param ite �}������ʒu���w�肵���C�e���[�^
* @param data �f�[�^
�A ���s�����ꍇ(�s���ȃC�e���[�^�̏ꍇ) false
*/
template<typename T>
inline bool BidirectionalList<T>::Insert(Const_Iterator & ite, const T & data)
{
	// �s���ȃC�e���[�^�����O
	if (ite.m_list != this) return false;

	Node* newNode = new Node(data);

	// ��C�e���[�^���ǂ������m�F
	// ��Ȃ�_�~�[�m�[�h���A���ʂȂ�ite.node��}��
	newNode->m_next = (ite.m_node != nullptr) ? ite.m_node : m_dummyNode->m_next;
	newNode->m_prev = (ite.m_node != nullptr) ? ite.m_node->m_prev : m_dummyNode;


	if (newNode->m_next)
	{
		newNode->m_next->m_prev = newNode;
	}
	// �O�Ƀm�[�h�����邩
	if (newNode->m_prev)
	{
		// ���̃m�[�h��V�����m�[�h�ɐݒ肷��
		newNode->m_prev->m_next = newNode;
	}
	else
	{
		// �_�~�[�m�[�h�̎���V�����m�[�h�ɐݒ肷��
		m_dummyNode->m_next = newNode;
	}

	m_size++;
	return true;
}

/**
* @brief �C�e���[�^�Ŏw��ʒu�̃f�[�^���폜
* @param[in]  �폜����ʒu���w�肵���C�e���[�^
* @return �폜�����������ꍇ true�A �����ȃC�e���[�^�A�_�~�[�m�[�h�ꍇ false
*/
template<typename T>
inline bool BidirectionalList<T>::Delete(Const_Iterator & ite)
{
	Node* nodeDelete = ite.m_node;

	// �s���ȃC�e���[�^�A�_�~�[�m�[�h, �قȂ郊�X�g�̗v�f�����O
	if (!nodeDelete || nodeDelete == m_dummyNode ||
		ite.m_list != this)
	{
		return false;
	}

	// �폜����m�[�h�̑O����Ȃ���
	nodeDelete->m_prev->m_next = nodeDelete->m_next;
	nodeDelete->m_next->m_prev = nodeDelete->m_prev;
	// �m�[�h�폜
	delete nodeDelete;
	m_size--;
	return true;
}

/**
* @brief �N�C�b�N�\�[�g�Ăяo���֐�
* @param[in]  iteLeft �\�[�g����͈͂̐擪�C�e���[�^
* @param[in]  iteRight �\�[�g����͈̖͂����C�e���[�^
* @param[in]  asc_des true : ����, false : �~��
* @param[in]  key �\�[�g�Ŏg�p����L�[
* @return �\�[�g�����������ꍇ true�A����ȊO�̏ꍇ false
*/
template<typename T>
inline bool BidirectionalList<T>::QuickSort(Const_Iterator iteLeft, Const_Iterator iteRight,
	bool asc_des, function<bool(const T&, const T&)> key)
{
	// �󂩈���������ꍇ�A�L�[��nullptr�̏ꍇ�͏������Ȃ�
	if (GetSize() <= 1 || key == nullptr)
		return false;
	
	Sort(iteLeft, --iteRight, asc_des, key);
	return true;
}

/**
* @brief �擪�C�e���[�^��Ԃ�
* @return bool �擪�C�e���[�^
*/
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::Begin() const
{
	// ���X�g���󂶂�Ȃ���
	if (m_dummyNode->m_next != m_dummyNode)
	{
		// �擪�C�e���[�^��Ԃ�
		return Iterator(m_dummyNode->m_next, this);
	}
	else
	{
		// ��̐擪�C�e���[�^��Ԃ�
		return Iterator(nullptr, this);
	}
}

/**
* @brief �擪�C�e���[�^��Ԃ�
* @return Iterator �擪�C�e���[�^
*/
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::begin() const
{
	return Begin();
}

/**
* @brief �擪��const�C�e���[�^��Ԃ�
* @return ConstIterato �擪const�C�e���[�^
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::ConstBegin() const
{
	// ���X�g���󂶂�Ȃ���
	if (m_dummyNode->m_next != m_dummyNode)
	{
		// �擪const�C�e���[�^��Ԃ�
		return Const_Iterator(m_dummyNode->m_next, this);
	}
	else
	{
		// ��̐擪const�C�e���[�^��Ԃ�
		return Const_Iterator(nullptr, this);
	}
}

/**
* @brief �����C�e���[�^��Ԃ�
* @return Iterator �����C�e���[�^
*/
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::End() const
{
	// ���X�g���󂶂�Ȃ���
	if (m_dummyNode->m_prev != m_dummyNode)
	{
		// �����C�e���[�^��Ԃ�
		return Iterator(m_dummyNode, this);
	}
	else
	{
		// ��̖����C�e���[�^��Ԃ�
		return Iterator(nullptr, this);
	}
}

/**
* @brief �����C�e���[�^��Ԃ�
* @return Iterator �����C�e���[�^
* `
*/
template<typename T>
inline typename BidirectionalList<T>::Iterator BidirectionalList<T>::end() const
{
	return End();
}

/**
* @brief ������const�C�e���[�^��Ԃ�
* @return ConstIterator ����const�C�e���[�^
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::ConstEnd() const
{
	// ���X�g���󂶂�Ȃ���
	if (m_dummyNode->m_prev != m_dummyNode)
	{
		// ����const�C�e���[�^��Ԃ�
		return Const_Iterator(m_dummyNode, this);
	}
	else
	{

		// ��̖���const�C�e���[�^��Ԃ�
		return Const_Iterator(nullptr, this);
	}
}

/**
* @brief �N�C�b�N�\�[�g�����s��������֐�
* @param[in]  iteLeft �\�[�g����͈͂̐擪�C�e���[�^
* @param[in]  iteRight �\�[�g����͈̖͂����C�e���[�^
* @param[in]  asc_des true : ����, false : �~��
* @param[in]  key �\�[�g�Ŏg�p����L�[
*/
template<typename T>
inline void BidirectionalList<T>::Sort(Const_Iterator  iteLeft, Const_Iterator  iteRight, bool asc_des, function<bool(const T&, const T&)> key)
{
	// ���[�ƉE�[���������Ȃ���
	if (iteLeft != iteRight)
	{
		// ���ڂ��擾����
		Const_Iterator pivot = Partition(iteLeft, iteRight, asc_des, key);
		// ���ڂ����������ċA�I�Ƀ\�[�g
		if (iteLeft != pivot)
		{
			Sort(iteLeft, --pivot, asc_des, key);
		}
		// ���ڂ����E�����ċA�I�Ƀ\�[�g
		if (pivot != iteRight)
		{
			Sort(++pivot, iteRight, asc_des, key);
		}
	}
}

/**
* @brief �N�C�b�N�\�[�g�̂��߂̋��ڂ�������֐�
* @param[in]  iteLeft �\�[�g����͈͂̐擪�C�e���[�^
* @param[in]  iteRight �\�[�g����͈̖͂����C�e���[�^
* @param[in]  asc_des true : ����, false : �~��
* @param[in]  key �\�[�g�Ŏg�p����L�[
* @return ���ڂ̃C�e���[�^
*/
template<typename T>
inline typename BidirectionalList<T>::Const_Iterator BidirectionalList<T>::Partition(Const_Iterator iteLeft, Const_Iterator iteRight,
	bool asc_des, function<bool(const T&, const T&)> key)
{
	// ����
	Node* pivot = iteLeft.m_node;
	// ����
	Node* left = iteLeft.m_node;
	// �E��
	Node* right = iteRight.m_node;

	while (left != right)
	{
		if (asc_des)
		{
			// �������r
			while (left != right && key(left->m_data, pivot->m_data))
				left = left->m_next;
			// �E�����r
			while (left != right && key(pivot->m_data, right->m_data))
				right = right->m_prev;
		}
		else
		{
			// �������r
			while (left != right && key(pivot->m_data, left->m_data))
				left = left->m_next;
			// �E�����r
			while (left != right && key(right->m_data, pivot->m_data))
				right = right->m_prev;
		}

		if (left != right)
		{
			// ���E�̗v�f������
			T temp = left->m_data;
			left->m_data = right->m_data;
			right->m_data = temp;
		}
	}

	// ���ڂƉE�[�̗v�f������
	T temp = pivot->m_data;
	pivot->m_data = right->m_data;
	right->m_data = temp;

	// ���ڂ̃C�e���[�^��Ԃ�
	BidirectionalList<T>::Const_Iterator it;
	it.m_node = right;
	return it;
}