#pragma once
#include <string.h>
#include<iostream>
#include"CasStation.h"


using std::string;

class Stretch {
	CasStation st1;
	CasStation st2;
	int time;  //! время прохождения перегона
public:
	Stretch(CasStation& st1, CasStation& st2, int time);

	void print() const;

	const CasStation& get_stat1();

	const CasStation& get_stat2();

	int get_time();

};

Stretch::Stretch(CasStation& st1, CasStation& st2, int time) {
	this->st1 = st1;
	this->st2 = st2;
	this->time = time;

	/*
	if (st1 < st2)
		st1.add_upper(time);
	else
		st2.add_upper(time);
	*/
}

void Stretch::print() const {
	printf("Stretch is %i min long and is between stations: ", this->time);
	cout << this->st1 << " " << this->st2 << endl;
}

const CasStation& Stretch::get_stat1() {
	return this->st1;
}

const CasStation& Stretch::get_stat2() {
	return this->st2;
}

int Stretch::get_time() {
	return this->time;
}