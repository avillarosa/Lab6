#include <iostream>
#include <string>

struct Dimension{
    int length;
    int width;
};

class Book{
    private:
        bool status;
        int numberOfPages;
        string title;
        Dimension dimen;
        int surfaceArea;
};

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
