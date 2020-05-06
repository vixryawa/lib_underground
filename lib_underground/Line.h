#pragma once
#include <vector>
#include <string.h>
#include<iostream>
#include"CasStation.h"
#include"TTree.h"
#include"pch.h"


using std::string;
//создание класса линия
class Line {
	//vector <CasStation> stations;
	//vector <Stretch> strcs;

	vector <int> time; //! массив расстояний станций от начала ветки
	int count; //! количество уже внесенных станций 
public:
	vector <Transfer> transf;
	int number_ = -1;
	TTree<CasStation> tree; //! дерево для хранения станций
	Line() {
		count = 0;
	}

	void add_station(CasStation& s1, int timeaway) {
		tree.Insert(s1); // вставляем в дерево
		time.push_back(timeaway); // добавляем в контейнер расстояний время
		s1.n_added = count; // запоминаем для каждой станции какой по счету она добавлена 
		count++; // количество уже внесенных станций увеличивается
	}

	int time_between(CasStation& s1, CasStation& s2) {
		if (s1.n_added < s2.n_added)
			return time[s2.n_added] - time[s1.n_added];
		else
			return time[s1.n_added] - time[s2.n_added];
	}
};

