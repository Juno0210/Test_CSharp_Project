// Kjs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void welcome() {
	cout << "Welcome to mining method selection - A Numerical Approach" << endl;
	cout << "Based on research by David E Nicholas" << endl;
}

// 10 Square set
double square_set(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 0;
	else if (geometry_distribution[0] == 'T')sum += 2;
	else if (geometry_distribution[0] == 'I')sum += 4;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += 4;
	else if (geometry_distribution[1] == 'I')sum += 4;
	else if (geometry_distribution[1] == 'T')sum += 1;
	else if (geometry_distribution[1] == 'V')sum += 1;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 2;
	else if (geometry_distribution[2] == 'I')sum += 3;
	else if (geometry_distribution[2] == 'S')sum += 3;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 3;
	else if (geometry_distribution[3] == 'G')sum += 3;
	else if (geometry_distribution[3] == 'E')sum += 3;
	return sum;
}

//square set
double square_set_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 3;
	else if (hangingWall_data[0] == 'M')sum += 2;
	else if (hangingWall_data[0] == 'S')sum += 2;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 3;
	else if (hangingWall_data[1] == 'C')sum += 3;
	else if (hangingWall_data[1] == 'W')sum += 2;
	else if (hangingWall_data[1] == 'D')sum += 2;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 4;
	else if (hangingWall_data[2] == 'M')sum += 3;
	else if (hangingWall_data[2] == 'S')sum += 2;

	return sum;
}

//square cut
double square_set_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 4;
	else if (oreZone_data[0] == 'M')sum += 1;
	else if (oreZone_data[0] == 'S')sum += 1;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 4;
	else if (oreZone_data[1] == 'C')sum += 4;
	else if (oreZone_data[1] == 'W')sum += 2;
	else if (oreZone_data[1] == 'D')sum += 1;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 4;
	else if (oreZone_data[2] == 'M')sum += 3;
	else if (oreZone_data[2] == 'S')sum += 2;

	return sum;
}

//Square set
double square_set_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 4;
	else if (footWall_data[0] == 'M')sum += 2;
	else if (footWall_data[0] == 'S')sum += 2;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 4;
	else if (footWall_data[1] == 'C')sum += 4;
	else if (footWall_data[1] == 'W')sum += 2;
	else if (footWall_data[1] == 'D')sum += 2;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 4;
	else if (footWall_data[2] == 'M')sum += 4;
	else if (footWall_data[2] == 'S')sum += 2;

	return sum;
}

//calculation for square set
double squareSet_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += square_set(geometry_distribution);

	sum += square_set_hanging_wall(hangingWall_data);

	sum += square_set_ore_zone(oreZone_data);

	sum += square_set_foot_wall(footWall_data);

	return sum;
}

// 9-Top SLicing
double top_slicing(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 3;
	else if (geometry_distribution[0] == 'T')sum += 3;
	else if (geometry_distribution[0] == 'I')sum += 0;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += -49;
	else if (geometry_distribution[1] == 'I')sum += 0;
	else if (geometry_distribution[1] == 'T')sum += 3;
	else if (geometry_distribution[1] == 'V')sum += 4;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 4;
	else if (geometry_distribution[2] == 'I')sum += 1;
	else if (geometry_distribution[2] == 'S')sum += 2;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 4;
	else if (geometry_distribution[3] == 'G')sum += 2;
	else if (geometry_distribution[3] == 'E')sum += 0;
	return sum;
}

//top slicing
double top_slicing_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 4;
	else if (hangingWall_data[0] == 'M')sum += 2;
	else if (hangingWall_data[0] == 'S')sum += 1;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 3;
	else if (hangingWall_data[1] == 'C')sum += 3;
	else if (hangingWall_data[1] == 'W')sum += 3;
	else if (hangingWall_data[1] == 'D')sum += 0;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 4;
	else if (hangingWall_data[2] == 'M')sum += 2;
	else if (hangingWall_data[2] == 'S')sum += 0;

	return sum;
}

//top slicing
double top_slicing_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 2;
	else if (oreZone_data[0] == 'M')sum += 3;
	else if (oreZone_data[0] == 'S')sum += 3;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 1;
	else if (oreZone_data[1] == 'C')sum += 1;
	else if (oreZone_data[1] == 'W')sum += 2;
	else if (oreZone_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 1;
	else if (oreZone_data[2] == 'M')sum += 2;
	else if (oreZone_data[2] == 'S')sum += 4;

	return sum;
}

//top slicing

double top_slicing_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 2;
	else if (footWall_data[0] == 'M')sum += 3;
	else if (footWall_data[0] == 'S')sum += 3;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 1;
	else if (footWall_data[1] == 'C')sum += 3;
	else if (footWall_data[1] == 'W')sum += 3;
	else if (footWall_data[1] == 'D')sum += 3;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 1;
	else if (footWall_data[2] == 'M')sum += 2;
	else if (footWall_data[2] == 'S')sum += 3;

	return sum;
}

//calculation for top slicing
double topSlicing_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += top_slicing(geometry_distribution);

	sum += top_slicing_hanging_wall(hangingWall_data);

	sum += top_slicing_ore_zone(oreZone_data);

	sum += top_slicing_foot_wall(footWall_data);

	return sum;
}

