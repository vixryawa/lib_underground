#pragma once
#include"CasStation.h"
#include"TransStation.h"
#include"Transfer.h"
#include"Line.h"
#include"Subway.h"

#ifdef PROJECT_EXPORTS
#define PROJECT_API __declspec(dllexport)
#else
#define PROJECT_API __declspec(dllimport)
#endif

extern "C"
{
	PROJECT_API CasStation* create_casstation(int n, int traf, char* name);
	PROJECT_API int get_n(CasStation* s);
	PROJECT_API int get_traf(CasStation* s);
	//PROJECT_API void get_name(CasStation* s, char* name, int max_name_len);
	//PROJECT_API void print_station(CasStation* s);
	PROJECT_API void dispose_station(CasStation* s);

	PROJECT_API TransStation* create_transstation(int n, int traf, char* name);
	//PROJECT_API void print_transstation(TransStation* s);
	PROJECT_API void connect(TransStation* s1, TransStation* s2);
	PROJECT_API void dispose_transstation(TransStation* s);

	PROJECT_API Transfer* create_transfer(CasStation* st1, CasStation* st2, int time, int traf);

	PROJECT_API Line* create_line();
	PROJECT_API void add_station (Line* l, CasStation* s1, int timeaway);
	PROJECT_API int time_between(Line* l, CasStation* s1, CasStation* s2);

	PROJECT_API Subway* create_subway();
	PROJECT_API void add_line(Subway* sub, Line* l1);
	PROJECT_API void add_transf(Subway* sub, Line* l1, Line* l2, Transfer* tr);
	PROJECT_API void add_stat_to_line(Subway* sub, CasStation* s, int timeaway, Line* l);
}