#include <iostream>
#include <string>
using namespace std;

enum Color { BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE };
enum Material {PLATIC, WOOD, STEEL };

struct Dimension {
	int length;
	int width;
};


class Book{
private:
	bool status;
	Dimension book;
	int numOfPages;
	string title;
	
public:

	// Setters
	void set_status(bool s){
		status = s;
	}
	void set_Dimension(int length, int width){
		length = book.length;
		width  = book.width;
	}	
	void set_numOfPages(int n){
		numOfPages = n;
	}
	void set_title(string s){
		title = s;
	} 

	// Getters
	bool get_status(){
		return status;
	}
	int get_surfaceArea(){
		return book.length * book.width;
	}
	int get_numOfPages(){
		return numOfPages;
	}
	string get_title(){
		return title;
	}
	
};

class TissueBox{

private:
	int numOfTissues;
	Dimension tissue;
	int max;
	

public:

	// Setters
	void set_numOfTissues(int n){
		numOfTissues = n;
	}
	void set_Dimension(int length, int width){
		tissue.length = length;
		tissue.width  = width;
	}
	void set_max(int m){
		max = m;
	}

	// Getters
	int get_numOfTissues(){
		return numOfTissues;
	}
	int get_surfaceArea(){
		return tissue.length * tissue.width;
	}
	float get_tissuePercentage{
		return ((float(numOfTissues))/max) * 100;
	}

};



class Lamp{

private:
	Color lColor;
	bool status;
	Dimension lamp;

public:

	// Setters
	void set_lColor(Color c){
		lColor = c;
	}
	void set_status(bool s){
		status = s;
	}
	void set_Dimension(int length, int width){
		lamp.length = length;
		lamp.width  = width;
	}

	// Getters
	Color get_lColor(){
		return lColor;
	}
	bool get_status(){
		return status;
	}
	int get_surfaceArea(){
		return lamp.length * lamp.width;
	}
	

};


class Table{
private:

public: 


};



	


