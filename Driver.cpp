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

	//ask user for file location
	cout<<"What file would like to input?"<<endl;
	cin>>filename;
	mySites = parseFile(filename); //parse the file
	
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
				//STATUS: gets or predicts the status of a site
				mySites.getStatus();
    				break;
			case 'o':
				//OUTPUT: writes a CSV
				mySites.writeCSV();
    				break;
			case 'h':
				//HELP: Shows a list of commands
				cout<<setw(10)<<"Command"<<setw(30)<<"Action"<<endl;
				cout<<setw(10)<<"a"<<setw(30)<<"Add a New Site"<<endl;
				cout<<setw(10)<<"s"<<setw(30)<<"Predict the status"<<endl;
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
				decision !='x';//exit
				break;
			}//end case
		}
		else{
			//input was not a char
			cout<<"Invalid input."<<endl;
			decision !='x'; //exit
		}
		
		

	}//end while
	
	return 0;
}

/**
* parseFile(string filename): assumes a csv file of sites with 7 elements each. Parses into SiteList object.
*/
SiteList parseFile(string filename){
	
	//declarations
	ifstream fin;
	SiteList mySites;
	
	//open the file
	fin.open(filename.c_str());

	//check to see if the file can open
	if (fin.fail()){
		cout<<"The file couldn't open. Try again..."<<endl;
		main();
	}
	else{
		//we opened the file
		
		//loop until the end of the file contents		
		while(!fin.eof()){
			//assumption: each line contains 7 fields in the same order
			
			//declarations	
			string tempId_str, tempName, tempStatus, tempRemStatus, tempType, tempX_str, tempY_str;
			int tempId;
			long  tempX,tempY;
			Site tempSite;
			
			//go through line
			getline(fin,tempId_str,','); //stop at ','
			getline(fin,tempName,','); //stop at ','
			getline(fin,tempStatus,','); //stop at ','
			getline(fin,tempRemStatus,','); //stop at ','
			getline(fin,tempType,','); //stop at ','
			getline(fin,tempX_str,','); //stop at ','
			getline(fin,tempY_str,'\r'); //stop at line-break '\r'
			
			//casting to appropriate datatypes
			tempId = atoi(tempId_str.c_str());
			tempX = atol(tempX_str.c_str());
			tempY = atol(tempY_str.c_str());
			
			//create a site
			tempSite = Site(tempId,tempName,tempStatus,tempRemStatus,tempType,tempX,tempY);
			//add site to SiteList			
			mySites.addNew(tempSite);
		}
	}
	
	return mySites;
}
