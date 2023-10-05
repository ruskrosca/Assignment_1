#ifndef ___PARAM_H___
#define ___PARAM_H___

#include <string>

using namespace std;

class Param
{
private:
	string m_name;		// �f�[�^
	Param* m_next;		// ���̃f�[�^�̃|�C���^��ێ�
	Param* m_prev;		// �O�̃f�[�^�̃|�C���^��ێ�

public:
	// �p�����[�^�̏�����
	Param(const string & valu)
		: m_name(valu)
		, m_next(nullptr)
		, m_prev(nullptr)
	{}
};



#endif // !___PARAM_H___
