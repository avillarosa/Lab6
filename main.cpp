#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    ifstream inFile;
    string entireFile;
    inFile.open("text.txt");
    getline(inFile, entireFile);
    smatch m;

    regex IPAddress ("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");

    cout<< "The IP Addresses matched and found are: \n";

    while(regex_search(entireFile, m , IPAddress)){
          for (auto x:m){
            cout<<x<<endl;
          }
          entireFile = m.suffix().str();
          }

    return 0;
}