//cut and fill
double cut_fill_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 4;
	else if (footWall_data[0] == 'M')sum += 2;
	else if (footWall_data[0] == 'S')sum += 2;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 4;
	else if (footWall_data[1] == 'C')sum += 4;
	else if (footWall_data[1] == 'W')sum += 2;
	else if (footWall_data[1] == 'D')sum += 2;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 4;
	else if (footWall_data[2] == 'M')sum += 4;
	else if (footWall_data[2] == 'S')sum += 2;

	return sum;
}
//cut and fill
double cut_fill_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 3;
	else if (oreZone_data[0] == 'M')sum += 2;
	else if (oreZone_data[0] == 'S')sum += 2;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 3;
	else if (oreZone_data[1] == 'C')sum += 3;
	else if (oreZone_data[1] == 'W')sum += 2;
	else if (oreZone_data[1] == 'D')sum += 2;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 3;
	else if (oreZone_data[2] == 'M')sum += 3;
	else if (oreZone_data[2] == 'S')sum += 2;

	return sum;
}
//cut and fill
double cut_fill_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 3;
	else if (hangingWall_data[0] == 'M')sum += 2;
	else if (hangingWall_data[0] == 'S')sum += 2;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 3;
	else if (hangingWall_data[1] == 'C')sum += 3;
	else if (hangingWall_data[1] == 'W')sum += 2;
	else if (hangingWall_data[1] == 'D')sum += 2;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 4;
	else if (hangingWall_data[2] == 'M')sum += 3;
	else if (hangingWall_data[2] == 'S')sum += 2;

	return sum;
}
// 8-Cut and Fill
double cut_fill(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 0;
	else if (geometry_distribution[0] == 'T')sum += 4;
	else if (geometry_distribution[0] == 'I')sum += 2;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += 4;
	else if (geometry_distribution[1] == 'I')sum += 4;
	else if (geometry_distribution[1] == 'T')sum += 0;
	else if (geometry_distribution[1] == 'V')sum += 0;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 0;
	else if (geometry_distribution[2] == 'I')sum += 3;
	else if (geometry_distribution[2] == 'S')sum += 4;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 3;
	else if (geometry_distribution[3] == 'G')sum += 3;
	else if (geometry_distribution[3] == 'E')sum += 3;
	return sum;
}
//calculation cut and fill
double cutFill_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += cut_fill(geometry_distribution);

	sum += cut_fill_hanging_wall(hangingWall_data);

	sum += cut_fill_ore_zone(oreZone_data);

	sum += cut_fill_foot_wall(footWall_data);

	return sum;
}


//Shrinkage stoping
double shrinkage_stoping_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 4;
	else if (hangingWall_data[0] == 'M')sum += 2;
	else if (hangingWall_data[0] == 'S')sum += 1;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 4;
	else if (hangingWall_data[1] == 'C')sum += 4;
	else if (hangingWall_data[1] == 'W')sum += 3;
	else if (hangingWall_data[1] == 'D')sum += 0;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 4;
	else if (hangingWall_data[2] == 'M')sum += 2;
	else if (hangingWall_data[2] == 'S')sum += 0;

	return sum;
}

//Shrinkage stoping
double shrinkage_stoping_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 1;
	else if (oreZone_data[0] == 'M')sum += 3;
	else if (oreZone_data[0] == 'S')sum += 4;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 0;
	else if (oreZone_data[1] == 'C')sum += 1;
	else if (oreZone_data[1] == 'W')sum += 3;
	else if (oreZone_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 0;
	else if (oreZone_data[2] == 'M')sum += 2;
	else if (oreZone_data[2] == 'S')sum += 4;

	return sum;
}

//Shrinkage Stoping
double shrinkage_stoping_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 2;
	else if (footWall_data[0] == 'M')sum += 3;
	else if (footWall_data[0] == 'S')sum += 3;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 2;
	else if (footWall_data[1] == 'C')sum += 3;
	else if (footWall_data[1] == 'W')sum += 3;
	else if (footWall_data[1] == 'D')sum += 2;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 2;
	else if (footWall_data[2] == 'M')sum += 2;
	else if (footWall_data[2] == 'S')sum += 3;

	return sum;
}


// 7-Shrinkage Stoping
double shrinkage_stoping(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 2;
	else if (geometry_distribution[0] == 'T')sum += 2;
	else if (geometry_distribution[0] == 'I')sum += 1;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += 1;
	else if (geometry_distribution[1] == 'I')sum += 2;
	else if (geometry_distribution[1] == 'T')sum += 4;
	else if (geometry_distribution[1] == 'V')sum += 3;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 2;
	else if (geometry_distribution[2] == 'I')sum += 1;
	else if (geometry_distribution[2] == 'S')sum += 4;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 3;
	else if (geometry_distribution[3] == 'G')sum += 2;
	else if (geometry_distribution[3] == 'E')sum += 1;
	return sum;
}
//calculation for shrinkage stoping
double shrinkageStoping_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += shrinkage_stoping(geometry_distribution);

	sum += shrinkage_stoping_hanging_wall(hangingWall_data);

	sum += shrinkage_stoping_ore_zone(oreZone_data);

	sum += shrinkage_stoping_foot_wall(footWall_data);

	return sum;
}

//Room and Pillar
double room_pillar_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 0;
	else if (footWall_data[0] == 'M')sum += 2;
	else if (footWall_data[0] == 'S')sum += 4;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 0;
	else if (footWall_data[1] == 'C')sum += 1;
	else if (footWall_data[1] == 'W')sum += 3;
	else if (footWall_data[1] == 'D')sum += 3;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 0;
	else if (footWall_data[2] == 'M')sum += 3;
	else if (footWall_data[2] == 'S')sum += 3;

	return sum;
}
double room_pillar_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 0;
	else if (oreZone_data[0] == 'M')sum += 3;
	else if (oreZone_data[0] == 'S')sum += 4;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 0;
	else if (oreZone_data[1] == 'C')sum += 1;
	else if (oreZone_data[1] == 'W')sum += 2;
	else if (oreZone_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 0;
	else if (oreZone_data[2] == 'M')sum += 2;
	else if (oreZone_data[2] == 'S')sum += 4;

	return sum;
}

