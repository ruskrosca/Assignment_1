#ifndef ___BIDIRECTIONAL_LIST_H___
#define ___BIDIRECTIONAL_LIST_H___

#include <iostream>
#include <string>
#include "Param.h"

using namespace std;

class BidirectionalList
{
public:
	Param* m_head;	// 先頭のデータ
	Param* m_tail;	// 末尾のデータ
public:
	BidirectionalList();
	~BidirectionalList();

	void GetList(const string& date);	// 取得したデータを格納する関数
	void Display();						// データ表示の関数

private:

};
#endif // !___BIDIRECTIONAL_LIST_H___
