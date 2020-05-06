#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include"pch.h"
#include <string>

using namespace std;
using std::string;


class CasStation {
protected:
    int n; //!< номер на линии
    int traf; //!< пассажиропоток
    string name; //!< название станции
public:
    int n_added = 0;
    // методы класса
    CasStation(int n = 0, int traf = 0, string name = "")
        :n(n), traf(traf), name(name) {}

    int get_n() const {
        return n;
    }

    int get_traf() const {
        return traf;
    }

    string get_name() const {
        return name;
    }

    //! перегрузка операторов
    friend bool operator> (const CasStation& s1, const CasStation& s2) {
        return s1.n > s2.n;
    }
    friend bool operator== (const CasStation& s1, const CasStation& s2) {
        return s1.n == s2.n;
    }
    friend bool operator< (const CasStation& s1, const CasStation& s2) {
        return !(s1 == s2 || s1 > s2);
    }
    friend ostream& operator<<(ostream& os, const CasStation& a) {
        os << a.name;
        return os;
    }

    virtual void print() const {
        printf("Station %s is number %i and traffic is %i\n",
            name.c_str(), n, traf);
    }
    virtual ~CasStation() {}

};