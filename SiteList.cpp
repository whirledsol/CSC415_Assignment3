// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: a seperate class to encapsulate an array of sites
// Filename: SiteList.cpp
// Last modified on: 3/4/2014
#include <string>
#include "Site.h"
#include "SiteList.h"
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <cmath>

using namespace std;


/**
	constructor
*/
SiteList::SiteList(){
	arrayLength = 0;
}

/**
	adds a new site but allows the user to input data
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
	cout<<"#######################\nADD A NEW SITE\n######################"<<endl;
	cout<<"Input Id"<<endl;
	if (!(cin >> id))
	{
		return false;
	}
	cin.ignore(); //needed to work with getline and cin
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
		return false;
	}
	cout<<"Input Y coordinate"<<endl;
	if (!(cin >> y))
	{
		return false;
	}

	/////////////////////////////////////////////////////
	//make sure there are no duplicates - CHECK FOR NAME
	/////////////////////////////////////////////////////
	if(findSite(name) < 0){
		//the name doesn't exist, create site
		newSite = Site(id, name, status, remediationStatus, contaminationType, x, y);
		//add site to list
  		bool returning = addNew(newSite);
		return returning;
	}
	else{
		//the name already exists
		return false;	
	}
}



/**
 * 	adds a new site with known Site obj
 */
bool SiteList::addNew(Site newSite){
  
  //make sure we don't go over the bounds of the array
  if(arrayLength<600){
    sites[arrayLength] = newSite;
    arrayLength++; //IMPORTANT
    return true;
  }
  else{
      return false;
  }
  
}


/**
 *	returns the status of a point, whether it is a site or not
 */
string SiteList::getStatus(long x, long y){
  
	//check to see if the x,y pair are already in the set (-1 means it is not found)
	int foundAt = findSite(x,y);

	if(foundAt >= 0){
		//the coordinates belong in the array at position foundAt
		return sites[foundAt].getStatus();
	}
	else{
		//WE MUST PREDICT! 
		string predictedStatus = predict(x,y);
		return predictedStatus;
	}
  return "";//WE SHOULD NOT GET HERE but it is required for certain g++ compilers
  
}


/**
 *	returns the status of a user-defined point
 */
string SiteList::getStatus(){

	//declarations
	  long x, y;

	//ask the user what coordinates
	  cout<<"Specify the X coordinate:"<<endl;
	  if (!(cin >> x))
	  {
		cin.clear();		
		return "Invalid Input";
	  }
	  
	  cout<<"Specify the Y coordinate:"<<endl;
	  if(!(cin >> y)){
		cin.clear();
		return "Invalid Input";
	  }

	//now we have x,y - call the other getStatus method
	  string returning = getStatus(x,y);

	  return returning;
  
}


/**
 * 	gets the size of the array
 */
int SiteList::size(){
    return arrayLength;
}


/**
* 	writes a CSV output to a location
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
        	//write first line
        	fout<<"Site Id,Site Name,Status,Remediation Status,Type of Contamination,X Coord,Y Coord\r";
		
		for(int i=0;i<arrayLength;i++){
			fout<<sites[i].toString()<<'\r';//formatted the same way it was imported
		}
		//then close the file
		fout.close();
	}
	
	return true;
}


/**
* 	writes a CSV output to a user-defined location
*/
bool SiteList::writeCSV(){

	//declaration
	string filename;

	//ask the user where they want the file
	cout<<"Where would you like to write the file?"<<endl;
	cin >> filename;

	//pass to other method
	bool returning = writeCSV(filename);
	
	return returning;
}


/**
 * 	asks for user input and parses file into sites
 */
bool SiteList::parseFromFile(){
    string filename;//declaration
    
    //ask user for file location
	cout<<"What file would like to input?"<<endl;
	cin>>filename;//get input

    //go to file designed for input only
    bool returning = parseFromFile(filename);
    return returning;
}

/**
 * parses file into sites
 */
bool SiteList::parseFromFile(string filename){
    
    //declarations
    ifstream fin;
    
    //open the file
    fin.open(filename.c_str());
    

    //check to see if the file can open
    if (fin.fail()){
        return false;
	}
	else{
		//we opened the file
		int lineInFile = 0;//keeps track of what line we're on
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
			
			//create a site, but only after the first line
			if(lineInFile > 0){
				tempSite = Site(tempId,tempName,tempStatus,tempRemStatus,tempType,tempX,tempY);
                
				//add site to SiteList
				addNew(tempSite);
			}
			lineInFile++; //going to the next line
		}
	}
    return true;
}




////////////////////////////////////////////////////////////////////
//      start PRIVATE METHODS
////////////////////////////////////////////////////////////////////


/*
 *	finds the first site with the matching x and y
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
 *	finds the first site with the matching name
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
 *	controls the status prediction of a point
 */
string SiteList::predict(long x, long y){
	Site closest[5];//create an empty array
	getClosest(closest,x,y);//pass to getClosest
	

        //WE HAVE THE SURROUNDING SITES
	//use inverse distance weighting (IDW) (see: https://www.ems-i.com/smshelp/Data_Module/Interpolation/Inverse_Distance_Weighted.htm)

    //declarations
    double average = 0;//the average: 0 = completely clear  -->  1 = completely contaminated
    double sumWeights = 0; //the sum of all the weights
    double p = 2.0; //the power - see IDW
    
    //for each in the closest array
    for (int i = 0; i<5;i++)
    {
        //only add data if the status is complete
        if(closest[i].getStatus() != "Incomplete"){
            double weight = 1/(pow(closest[i].getDistance(x,y),p)); //the weight ~ 1/distance
            sumWeights +=weight; //running sum, we devide later
            average += weight*closest[i].hasSurroundingContamination(); //remember: 0=clear, 1=contaminated
        }
    }
    average = average/sumWeights; //now we normalize
   
    //the average is the percentage of contamination. Convert that into a string.    
    if(average > 0 && average < 0.33){
        return "Not Contaminated"; //GREEN
    }
    else if (average >= 0.33 && average < 0.66){
        return "Possibly Contaminated"; //YELLOW
    }
    else{
        return "Contaminated"; //RED
    }
}


/**
 * returns the five closest sites
 */
void SiteList::getClosest(Site closest[], long x, long y){
    //create a copy of the sites array that will be sorted
    Site sortedSites[600];
    copyArray(sites,sortedSites);
    //sort that array based on distance from x,y
	sortArray(sortedSites, x, y);
    //get the top 5 and put into closest
	for(int i=0;i<5;i++){
		closest[i] = sortedSites[i];
	}
	
  return;  
}


/**
 * sorts the array based on distance 
 */
void SiteList::sortArray(Site incomingArray[], long x, long y){

	//insertion sort
	
	//go through array with i being the partition between sorted and unsorted
	for (int i=1; i<arrayLength;i++)
	{
		//new item to the sorted partition gets stored temporarily
		Site tempSite = incomingArray[i];
		double tempDis = incomingArray[i].getDistance(x,y);		
		
		int j;//must define outside for

		//find the j where the new item fits and shift everything over one until
		for(j = i-1; j>=0 && tempDis < incomingArray[j].getDistance(x,y);j--){
			incomingArray[j+1] = incomingArray[j];	//shift over
		}
		incomingArray[j+1] = tempSite;		//insert

	}  
}


/**
 * copies the contents of one array to another
 */
void SiteList::copyArray(const Site from[], Site to[]){
    for (int i=0;i<600; i++){
	//copy element by element
        to[i] = from[i];
    }
    
}





