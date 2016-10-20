#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Color { BLACK = 0, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE };
enum Material { PLASTIC, WOOD, STEEL };

struct Dimension {
    int width;
    int length;
};

void showMenu() {
    cout << "\n----------- Menu -----------\n";
    cout << "\n1. Add Items";
    cout << "\n2. Remove Items";
    cout << "\n3. View List Items";
    cout << "\n4. Exit";
    cout << "\n----------------------------\n";
    
}

void showMenuAddStuff() {
    cout << "\n----------- Menu Of Things-----------\n";
    cout << "\n1. Add Book";
    cout << "\n2. Add Tissues";
    cout << "\n3. Add Lamp";
    cout << "\n4. Exit";
    cout << "\n-------------------------------------\n";
    
}

void showMenuRemoveStuff() {
    cout << "\n----------- Menu Of Things-----------\n";
    cout << "\n1. Remove Book";
    cout << "\n2. Remove Tissues";
    cout << "\n3. Remove Lamp";
    cout << "\n4. Exit";
    cout << "\n-------------------------------------\n";
    
}

// Class Book
class Book {
private:
    bool status;
    Dimension dimBook;
    int numOfPages;
    string Title;
    
public:
    void input() {
        cin.ignore();
        cout << "\nEnter The title of the book: " << flush;
        getline(cin, Title);
        
        cout << "\nHow many papers does the book have? " << flush;
        cin >> numOfPages;
        
        cout << "\nIs the book closed or opened? (press 1 for open, 0 for closed): " << flush;
        cin >> status;
        
        cout << "\nEnter your book width: " << flush;
        cin >> dimBook.width;
        
        cout << "\nEnter your book length: " << flush;
        cin >> dimBook.length;
        
    }
    void output() {
        cout << "\nThe title: " << Title;
        cout << "\nPapers: " << numOfPages;
        if (status == 1)
        {
            cout << "\nStatus: Opened";
        }
        else {
            cout << "\nStatus: Closed";
        }
        cout << "\nWidth: " << dimBook.width << " Length: " << dimBook.length << " Area: " << getSurfaceArea() << endl;
    };
    
    void setSurfaceArea(int length, int width) { dimBook.length = length; dimBook.width = width; };
    int getSurfaceArea()
    {
        //if the book is opened, surface area of the book multiply by 2, else surface area.
        if (status == 1) {
            return 2 * dimBook.length * dimBook.width;
        }
        else {
            return dimBook.length * dimBook.width;
        }
    }
    
    string getTitle() { return Title; }
    
};

// Class Tissue Box
class TissueBox {
private:
    int numOfTissues;
    Dimension tdimension;
    int max;
    int current;
    
public:
    void input() {
        cout << "\nHow many tissues are in the box right now?" << flush;
        cin >> current;
        
        cout << "\nThe total of number tissues that the box can contain:  " << flush;
        cin >> max;
        
        cout << "\nEnter the width of box: " << flush;
        cin >> tdimension.width;
        
        cout << "\nEnter the length of box: " << flush;
        cin >> tdimension.length;
        
    }
    void output() {
        cout << "\nThere are " << current << " tissues are in the box";
        cout << "\nWidth: " << tdimension.width << " Length: " << tdimension.length << " Area: " << getSurfaceArea() << endl;
    };
    
    void setSurfaceArea(int length, int width) { tdimension.length = length; tdimension.width = width; };
    int getSurfaceArea() { return tdimension.length * tdimension.width; }
};

// Class Lamp
class Lamp {
private:
    Color lcolor;
    bool status;
    Dimension lampDim;
    int inputColor;
    
public:
    void input() {
        cout << "\nWhich color do you like for lamp?" << flush;
        cin >> inputColor;
        
        cout << "\nIs the lamp on or off? (press 1 for on, 0 for off): " << flush;
        cin >> status;
        
        cout << "\nEnter the width of lamp: " << flush;
        cin >> lampDim.width;
        
        cout << "\nEnter the length of lamp: " << flush;
        cin >> lampDim.length;
        
    }
    
    void output() {
        
        
        
        if (status == 1)
        {
            cout << "\nStatus: ON";
        }
        else {
            cout << "\nStatus: OFF";
        }
        cout << "\nWidth: " << lampDim.width << " Length: " << lampDim.length << " Area: " << getSurfaceArea() << endl;
    };
    
    //BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE
    
    void setSurfaceArea(int length, int width) { lampDim.length = length; lampDim.width = width; };
    int getSurfaceArea() { return lampDim.length * lampDim.width; }
};

class Table {
private:
    Color r;
    int leg;
    int currsurfaceArea;
    int surfaceArea;
    Dimension tableDim;
    Material typeOfMaterial;
    vector<Book> ListBook;
    vector<TissueBox> ListTissue;
    vector<Lamp> ListLamp;
    
public:
    Table() {}; //Default Constructor
    ~Table() {}; //Default Destructor
    
