// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: a seperate class to encapsulate an array of sites
// Filename: SiteList.cpp
// Last modified on: 2/24/2014
#include <string>

class SiteList {
	public:
		
		
		SiteList(); //constructor
		bool addNew(); //adds a new site
		bool addNew(Site newSite);//adds a new site with known Site
		std::string getStatus(long x, long y);//returns the status of a point, whether it is a site or not
		//void getArray(Site[] into,int size);//takes the array and puts it into "into" by reference
		int size();//gets the size of the array
		
		
	private:
		Site sites[600];//attr for the list of sites
		int arrayLength;
		
		int findSite(Site newSite);//finds the first index of a site in the list
		int findSite(long x, long y);//finds the first site with the matching x and y
		std::string predict(long x, long y);//controls the status prediction of a point
		int getClosest(Site closest[], long x, long y);//returns the five closest sites
		bool sortArray(long x, long y); //sorts the array based on distance
		
};
		