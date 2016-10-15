#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Colors {};
enum Materials {};

struct Dimensions {
	int length;
	int width;
};

class Table{

private:
	Colors col;
	int legs;
	Dimensions dim;
	Materials 
	

public:



};

class Book{
private:
	
public:




};

class TissueBox{

private:
	int numOfTissues;
	Dimensions dimen;
	int max;
	

public: 
	// Default Constructor
	TissueBox();

	// Setters
	void set_numOfTissues(int n){
		numOfTissues = n;
	}
	void set_Dimensions(int length, int width){
		dimen.length = length;
		dimen.width  = width;
	}
	void set_max(int m){
		max = m;
	}

	// Getters
	int get_numOfTissues(){
		return numOfTissues;
	}
	int get_SurfaceArea(){
		return dimen.length * dimen.width;
	}
	float get_tissuePercentage{
		return ((float(numOfTissues))/max) * 100;
	}

};



class Lamp{

private:

public:




};



	




