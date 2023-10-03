#ifndef ___PARAM_H___
#define ___PARAM_H___

#include <string>

using namespace std;

class Param
{
public:
	string m_name;		// データ
	Param* m_next;		// 次のデータのポインタを保持
	Param* m_last;		// 前のデータのポインタを保持

public:

	// パラメータの初期化
	Param(const string & valu)
		: m_name(valu)
		, m_next(nullptr)
		, m_last(nullptr)
	{}
};



#endif // !___PARAM_H___
