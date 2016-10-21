#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Color {BLACK, BROWN, WHITE, GREEN, RED};

enum Material {WOOD, METAL, CERAMIC};

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
			surfaceArea = length*width;
		}
};

class TissueBox{

	private:
		int maxTissues;
		int currentTissues;
		Dimension tissueDim;
		int surfaceArea;

	public:
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

int main(){

	string response;
	cout << "Are you interested in buying a table today? (yes/no) ";
	cin >> response;
	
	while (response != "yes" && response != "no"){
		cout << "Invalid response. Please respond with \"yes\" or \"no.\" ";
		cin >> response;
	}

	if (response == "yes"){

		Table table;

		string tableMaterial;
		string tableColor;
		int numberOfLegs;
		int tableLength;
		int tableWidth;
		int tableSurfaceArea;

		cout << "Please select the material you would like your table "
			 << "to be made out of: (wood / metal / ceramic) ";
		cin >> tableMaterial;
		while (tableMaterial != "wood" && tableMaterial != "metal" && tableMaterial != "ceramic"){
			cout << "Invalid response. Please respond with \"wood,\"  \"metal,\" or \"ceramic.\" ";
			cin >> tableMaterial;
		}

		table.setMaterial(tableMaterial);

		cout << "Please select the number of legs you would like "
			 << "your table to have(1, 3, or 4): ";
		cin >> numberOfLegs;

		while (numberOfLegs != 1 && numberOfLegs != 3 && numberOfLegs != 4){
			cout << "Invalid response. Please respond with \"1,\"  \"3,\" or \"4.\" ";
			cin >> numberOfLegs;
		}

		table.setNumberOfLegs(numberOfLegs);

		cout << "Please select the color of table you would like: "
			 << "(black, brown, white, green, red) ";
		cin >> tableColor;
		while (tableColor != "black" && tableColor != "brown" && tableColor != "white"
			&& tableColor != "green" && tableColor != "red"){
			cout << "Invalid response. Please respond with \"black,\"  \"brown,\"" 
				 << " \"white,\" \"green,\" or \"red.\" ";
			cin >> tableColor;
		}

		table.setColor(tableColor);

		cout << "How many inches long would you like your table to be? ";
		cin >> tableLength;
		table.setLength(tableLength);

		cout << "How many inches wide would you like your table to be? ";
		cin >> tableWidth;
		table.setWidth(tableWidth);

		table.setSurfaceArea(tableLength, tableWidth);
		cout << "The current surface area of the table available is "
			<< table.getSurfaceArea() << " inches." << endl;

		//string addOrRemove;
		
		cout << "Would you like to add an object to the table to see if it fits? (yes/no) ";
		cin >> response;

		while (response != "yes" && response != "no"){
			cout << "Invalid response. Please respond with \"yes\" or \"no.\" ";
			cin >> response;
		}

		string addOrRemove = "add";

		while (response == "yes"){

			string object;
			string title;
			int numberOfPages;
			string status;
			int length;
			int width;
			int surfaceArea;

			if (addOrRemove == "add"){
				cout << "What kind of object would you like to add to your table? (book, tissue box, lamp) ";
				getline(cin, object);

				while (object != "book" && object != "tissue box" && object != "lamp"){
					cout << "Invalid response. Please respond with \"book,\" \"tissue box,\" or \"lamp.\" ";
					getline(cin,object);
				}

				if (object == "book"){

					Book book;

					cout << "What is the title of your book? ";
					getline(cin, title);
					book.setTitle(title);

					cout << "How many pages does " << title << " have? ";
					cin >> numberOfPages;
					book.setNumberOfPages(numberOfPages);

					cout << "Is the book opened or closed? ";
					cin >> status;
					book.setStatus(status);

					while (status != "opened" && status != "closed"){
						cout << "Invalid response. Please respond with \"opened\" or \"closed.\" ";
						cin >> status;
					}

					cout << "What is the length of your " << status << " book in inches? ";
					cin >> length;
					book.setLength(length);

					cout << "What is the width of your " << status << " book in inches? ";
					cin >> width;
					book.setWidth(width);

					book.setSurfaceArea(length, width);

					table.addBook(book);

					cout << "The current surface area of the table available is "
						<< table.getSurfaceArea() << " inches." << endl;
				}

				else if (object == "tissue box"){
					TissueBox tissueBox;

					cout << "What is the length of your tissue box in inches? ";
					cin >> length;
					tissueBox.setLength(length);

					cout << "What is the width of your tissue box in inches? ";
					cin >> width;
					tissueBox.setWidth(width);

					tissueBox.setSurfaceArea(length, width);

					table.addTissueBox(tissueBox);

					cout << "The current surface area of the table available is "
						<< table.getSurfaceArea() << " inches." << endl;
				}

				else{

					Lamp lamp;

					cout << "What is the length of the base of your lamp in inches? ";
					cin >> length;
					lamp.setLength(length);

					cout << "What is the width of the base of your lamp in inches? ";
					cin >> width;
					lamp.setWidth(width);

					lamp.setSurfaceArea(length, width);

					table.addLamp(lamp);

					cout << "The current surface area of the table available is "
						<< table.getSurfaceArea() << " inches." << endl;

				}

				cout << endl << "You currently have " << table.getNumberOfBooks() << " books, "
					<< table.getNumberOfTissueBoxes() << " tissue boxes, and "
					<< table.getNumberOfLamps() << " lamps on your table." << endl << endl;
			}

			else{
				cout << "You may remove the most recent object added of a certain type. "
					<< "Would you like to remove the most recently added book, tissue box, or lamp? ";
				getline(cin, object);

				while (object != "book" && object != "tissue box" && object != "lamp"){
					cout << "Invalid response. Please respond with \"book,\" \"tissue box,\" or \"lamp.\" ";
					getline(cin,object);
				}

				if (object == "book"){
					table.removeBook();
					cout << "The current surface area of the table available is "
						<< table.getSurfaceArea() << " inches." << endl;
				}

				else if (object == "tissue box"){
					table.removeTissueBox();
					cout << "The current surface area of the table available is "
						<< table.getSurfaceArea() << " inches." << endl;

				}

				else{
					table.removeLamp();
					cout << "The current surface area of the table available is "
						<< table.getSurfaceArea() << " inches." << endl;
				}

				cout << endl << "You currently have " << table.getNumberOfBooks() << " books, "
					<< table.getNumberOfTissueBoxes() << " tissue boxes, and "
					<< table.getNumberOfLamps() << " lamps on your table." << endl << endl;
			}

			cout << "Would you like to add or remove another object? (yes/no) ";
			cin >> response;

			while (response != "yes" && response != "no"){
				cout << "Invalid response. Please respond with \"yes\" or \"no.\" ";
				cin >> response;
			}

			if (response == "yes"){
				cout << "Would you like to add a new object or remove an existing one? (add/remove) ";
				cin >> addOrRemove;

				while (addOrRemove != "add" && addOrRemove != "remove"){
					cout << "Invalid response. Please respond with \"add\" or \"remove.\" ";
					cin >> addOrRemove;
				}
			}
		}
	

		cout << endl<< "You have chosen an excellent table! Come back again soon!" << endl<<endl;
	}

	else{
		cout << endl<< "Come back again soon!" << endl<<endl;
	}

	return 0;
}
