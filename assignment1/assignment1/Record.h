/**********************************************************************************//**
	@file           Record.h
	@brief          成績データ宣言
	@author			RyosukeNarsushima
*//***********************************************************************************/

#ifndef ___RECORD_H___
#define ___RECORD_H___

#include <string>

/**
* @brief 成績データ
*/
struct Record
{
	//! スコア
	std::string score;
	//! ユーザー名
	std::string userName;
};

#endif // !___RECORD_H___