    //Print List Items.
    void printListItems() {
        cout << "\n----------- LIST OF ITEMS -----------\n";
        
        if (ListBook.empty() && ListTissue.empty() && ListLamp.empty()){
            cout << "\nThere are no items in list.";
        }
        else {
            int sizeBook = ListBook.size();
            for (int i = 0; i < sizeBook; i++) {
                cout << "\nBook " << i + 1 << "\n"; ListBook[i].output();
            }
            
            int sizeTissue = ListTissue.size();
            for (int i = 0; i < sizeTissue; i++) {
                cout << "\nTissue " << i + 1 << "\n"; ListTissue[i].output();
            }
            
            int sizeLamp = ListLamp.size();
            for (int i = 0; i < sizeLamp; i++) {
                cout << "\nLamp " << i + 1 << "\n"; ListLamp[i].output();
            }
        }
        
        cout << "\n----------------------------\n";
    }
    
    // Finding total Area of all items.
    float totalAreaAllItems() {
        float total = 0;
        int sizeBook = ListBook.size();
        for (int i = 0; i < sizeBook; i++) {
            total += ListBook[i].getSurfaceArea();
        }
        
        int sizeTissue = ListTissue.size();
        for (int i = 0; i < sizeTissue; i++) {
            total += ListTissue[i].getSurfaceArea();
        }
        
        int sizeLamp = ListLamp.size();
        for (int i = 0; i < sizeLamp; i++) {
            total += ListLamp[i].getSurfaceArea();
        }
        
        return total;
    }
    
    //Surface Area Setter
    void setSurfaceArea(int length, int width) { surfaceArea = length * width; } // set the surface area of table
    
    int getSurfaceArea() { return surfaceArea; }
    
    //Adding Book
    void addBook(Book book) {
        if(surfaceArea >= book.getSurfaceArea()){
            ListBook.push_back(book);
            surfaceArea -= book.getSurfaceArea();
        }
        else {
            cout << endl << "I'm sorry. There is not enough room on the table" << "." << endl;
        }
        
    }
    
    //Adding Tissue
    void addTissue(TissueBox tissueBox) {
        if (surfaceArea >= tissueBox.getSurfaceArea()) {
            ListTissue.push_back(tissueBox);
            surfaceArea -= tissueBox.getSurfaceArea();
        }
        else {
            cout << endl << "I'm sorry. There is not enough room on the table" << "." << endl;
        }
        
    }
    
    //Adding Lamp
    void addLamp(Lamp lamp) {
        if (surfaceArea >= lamp.getSurfaceArea()) {
            ListLamp.push_back(lamp);
            surfaceArea -= lamp.getSurfaceArea();
        }
        else {
            cout << endl << "I'm sorry. There is not enough room on the table " << "." << endl;
        }
        
    }
    
    //Remove Book
    void removeBook() {
        if (!ListBook.empty()) {
            int i = ListBook.size();
            surfaceArea += ListBook[i - 1].getSurfaceArea();
            cout << endl << ListBook[i - 1].getTitle() << " has been removed from the table." << endl;
            ListBook.pop_back();
        }
        else {
            cout << endl << "There are currently no books on the table." << endl;
        }
    }
    
    //Remove Tissue
    void removeTissueBox() {
        if (!ListTissue.empty()) {
            int i = ListTissue.size();
            surfaceArea += ListTissue[i - 1].getSurfaceArea();
            cout << endl << "The most recent tissue box placed has been removed from the table." << endl;
            ListTissue.pop_back();
        }
        else {
            cout << endl << "There are currently no tissue boxes on the table." << endl;
        }
    }
    
    //Remove Lamp
    void removeLamp() {
        if (!ListLamp.empty()) {
            int i = ListLamp.size();
            surfaceArea += ListLamp[i - 1].getSurfaceArea();
            cout << endl << "The most recent lamp placed has been removed from the table." << endl;
            ListLamp.pop_back();
        }
        else {
            cout << endl << "There are currently no lamp on the table." << endl;
        }
    }
    
    //Function Input
    void input() {
        //cout << "what table color do you want?" << flush;
        
        cout << "\nHow many legs you want for a table? " << flush;
        cin >> leg;
        
        cout << "\nEnter your table width: " << flush;
        cin >> tableDim.width;
        
        cout << "\nEnter your table length: " << flush;
        cin >> tableDim.length;
        
        setSurfaceArea(tableDim.width, tableDim.length);
    }
    
    //Function Output
    void output() {
        cout << "\n----------- SUMMARY -----------\n";
        printListItems();
        cout << "\nArea of the table: " << getSurfaceArea() << " square inch";
        cout << "\nTotal Area of items on the table: " << totalAreaAllItems() << " square inch";
        cout << "\nWe still have around " << getSurfaceArea() - totalAreaAllItems() << " square inch" << endl;
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