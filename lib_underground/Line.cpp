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

    Line* create_line() {
        return new Line();
    }

    void add_station(Line* l, CasStation* s1, int timeaway) {
        return l->add_station(*s1, timeaway);
    }

    int time_between(Line* l, CasStation* s1, CasStation* s2) {
        return l->time_between(*s1, *s2);
    }
}