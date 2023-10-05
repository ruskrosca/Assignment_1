#include <iostream>
#include <fstream>
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

	//BidirectionalList* bidirectionalList;
	//string line;
	// 一行取り出す
	/*while (getline(scoreFile, line))
	{
		// リストに追加
		bidirectionalList.GetList(line);
	}

	// リストの表示
	bidirectionalList.Display();*/

	getchar();
	return 0;
}