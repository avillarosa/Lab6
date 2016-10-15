#include <iostream>
#includ <string>

using namespace std;

struct Dimension{
    int length;
    int width;
};

enum Color {};

enum Material {WOOD, STEEL, PLASTIC};

class Book {
    private:

        bool status;
        int numberOfPages;
        string title;
        Dimension dimen;

    public:

        Book(bool s, int p, string t, int l, int w){
            status = s;
            numberOfPages = p;
            title = t;
            bookDim.length = l;
            bookDim.width = w;
        }

        void setStatus(bool s){
            status = s;
        }

        void setNumberOfPages(int p){
            numberOfPages = p;
        }
        void setTitle(string t){
            title = t;
        }
        void setBookDim(int l, int w){
            dimen.length = l;
            dimen.width = w;
        }

        bool getStatus(){
            return status;
        }
        int getNumberOfPages(){
            return numberOfPAges;
        }
        string getTitle(){
            return title;
        }
        int getLength(){
            return dimen.length;
        }
        int getWidth(){
            return dimen.width;
        }
        int getSurfaceArea(){
            return dimen.length*dimen.width;
        }
};

class TissueBox{
    int maxTissues;
    int currentTissues;
};

class Lamp{
    Color color;
    bool on;
};

class Table{
};
