#pragma once
#include <vector>
#include<iostream>

#include"CasStation.h"

//! описание
class TransStation : public CasStation {
    vector <TransStation> transf;

public:
    TransStation(int n, int traf, string name) :
        CasStation(n, traf, name) {}

    void connect(TransStation& s2) {
        transf.push_back(s2);
    }

    void print() const {
        int j = 0;
        printf("Station %s is number %i and traffic is %i\nYou can change the line and go to %i stations: ",
            name.c_str(), n, traf, int(transf.size()));
        for (j = 0; j < int(transf.size()); j++) {
            cout << transf[j].name;
            cout << endl;
        }
        printf("\n");
    }
};

