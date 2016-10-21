#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

enum Color { BLACK = 0, BROWN, GREEN, RED,  WHITE };
enum Material { PLASTIC, METAL, CERAMIC, WOOD };

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
        
        cout << "\nEnter your book width: " << flush;
        cin >> dimBook.width;
        
        cout << "\nEnter your book length: " << flush;
        cin >> dimBook.length;
        
        cout << "\nIs the book closed or opened? (press 1 for open, 0 for closed): " << flush;
        cin >> status;
        
        
        
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
    int getDimension() { return dimBook.length; dimBook.width; }
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
        cout << "\nWidth: " << tdimension.width << " Length: " << tdimension.length << " Area: " << getSurfaceArea() << " square inch" << endl;
    };
    
    void setSurfaceArea(int length, int width) { tdimension.length = length; tdimension.width = width; };
    int getSurfaceArea() { return tdimension.length * tdimension.width; }
};

// Class Lamp
class Lamp {
private:
    Color color;
    bool status;
    Dimension lampDim;
    string inputColor;
    
public:
    Color getColor() {
        return color;
    }
    void setColor(string c) {
        if (c == "black") {
            color = BLACK;
        }
        else if (c == "brown") {
            color = BROWN;
        }
        else if (c == "white") {
            color = WHITE;
        }
        else if (c == "green") {
            color = GREEN;
        }
        else {
            color = RED;
        }
    }
    
    void setSurfaceArea(int length, int width) { lampDim.length = length; lampDim.width = width; };
    int getSurfaceArea() { return lampDim.length * lampDim.width; }
    
    void input() {
        cin.ignore();
        cout << "\nWhich color do you like for lamp? (black, brown, white, green, red)" << flush;
        getline(cin,inputColor);
        setColor(inputColor);
        
        cout << "\nIs the lamp on or off? (press 1 for on, 0 for off): " << flush;
        cin >> status;
        
        cout << "\nEnter the width of lamp: " << flush;
        cin >> lampDim.width;
        
        cout << "\nEnter the length of lamp: " << flush;
        cin >> lampDim.length;
        
    }
    
    void output() {
        int colorList = getColor();
        cout << "Color: ";
        switch (colorList) {
            case 0: cout << "Black"; break;
            case 1: cout << "Brown"; break;
            case 2: cout << "Green"; break;
            case 3: cout << "Red"; break;
            case 4: cout << "White"; break;
        }
        
        
        if (status == 1)
        {
            cout << "\nStatus: ON";
        }
        else {
            cout << "\nStatus: OFF";
        }
        cout << "\nWidth: " << lampDim.width << " Length: " << lampDim.length << " Area: " << getSurfaceArea() << " square inch" << endl;
    };
    
};

class Table {
    
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
    Color getColor() {
        return color;
    }
    
    int getNumberOfLegs() {
        return numberOfLegs;
    }
    
    Material getMaterial() {
        return material;
    }
    
    int getLength() {
        return tableDim.length;
    }
    
    int getWidth() {
        return tableDim.width;
    }
    
    int getSurfaceArea() {
        return surfaceArea;
    }
    
    int getNumberOfBooks() {
        return books.size();
    }
    
    int getNumberOfTissueBoxes() {
        return tissueBoxes.size();
    }
    
    int getNumberOfLamps() {
        return lamps.size();
    }
    
    void setColor(string c) {
        if (c == "black") {
            color = BLACK;
        }
        else if (c == "brown") {
            color = BROWN;
        }
        else if (c == "white") {
            color = WHITE;
        }
        else if (c == "green") {
            color = GREEN;
        }
        else {
            color = RED;
        }
    }
    
    void setNumberOfLegs(int numLegs) {
        numberOfLegs = numLegs;
    }
    
    void setMaterial(string m) {
        if (m == "wood") {
            material = WOOD;
        }
        else if (m == "metal") {
            material = METAL;
        }
        else {
            material = CERAMIC;
        }
    }
    
