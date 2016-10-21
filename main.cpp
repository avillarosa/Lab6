<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// List of available colors
enum Color {BLACK, BROWN, WHITE, GREEN, RED};

// List of available material
enum Material {WOOD, METAL, CERAMIC};

// Struct to get the dimensions of each object. Length and width
struct Dimension{
	int length;
	int width;
};

class Book{
	
	private: 
		bool status;
		int numberOfPages;
		string title;
		Dimension bookDim;
		int surfaceArea;

	public:
		// Getters
		bool getStatus(){
			return status;
		}

		int getNumberOfPages(){
			return numberOfPages;
		}

		string getTitle(){
			return title;
		}

		int getLength(){
			return bookDim.length;
		}

		int getWidth(){
			return bookDim.width;
		}

		int getSurfaceArea(){
			return surfaceArea;
		}

		// Setters
		void setStatus(string s){
			if (s == "open"){
				status = true;
			}
			else{
				status = false;
			}
		}

		void setNumberOfPages(int p){
			numberOfPages = p;
		}

		void setTitle(string t){
			title = t;
		}

		void setLength(int l){
			bookDim.length = l;
		}

		void setWidth(int w){
			bookDim.width = w;
		}

		void setSurfaceArea(int length, int width){
			surfaceArea = length * width;
		}
};

class TissueBox{

	private:
		int maxTissues;
		int currentTissues;
		Dimension tissueDim;
		int surfaceArea;

	public:
		// Getters
		int getMaxTissues(){
			return maxTissues;
		}

		int getCurrentTissues(){
			return currentTissues;
		}

		int getLength(){
			return tissueDim.length;
		}

		int getWidth(){
			return tissueDim.width;
		}

		int getSurfaceArea(){
			return surfaceArea;
		}

		// Setters
		void setMaxTissues(int maxT){
			maxTissues = maxT;
		}

		void setLength(int l){
			tissueDim.length = l;
		}

		void setWidth(int w){
			tissueDim.width = w;
		}

		void setSurfaceArea(int length, int width){
			surfaceArea = length * width;
		}
};

class Lamp{	

	private:
		Color color;
		bool status;
		Dimension lampDim;
		int surfaceArea;

	public:
		// Getters
		Color getColor(){
			return color;
		}

		bool getStatus(){
			return status;
		}

		int getLength(){
			return lampDim.length;
		}

		int getWidth(){
			return lampDim.width;
		}

		int getSurfaceArea(){
			return surfaceArea;
		}

		// Setters
		void setColor(Color c){
			color = c;
		}

		void setStatus(bool s){
			status = s;
		}

		void setLength(int l){
			lampDim.length = l;
		}

		void setWidth(int w){
			lampDim.width = w;
		}

		void setSurfaceArea(int length, int width){
			surfaceArea = length * width;
		}
};

class Table{

	private: 
		Color color;
		int numberOfLegs;
		Material material;
		Dimension tableDim;
		int surfaceArea;
		vector < Book > books;
		vector <TissueBox> tissueBoxes;
		vector <Lamp> lamps;


	public: 
		// Getters
		Color getColor(){
			return color;
		}

		int getNumberOfLegs(){
			return numberOfLegs;
		}

		Material getMaterial(){
			return material;
		}

		int getLength(){
			return tableDim.length;
		}

		int getWidth(){
			return tableDim.width;
		}

		// Setters
		int getSurfaceArea(){
			return surfaceArea;
		}

		int getNumberOfBooks(){
			return books.size();
		}

		int getNumberOfTissueBoxes(){
			return tissueBoxes.size();
		}

		int getNumberOfLamps(){
			return lamps.size();
		}

		vector<Book> getBooks(){
			return books;
		}

		void setColor(string c){
			if (c == "black"){
				color = BLACK;
			}
			else if (c == "brown"){
				color = BROWN;
			}
			else if (c == "white"){
				color = WHITE;
			}
			else if (c == "green"){
				color = GREEN;
			}
			else{
				color = RED;
			}
		}

		void setNumberOfLegs(int numLegs){
			numberOfLegs = numLegs;
		}

		void setMaterial(string m){
			if (m == "wood"){
				material = WOOD;
			}
			else if (m == "metal"){
				material = METAL;
			}
			else{
				material = CERAMIC;
			}
		}

		void setLength(int l){
			tableDim.length = l;
		}

		void setWidth(int w){
			tableDim.width = w;
		}

		void setSurfaceArea(int length, int width){
			surfaceArea = length * width;
		}

