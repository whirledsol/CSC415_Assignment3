// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: a header file for the SiteList obj
// Filename: SiteList.h
// Last modified on: 3/4/2014
#include <string>

class SiteList {
	public:
		
		
		SiteList(); //constructor
		bool addNew(); //adds a new site
		bool addNew(Site);//adds a new site with known Site
		std::string getStatus(long, long);//returns the status of a point, whether it is a site or not
		std::string getStatus();//returns the status of a user-defined point
		//void getArray(Site[] into,int size);//takes the array and puts it into "into" by reference
		int size();//gets the size of the array
		bool writeCSV(std::string);//writes a CSV output to a location
		bool writeCSV();//writes a CSV output to a user-defined location
        bool parseFromFile();//asks for user input and parses file into sites
        bool parseFromFile(std::string);//parses file into sites
    
	private:
		Site sites[600];//attr for the list of sites
		int arrayLength;
		
		int findSite(long, long);//finds the first site with the matching x and y
		int findSite(std::string); //finds the first site with the matching name
		std::string predict(long, long);//controls the status prediction of a point
		void getClosest(Site[], long, long);//returns the five closest sites
		void sortArray(Site[], long, long); //sorts the array based on distance
		void copyArray(const Site[], Site[]);//copies the contents of one array to another
};
		
