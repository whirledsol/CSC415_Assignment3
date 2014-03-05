// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: Utilizes SiteList.cpp and Site.cpp to make eucliean distance predictions
// Filename: Driver.cpp
// Last modified on: 3/4/2014


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

/**
*	throwError(string msg): a function that handles displaying an error message
*/
void throwError(string msg){
	cout<<msg<<endl;
	cin.ignore();
	cin.clear();

}
/**
*	START HERE!
*/
int main(){
	
	//declarations
	string filename;
	SiteList mySites;
	string decisionStr;
	char decision = 'd';//set decision input to default
	bool fileImportSucceeded = false;
    
	//import the file
    	while(!fileImportSucceeded){
        	fileImportSucceeded = mySites.parseFromFile(); //parse the file
		if(!fileImportSucceeded){
			throwError("File could not be parsed");
			exit(0);	
		}
	}
    
	//constantly ask user for input until 'x' is printed
	while(decision !='x'){
		
		//ask user for input
		cout<<"What would you like to do? Type 'h' for help."<<endl;
		//user-input for decision
		cin >> decisionStr;
		
		
		if (decisionStr.length() == 1){

			//to use switch-case, convert to char
			decision = decisionStr[0];

			//begin switch-case
			switch (decision){
			case 'a':
				//ADD: Adds a new site to the list
				if (!mySites.addNew())
				{
					throwError("Could not add the new site. Try again.");					
				}

    				break;
			case 's':
				//STATUS: gets or predicts the status of a point
				cout<<"#######################"<<endl;
				cout<<"The status is: "<<mySites.getStatus()<<endl;
				cout<<"#######################"<<endl;
    				break;
			case 'o':
				//OUTPUT: writes a CSV
				if (!mySites.writeCSV())
				{
					throwError("Could not write to the file specified. Try again.");		
				}
				else
				{
					cout<<"#######################"<<endl;
					cout<<"Written to file."<<endl;
					cout<<"#######################"<<endl;
				}
    				break;
			case 'h':
				//HELP: Shows a list of commands
				cout<<"#######################"<<endl;
				cout<<setw(10)<<"Command"<<setw(30)<<"Action"<<endl;
				cout<<setw(10)<<"a"<<setw(30)<<"Add a New Site"<<endl;
				cout<<setw(10)<<"s"<<setw(30)<<"Get/Predict the status"<<endl;
				cout<<setw(10)<<"o"<<setw(30)<<"Output List"<<endl;
				cout<<setw(10)<<"h"<<setw(30)<<"Help"<<endl;
				cout<<setw(10)<<"x"<<setw(30)<<"Exit this Program"<<endl;
				cout<<"#######################"<<endl;
    				break;
			case 'x':
				//EXIT
    				break;
			default:
				//a non-specified value was inputed
				throwError("Not a recognized command. Press 'h' for help.");		
				break;
			}//end case
		}
		else{
			//input was not a char
			throwError("Not a recognized command. Press 'h' for help.");	
		}
		
		

	}//end while
	
	return 0;
}


