#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>

//This is a program to search through and delete unwanted files in pupil areas

using namespace std;

int main()
{
    string text;
    cout << "                   Raspberry Destroy V2.0.0" << endl;
    cout << "       Version 2.0.0 Supports the following file formats" << endl;
    cout << "           exe | nds | mp3 | bat | iso | mkv | msi" << endl;
    cout << " " << endl;
    cout << "           WARNING do not run on any computer but zeus!!!" << endl;
    cout << " " << endl;
    cout << "               Do you want to start deleting? | Y:N" << endl;
    cout << ": ";
    cin >> text;
    cout << "Starting Raspberry Destroy!" << endl;
    cout << " " << endl;
    string line;
    ifstream wildfile ("wildcard_names.txt"); //Name of the file with wildcard files
    ifstream specific_file ("specific_files.txt"); //Name of file with specific filenames to delete
    if (wildfile.is_open())
    {
        while (wildfile.good())
        {
            getline (wildfile, line); //Get text from wildcard file and start deleting
            string path = "del /F /S /Q E:\\users\\*." + line; //Declare path variable
            //path = "del /F /S /Q C:\\Users\\Ian\\Desktop\\Files\\*." + line; //FOR TESTING
            cout << (path) <<endl;
            system (path.c_str());
        }
        wildfile.close(); //Close wildcard file
        (specific_file.is_open());
        {
            while (specific_file.good())
            {
                getline (specific_file, line); //Get text for specific files from txt documents
                string path2 = "del /F /S /Q E:\\users\\" + line; //Declare path variable
                //string path2 = "del /F /S /Q D:\\users\\" + line + """;
                cout << (path2) <<endl;
                system(path2.c_str());
            }
            specific_file.close(); //Close Specific file
        }
    }
    //else if
    else cout << "Sorry no file" << endl;
    cout << "Completed Succesfully" << endl;
    cout << "Exit App?" << endl;
    cout << ": ";
    cin >> text;
    return 0;
}