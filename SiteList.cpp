// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: a seperate class to encapsulate an array of sites
// Filename: SiteList.cpp
// Last modified on: 2/24/2014
#include <string>
#include "Site.h"
#include "SiteList.h"
#include <iostream>
#include <fstream>
using namespace std;
/*
constructor
*/
SiteList::SiteList(){
 arrayLength = 0;
}


/*
adds a new site
*/
bool SiteList::addNew(){
	//declarations
	Site newSite;
	int id;
	string name;
	string status;
	string remediationStatus;
	string contaminationType;
        long x;
        long y;
	
	//ask the user for input
	cout<<"#######################\nADD A NEW SITE"<<endl;
	
	//assume id is the next in the series
	id = arrayLength;

	cout<<"Input Name"<<endl;
	getline(cin, name);
	cout<<"Input Status"<<endl;
	getline(cin, status);
	cout<<"Input Remediation Status"<<endl;
	getline(cin, remediationStatus);
	cout<<"Input Contamination Type"<<endl;
	getline(cin, contaminationType);
	cout<<"Input X coordinate"<<endl;
	if (!(cin >> x))
	{
		cout<<"Invalid input"<<endl;
		return false;
	}
	cout<<"Input Y coordinate"<<endl;
	if (!(cin >> y))
	{
		cout<<"Invalid input"<<endl;
		return false;
	}
	
	if(findSite(name) < 0){
		//the name doesn't exist, create site
		newSite = Site(id, name, status, remediationStatus, contaminationType, x, y);
		//add site to list
  		bool returning = addNew(newSite);
		return returning;
	}
	else{
		cout<<"The Site already exists."<<endl;
		return false;	
	}
	
	

  
}

/*
 * adds a new site with known Site obj
 */
bool SiteList::addNew(Site newSite){
  
  if(arrayLength<600){
    sites[arrayLength] = newSite;
    arrayLength++;
    return true;
  }
  else{
      return false;
  }
  
}
/*
 *returns the status of a point, whether it is a site or not
 */
string SiteList::getStatus(long x, long y){
  
  cout<<"NOT IMPLEMENTED YET"<<endl;
  return "";
  
}

/*
 *returns the status of a user-defined point
 */
string SiteList::getStatus(){
  long x, y;
  cout<<"Specify the X coordinate:"<<endl;
  if (!(cin >> x))
  {
	cout<<"Invalid Input"<<endl;
	return "";
  }
  
  cout<<"Specify the Y coordinate:"<<endl;
  if(!(cin>>y)){
	cout<<"Invalid Input"<<endl;
	return "";
  }

  string returning = getStatus(x,y);

  return returning;
  
}

/*
 * gets the size of the array
 */
int SiteList::size(){
    return arrayLength;
}

/**
* writes a CSV output to a location
*/
bool SiteList::writeCSV(string location){
	
	//create an output file stream
	ofstream fout;

	//open the output location	
	fout.open(location.c_str());
	if(fout.fail()){
		return false;
	}
	else{
		//we opened the file, now write
		for(int i=0;i<arrayLength;i++){
			fout<<sites[i].toString()<<'\r';
		}

		//then close the file
		fout.close();
	}
	
	return true;
}

/**
* writes a CSV output to a user-defined location
*/
bool SiteList::writeCSV(){

	//declaration
	string filename;
	cout<<"Where would you like to write the file?"<<endl;
	cin >> filename;
	//pass to other method
	bool returning = writeCSV(filename);
	
	return returning;
}
////////////////////////////////////////////////////////////////////
//      start PRIVATE METHODS
////////////////////////////////////////////////////////////////////

/*
 * finds the first index of a site in the list
 */
int SiteList::findSite(Site newSite){
  
  int index = -1; //set the index to the default value
  
  //go through array
  for(int i=0; i<arrayLength; i++){
    if(sites[i] == newSite){
	//we found a match so index==i
	index = i;
    }
  }
  
  return index;
  
}

/*
 * finds the first site with the matching x and y
 */
int SiteList::findSite(long x, long y){
   int index = -1; //set the index to the default value
  
  //go through array
  for(int i=0; i<arrayLength; i++){
    if((sites[i].getX() == x) && (sites[i].getY() == y)){
	//we found a match so index==i
	index = i;
    }
  }
  
  return index; 
}

/*
 * finds the first site with the matching name
 */
int SiteList::findSite(string name){
   int index = -1; //set the index to the default value
  
  //go through array
  for(int i=0; i<arrayLength; i++){
    if (sites[i].getName() == name){
	//we found a match so index==i
	index = i;
    }
  }
  
  return index; 
}

/*
 * controls the status prediction of a point
 */
string SiteList::predict(long x, long y){
  cout<<"NOT IMPLEMENTED YET"<<endl;
  return "";  
}

/*
 * returns the five closest sites
 */
int SiteList::getClosest(Site closest[], long x, long y){
  cout<<"NOT IMPLEMENTED YET"<<endl;
  return -1;  
}

/*
 * sorts the array based on distance 
 */
bool SiteList::sortArray(long x, long y){
  cout<<"NOT IMPLEMENTED YET"<<endl;
  return false;
  
}
