/**********************************************************************************//**
	@file           main.cpp
	@brief          �o�������X�g���H
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
	// �����p
	//BidirectionalList<int> intList;
	//BidirectionalList<float> floatList;

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
		int score;
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

	// ���[�U�[���Ń\�[�g����
	bidirectionalList.QuickSort(bidirectionalList.ConstBegin(),bidirectionalList.ConstEnd(),
		true,[](const Record& a, const Record& b) {
		return a.score < b.score;});

	

	// �\��
	for (const Record& rec: bidirectionalList)
	{
		cout << rec.score << " " << rec.userName << endl;
	}

	getchar();
	return 0;
}