//Room and pillar
double room_pillar_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 0;
	else if (hangingWall_data[0] == 'M')sum += 3;
	else if (hangingWall_data[0] == 'S')sum += 4;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 0;
	else if (hangingWall_data[1] == 'C')sum += 1;
	else if (hangingWall_data[1] == 'W')sum += 2;
	else if (hangingWall_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 0;
	else if (hangingWall_data[2] == 'M')sum += 2;
	else if (hangingWall_data[2] == 'S')sum += 4;

	return sum;
}
// 6-Room And Pillar
double room_pillar(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 0;
	else if (geometry_distribution[0] == 'T')sum += 4;
	else if (geometry_distribution[0] == 'I')sum += 2;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += 4;
	else if (geometry_distribution[1] == 'I')sum += 2;
	else if (geometry_distribution[1] == 'T')sum += -49;
	else if (geometry_distribution[1] == 'V')sum += -49;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 4;
	else if (geometry_distribution[2] == 'I')sum += 1;
	else if (geometry_distribution[2] == 'S')sum += 0;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 3;
	else if (geometry_distribution[3] == 'G')sum += 3;
	else if (geometry_distribution[3] == 'E')sum += 3;
	return sum;
}

//calculation for room and pillar
double roomPillar_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += room_pillar(geometry_distribution);

	sum += room_pillar_hanging_wall(hangingWall_data);

	sum += room_pillar_ore_zone(oreZone_data);

	sum += room_pillar_foot_wall(footWall_data);

	return sum;
}

//longwall
double longwall_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 2;
	else if (footWall_data[0] == 'M')sum += 3;
	else if (footWall_data[0] == 'S')sum += 3;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 1;
	else if (footWall_data[1] == 'C')sum += 2;
	else if (footWall_data[1] == 'W')sum += 4;
	else if (footWall_data[1] == 'D')sum += 3;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 1;
	else if (footWall_data[2] == 'M')sum += 3;
	else if (footWall_data[2] == 'S')sum += 3;

	return sum;
}
//long wall
double longwall_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 4;
	else if (oreZone_data[0] == 'M')sum += 1;
	else if (oreZone_data[0] == 'S')sum += 0;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 4;
	else if (oreZone_data[1] == 'C')sum += 4;
	else if (oreZone_data[1] == 'W')sum += 0;
	else if (oreZone_data[1] == 'D')sum += 0;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 4;
	else if (oreZone_data[2] == 'M')sum += 3;
	else if (oreZone_data[2] == 'S')sum += 0;

	return sum;
}
double longwall_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 4;
	else if (hangingWall_data[0] == 'M')sum += 2;
	else if (hangingWall_data[0] == 'S')sum += 0;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 4;
	else if (hangingWall_data[1] == 'C')sum += 4;
	else if (hangingWall_data[1] == 'W')sum += 3;
	else if (hangingWall_data[1] == 'D')sum += 0;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 4;
	else if (hangingWall_data[2] == 'M')sum += 2;
	else if (hangingWall_data[2] == 'S')sum += 0;

	return sum;
}
double long_wall(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += -49;
	else if (geometry_distribution[0] == 'T')sum += 4;
	else if (geometry_distribution[0] == 'I')sum += -49;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += 4;
	else if (geometry_distribution[1] == 'I')sum += 0;
	else if (geometry_distribution[1] == 'T')sum += -49;
	else if (geometry_distribution[1] == 'V')sum += -49;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 4;
	else if (geometry_distribution[2] == 'I')sum += 0;
	else if (geometry_distribution[2] == 'S')sum += -49;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 4;
	else if (geometry_distribution[3] == 'G')sum += 2;
	else if (geometry_distribution[3] == 'E')sum += 0;
	return sum;
}
//calculation for block caving
// 3-Sublevel Stoping

// room and Pillar

double longwall_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += long_wall(geometry_distribution);

	sum += longwall_hanging_wall(hangingWall_data);

	sum += longwall_ore_zone(oreZone_data);

	sum += longwall_foot_wall(footWall_data);

	return sum;
}
double sublevel_stoping(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 2;
	else if (geometry_distribution[0] == 'T')sum += 2;
	else if (geometry_distribution[0] == 'I')sum += 1;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += 1;
	else if (geometry_distribution[1] == 'I')sum += 2;
	else if (geometry_distribution[1] == 'T')sum += 4;
	else if (geometry_distribution[1] == 'V')sum += 3;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 2;
	else if (geometry_distribution[2] == 'I')sum += 1;
	else if (geometry_distribution[2] == 'S')sum += 4;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 3;
	else if (geometry_distribution[3] == 'G')sum += 3;
	else if (geometry_distribution[3] == 'E')sum += 1;
	return sum;
}

//Sublevel Stoping
double sublevel_stoping_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += -49;
	else if (oreZone_data[0] == 'M')sum += 3;
	else if (oreZone_data[0] == 'S')sum += 4;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 0;
	else if (oreZone_data[1] == 'C')sum += 0;
	else if (oreZone_data[1] == 'W')sum += 1;
	else if (oreZone_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 0;
	else if (oreZone_data[2] == 'M')sum += 2;
	else if (oreZone_data[2] == 'S')sum += 4;

	return sum;
}

