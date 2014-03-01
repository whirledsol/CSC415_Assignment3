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
using namespace std;

SiteList parseFile(string filename);

int main(){
	string filename;
	SiteList mySites;
	
	cout<<"What file would like to input?"<<endl;
	cin>>filename;
	mySites = parseFile(filename);
	
	
	return 0;
}

SiteList parseFile(string filename){

	ifstream fin;
	SiteList mySites;
	
	fin.open(filename.c_str());
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
			getline(fin,tempId_str,',');
			getline(fin,tempName,',');
			getline(fin,tempStatus,',');
			getline(fin,tempRemStatus,',');
			getline(fin,tempType,',');
			getline(fin,tempX_str,',');
			getline(fin,tempY_str,'\r');
			
			//casting
			tempId = atoi(tempId_str.c_str());
			tempX = atol(tempX_str.c_str());
			tempY = atol(tempY_str.c_str());
			
			//create a site
			tempSite = Site(tempId,tempName,tempStatus,tempRemStatus,tempType,tempX,tempY);
			//DEBUG
			cout<<"name:"<<tempSite.toString()<<endl;
			//add site to SiteList			
			mySites.addNew(tempSite);
			//DEBUG
			cout<<"LENGTH:"<<mySites.size()<<endl;
		}
	}
	
	return mySites;
}
