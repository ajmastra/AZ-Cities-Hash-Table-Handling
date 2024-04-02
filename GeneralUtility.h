// Precompiler directives /////////////////////////////////////////////////////

#ifndef GENERAL_UTILITY_H
#define GENERAL_UTILITY_H

// Header files ///////////////////////////////////////////////////////////////

#include "StandardConstants.h"
#include <string.h>
#include <stdlib.h>  // requires srand call in main function if rand used
#include <stdio.h>   // for printChars

// global constants ////////////////////////////////////////////////////////////

   // none

// data structures /////////////////////////////////////////////////////////////

   // None

/*
Name: privateCompareStrings
Process: compares two strings as follows:
         - if left string is alphabetically greater than the right string, 
         returns value greater than zero
         - if left string is alphabetically less than the right string, 
         returns value less than zero
         - if strings are alphabetically equal but one is longer, 
           longer one is greater
         - otherwise, returns zero
Function input/parameters: two strings to be compared (const char *)
Function output/parameters: none
Function output/returned: result as specified above (int)
Device input/ ---: none
Device output/ ---: none
Dependencies: privateGetStringLength
*/
int privateCompareStrings( const char *leftStr, const char *rightStr );

/*
Name: privateCompareStringSegments
Process: compares two string segments as follows:
         - compares the string segments up to the length of the test segment
         - if test segment segment is alphabetically greater 
                                      than the equal sized right string segment, 
         returns value greater than zero
         - if test segment segment is alphabetically less 
                                                  than the right string segment, 
         returns value less than zero
         - if string segments are equal returns zero
Function input/parameters: two strings to be compared (const char *)
Function output/parameters: none
Function output/returned: result as specified above (int)
Device input/---: none
Device output/---: none
Dependencies: strlen
*/
int privateCompareStringSegments( const char *testSegment, 
                                                         const char *otherStr );

/*
Name: privateCopyString
Process: copies string character for character up to NULL_CHAR of source string
Function input/parameters: source string to be copied (const char *)
Function output/parameters: destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void privateCopyString( char *dest, const char *source );

/*
Name: privateDisplayChars
Process: recursively displays a specified number of characters
Function input/parameters: number of characters (int), output character (char)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: characters displayed as specified
Dependencies: privateDisplayChars (recursively), printf
*/
void privateDisplayChars( int numChars, char outChar );

/*
Name: privateFindMax
Process: finds maximum between two values, returns larger
Function input/parameters: two values (int)
Function output/parameters: none
Function output/returned: larger of two values (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int privateFindMax( int one, int other );

/*
Name: privateGetRandBetween
Process: generates and returns a random value
         between two given values, inclusive
Function Input/Parameters: low, high limits (int)
Function Output/Parameters: none
Function Output/Returned: random value as specified
Device Input/---: none
Device Output/---: none
Dependencies: rand
*/
int privateGetRandBetween( int lowVal, int highVal );

/*
Name: privateGetStringLength
Process: finds length of string
Function input/parameters: c-style string (const char *)
Function output/parameters: none
Function output/returned: calculated length of string (int)
Device input/ ---: none
Device output/ ---: none
Dependencies: none
*/
int privateGetStringLength( const char *str );

/*
Name: privateIsInArray
Process: utility function that reports if a specified value 
         has been found in a given array
Function input/parameters: pointer to integer array (int *), value (int),
                           size of array (int)
Function output/parameters: none
Function output/returned: result as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool privateIsInArray( int *array, int value, int arraySize );

/*
Name: privateToPower
Process: recursively calculates a base to exponent value 
         for positive integer exponents
Function input/parameters: base, exponent (int)
Function output/parameters: none
Function output/returned: calculated value (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int privateToPower( int base, int exponent );


#endif		// GENERAL_UTILITY_H