//sublevel stoping
double sublevel_stoping_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 0;
	else if (footWall_data[0] == 'M')sum += 2;
	else if (footWall_data[0] == 'S')sum += 4;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 0;
	else if (footWall_data[1] == 'C')sum += 0;
	else if (footWall_data[1] == 'W')sum += 2;
	else if (footWall_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 0;
	else if (footWall_data[2] == 'M')sum += 1;
	else if (footWall_data[2] == 'S')sum += 4;

	return sum;
}
double sublevel_stoping_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += -49;
	else if (hangingWall_data[0] == 'M')sum += 3;
	else if (hangingWall_data[0] == 'S')sum += 4;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += -49;
	else if (hangingWall_data[1] == 'C')sum += 0;
	else if (hangingWall_data[1] == 'W')sum += 1;
	else if (hangingWall_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 0;
	else if (hangingWall_data[2] == 'M')sum += 2;
	else if (hangingWall_data[2] == 'S')sum += 4;

	return sum;
}



// sublevel caving
double sublevel_caving_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 0;
	else if (oreZone_data[0] == 'M')sum += 3;
	else if (oreZone_data[0] == 'S')sum += 3;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 0;
	else if (oreZone_data[1] == 'C')sum += 2;
	else if (oreZone_data[1] == 'W')sum += 4;
	else if (oreZone_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 0;
	else if (oreZone_data[2] == 'M')sum += 2;
	else if (oreZone_data[2] == 'S')sum += 2;

	return sum;
}
double sublevel_caving_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 0;
	else if (footWall_data[0] == 'M')sum += 2;
	else if (footWall_data[0] == 'S')sum += 4;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 0;
	else if (footWall_data[1] == 'C')sum += 1;
	else if (footWall_data[1] == 'W')sum += 3;
	else if (footWall_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 0;
	else if (footWall_data[2] == 'M')sum += 2;
	else if (footWall_data[2] == 'S')sum += 4;

	return sum;
}
// 4-Sublevel Caving
double sublevel_caving(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 3;
	else if (geometry_distribution[0] == 'T')sum += 4;
	else if (geometry_distribution[0] == 'I')sum += 1;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += -49;
	else if (geometry_distribution[1] == 'I')sum += 0;
	else if (geometry_distribution[1] == 'T')sum += 4;
	else if (geometry_distribution[1] == 'V')sum += 4;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 1;
	else if (geometry_distribution[2] == 'I')sum += 1;
	else if (geometry_distribution[2] == 'S')sum += 4;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 4;
	else if (geometry_distribution[3] == 'G')sum += 2;
	else if (geometry_distribution[3] == 'E')sum += 0;
	return sum;
}
// sublevel caving
double sublevel_caving_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 3;
	else if (hangingWall_data[0] == 'M')sum += 2;
	else if (hangingWall_data[0] == 'S')sum += 1;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 3;
	else if (hangingWall_data[1] == 'C')sum += 4;
	else if (hangingWall_data[1] == 'W')sum += 3;
	else if (hangingWall_data[1] == 'D')sum += 1;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 4;
	else if (hangingWall_data[2] == 'M')sum += 2;
	else if (hangingWall_data[2] == 'S')sum += 0;

	return sum;
}


//calculation for sublevel caving
double sublevelCaving_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += sublevel_caving(geometry_distribution);

	sum += sublevel_caving_hanging_wall(hangingWall_data);

	sum += sublevel_caving_ore_zone(oreZone_data);

	sum += sublevel_caving_foot_wall(footWall_data);

	return sum;
}

double sublevelStoping_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += sublevel_stoping(geometry_distribution);

	sum += sublevel_stoping_hanging_wall(hangingWall_data);

	sum += sublevel_stoping_ore_zone(oreZone_data);

	sum += sublevel_stoping_foot_wall(footWall_data);

	return sum;
}
string ore_thickness(double thickness) {
	if (thickness < 10)return "Narrow";
	else if (thickness >= 10 && thickness < 30)return "intermediate";
	else if (thickness >= 30 && thickness < 100)return "Thick";
	else return "Very_thick";
}


double open_pit_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 3;
	else if (footWall_data[0] == 'M')sum += 4;
	else if (footWall_data[0] == 'S')sum += 4;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 2;
	else if (footWall_data[1] == 'C')sum += 3;
	else if (footWall_data[1] == 'W')sum += 4;
	else if (footWall_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 2;
	else if (footWall_data[2] == 'M')sum += 3;
	else if (footWall_data[2] == 'S')sum += 4;

	return sum;
}

double open_pit_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 3;
	else if (oreZone_data[0] == 'M')sum += 4;
	else if (oreZone_data[0] == 'S')sum += 4;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 2;
	else if (oreZone_data[1] == 'C')sum += 3;
	else if (oreZone_data[1] == 'W')sum += 4;
	else if (oreZone_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 2;
	else if (oreZone_data[2] == 'M')sum += 3;
	else if (oreZone_data[2] == 'S')sum += 4;

	return sum;
}

