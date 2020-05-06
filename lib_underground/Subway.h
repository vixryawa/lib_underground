#pragma once
#include <vector>
#include <string.h>
#include<iostream>

#include"pch.h"
#include "SubwLib.h"
#include"Transfer.h"
#include"CasStation.h"
#include"TTree.h"
#include"Line.h"

using std::string;
//�������� ������ �����
class Subway {
	vector <Line> lines; //! ������ �����
	//vector <Transfer> transfers;
	// Transfer transfer[5][5]; //! ������ ���������
	int count; //! ���������� ��� ��������� ������� 
public:
	Subway() {
		count = 0;
	}

	void add_line(Line& l1) {
		lines.push_back(l1);
	}

	void add_transf(Line& l1, Line& l2, Transfer& tr) {
		//transfers.push_back(tr);
		(l1.transf).push_back(tr);
		(l2.transf).push_back(tr);
	}

	void add_stat_to_line(CasStation& s, int timeaway, Line& l) {
		l.add_station(s, timeaway);
	}

	//int time_between(CasStation& s1, CasStation& s2);
};
