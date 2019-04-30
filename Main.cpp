#include "header.h"


int main() {
	ifstream inputFile;
	

	int rows, cols;
	int i;
	string filename = " ";
	vector<vector<vector<short>>> imageData; // initially empty
	
	string transforms[] = {"vertical", "horizontal", "remove", "negative", "contrast","noise","gray","red","green","blue"};
		srand(time(0));
	
	cout << "enter file name" << endl;
	cin >> filename;
	

	
	
	openInputFile(inputFile, filename);
	string nameonly = filename.substr(0, filename.length()-4);
	
	
	readHeader(inputFile, rows, cols);
	cout << "rows: " << rows << " cols: " << cols << endl;
	readBody(inputFile, imageData, rows, cols);
	cout << "rows check: " << imageData.size() << " cols check: " << imageData.at(0).size() << endl;
	// task: define and call a displaySingleRow() function that accepts a row of image data and displays the triples
	//displaySingleRow(imageData.at(rows - 1)); // display that last row
	
	for (i = 0; i <= 9; i++) {
	applyModification(imageData, nameonly, transforms[i]); // put in string what user enters eventually
	}
	
	return 0;
}









