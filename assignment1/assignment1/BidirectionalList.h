#ifndef ___BIDIRECTIONAL_LIST_H___
#define ___BIDIRECTIONAL_LIST_H___

#include <iostream>
#include <string>
#include "Param.h"

using namespace std;

class BidirectionalList
{
public:
	Param* m_head;	// �擪�̃f�[�^
	Param* m_tail;	// �����̃f�[�^
public:
	BidirectionalList();
	~BidirectionalList();

	void GetList(const string& date);	// �擾�����f�[�^���i�[����֐�
	void Display();						// �f�[�^�\���̊֐�

private:

};
#endif // !___BIDIRECTIONAL_LIST_H___
