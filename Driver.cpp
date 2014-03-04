// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Introduction to C++
// Description: Takes an input and tests if it is a perfect number
// Filename: isPerfect.cpp
// Last modified on: 2/14/2014


#include <iostream>
#include <fstream>
#include <cmath>
#include <cctype>
#include <string>
#include <stdlib.h> 
#include "Site.h"
#include "SiteList.h"
#include <iomanip>
using namespace std;

SiteList parseFile(string filename);

int main(){
	
	//declarations
	string filename;
	SiteList mySites;
	char decision = 'f';
    bool fileImportSucceeded;
    
    while(!fileImportSucceeded){
        fileImportSucceeded = mySites.parseFromFile(); //parse the file
	}
    
	//constantly ask user for input until 'x' is printed
	while(decision !='x'){
		
		//ask user for input
		cout<<"What would you like to do? Type 'h' for help."<<endl;
		//user-input for decision
		if (cin >> decision){
			//begin switch-case
			switch (decision){
			case 'a':
				//ADD: Adds a new site to the list
				mySites.addNew();
    				break;
			case 's':
				//STATUS: gets or predicts the status of a point
				cout<<"The status is: "<<mySites.getStatus()<<endl;
    				break;
			case 'o':
				//OUTPUT: writes a CSV
				mySites.writeCSV();
    				break;
			case 'h':
				//HELP: Shows a list of commands
				cout<<setw(10)<<"Command"<<setw(30)<<"Action"<<endl;
				cout<<setw(10)<<"a"<<setw(30)<<"Add a New Site"<<endl;
				cout<<setw(10)<<"s"<<setw(30)<<"Get/Predict the status"<<endl;
				cout<<setw(10)<<"o"<<setw(30)<<"Output List"<<endl;
				cout<<setw(10)<<"h"<<setw(30)<<"Help"<<endl;
				cout<<setw(10)<<"x"<<setw(30)<<"Exit this Program"<<endl;
    				break;
			case 'x':
				//EXIT
    				break;
			default:
				//a non-specified value was inputed
				cout<<"Invalid input."<<endl;
				decision ='x';//exit
				break;
			}//end case
		}
		else{
			//input was not a char
			cout<<"Invalid input."<<endl;
			decision ='x'; //exit
		}
		
		

	}//end while
	
	return 0;
}


