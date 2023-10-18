#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BidirectionalList.h"


using namespace std;


int main()
{
	// �t�@�C���ǂݍ���
	string fileName("Assets/Scores.txt");
	ifstream scoreFile(fileName);

	// �ǂݍ��݂ŗ�����
	if (!scoreFile)
	{
		cout << "�t�@�C���I�[�v���Ɏ��s" << endl;
		cin.get();
		return 1;
	}

	BidirectionalList<Record> bidirectionalList;
	string line;

	BidirectionalList<Record>::Iterator it = bidirectionalList.Begin();

	// 1�s���ǂݍ���
	while (getline(scoreFile, line))
	{
	
		istringstream istring(line);
		string score;
		string userName;

		// ���ꂼ��̕ϐ��Ɋi�[
		if (istring >> score >> userName)
		{
			// ���X�g�Ɋi�[
			Record rec = { score, userName };
			bidirectionalList.Insert(it, rec);
			it = bidirectionalList.End();
		}
	}
	scoreFile.close();

	// �\��
	for (BidirectionalList<Record>::Iterator it = bidirectionalList.Begin(); it != bidirectionalList.End(); ++it)
	{
		cout << (*it).score << " " << (*it).userName << endl;
	}

	getchar();
	return 0;
}