#include "BidirectionalList.h"

BidirectionalList::BidirectionalList()
	: m_head(nullptr)
	, m_tail(nullptr)
{}

BidirectionalList::~BidirectionalList()
{}

void BidirectionalList::GetList(const string & data)
{
	// �V�����f�[�^���擾
	Param* getParam = new Param(data);
	// ���X�g�̒��g���m�F������
	if (!m_head)
	{	// �󂾂����ꍇ	
		// �擾�����f�[�^��ݒ肷��
		m_head = getParam;	// �擪��ݒ�
		m_tail = getParam;	// ������ݒ�
	}
	else
	{	// �󂶂�Ȃ������ꍇ
		m_tail->m_next = getParam;	// �����̎��ɐV�����f�[�^��ݒ�
		getParam->m_last = m_tail;	// �V�����f�[�^�ɖ����̃f�[�^��ݒ�
		m_tail = getParam;		// �������X�V������
	}
}

void BidirectionalList::Display()
{
	// �擪�̏����擾
	Param* displayParam = m_head;
	while (displayParam)
	{
		// �f�[�^��\��
		cout << displayParam->m_name << ""  << endl;	
		displayParam = displayParam->m_next;	// ���̃f�[�^��ݒ�
	}
}

