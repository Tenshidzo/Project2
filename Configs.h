
#pragma once
#include "Lib.h"
struct Configs {
	char name[1000] = "";
	int price = 0;
};
int size_arr_Processors = 3;
int size_arr_VideoCards = 3;
int size_arr_ozu = 6;
Configs* arr_Processors = new Configs[size_arr_Processors]{
		{"Intel CORE i9-13600KF", 25000},
		{"Ryzen 5-3600", 8000},
		{"Intel CORE i7-10700KF", 10000}
};
Configs* arr_VideoCards = new Configs[size_arr_VideoCards]{
	{"Nvidia RTX 3090ti", 38000},
	{"Nvidia GTX 1080ti", 15000},
	{"Nvidia GTX 1050", 8000}
}
;
Configs* arr_ozu = new Configs[size_arr_ozu]{
	{"DDR4 8 gb", 3000},
	{"DDR3 8 gb", 2431},
	{"DDR4 16 gb", 6000},
	{"DDR5 16 gb", 8000},
	{"DDR3 4 gb", 1500},
	{"DDR5 32 gb",10090},
};
Configs* arr_rgb = new Configs[2]{
	{"Yes", 1000},
	{"No", 0}
};
