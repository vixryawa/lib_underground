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

    Transfer* create_transfer(CasStation* st1, CasStation* st2, int time, int traf) {
        return new Transfer(*st1, *st2, time, traf);
    }

}
