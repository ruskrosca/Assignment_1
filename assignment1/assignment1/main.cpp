#include <iostream>
#include <fstream>
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

	//BidirectionalList* bidirectionalList;
	//string line;
	// ��s���o��
	/*while (getline(scoreFile, line))
	{
		// ���X�g�ɒǉ�
		bidirectionalList.GetList(line);
	}

	// ���X�g�̕\��
	bidirectionalList.Display();*/

	getchar();
	return 0;
}