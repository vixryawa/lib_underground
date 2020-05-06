#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"pch.h"
#include <string>
#include "SubwLib.h"

using namespace std;
using std::string;


extern "C" {

    CasStation* create_casstation(int n, int traf, char* name) {
        return new CasStation(n, traf, name);
    }

    int get_n(CasStation* s) {
        return s->get_n();
    }

    int get_traf(CasStation* s) {
        return s->get_traf();
    }

 //   void get_name(CasStation* s, char* name, int max_name_len) {
 //       strncpy_s(name, max_name_len, s->get_name().c_str(), max_name_len);
 //   }

    void print_station(CasStation* s) {
        return s->print();
    }

    void dispose_station(CasStation* s) {
        delete s;
    }
}
