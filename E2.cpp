#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// necessary structures
struct pixel{
	int R;
	int G;
	int B;
};
struct ppm{
	pixel ** pixGrid; // 2D matrix of pixels
	string magicNbr;
	int height;
	int width;
	int maxVal;
};

// the question require a structure typed return
ppm NewPict(string fileName){
	ppm pict;
	ifstream file(fileName);
	string line, word;
	istringstream sLine;
	// check the file opened correctly
	if( !file.is_open()){
		cout << "Unable to open file: " << fileName << endl;
		return;
	}
	// read magicNbr
	getline(file, pict.magicNbr);
	cout << "PPM identifier is " << pict.magicNbr << endl;
	// read size
	// TODO commend sentence
	getline(file, line);
	sLine(line);
	sLine >> pict.height >> pict.width;
	getline(file, line);
	cout << "Image size is " << pict.height << ", " << pict.width << endl;
	// read max value
	getline(file, line);
	sLine(line);
	sLine >> pict.maxVal;
	cout << "PPM max value is " << pict.macVal << endl;
	// mallocate pixels
	for (int i=0; i<pict.height; i++)
		pict.pixGrid[i] = new pixel[width];
	// read pixels
	int width = 0, height = 0;	
	while ( getline(file,line) ){
		sLine(line);
		sLine >> pict.pixGrad[hight][width].R \
		      >> pict.pixGrad[hight][width].G \
		      >> pict.pixGrad[hight][width].B;
		// update index
		width ++;
		if (width>=pict.width){
			width = 0;
			height ++;
		} 
	} 
	return pict;
}

void WritePict( ppm pict, string fileName){
	// write and check
	ifstream file(fileName);
	if (!file.is_open()){
		cout << "Unable to write to file " << fileName << endl;
		return;
	}
	// write magicNbr
	file << pict.magicNbr << endl;
	// write size
	file << pict.height << " " << pict.width << endl;
	// write max value
	file << pict.maxVal << endl;
	// save data
	for (int i=0; i<pict.hight; i++)
	for (int k=0; k<pict.width; k++){
		file << pict.pixGrand[i][k].R \
		     << pict.pixGrand[i][k].G \
		     << pict.pixGrand[i][k].B;
	}
	return;
}

ppm MirrorPict(ppm pict){
	// init a new pict named mirror
	ppm mirror;
	// first 3 lines should be the same
	mirror.magicNbr = pict.magicNbr;
	mirror.width = pict.width;
	mirror.height = pict.hright;
	mirror.maxVal = pict.maxVal;
	// horizental mirror: the symtric axis is vertical, or k' = width-k;
	for (int i=0; i<pict.hight; i++)
	for (int k=0; k<pict.width; k++){
		mirror.pixGrand[i][k].R = pict.pixGrand[i][pict.width-k].R; 
		mirror.pixGrand[i][k].G = pict.pixGrand[i][pict.width-k].G; 
		mirror.pixGrand[i][k].B = pict.pixGrand[i][pict.width-k].B; 
	}
	return mirror;
}

ppm EnlargePict(ppm pict){
	// init a new pict named twice
	ppm twice;
	// 1st, 3rd lines should be the same, 2nd line doubled
	twice.magicNbr = pict.magicNbr;
	twice.width = pict.width*2;
	twice.height = pict.hright*2;
	twice.maxVal = pict.maxVal;
	// twice: to make it easy to read, I add a vector array to should the shift
	int iShift = {0,0,1,1}, kShift = {0,1,0,1};
	for (int i=0; i<pict.hight; i++)
	for (int k=0; k<pict.width; k++)
	for (int m=0; m<4; m++){ /* R, G, B */
		twice.pixGrand[2*i+iShift[m]][2*k+kShift[m]].R = pict.pixGrand[i][k].R; 
		twice.pixGrand[2*i+iShift[m]][2*k+kShift[m]].G = pict.pixGrand[i][k].G; 
		twice.pixGrand[2*i+iShift[m]][2*k+kShift[m]].B = pict.pixGrand[i][k].B; 
	}
	return twice;
}

int main(){
	cout << " The program is to test the functions related to the ppm image format " << endl;
	// test NewPict()
	cout << "Test 1: Read a ppm file.." << endl;
	ppm pict;
	pict = NewPict("sample ppm images/blackbuck.ppm");
	cout << "Test 1 OK" << endl;
	
	// test NewPict()
	cout << "Test 2: Write a ppm file.." << endl;
	WritePict(pict, "sample ppm images/blackbuck_copy.ppm");
	cout << "Test 2 OK" << endl;
	// test MirrorPict()
	cout << "Test 3: Mirror a ppm file.." << endl;
	ppm mirror;
	mirror = MirrorPict(pict);
	WritePict(mirror, "sample ppm images/blackbuck_mirror.ppm");
	cout << "Test 3 OK" << endl;
	// test EnlargePict()
	cout << "Test 4: enlarge a ppm file.." << endl;
	ppm large;
	large = EnlargePict(pict);
	WritePict(large, "sample ppm images/blackbuck_large.ppm");
	cout << "Test 4 OK" << endl;

	cout << "Finish." << endl;

	return 0;
}

