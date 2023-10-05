#ifndef ___PARAM_H___
#define ___PARAM_H___

#include <string>

using namespace std;

class Param
{
private:
	string m_name;		// データ
	Param* m_next;		// 次のデータのポインタを保持
	Param* m_prev;		// 前のデータのポインタを保持

public:
	// パラメータの初期化
	Param(const string & valu)
		: m_name(valu)
		, m_next(nullptr)
		, m_prev(nullptr)
	{}
};



#endif // !___PARAM_H___
