#include "HashUtility.h"

/*
Name: addHashItem
Process: adds new item to hash table
Function input/parameters: pointer to hash table (HashTableType *), 
                           city name (const char *), 
                           city rank and population (int)
Function output/parameters: updated pointer to hash table (HashTableType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: generateHashIndex, addItemAsData
*/
void addHashItem( HashTableType *hashData, char *cityName, 
                                                    int cityRank, int cityPop )
{

}                                                    

/*
Name: clearHashTable
Process: verifies valid data,
         clears contents of hash table, and then hash table itself
Function input/parameters: pointer to hash table (HashTableType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: clearArray, free
*/
HashTableType *clearHashTable( HashTableType *hashData )
{
    return NULL; //stub
}

/*
Name: findMean
Process: finds the mean of a set of integers
Function input/parameters: integer array (int *), size (int)
Function output/parameters: none
Function output/returned: mean of values (double)
Device input/---: none
Device output/---: none
Dependencies: none
*/
double findMean( int *array, int size )
{
    return 0; // stub
}

/*
Name: findMedian
Process: finds the median of a set of integers,
         assumes all input arrays will have an odd number of values
Function input/parameters: integer array (int *), size (int)
Function output/parameters: none
Function output/returned: median of values (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int findMedian( int *array, int size )
{
    return 0; // stub
}

/*
Name: generateHashIndex
Process: finds hashed index for given data item,
         sums integer values of city name characters,
         if city name length is less than MINIMUM_HASH_CHARACTERS,
         repeats going over the city letters as needed to meet this minimum
Function input/parameters: hash table (const HashTableType),
                           city name (const char *)
Function output/parameters: none
Function output/returned: generated hash index (int)
Device input/---: none
Device output/---: none
Dependencies: privateGetStringLength
*/
int generateHashIndex( const HashTableType hashData, const char *cityName )
{
    return 0; // stub
}

/*
Name: getHashDataFromFile
Process: uploads data from city file with unknown number of data sets,
         provides Boolean parameter to display data input success
Function input/parameters: file name (char *), capacity (int),
                           verbose flag (bool)
Function output/parameters: none
Function output/returned: pointer to newly created hash table 
                            (HashTableType *)
Device input/file: data from HD
Device output/---: none
Dependencies: openInputFile, initializeHashTable, readStringToDelimiterFromFile, 
              readStringToLineEndFromFile, checkForEndOfInputFile, 
              readCharacterFromFile, readIntegerFromFile, 
              addHashItem, printf, closeInputFile
*/

HashTableType *getHashDataFromFile( const char *fileName, 
                                                   int capacity, bool verbose )
{
    return NULL;
}

/*
Name: initializeHashTable
Process: dynamically creates new hash table with internal components
Function input/parameters: capacity (int)
Function output/parameters: none
Function output/returned: pointer to newly created hash table 
                            (HashTableType *)
Device input/file: data from HD
Device output/---: none
Dependencies: malloc w/sizeof, initializeBST
*/
HashTableType *initializeHashTable( int capacity )
{
    return NULL;
}

/*
Name: removeHashItem
Process: acquires hashed item, returns
Function input/parameters: pointer to hash table (HashTableType *),
                           city name (const char *)
Function output/parameters: none
Function output/returned: pointer to removed item (CityType *), or empty data
Device input/---: none
Device output/---: none
Dependencies: generateHashIndex, removeItem
*/
bool removeHashItem( HashTableType *hashData, 
                                  CityType *removedItem, const char *cityName )
{
    return false; // stub
}

/*
Name: searchHashTable
Process: searches for value in table, returns item if found and true,
         returns empty found item and false if not
Function input/parameters: hash table (const HashTableType),
                           city name (const char *)
Function output/parameters: found item (CityType *)
Function output/returned: Boolean result as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: generateHashIndex, search, setCityFromStruct, setCityDataToEmpty
*/
bool searchHashTable( const HashTableType hashData, 
                                    CityType *foundItem, const char *cityName )
{
    return false; // stub
}

/*
Name: showHashTableStatus
Process: displays item counts from each BST element in the hash table,
         displays highest and lowest number of items in an element,
         displays range between highest and lowest,
         displays the mean and median,
         and displays the total number of nodes found,
         all in a formatted structure
Function input/parameters: hashTable (const HashTableType)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: hash data status displayed as specified
Dependencies: malloc w/sizeof, countTreeNodes, printf, 
              findMean, findMedian, free
*/
void showHashTableStatus( const HashTableType hashData )
{
    
}
