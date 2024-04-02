#ifndef STATE_UTILITY_H
#define STATE_UTILITY_H

// header files
#include <time.h>
#include <stdio.h>
#include "GeneralUtility.h"
#include "StandardConstants.h"

// constants
#define NOT_FOUND -1

// data structure
typedef struct CityStruct
   {
    char name[ STD_STR_LEN ];

    int rank, population;
   } CityType;

typedef struct CityArrayStruct
   {
    CityType *array;

    int size, capacity;
   } CityArrayType;


// prototypes

/*
Name: addItemAsData
Process: checks for resize needed, adds given CityType data to array 
         sorted by name/key       
Function input/parameters: city name (const char *),
                           rank and population (int)
Function output/parameters: updated city data (CityArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: privateCopyString, checkForResize
*/
void addItemAsData( CityArrayType *cityData, const char *nameSet, 
                                                      int rankSet, int popSet );

/*
Name: addItemAsStruct
Process: checks for resize needed, adds given CityType data in struct
         sorted by name/key                
Function input/parameters: city array struct (CityArrayType *),
                           city data to be added (CityType)
Function output/parameters: updated city data (CityArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: addItemAsData
*/
void addItemAsStruct( CityArrayType *cityData, const CityType cityAdded );

/*
Name: checkForResize
Process: checks for resize needed, creates new array with double capacity,
         assigns data into new array, removes and replaces old array
         with new array
Function input/parameters: city data (CityArrayType *),
Function output/parameters: updated city data (CityArrayType *) as needed
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: malloc, setCityFromStruct, free
*/
void checkForResize( CityArrayType *cityData );

/*
Name: clearArray
Process: verifies valid data,
         deallocates array struct and array within struct, returns NULL
Function input/parameters: array data (CityArrayType *)
Function output/parameters: none
Function output/returned: returns NULL (CityArrayType *)
Device input/---: none
Device output/---: none
Dependencies: free
*/
CityArrayType *clearArray( CityArrayType *cityData );

/*
Name: compareCities
Process: compares names/keys of two citys
         if first city name is greater than second, returns positive number,
         if first city name is less than second, returns a negative number,
         otherwise returns zero
Function input/parameters: two cities (const StateType)
Function output/parameters: none
Function output/returned: integer result as specified (int)
Device input/---: none
Device output/---: none
Dependencies: privateCompareStrings
*/
int compareCities( const CityType oneCity, const CityType otherCity );

/*
Name: createArray
Process: creates city data array type, initializes support information
Function input/parameters: initial capacity (int)
Function output/parameters: none
Function output/returned: pointer to created array type (CityArrayType *)
Device input/---: none
Device output/---: none
Dependencies: malloc
*/
CityArrayType *createArray( int capacity );

/*
Name: removeItem
Process: searches for item in list by name, if found, removes,
         shifts remaining data down, and returns true,
         otherwise returns false
Function input/parameters: city data (CityArrayType *),
                           item name/key to be removed (const char *)
Function output/parameters: updated city data (CityArrayType *),
                            removed item (CityType *)
Function output/returned: Boolean result as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: search, setCityFromStruct
*/
bool removeItem( CityArrayType *cityData, 
                           CityType *removedItem, const char *removeName );

/*
Name: search
Process: searches for item using binary search,
         if found, returns index, otherwise returns NOT_FOUND
Function input/parameters: city data (CityArrayType *),
                           item name/key to be found (const char *)
Function output/parameters: none
Function output/returned: index or NOT_FOUND as specified (int)
Device input/---: none
Device output/---: none
Dependencies: privateCompareStrings
*/
int search( CityArrayType *cityData, const char *name );

/*
Name: setCityToString
Process: sets city data into a string
Function input/parameters: city type data (const CityType)
Function output/parameters: updated city data as string (char *) 
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: 
*/
void setCityToString( char *cityStr, const CityType cityNode );

/*
Name: setCityDataToEmpty
Process: sets city data to empty string and zeros for the numerical data
Function input/parameters: node to be emptied (CityType *)
Function output/parameters: updated city data (CityType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setCityFromData
*/
void setCityDataToEmpty( CityType *cityNode );

/*
Name: setCityFromData
Process: sets city data into a city data node
Function input/parameters: city name (const char *), 
                           city rank and population (int)
Function output/parameters: updated city data (CityType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: privateCopyString
*/
void setCityFromData( CityType *cityNode, 
                                const char *nameSet, int rank, int population );

/*
Name: setCityFromStruct
Process: sets city data from source struct into destination struct
Function input/parameters: city type data as struct (const CityType)
Function output/parameters: updated city data as struct (CityType *) 
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setCityFromData
*/
void setCityFromStruct( CityType *cityNode, const CityType source );

#endif   // STATE_UTILITY_H
