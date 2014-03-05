// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: class functions for a Site object
// Filename: Site.cpp
// Last modified on: 3/3/2014
#include "Site.h"
#include <string>
#include <cmath>
#include <sstream>
using namespace std;


Site::Site(int an_id, string a_name, string a_status, string a_remediationStatus, string a_contaminationType, long a_x, long a_y){
   
    //constructor
   id = an_id;
   name = a_name;
   status = a_status;
   remediationStatus = a_remediationStatus;
   contaminationType = a_contaminationType;
   x = a_x;
   y = a_y;
    
}

Site::Site(){
    //default constructor
}

//getters
int Site::getId() const{
    return id;
}
long Site::getX() const{
    return x;
}
long Site::getY() const{
    return y;
}
string Site::getStatus() const{
    return status;
}
string Site::getName() const{
    return name;
}


/**
 * hasSurroundingContamination
 */
bool Site::hasSurroundingContamination() const {
    
    
    //based on in-class discussion only clear and Pending receipt of waiver are considered clear sites; the rest is unknown or contaminated
    if (status == "Clear"|| status == "Pending receipt of waiver")
    {
        return false;
    }
    else{
        return true;
    }
    
}

/**
 * getDistance: returns the distance between the site object and the input x and y
 */
double Site::getDistance(long inputX, long inputY){
    double distance;
    distance = sqrt(pow((double) inputX-x,2)+pow((double)   inputY-y,2));
    return distance;
}

/**
 * toString: returns a readable display of the site for debugging purposes
 */
string Site::toString() const{
	stringstream ss;
	ss << id << "," << name << "," << status << "," << remediationStatus << "," << contaminationType << "," << x << "," << y;
	return ss.str();
}



