// Name: Will Rhodes
// Course: CSC 415
// Semester: Spring 2014
// Instructor: Dr. Pulimood
// Exercise : Assignment 3
// Description: class functions for a Site object
// Filename: Site.cpp
// Last modified on: 2/24/2014
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
string Site::getRemediationStatus() const{
	return remediationStatus;
}
string Site::getContaminationType() const{
	return contaminationType;
}
string Site::getName() const{
    return name;
}


/**
 * getDistance: returns the distance between the site object and the input x and y
 */
double Site::getDistance(long inputX, long inputY){
    double distance;
    distance = sqrt(pow(inputX-x,2)+pow(inputY-y,2));
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

/**
 * overloads the equality opperator
 */
 bool Site::operator== (Site &other) const{
 
  //two sites are equal if their ids are equal
  bool condition = id == other.getId();
  condition = condition && name == other.getName();
  condition = condition && x == other.getX();
  condition = condition && y == other.getY();
  condition = condition && x == other.getX();
  condition = condition && remediationStatus == other.getRemediationStatus();
  condition = condition && status == other.getStatus();
  condition = condition && contaminationType == other.getContaminationType();
  return condition;
  
}




