 Name: Will Rhodes
 Course: CSC 415
 Semester: Spring 2014
 Instructor: Dr. Pulimood
 Exercise : Assignment 3
 Description: The following program allows the user to perform a variety of tasks on a list of brownfield data. The core algorithm in the program predicts the contamination status based on the five closest sites (see "Algorithm" for more information).

################################################################################
Documentation
################################################################################
1. To run the program in a terminal, ./assignment3Exec where "assignment3Exec" is the compiled filename
2. The user must first enter the filename of the csv with 7 fields specifying brownfield data (see "Input Format" for more information).
3. If the parsing is sucessful, the program will ask for an input command.

The list of possible commands:
#######################
   Command                        Action
         a                Add a New Site
         s        Get/Predict the status
         o                   Output List
         h                          Help
         x             Exit this Program
#######################

4. Follow the directions in each option. If an invalid input was entered, the user will be sent back to the main screen.


################################################################################
Algorithm
################################################################################
*The distances are based off of Euclidean distances.

*Based on the statuses, each site either implies the surrounding region is contaminated or not. This is calculated by hasSurroundingContamination() in the Site object.
*The prediction is based off of the inverse weighted mean of these boolean values (1 = contaminated, 0 = clear).
*inverseWeight = 1/(distances^p) where p is the arbitrary power-value
*average = sum(inverseWeight*hasSurroundingContamination())/sum_of_weights
*The results for average is normalized (between 0 and 1) that shows the percent likelihood of contamination.


################################################################################
Input Format
################################################################################
The input file should be comma separated  values with the following fields:
	Site Id,Site Name,Status,Remediation Status,Type of Contamination,X Coord,Y Coord
