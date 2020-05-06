#pragma once
#include <vector>
#include <string.h>
#include<iostream>
#include"CasStation.h"
#include"TTree.h"
#include"pch.h"


using std::string;
//�������� ������ �����
class Line {
	//vector <CasStation> stations;
	//vector <Stretch> strcs;

	vector <int> time; //! ������ ���������� ������� �� ������ �����
	int count; //! ���������� ��� ��������� ������� 
public:
	vector <Transfer> transf;
	int number_ = -1;
	TTree<CasStation> tree; //! ������ ��� �������� �������
	Line() {
		count = 0;
	}

	void add_station(CasStation& s1, int timeaway) {
		tree.Insert(s1); // ��������� � ������
		time.push_back(timeaway); // ��������� � ��������� ���������� �����
		s1.n_added = count; // ���������� ��� ������ ������� ����� �� ����� ��� ��������� 
		count++; // ���������� ��� ��������� ������� �������������
	}

	int time_between(CasStation& s1, CasStation& s2) {
		if (s1.n_added < s2.n_added)
			return time[s2.n_added] - time[s1.n_added];
		else
			return time[s1.n_added] - time[s2.n_added];
	}
};

