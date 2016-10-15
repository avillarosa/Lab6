nclude <vector>
#include <string>
using namespace std;

enum Color { BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE };
enum Material { PLASTIC, WOOD, STEEL };

struct Dimension {
	int width;
	int length;
};

class Table {
private:
	Color r;
	int leg;
	Dimension dimen;
	Material typeOfMaterial;
	vector<Book> ListOfBook;
	vector<TissueBox> ListOfTissueBoxes;
	vector<Lamp> ListOfLamp;
public:
	void input() {
		cout << "what table color do you want?" << flush;
		
		cout << "Enter your width: " << flush;
		cin >> dimen.width;

		cout << "Enter your length: " << flush;
		cin >> dimen.length;

	}
	void output() {

	}

	void setSurface(int length, int width) { dimen.length = length; dimen.width = width; }
	int getSurfaceArea() { return dimen.length * dimen.width; }

};


// Class Book
class Book {
private:
	bool status;
	Dimension book;
	int numOfPages;
	string Title;

public:
	void input1() {
		cout << "The title of the book: " << flush;
		getline(cin, Title);

		cout << "How many papers does the book have?" << flush;
		cin >> numOfPages;

		cout << "Is the book closed or opened? (press 1 for open, 0 for closed): " << flush;
		cin >> status;

		cout << "Enter your width: " << flush;
		cin >> book.width;

		cout << "Enter your length: " << flush;
		cin >> book.length;

	}

	void output1() {
	
	}

	void setSurfaceArea(int length, int width) { book.length = length; book.width = width; };
	int getSurfaceArea() { return book.length * book.width; }
};

// Class Tissue Box
class TissueBox{
private:
	int numOfTissues;
	Dimension tissue;
	int max;
	int current;

public:
	void input2() {
		cout << "How many tissues are in the box right now?" << flush;
		cin >> current;

		cout << "The total of number tissuses that the box can contain:  " << flush;
		cin >> max;

		cout << "Enter the width of box: " << flush;
		cin >> tissue.width;

		cout << "Enter the length of box: " << flush;
		cin >> tissue.length;

	}
	void ouput2();
	void setSurfaceArea(int length, int width) { tissue.length = length; tissue.width = width; };
	int getSurfaceArea() { return tissue.length * tissue.width;  }
};


// Class Lamp
class Lamp {
private:
	Color lcolor;
	bool status;
	Dimension lamp;
	
public:
	void input() {
		
		
	}

	void output();

	void setSurfaceArea(int length, int width) { lamp.length = length; lamp.width = width; };
	int getSurfaceArea() { return lamp.length * lamp.width; }
};


