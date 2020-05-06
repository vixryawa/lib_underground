#pragma once
#include <string.h>
#include<iostream>
#include"CasStation.h"
#include"pch.h"

using std::string;

class Transfer {
	CasStation st1;
	CasStation st2;
	int time;  // время на переход
	int traf; //пассариропоток
public:
	Transfer();

	Transfer(CasStation& st1, CasStation& st2, int time, int traf)
		:st1(st1), st2(st2), time(time), traf(traf) {
		time = 0;
		traf = 0;
	}

	void print() const {
		printf("Transfer is %i min long, traffic is %i and is between stations: ", this->time, this->traf);
		cout << this->st1 << " " << this->st2 << endl;
	}

	CasStation& get_stat1() {
		return this->st1;
	}

	CasStation& get_stat2() {
		return this->st2;
	}

	int get_time() {
		return this->time;
	}

	int get_traf() {
		return this->traf;
	}


};
