// header file
#include "CityUtility.h"

////////////////////////////////////////////////////////////////////////////////
// Function Implementations

/*
Name: addItemAsData
Process: checks for resize needed, adds given CityType data to array sorted        
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
                                                       int rankSet, int popSet )
   {
    int index = cityData->size;

    checkForResize( cityData );

    while( index > 0 
      && privateCompareStrings( cityData->array[ index - 1 ].name, 
                                                                 nameSet ) > 0 )
       {
        setCityFromStruct( &cityData->array[ index ], 
                                                cityData->array[ index - 1 ] );

        index--;
       }

    setCityFromData( &cityData->array[ index ], nameSet, rankSet, popSet );

    cityData->size = cityData->size + 1;
   }

/*
Name: addItemAsStruct
Process: checks for resize needed, adds given CityType data in struct
         sorted by name/key       
Function input/parameters: city data struct (CityArray),
Function output/parameters: updated city data (CityArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: addItemAsData
*/
void addItemAsStruct( CityArrayType *cityData, const CityType cityAdded )
   {
    addItemAsData( cityData, cityAdded.name, 
                                       cityAdded.rank, cityAdded.population );
   }

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
void checkForResize( CityArrayType *cityData )
   {
    int index;
    CityType *newArr;

    if( cityData->size == cityData->capacity )
       {
        cityData->capacity = cityData->capacity * 2;

        newArr = (CityType *)malloc( cityData->capacity * sizeof( CityType ) );        

        for( index = 0; index < cityData->size; index++ )
           {
            setCityFromStruct( &newArr[ index ], cityData->array[ index ] );
           }

        free( cityData->array );

        cityData->array = newArr;
       }
   }

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
CityArrayType *clearArray( CityArrayType *cityData )
   {
    if( cityData != NULL )
       {
        free( cityData->array );

        cityData->size = 0;

        cityData->capacity = 0;

        free( cityData );
       }

    return NULL;
   }

/*
Name: compareCities
Process: compares names/keys of two cities
         if first city name is greater than second, returns positive number,
         if first city name is less than second, returns a negative number,
         otherwise returns zero
Function input/parameters: two cities (const CityType)
Function output/parameters: none
Function output/returned: integer result as specified (int)
Device input/---: none
Device output/---: none
Dependencies: privateCompareStrings
*/
int compareCities( const CityType oneCity, const CityType otherCity )
   {
    return privateCompareStrings( oneCity.name, otherCity.name );
   }

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
CityArrayType *createArray( int capacity )
   {
    CityArrayType *newCityData = (CityArrayType *)malloc( 
                                                     sizeof( CityArrayType ) );

    newCityData->array = (CityType *)malloc( capacity * sizeof( CityType ) );

    newCityData->capacity = capacity;

    newCityData->size = 0;

    return newCityData;
   }

/*
Name: removeItem
Process: searches for item in list by name, if found, 
         sets removed item to found data, removes,
         shifts remaining data down, and returns true,
         otherwise sets removed item to empty, returns false
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
                            CityType *removedItem, const char *removeName )
   {
    int wkgIndex, searchIndex = search( cityData, removeName );

    if( searchIndex != NOT_FOUND )
       {
        setCityFromStruct( removedItem, cityData->array[ searchIndex ] );

        cityData->size = cityData->size - 1;

        for( wkgIndex = searchIndex; wkgIndex < cityData->size; wkgIndex++ )
           {
            setCityFromStruct( &cityData->array[ wkgIndex ], 
                                             cityData->array[ wkgIndex + 1 ] );
           }

        return true;
       }

    setCityDataToEmpty( removedItem );

    return false;
   }

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
int search( CityArrayType *cityData, const char *name )
   {
    int compareVal, lowIndex = 0, midIndex, highIndex = cityData->size - 1;

    do
       {
        midIndex = ( lowIndex + highIndex ) / 2;

        compareVal = privateCompareStrings( 
                                      cityData->array[ midIndex ].name, name );

        if( compareVal > 0 )
           {
            highIndex = midIndex - 1;
           }

        else if( compareVal < 0 )
           {
            lowIndex = midIndex + 1;
           }

        else
           {
            return midIndex;
           }
       }
    while( lowIndex <= highIndex );

    return NOT_FOUND;
   }

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
void setCityToString( char *cityStr, const CityType cityNode )
   {
    sprintf( cityStr, "Name: %s, Rank: %d, Population: %d", 
                         cityNode.name, cityNode.rank, cityNode.population );
   }

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
void setCityDataToEmpty( CityType *cityNode )
   {
    setCityFromData( cityNode, "", 0, 0 );
   }

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
                                 const char *nameSet, int rank, int population )
   {
    privateCopyString( cityNode->name, nameSet );

    cityNode->rank = rank;

    cityNode->population = population;
   }

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
void setCityFromStruct( CityType *cityNode, const CityType source )
   {
    setCityFromData( cityNode, source.name, source.rank, source.population );
   }

   