		void addBook(Book book){
			if (surfaceArea >= book.getSurfaceArea()){
				books.push_back(book);
				surfaceArea -= book.getSurfaceArea();
				cout << endl << book.getTitle() << " has been added to your table." << endl;
			}
			else{
				cout << endl<<"I'm sorry. There is not enough room on the table for " <<book.getTitle()<< "." <<endl;
			}
		}

		void removeBook(){
			if (!books.empty()){
				int i = books.size();
				surfaceArea += books[i-1].getSurfaceArea();
				cout << endl<< books[i - 1].getTitle() << " has been removed from the table." << endl;
				books.pop_back();
			}
			else{
				cout << endl<<"There are currently no books on the table." << endl;
			}
		}

		void addTissueBox(TissueBox tissueBox){
			if (surfaceArea >= tissueBox.getSurfaceArea()){
				tissueBoxes.push_back(tissueBox);
				surfaceArea -= tissueBox.getSurfaceArea();
				cout << endl << "The tissue box has been added to your table." << endl;
			}
			else{
				cout << endl<<"I'm sorry. There is not enough room on the table for this tissue box." << endl;
			}
		}

		void removeTissueBox(){
			if (!tissueBoxes.empty()){
				int i = tissueBoxes.size();
				surfaceArea += tissueBoxes[i - 1].getSurfaceArea();
				cout << endl<<"The most recent tissue box placed has been removed from the table." << endl;
				tissueBoxes.pop_back();
			}
			else{
				cout << endl<<"There are currently no tissue boxes on the table." << endl;
			}
		}

		void addLamp(Lamp lamp){
			if (surfaceArea >= lamp.getSurfaceArea()){
				lamps.push_back(lamp);
				surfaceArea -= lamp.getSurfaceArea();
				cout << endl << "The lamp has been added to your table." << endl;
			}
			else{
				cout << endl<<"I'm sorry. There is not enough room on the table for this lamp." << endl;
			}
		}

		void removeLamp(){
			if (!lamps.empty()){
				int i = lamps.size();
				surfaceArea += lamps[i - 1].getSurfaceArea();
				cout << endl<<"The most recent lamp placed has been removed from the table." << endl;
				lamps.pop_back();
			}
			else{
				cout << endl<<"There are currently no lamps on the table." << endl;
			}
		}

};

int main()
{
    int mainChoice, choice;
    Table a;
    
    a.input();
    do {
        showMenu();
        do {
            cout << "\nEnter your choice: ";
            cin >> mainChoice;
            
            if (mainChoice < 1 || mainChoice > 4)
            {
                cout << "\nInvalid Choice. Please try again !";
            }
        } while (mainChoice < 1 || mainChoice > 4);
        
        //choice to add items
        if (mainChoice == 1) {
            do {
                showMenuAddStuff();
                do {
                    cout << "\nEnter your choice: ";
                    cin >> choice;
                    
                    if (choice < 1 || choice > 4)
                    {
                        cout << "\nInvalid Choice. Please try again !";
                    }
                } while (choice < 1 || choice > 4);
                
                if (choice == 1) // Book
                {
                    Book b;
                    b.input();
                    a.addBook(b);
                    cout << "\nArea of book " << b.getTitle() << " : " << b.getSurfaceArea() << " square inch";
                }
                else if (choice == 2) // tissue box
                {
                    TissueBox c;
                    c.input();
                    a.addTissue(c);
                    cout << "\nArea of Tissue Box " << " : " << c.getSurfaceArea() << " square inch";
                }
                else if (choice == 3) // choice lamp
                {
                    Lamp d;
                    d.input();
                    a.addLamp(d);
                    cout << "\nArea of the lamp " << " : " << d.getSurfaceArea() << " square inch";
                }
                
                cout << "\nCurrent Area of Table After Adding the item: " << a.getSurfaceArea() << " square inch";
                
            } while (choice != 4);
        }
        
        //choice to remove items
        else if (mainChoice == 2) {
            do {
                showMenuRemoveStuff();
                do {
                    cout << "\nEnter your choice: ";
                    cin >> choice;
                    
                    if (choice < 1 || choice > 4)
                    {
                        cout << "\nInvalid Choice. Please try again !";
                    }
                } while (choice < 1 || choice > 4);
                
                switch (choice) {
                    case 1: a.removeBook(); break;
                    case 2: a.removeTissueBox(); break;
                    case 3: a.removeLamp(); break;
                }
                
            } while (choice != 4);
        }
        
        //choice to print item list
        else if (mainChoice == 3) {
            a.printListItems();
        }
        
    } while (mainChoice != 4);
    
    a.output();
    
    system("pause");
	return 0;
}


