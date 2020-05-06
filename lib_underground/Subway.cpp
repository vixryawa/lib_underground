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

    Subway* create_subway() {
        return new Subway();
    }

    void add_line(Subway* sub, Line* l1) {
        return sub->add_line(*l1);
    }

    void add_transf(Subway* sub, Line* l1, Line* l2, Transfer* tr) {
        return sub->add_transf(*l1, *l2, *tr);
    }

    void add_stat_to_line(Subway* sub, CasStation* s, int timeaway, Line* l) {
        return sub->add_stat_to_line(*s, timeaway, *l);
    }
}