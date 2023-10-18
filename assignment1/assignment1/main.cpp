#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BidirectionalList.h"


using namespace std;


int main()
{
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
		string score;
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

	// 表示
	for (BidirectionalList<Record>::Iterator it = bidirectionalList.Begin(); it != bidirectionalList.End(); ++it)
	{
		cout << (*it).score << " " << (*it).userName << endl;
	}

	getchar();
	return 0;
}