/* name: Jon Fisher
 Class: CptS 121, Spring 2019
 Date: April 3, 2019
 Programming Assignment: PA9                                                                 
 Description: This program computes images
*/
#include "header.h"

/*
 * Function: string getWords(string words)               	
 * Date Created: 4/3/19                 	        
 * Date Last Modified: 4/3/19                       
 * Description: gets a random word from the inputFile                	
 * Input parameters: string words    	
 * Returns: a string word         	
 * Pre: no word  	
 * Post: a word     
*/



void applyVerticalFlip(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	
	int i, j, k;
	for (i= Data.size()-1; i >= 0; i--) {
		for (j=Data[0].size()-1; j >= 0; j--) {
			for (k=0; k < 3; k++) {
				outputFile << Data.at(i).at(j).at(k) << " ";
				}
			}
			outputFile << endl;

	
	}
}

void applyHorizontalFlip(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	
	int i, j, k;
	for (i= 0; i < Data.size(); i++) {
		for (j=Data[0].size()-1; j >= 0; j--) {
			for (k=0; k < 3; k++) {
				outputFile << Data.at(i).at(j).at(k) << " ";
				}
			}
			outputFile << endl;
}
		
}

short computeNegativeValue(short value) {
	 

	 return abs(value - 255);

	 
}

short computeHighContrastValue(short value) {
		
		if (value > 127) {
			value = 255;
			return value;
			}
		else {
			value = 0;
			return value;
		}
	
	 }
short computeRandomNoiseValue(short value) {
	
	short n = 0;
	 n = rand() % 100 + (-50);
	 
	
	value = value + n;
	if (value > 255) {
		return 255;
	}

	if (value < 0) {
		return 0;
	}
	return value;
}

short computeGrayScaleValue(vector<short> gray) {
	
	int average = 0;
	
	average = (gray.at(0) + gray.at(1) + gray.at(2)) / 3;
	
	return average;
	
	
}

void applyGray(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	short i, j, k;
	short average;
	for (i = 0; i < Data.size(); i++) {
		for (j = 0; j < Data.at(i).size(); j++) {
			average = computeGrayScaleValue(Data.at(i).at(j));
			for (k=0; k < 3; k++) {
				outputFile << average << " ";
			}
		outputFile << endl;
		}
	outputFile << endl;
	}
}


void applyRed(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	short i, j, k;
	for (i = 0; i < Data.size(); i++) {
		for (j = 0; j < Data.at(i).size(); j++) {
			outputFile << "0" << " ";
			outputFile << Data.at(i).at(j).at(1) << " ";
			outputFile << Data.at(i).at(j).at(2) << " ";
			}
		outputFile << endl;
		}
	outputFile << endl;
	}

void applyGreen(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	short i, j, k;
	for (i = 0; i < Data.size(); i++) {
		for (j = 0; j < Data.at(i).size(); j++) {
		
			outputFile << Data.at(i).at(j).at(0) << " ";
			outputFile << "0" << " ";
			outputFile << Data.at(i).at(j).at(2) << " ";
			}
		outputFile << endl;
		}
	outputFile << endl;
	}
void applyBlue(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	short i, j, k;
	for (i = 0; i < Data.size(); i++) {
		for (j = 0; j < Data.at(i).size(); j++) {
		
			outputFile << Data.at(i).at(j).at(0) << " ";
			outputFile << Data.at(i).at(j).at(1) << " ";
			outputFile << "0" << " ";			
			}
		outputFile << endl;
		}
	outputFile << endl;
	}










	
void applyNoise(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	short i, j, k;
	for (i = 0; i < Data.size(); i++) {
		for (j = 0; j < Data.at(i).size(); j++) {
			for (k=0; k < 3; k++) {
				outputFile << computeRandomNoiseValue(Data.at(i).at(j).at(k));
				outputFile << " " ;
			}
		outputFile << endl;
		}
	outputFile << endl;
	}
}
	

void applyContrast(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	short i, j, k;
	for (i = 0; i < Data.size(); i++) {
		for (j = 0; j < Data.at(i).size(); j++) {
			for (k=0; k < 3; k++) {
				outputFile << computeHighContrastValue(Data.at(i).at(j).at(k));
				outputFile << " " ;
			}
		outputFile << endl;
		}
	outputFile << endl;
	}
}






	 
	 