    void setLength(int l) {
        tableDim.length = l;
    }
    
    void setWidth(int w) {
        tableDim.width = w;
    }
    
    void setSurfaceArea(int length, int width) {
        surfaceArea = length * width;
    }
    
    void addBook(Book book) {
        if (surfaceArea >= book.getSurfaceArea()) {
            books.push_back(book);
            surfaceArea -= book.getSurfaceArea();
            cout << endl << book.getTitle() << " has been added to your table." << endl;
            cout << "Area of book " << book.getTitle() << " : " << book.getSurfaceArea() << " square inch";
        }
        else {
            cout << endl << "I'm sorry. There is not enough room on the table for " << book.getTitle() << "." << endl;
        }
        cout << "\nCurrent Area on the table left: " << getSurfaceArea() << " square inch";
    }
    
    void removeBook() {
        if (!books.empty()) {
            int i = books.size();
            surfaceArea += books[i - 1].getSurfaceArea();
            cout << endl << books[i - 1].getTitle() << " has been removed from the table." << endl;
            books.pop_back();
        }
        else {
            cout << endl << "There are currently no books on the table." << endl;
        }
    }
    
    void addTissueBox(TissueBox tissueBox) {
        if (surfaceArea >= tissueBox.getSurfaceArea()) {
            tissueBoxes.push_back(tissueBox);
            surfaceArea -= tissueBox.getSurfaceArea();
            cout << endl << "The tissue box has been added to your table." << endl;
            cout << "Area of Tissue Box" << " : " << tissueBox.getSurfaceArea() << " square inch";
            cout << "\nCurrent Area on the table left: " << getSurfaceArea() << " square inch";
        }
        else {
            cout << endl << "I'm sorry. There is not enough room on the table for this tissue box." << endl;
        }
        cout << "\nCurrent Area on the table left: " << getSurfaceArea() << " square inch";
    }
    
    void removeTissueBox() {
        if (!tissueBoxes.empty()) {
            int i = tissueBoxes.size();
            surfaceArea += tissueBoxes[i - 1].getSurfaceArea();
            cout << endl << "The most recent tissue box placed has been removed from the table." << endl;
            tissueBoxes.pop_back();
        }
        else {
            cout << endl << "There are currently no tissue boxes on the table." << endl;
        }
    }
    
    void addLamp(Lamp lamp) {
        if (surfaceArea >= lamp.getSurfaceArea()) {
            lamps.push_back(lamp);
            surfaceArea -= lamp.getSurfaceArea();
            cout << endl << "The lamp has been added to your table." << endl;
            cout << "Area of the lamp" << " : " << lamp.getSurfaceArea() << " square inch";
            
        }
        else {
            cout << endl << "I'm sorry. There is not enough room on the table for this lamp." << endl;
            
        }
        cout << "\nCurrent Area on the table left: " << getSurfaceArea() << " square inch";
    }
    
    void removeLamp() {
        if (!lamps.empty()) {
            int i = lamps.size();
            surfaceArea += lamps[i - 1].getSurfaceArea();
            cout << endl << "The most recent lamp placed has been removed from the table." << endl;
            lamps.pop_back();
        }
        else {
            cout << endl << "There are currently no lamps on the table." << endl;
        }
    }
    
    float totalAreaAllItems() {
        float total = 0;
        int sizeBook = books.size();
        for (int i = 0; i < sizeBook; i++) {
            total += books[i].getSurfaceArea();
        }
        
        int sizeTissue = tissueBoxes.size();
        for (int i = 0; i < sizeTissue; i++) {
            total += tissueBoxes[i].getSurfaceArea();
        }
        
        int sizeLamp = lamps.size();
        for (int i = 0; i < sizeLamp; i++) {
            total += lamps[i].getSurfaceArea();
        }
        
        return total;
    }
    
