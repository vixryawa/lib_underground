#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include"pch.h"
#include "SubwLib.h"

using namespace std;
using std::string;

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" {

    TransStation* create_transstation(int n, int traf, char* name) {
        return new TransStation(n, traf, name);
    }

    void print_transstation(TransStation* s) {
        return s->print();
    }

    void connect(TransStation* s1, TransStation* s2) {
        return s1->connect(*s2);
    }

    void dispose_transstation(TransStation* s) {
        delete s;
    }
}