double open_pit_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 3;
	else if (hangingWall_data[0] == 'M')sum += 4;
	else if (hangingWall_data[0] == 'S')sum += 4;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 2;
	else if (hangingWall_data[1] == 'C')sum += 3;
	else if (hangingWall_data[1] == 'W')sum += 4;
	else if (hangingWall_data[1] == 'D')sum += 4;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 2;
	else if (hangingWall_data[2] == 'M')sum += 3;
	else if (hangingWall_data[2] == 'S')sum += 4;

	return sum;
}
double open_pit(vector<char> geometry_distribution) {
	//	double sum=0;
		// general Shape
		// massive tabular irregular
	//	cout<<1;
	double sum = 0;
	if (geometry_distribution[0] == 'M')sum += 3;
	else if (geometry_distribution[0] == 'T')sum += 2;
	else if (geometry_distribution[0] == 'I')sum += 3;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += 2;
	else if (geometry_distribution[1] == 'I')sum += 3;
	else if (geometry_distribution[1] == 'T')sum += 4;
	else if (geometry_distribution[1] == 'V')sum += 4;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 3;
	else if (geometry_distribution[2] == 'I')sum += 3;
	else if (geometry_distribution[2] == 'S')sum += 4;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 3;
	else if (geometry_distribution[3] == 'G')sum += 3;
	else if (geometry_distribution[3] == 'E')sum += 3;
	return sum;
}

double openPit_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += open_pit(geometry_distribution);

	sum += open_pit_hanging_wall(hangingWall_data);

	sum += open_pit_ore_zone(oreZone_data);

	sum += open_pit_foot_wall(footWall_data);

	return sum;
}
double block_caving(vector<char> geometry_distribution) {
	double sum = 0;
	// general Shape
	// massive tabular irregular
	if (geometry_distribution[0] == 'M')sum += 4;
	else if (geometry_distribution[0] == 'T')sum += 2;
	else if (geometry_distribution[0] == 'I')sum += 3;
	// ore thickness
	// narrow doubleermediate thick very thick
	if (geometry_distribution[1] == 'N')sum += -49;
	else if (geometry_distribution[1] == 'I')sum += 0;
	else if (geometry_distribution[1] == 'T')sum += 2;
	else if (geometry_distribution[1] == 'V')sum += 4;
	// Ore Plunge
	// flat doubleermediate steep
	if (geometry_distribution[2] == 'F')sum += 3;
	else if (geometry_distribution[2] == 'I')sum += 2;
	else if (geometry_distribution[2] == 'S')sum += 4;
	// grade distribution
	// uniform gradational erratic
	if (geometry_distribution[3] == 'U')sum += 4;
	else if (geometry_distribution[3] == 'G')sum += 2;
	else if (geometry_distribution[3] == 'E')sum += 0;
	return sum;
}

double block_caving_hanging_wall(vector<char>& hangingWall_data) {
	//rock substance strength
	double sum = 0;
	if (hangingWall_data[0] == 'W')sum += 4;
	else if (hangingWall_data[0] == 'M')sum += 2;
	else if (hangingWall_data[0] == 'S')sum += 1;

	//Fracture strength
	if (hangingWall_data[1] == 'V')sum += 3;
	else if (hangingWall_data[1] == 'C')sum += 4;
	else if (hangingWall_data[1] == 'W')sum += 3;
	else if (hangingWall_data[1] == 'D')sum += 0;
	//
	//Fracture Strength
	if (hangingWall_data[2] == 'W')sum += 4;
	else if (hangingWall_data[2] == 'M')sum += 2;
	else if (hangingWall_data[2] == 'S')sum += 0;

	return sum;
}
double block_caving_ore_zone(vector<char>& oreZone_data) {
	//rock substance strength
	double sum = 0;
	if (oreZone_data[0] == 'W')sum += 4;
	else if (oreZone_data[0] == 'M')sum += 1;
	else if (oreZone_data[0] == 'S')sum += 1;

	//Fracture strength
	if (oreZone_data[1] == 'V')sum += 4;
	else if (oreZone_data[1] == 'C')sum += 4;
	else if (oreZone_data[1] == 'W')sum += 3;
	else if (oreZone_data[1] == 'D')sum += 0;
	//
	//Fracture Strength
	if (oreZone_data[2] == 'W')sum += 4;
	else if (oreZone_data[2] == 'M')sum += 3;
	else if (oreZone_data[2] == 'S')sum += 0;

	return sum;
}
double block_caving_foot_wall(vector<char>& footWall_data) {
	//rock substance strength
	double sum = 0;
	if (footWall_data[0] == 'W')sum += 2;
	else if (footWall_data[0] == 'M')sum += 3;
	else if (footWall_data[0] == 'S')sum += 3;

	//Fracture strength
	if (footWall_data[1] == 'V')sum += 1;
	else if (footWall_data[1] == 'C')sum += 3;
	else if (footWall_data[1] == 'W')sum += 3;
	else if (footWall_data[1] == 'D')sum += 3;
	//
	//Fracture Strength
	if (footWall_data[2] == 'W')sum += 1;
	else if (footWall_data[2] == 'M')sum += 3;
	else if (footWall_data[2] == 'S')sum += 3;

	return sum;
}
double blockCaving_calc(vector<char> geometry_distribution, vector<char> hangingWall_data, vector<char> oreZone_data, vector<char> footWall_data) {

	double sum = 0;
	sum += block_caving(geometry_distribution);

	sum += block_caving_hanging_wall(hangingWall_data);

	sum += block_caving_ore_zone(oreZone_data);

	sum += block_caving_foot_wall(footWall_data);

	return sum;
}