void applyNegative(const vector<vector<vector<short>>>& Data, ofstream& outputFile) {
	short i, j, k;
	for (i = 0; i < Data.size(); i++) {
		for (j = 0; j < Data.at(i).size(); j++) {
			for (k=0; k < 3; k++) {
				outputFile << computeNegativeValue(Data.at(i).at(j).at(k));
				outputFile << " " ;
			}
		outputFile << endl;
		}
	outputFile << endl;
	}
}



void applyModification(const vector<vector<vector<short>>>& image, string filename, string transformation) {
	ofstream outputFile;
	
	
	if (transformation == "vertical") { 
		string ofilename = filename + "vertical.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyVerticalFlip(image, outputFile); // vertical flip function 	
}

	else if (transformation == "horizontal") {
		string ofilename = filename + "horizontal.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyHorizontalFlip(image, outputFile); // horizontal flip function 	

}
	else if (transformation == "negative") {
		string ofilename = filename + "negative.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyNegative(image, outputFile); //  makes image negative 		
	}
	else if (transformation == "contrast") {
		string ofilename = filename + "contrast.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyContrast(image, outputFile); //  adds contrast		

}

	else if (transformation == "noise") {
		string ofilename = filename + "noise.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyNoise(image, outputFile); //  adds random noise 		

}

	else if (transformation == "gray") {
		string ofilename = filename + "gray.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyGray(image, outputFile); //  adds Grayscale value  		

}
	
	

	else if (transformation == "red") {
		string ofilename = filename + "red.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyRed(image, outputFile); //  adds random noise 		

}

	else if (transformation == "green") {
		string ofilename = filename + "green.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyGreen(image, outputFile); //  adds random noise 		

}

	else if (transformation == "blue") {
		string ofilename = filename + "blue.ppm"; 
		openOutputFile(outputFile, ofilename);
		int columns = image[0].size();
		int rows = image.size();
		outputFile << "P3" << endl;
		outputFile << columns << " " << rows << endl;
		outputFile << "255" << endl;
		applyBlue(image, outputFile); //  adds random noise 		

}
	
}
/*
void displaySingleRow(const vector<vector<short>>& row) {
	int i, j;
	for (i = 0; i < row.size(); i++) {
		for (j = 0; j < row.at(i).size(); j++) {
			cout << row.at(i).at(j) << " ";
		}
		
	}
	cout << endl;
}
*/
void readBody(ifstream& inputFile, vector<vector<vector<short>>>& imageData, int rows, int cols) {
	// there are several ways to read the body of the file
	// into a 3D vector
	// we are going to read each value in the body 
	// into a short value
	// we will push_back the value into an RGB triple (vector)
	// once we have pushed 3 values into the RGB triple
	// we will push_back that RGB triple to a row of RGB triples
	// we want to clear out the RGB triple to prepare for
	// the next triple
	// once we have pushed cols number of RGB triples into 
	// a row, we want to push_back the row to imageData
	// and clear out the row to prepare for the next row
	short value;
	vector<short> rgbTriple;
	vector<vector<short>> rowOfTriples;
	
	while (!inputFile.eof()) {
		inputFile >> value;
		if (inputFile.good()) {
			//cout << "Read value: " << value << endl;
			rgbTriple.push_back(value);
			if (rgbTriple.size() == 3) {
				// just processed a pixel
				rowOfTriples.push_back(rgbTriple);
				rgbTriple.clear();
				if (rowOfTriples.size() == cols) {
					// just processed a row
					imageData.push_back(rowOfTriples);
					rowOfTriples.clear();
				}
			}
		}
	}
	

}

void readHeader(ifstream& inputFile, int& rows, int& cols) {
	string specification;
	int maxRGB;
	inputFile >> specification;
	inputFile >> cols >> rows;
	inputFile >> maxRGB;

}

void openInputFile(ifstream& inputFile, string fname) {
	inputFile.open(fname);
	
	if (inputFile.is_open()) {
		cout << "Successfully opened " << fname << " file" << endl;
	}
	else {
		cout << "Failed to open input file" << endl;
		exit(-1);
	}
}
 void openOutputFile(ofstream& outputFile, string fname) {
 	  outputFile.open(fname);
 	  
	
	if (outputFile.is_open()) {
		cout << "Successfully opened " << fname << " output file" << endl;
	}
	else {
		cout << "Failed to open output file" << endl;
		exit(-1);
	}
}
	

