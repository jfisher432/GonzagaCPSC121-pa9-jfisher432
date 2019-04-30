/*
 Name: Jon Fisher
 Class: CptS 121, Spring 2019
 Date: April 3, 2019
 Programming Assignment: PA9                                                                 
 Description: This program computes images
 
*/

#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

void openInputFile(ifstream&, string);
void openOutputFile(ofstream&, string);
void readHeader(ifstream&, int&, int&);
void readBody(ifstream&, vector<vector<vector<short>>>&, int, int);
void displaySingleRow(const vector<vector<short>>&);
void applyVerticalFlip(const vector<vector<vector<short>>>&, ofstream&);
void applyModification(const vector<vector<vector<short>>>& , string, string);
void applyHorizontalFlip(const vector<vector<vector<short>>>&, ofstream&);
void applyNegative(const vector<vector<vector<short>>>&, ofstream&);
short computeNegativeValue(short);
short computeHighContrastValue(short);
void applyContrast(const vector<vector<vector<short>>>&, ofstream&);
short computeRandomNoiseValue(short);
void applyNoise(const vector<vector<vector<short>>>&, ofstream&);
short computeGrayScaleValue(vector<short>);
void applyGray(const vector<vector<vector<short>>>&, ofstream&);
short computeRemovalRed(short);
void applyRed(const vector<vector<vector<short>>>&, ofstream&);
void applyGreen(const vector<vector<vector<short>>>&, ofstream&);
void applyBlue(const vector<vector<vector<short>>>&, ofstream&);
#endif 