string plunge(double angle) {
	if (angle < 20)return "Flat";
	else if (angle >= 20 && angle < 55)return "intermediate";
	else return "Steep";
}
int main()
{
    std::cout << "Hello World!\n";
	welcome();
	// geometry_distribution vector to store geometry of deposit
	vector<char> geometry_distribution(4);
	//	vector<char> rock_characterstics(3);
	vector<char> hangingWall_data(3);

	vector<char> oreZone_data(3);

	vector<char> footWall_data(3);

	// 1-General shape
	double gen_shape;
	cout << "Enter the general shape choose value between 1-3" << endl;
	cout << "1-equi-dimensional/massive" << endl;
	cout << "2-platey-tabular" << endl;
	cout << "3-irregular" << endl;
	cin >> gen_shape;
	if (gen_shape == 1) {
		//	    geometry_distribution.push_back('M');
		geometry_distribution[0] = 'M';
		cout << "Shape is :" << " " << "Massive" << endl;
	}
	else if (gen_shape == 2) {
		//	    geometry_distribution.push_back('T');
		geometry_distribution[0] = 'T';
		cout << "Shape is :" << " " << "Platey-Tabular" << endl;
	}
	else if (gen_shape == 3) {
		//	    geometry_distribution.push_back('I');
		geometry_distribution[0] = 'I';
		cout << "Shape is :" << " " << "Irregular" << endl;
	}
	// 2-Ore Thickness

	double thickness;
	cout << "Enter the Thickness : Enter the value in m" << endl;
	cin >> thickness;
	string thickness_str = ore_thickness(thickness);
	cout << "Thickness is:" << thickness_str << endl;
	if (thickness_str == "Narrow")geometry_distribution[1] = 'N';
	else if (thickness_str == "intermediate")geometry_distribution[1] = 'I';
	else if (thickness_str == "Thick")geometry_distribution[1] = 'T';
	else if (thickness_str == "Very_thick")geometry_distribution[1] = 'V';
	// 3-Plunge angle

	double angle;
	cout << "Enter Plunge angle between 0-360 degrees:" << endl;
	cin >> angle;
	string angle_str = plunge(angle);
	if (angle_str == "Flat") {
		//        geometry_distribution.push_back('F');
		geometry_distribution[2] = 'F';
		cout << "Plunge angle is:" << " " << "Flat" << endl;
	}
	else if (angle_str == "intermediate") {
		//        geometry_distribution.push_back('I');
		geometry_distribution[2] = 'I';
		cout << "Plunge angle is:" << " " << "intermediate" << endl;
	}
	else if (angle_str == "Steep") {
		//        geometry_distribution.push_back('S');
		geometry_distribution[2] = 'S';
		cout << "Plunge angle is:" << " " << "Steep" << endl;
	}
	// 4-Grade Distribution
	double grade;
	cout << "Enter grade distribution choose value between 1-3" << endl;
	cout << "1-Uniform" << endl;
	cout << "2-Gradational" << endl;
	cout << "3-Erratic" << endl;
	cin >> grade;
	if (grade == 1) {
		//	    geometry_distribution.push_back('U');
		geometry_distribution[3] = 'U';
		cout << "Grade distribution is:" << " " << "Uniform" << endl;
	}
	else if (grade == 2) {
		//	    geometry_distribution.push_back('G');
		geometry_distribution[3] = 'G';
		cout << "Grade distribution is:" << " " << "Gradational" << endl;
	}
	else if (grade == 3) {
		//	    geometry_distribution.push_back('E');
		geometry_distribution[3] = 'E';
		cout << "Grade distribution is:" << " " << "Erratic" << endl;
	}
	//	Rock Mechanics Characterstics
	//  1-Strength
	//	double strength;
	//	cout<<"Enter the rock substance strength :"<<endl;
	//	cin>>strength;
	//	string strength_str=rock_substance_strength(strength);
	//	if(strength_str=="Weak"){
	//		rock_characterstics[0]='W';
	//		cout<<strength_str<<endl;
	//	}
	//	else if(strength_str=="Moderate"){
	//		rock_characterstics[0]='M';
	//		cout<<strength_str<<endl;
	//	}
	//	else if(strength_str=="Strong"){
	//		rock_characterstics[0]='S';
	//		cout<<strength_str<<endl;
	//	}
	//	
	////	for(double i=0;i<geometry_distribution.size();i++){
	////        cout<<geometry_distribution[i]<<" ";
	////    }
	//    
	//    
	////    2-Fracture spacing
	////	  for very_wide D is used
	//    double spacing;
	//    cout<<"Enter the fracture spacing per meters"<<endl;
	//    cin>>spacing;
	//    string spacing_str=fracture_spacing(spacing);
	//    if(spacing_str=="Very_Close"){
	//		rock_characterstics[1]='V';
	//		cout<<spacing_str<<endl;
	//	}
	//	else if(spacing_str=="Close"){
	//		rock_characterstics[1]='C';
	//		cout<<spacing_str<<endl;
	//	}
	//	else if(spacing_str=="Wide"){
	//		rock_characterstics[1]='W';
	//		cout<<spacing_str<<endl;
	//	}
	//	else if(spacing_str=="Very_Wide"){
	//		rock_characterstics[1]='D';
	//		cout<<spacing_str<<endl;
	//	}
	//
	////	3-Fracture Shear Strength
	//
	//	double shear_strength;
	//	cout<<"Enter Fracture_shear_strength"<<endl;
	//	cout<<"1-Weak"<<endl;
	//	cout<<"2-Moderate"<<endl;
	//	cout<<"3-Strong"<<endl;
	//	cin>>shear_strength;
	//	if(shear_strength==1){
	//		rock_characterstics[2]='W';
	//		cout<<"Fracture shear strength is"<<" "<<"Weak"<<endl;
	//	}
	//	else if(shear_strength==2){
	//		rock_characterstics[2]='M';
	//		cout<<"Fracture shear strength is"<<" "<<"Moderate"<<endl;
	//	}
	//	else if(shear_strength==3){
	//		rock_characterstics[2]='S';
	//		cout<<"Fracture shear strength is"<<" "<<"Strong"<<endl;
	//	}

		//hangingwall rock substance strength


	//vector<char> hangingWall_data(3);
	//
	//	vector<char> oreZone_data(3);
	//
	//	vector<char> footWall_data(3);


	double hangingWallstrength;
	cout << "Enter the rock substance strength for hangingWall:" << endl;
	cout << "1-Weak" << endl;
	cout << "2-Moderate" << endl;
	cout << "3-Strong" << endl;
	cin >> hangingWallstrength;

	if (hangingWallstrength == 1) {
		hangingWall_data[0] = 'W';
		cout << "Hanging Wall rock substance Strength is - Weak" << endl;
	}
	else if (hangingWallstrength == 2) {
		hangingWall_data[0] = 'M';
		cout << "Hanging Wall rock substance Strength is - Moderate" << endl;
	}
	else if (hangingWallstrength == 3) {
		hangingWall_data[0] = 'S';
		cout << "Hanging Wall rock substance Strength is - Strong" << endl;
	}

	//hangingwall fracture spacing
	double hangingWall_fs;
	cout << "Enter the fracture spacing for hangingWall:" << endl;
	cout << "1-Very_Close" << endl;
	cout << "2-Close" << endl;
	cout << "3-Weak" << endl;
	cout << "3-Very_Weak" << endl;
	cin >> hangingWall_fs;

	if (hangingWall_fs == 1) {
		hangingWall_data[1] = 'V';
		cout << "Hanging Wall rock substance Strength is - Very Close" << endl;
	}
	else if (hangingWall_fs == 2) {
		hangingWall_data[1] = 'C';
		cout << "Hanging Wall rock substance Strength is - Close" << endl;
	}
	else if (hangingWall_fs == 3) {
		hangingWall_data[1] = 'W';
		cout << "Hanging Wall rock substance Strength is - Weak" << endl;
	}
	else if (hangingWall_fs == 4) {
		hangingWall_data[1] = 'D';
		cout << "Hanging Wall rock substance Strength is - Very Weak" << endl;
	}

	// hangingWall fracture strength

	double hangingWall_fstr;
	cout << "Enter the rock fracture strength for hangingWall:" << endl;
	cout << "1-Weak" << endl;
	cout << "2-Moderate" << endl;
	cout << "3-Strong" << endl;
	cin >> hangingWall_fstr;

	if (hangingWall_fstr == 1) {
		hangingWall_data[2] = 'W';
		cout << "Hanging Wall fracture strength Strength is - Weak" << endl;
	}
	else if (hangingWall_fstr == 2) {
		hangingWall_data[2] = 'M';
		cout << "Hanging Wall fracture strength Strength is - Moderate" << endl;
	}
	else if (hangingWall_fstr == 3) {
		hangingWall_data[2] = 'S';
		cout << "Hanging Wall fracture strength Strength is - Strong" << endl;
	}


	//	Ore Zone data


	double oreZonestrenth;
	cout << "Enter the rock substance strength for ore zone:" << endl;
	cout << "1-Weak" << endl;
	cout << "2-Moderate" << endl;
	cout << "3-Strong" << endl;
	cin >> oreZonestrenth;

	if (oreZonestrenth == 1) {
		oreZone_data[0] = 'W';
		cout << "Ore Zone rock substance Strength is - Weak" << endl;
	}
	else if (oreZonestrenth == 2) {
		oreZone_data[0] = 'M';
		cout << "Ore Zone  rock substance Strength is - Moderate" << endl;
	}
	else if (oreZonestrenth == 3) {
		oreZone_data[0] = 'S';
		cout << "Ore Zone  rock substance Strength is - Strong" << endl;
	}


	//oreZone fracture spacing


	double oreZone_fs;
	cout << "Enter the fracture spacing for OreZone:" << endl;
	cout << "1-Very_Close" << endl;
	cout << "2-Close" << endl;
	cout << "3-Weak" << endl;
	cout << "3-Very_Weak" << endl;
	cin >> oreZone_fs;

	if (oreZone_fs == 1) {
		oreZone_data[1] = 'V';
		cout << "Ore Zone  rock substance Strength is - Very Close" << endl;
	}
	else if (oreZone_fs == 2) {
		oreZone_data[1] = 'C';
		cout << "Ore Zone  rock substance Strength is - Close" << endl;
	}
	else if (oreZone_fs == 3) {
		oreZone_data[1] = 'W';
		cout << "Ore Zone  rock substance Strength is - Weak" << endl;
	}
	else if (oreZone_fs == 4) {
		oreZone_data[1] = 'D';
		cout << "Ore Zone  rock substance Strength is - Very Weak" << endl;
	}

	// oreZone fracture strength

	double oreZone_fstr;
	cout << "Enter the rock fracture strength for Ore Zone :" << endl;
	cout << "1-Weak" << endl;
	cout << "2-Moderate" << endl;
	cout << "3-Strong" << endl;
	cin >> oreZone_fstr;

	if (oreZone_fstr == 1) {
		oreZone_data[2] = 'W';
		cout << "Ore Zone  fracture strength Strength is - Weak" << endl;
	}
	else if (oreZone_fstr == 2) {
		oreZone_data[2] = 'M';
		cout << "Ore Zone  fracture strength Strength is - Moderate" << endl;
	}
	else if (oreZone_fstr == 3) {
		oreZone_data[2] = 'S';
		cout << "Ore Zone  fracture strength Strength is - Strong" << endl;
	}


	//FootWall Data

	double footWallstrenth;
	cout << "Enter the rock substance strength for Foot Wall:" << endl;
	cout << "1-Weak" << endl;
	cout << "2-Moderate" << endl;
	cout << "3-Strong" << endl;
	cin >> footWallstrenth;

	if (footWallstrenth == 1) {
		footWall_data[0] = 'W';
		cout << "Foot Wall rock substance Strength is - Weak" << endl;
	}
	else if (footWallstrenth == 2) {
		footWall_data[0] = 'M';
		cout << "Foot Wall  rock substance Strength is - Moderate" << endl;
	}
	else if (footWallstrenth == 3) {
		footWall_data[0] = 'S';
		cout << "Foot Wall rock substance Strength is - Strong" << endl;
	}

	//FootWall fracture spacing
	double footWall_fs;
	cout << "Enter the fracture spacing for Foot Wall:" << endl;
	cout << "1-Very_Close" << endl;
	cout << "2-Close" << endl;
	cout << "3-Weak" << endl;
	cout << "3-Very_Weak" << endl;
	cin >> footWall_fs;

	if (footWall_fs == 1) {
		footWall_data[1] = 'V';
		cout << "Foot Wall rock substance Strength is - Very Close" << endl;
	}
	else if (footWall_fs == 2) {
		footWall_data[1] = 'C';
		cout << "Foot Wall rock substance Strength is - Close" << endl;
	}
	else if (footWall_fs == 3) {
		footWall_data[1] = 'W';
		cout << "Foot Wall rock substance Strength is - Weak" << endl;
	}
	else if (footWall_fs == 4) {
		footWall_data[1] = 'D';
		cout << "Foot Wall rock substance Strength is - Very Weak" << endl;
	}

	// FootWall fracture strength

	double footWall_fstr;
	cout << "Enter the rock fracture strength for Foot Wall :" << endl;
	cout << "1-Weak" << endl;
	cout << "2-Moderate" << endl;
	cout << "3-Strong" << endl;
	cin >> footWall_fstr;

	if (footWall_fstr == 1) {
		footWall_data[2] = 'W';
		cout << "Foot Wall fracture strength Strength is - Weak" << endl;
	}
	else if (footWall_fstr == 2) {
		footWall_data[2] = 'M';
		cout << "Foot Wall fracture strength Strength is - Moderate" << endl;
	}
	else if (footWall_fstr == 3) {
		footWall_data[2] = 'S';
		cout << "Foot Wall fracture strength Strength is - Strong" << endl;
	}

	//	Check Methods
	for (double i = 0;i < geometry_distribution.size();i++) {
		cout << geometry_distribution[i] << " ";
	}
	cout << endl;
	//    for(double i=0;i<rock_characterstics.size();i++){
	//        cout<<rock_characterstics[i]<<" ";
	//    }
	//    double sum1=0;

	cout << endl;
	//	final calculation using priority_queue
	//  

	priority_queue< pair<double, string> >pq;
	double OPEN_PIT, BLOCK_CAVING, SUBLEVEL_STOPING, SUBLEVEL_CAVING, LONG_WALL, ROOM_PILLAR, SHRINKAGE_STOPING, CUT_FILL, TOP_SLICING, SQUARE_SET;
	OPEN_PIT = openPit_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	//	cout<<OPEN_PIT;
	BLOCK_CAVING = blockCaving_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<BLOCK_CAVING<<endl;
	SUBLEVEL_STOPING = sublevelStoping_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<SUBLEVEL_STOPING<<endl;
	SUBLEVEL_CAVING = sublevelCaving_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<SUBLEVEL_CAVING<<endl;
	LONG_WALL = longwall_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<LONG_WALL<<endl;
	ROOM_PILLAR = roomPillar_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<ROOM_PILLAR<<endl;
	SHRINKAGE_STOPING = shrinkageStoping_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<SHRINKAGE_STOPING<<endl;
	CUT_FILL = cutFill_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<CUT_FILL<<endl;
	TOP_SLICING = topSlicing_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<TOP_SLICING<<endl;
	SQUARE_SET = squareSet_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
	// cout<<SQUARE_SET<<endl;
// 	string Open_Pit,Block_Caving,Sublevel_Stoping,Sublevel_Caving,Long_Wall,Room_Pillar,Shrinkage_Stoping,Cut_Fill,Top_Slicing,Square_Cut;
	pq.push(make_pair(OPEN_PIT, "Open_Pit"));
	// 	cout<<pq.top().first<<pq.top().second<<endl;
	pq.push(make_pair(BLOCK_CAVING, "Block_Caving"));
	pq.push(make_pair(SUBLEVEL_STOPING, "Sublevel_Stoping"));
	pq.push(make_pair(SUBLEVEL_CAVING, "Sublevel_Caving"));
	pq.push(make_pair(LONG_WALL, "Long_Wall"));
	pq.push(make_pair(ROOM_PILLAR, "Room_Pillar"));
	pq.push(make_pair(SHRINKAGE_STOPING, "Shrinkage_Stoping"));
	pq.push(make_pair(CUT_FILL, "Cut_Fill"));
	pq.push(make_pair(TOP_SLICING, "Top_Slicing"));
	pq.push(make_pair(SQUARE_SET, "Square_Cut"));

	double count = 10;

	while (count--) {
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}

	cout << "OK!!!" << endl;













	//	double ans=0;
	//	open_pit(ans,geometry_distribution);
	//	cout<<ans;
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
