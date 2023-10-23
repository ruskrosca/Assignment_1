/**********************************************************************************//**
	@file           main.cpp
	@brief          双方向リスト実践
	@author			RyosukeNarsushima
*//***********************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BidirectionalList.h"
#include "Record.h"

using namespace std;


int main()
{
	// 実験用
	//BidirectionalList<int> intList;
	//BidirectionalList<float> floatList;

	// ファイル読み込み
	string fileName("Assets/Scores.txt");
	ifstream scoreFile(fileName);

	// 読み込みで来たか
	if (!scoreFile)
	{
		cout << "ファイルオープンに失敗" << endl;
		cin.get();
		return 1;
	}

	BidirectionalList<Record> bidirectionalList;
	string line;

	BidirectionalList<Record>::Iterator it = bidirectionalList.Begin();

	// 1行ずつ読み込む
	while (getline(scoreFile, line))
	{
	
		istringstream istring(line);
		int score;
		string userName;

		// それぞれの変数に格納
		if (istring >> score >> userName)
		{
			// リストに格納
			Record rec = { score, userName };
			bidirectionalList.Insert(it, rec);
			it = bidirectionalList.End();
		}
	}
	scoreFile.close();

	// ユーザー名でソートする
	bidirectionalList.QuickSort(bidirectionalList.ConstBegin(),bidirectionalList.ConstEnd(),
		true,[](const Record& a, const Record& b) {
		return a.score < b.score;});

	

	// 表示
	for (const Record& rec: bidirectionalList)
	{
		cout << rec.score << " " << rec.userName << endl;
	}

	getchar();
	return 0;
}