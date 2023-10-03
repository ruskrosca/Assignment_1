#include "BidirectionalList.h"

BidirectionalList::BidirectionalList()
	: m_head(nullptr)
	, m_tail(nullptr)
{}

BidirectionalList::~BidirectionalList()
{}

void BidirectionalList::GetList(const string & data)
{
	// 新しくデータを取得
	Param* getParam = new Param(data);
	// リストの中身を確認をする
	if (!m_head)
	{	// 空だった場合	
		// 取得したデータを設定する
		m_head = getParam;	// 先頭を設定
		m_tail = getParam;	// 末尾を設定
	}
	else
	{	// 空じゃなかった場合
		m_tail->m_next = getParam;	// 末尾の次に新しいデータを設定
		getParam->m_last = m_tail;	// 新しいデータに末尾のデータを設定
		m_tail = getParam;		// 末尾を更新をする
	}
}

void BidirectionalList::Display()
{
	// 先頭の情報を取得
	Param* displayParam = m_head;
	while (displayParam)
	{
		// データを表示
		cout << displayParam->m_name << ""  << endl;	
		displayParam = displayParam->m_next;	// 次のデータを設定
	}
}