    void printListItems() {
        cout << "\n----------- LIST OF ITEMS ON TABLE -----------\n";
        
        if (books.empty() && tissueBoxes.empty() && lamps.empty()) {
            cout << "\nThere are no items in list.";
        }
        else {
            int sizeBook = books.size();
            for (int i = 0; i < sizeBook; i++) {
                cout << "\nBook " << i + 1 << "\n"; books[i].output();
            }
            
            int sizeTissue = tissueBoxes.size();
            for (int i = 0; i < sizeTissue; i++) {
                cout << "\nTissue " << i + 1 << "\n"; tissueBoxes[i].output();
            }
            
            int sizeLamp = lamps.size();
            for (int i = 0; i < sizeLamp; i++) {
                cout << "\nLamp " << i + 1 << "\n"; lamps[i].output();
            }
        }
        
        cout << "\n--------------------------------------------\n";
    }
    
    
    void input() {
        string tableMaterial;
        string tableColor;
        int tableLength;
        int tableWidth;
        
        cout << "Please select the material you would like your table "
        << "to be made out of: (wood / metal / ceramic / plastic) ";
        getline(cin, tableMaterial);
        while (tableMaterial != "wood" && tableMaterial != "metal" && tableMaterial != "ceramic" && tableMaterial != "plastic") {
            cout << "Invalid response. Please respond with \"wood, \"plastic, \"  \"metal,\" or \"ceramic.\" ";
            getline(cin, tableMaterial);
        }
        
        setMaterial(tableMaterial);
        
        cout << "Please select the number of legs you would like "
        << "your table to have(1, 3, or 4): ";
        cin >> numberOfLegs;
        
        while (numberOfLegs != 1 && numberOfLegs != 3 && numberOfLegs != 4) {
            cout << "Invalid response. Please respond with \"1,\"  \"3,\" or \"4.\" ";
            cin >> numberOfLegs;
        }
        
        setNumberOfLegs(numberOfLegs);
        
        cout << "Please select the color of table you would like: "
        << "(black, brown, white, green, red) ";
        cin.ignore();
        getline(cin, tableColor);
        while (tableColor != "black" && tableColor != "brown" && tableColor != "white"
               && tableColor != "green" && tableColor != "red") {
            cout << "Invalid response. Please respond with \"black,\"  \"brown,\""
            << " \"white,\" \"green,\" or \"red.\" ";
            getline(cin, tableColor);
        }
        
        setColor(tableColor);
        
        cout << "How many inches long would you like your table to be? ";
        cin >> tableLength;
        setLength(tableLength);
        
        cout << "How many inches wide would you like your table to be? ";
        cin >> tableWidth;
        setWidth(tableWidth);
        
        setSurfaceArea(tableLength, tableWidth);
        cout << "The current surface area of the table available is "
        << surfaceArea << " square inches." << endl;
    }
    
    void output() {
        int colorList = getColor();
        int materialList = getMaterial();
        cout << "\n----------- SUMMARY -----------\n";
        cout << "Table has " << getNumberOfLegs() << " legs" << endl;
        cout << "Color: ";
        switch (colorList) {
            case 0: cout << "Black"; break;
            case 1: cout << "Brown"; break;
            case 2: cout << "Green"; break;
            case 3: cout << "Red"; break;
            case 4: cout << "White"; break;
        }
        //PLASTIC, METAL, CERAMIC, WOOD
        cout << "\nMaterial: ";
        switch (materialList) {
            case 0: cout << "Plastic"; break;
            case 1: cout << "Metal"; break;
            case 2: cout << "Creamic"; break;
            case 3: cout << "Wood"; break;
        }
        cout << "\nArea of the table: " << getSurfaceArea() << " square inch";
        printListItems();
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
                }
                else if (choice == 2) // tissue box
                {
                    TissueBox c;
                    c.input();
                    a.addTissueBox(c);
                }
                else if (choice == 3) // choice lamp
                {
                    Lamp d;
                    d.input();
                    a.addLamp(d);
                }
                
                
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