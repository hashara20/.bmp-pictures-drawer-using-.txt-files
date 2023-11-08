/**
 * pics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include<vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);
///////
void openFile1(ifstream& ins1 ,string file);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character, clears drawer and prints
 *            "Error in input file: " << [character already read]
 *            << [all chars remaining on the line] << endl;
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded <filename>]", where <filename> is replaced with
 *                                  the name of the file.
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cin, cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

void coolPics()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();

    return;
}

void writeFile(const Graphics& drawer)
{
    // TODO: implement
     string fileName;
     cin >> fileName;
     fileName += ".bmp";

     drawer.writeFile(fileName);
     cout << "[Wrote :" << fileName << "]" << endl;

    // This will make use of Graphics::writeFile()
}

void loadFile(Graphics& drawer)
{


    ifstream file1;
    string fileName=openFile(file1);

    char shape;
    vector<char>vec;

    string line;
    string error;

    string x;

    char rem;


    int i=0;
    for (string line; getline(file1, line); ){
            vec.push_back(line[0]);

    }





    for(int j=0;j<vec.size();j++) {

            ifstream file2;
            openFile1(file2,fileName);


            for(int a=0;a<j;a++){
            getline(file2,x);
            }


            Circle circle;
            Line line;
            Rectangle rectangle;
            Triangle triangle;


           shape=vec[j];
           file2>>rem;


                if(shape=='C'){
                    file2 >> circle;
                    circle.draw(drawer);
                    //file2>>rem[j];
                    }

                else if(shape=='L'){
                    file2 >> line;
                    line.draw(drawer);
                   // file2>>rem;
                    }

                else if(shape=='R'){
                    file2 >> rectangle;
                    rectangle.draw(drawer);
                    //file2>>rem[j];
                    }

                else if(shape=='T'){
                    file2 >> triangle;
                    triangle.draw(drawer);
                    //file2>>rem;

                    }

                else{
                    getline(file2, error);
                    //drawer.clear();
                    cout << "Error in input file: " << shape << error << endl;
                    }

                    file2.close();

        }

    cout << "[Loaded " << fileName << "]" << endl;

}

  string tolower(string str)
  {
    // TODO: implement
    for (int x = 0; x < str.length(); x++) {
        str[x] = tolower(str[x]);
    }

    return str;

  }


// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";

        ins.open(fileName);
    }

    return fileName;
}
////////////////////////////////////////////////////////////////

void openFile1(ifstream& ins1 ,string file)
{
    string fileName1;
    fileName1=file;

    // close stream if open
    if (ins1.is_open())
    {
        ins1.clear();
        ins1.close();
    }

    // get filename
    ins1.open(fileName1);

}
