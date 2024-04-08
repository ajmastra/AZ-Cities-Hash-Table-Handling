#include "HashUtility.h"

const int MINIMUM_HASH_CHARACTERS = 10;

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
    // calculate the has index
    int index = generateHashIndex( *hashData, cityName );

    /// add the city data to the appropriate array
    addItemAsData( hashData->table[ index ], cityName, cityRank, cityPop );
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
    int index;

    // check if the hash data is empty
    if( hashData != NULL )
    {
        // if it is not, clear each city type array on the hash table
        for( index = 0; index < hashData->capacity; index++ )
        {
            // clear each item
            clearArray( hashData->table[index] );
        }
        // free the hash table itself
        free( hashData->table );

        // free the hashData
        free(hashData);
        
    }

    // return null
    return NULL;
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
    // initialize variables
    int index;
    double sum, mean;

    // iterate through array
    for( index = 0; index < size; index++ )
    {
        // sum value at each array index
        sum = sum + array[index];
    }

    // divide sum by size
    mean = sum / size;

    // return the mean
    return mean;
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
    // choose the sorting method you want to use
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
    // initializ variables
    // sum, city name
            // func: privateGetStringLength
    int index = 0, sum = 0;
    int citySize = privateGetStringLength( cityName ); 

    // sum until the city name length is larger than MINIMUM_HASH_CHARACTERS
    while( index < MINIMUM_HASH_CHARACTERS || index < citySize )
    {
        // update the sum
        sum = sum + (int)cityName[ index % citySize ];

        // increment the index
        index++;
    }

    // return the sum % hashData capacity  ????????????????????????????
    return sum % hashData.capacity;
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
    // initialize variables
    char cityName[STD_STR_LEN], junkString[STD_STR_LEN];
    int cityRank, cityPop, loopCounter = 1;

    // initialize the hash table to null incase we cant open the file
    HashTableType *hashTable = NULL;

    // check if we can open the file
    if( openInputFile( fileName ))
    {
        // initialize the hash table
        hashTable = initializeHashTable( capacity );

        // ignore the first line of the file
        readStringToLineEndFromFile( junkString );

        // prime the loop by reading the first rank
        cityRank = readIntegerFromFile( );

        // loop until the end of the file
        while( !checkForEndOfInputFile( ) )
        {   
            // get rid of comma after the rank
            readCharacterFromFile(  );

            // read rest of the data
            readStringToDelimiterFromFile( COMMA, cityName );

            cityPop = readIntegerFromFile( );

            // check for verbose flag
            if(verbose)
            {
                // print
                printf( "%5d) City name: %s, Population: %d\n", loopCounter, cityName, cityPop );

            }

            // add the item
            addHashItem( hashTable, cityName, cityRank, cityPop );

            // increment the loop counter
            loopCounter = loopCounter + 1; 

            // reprime the loop
            cityRank = readIntegerFromFile( );           

        }
        // close the input file
        closeInputFile( );
    }


        
    // return the hashTable
    return hashTable;
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
Dependencies: malloc w/sizeof, createArray
*/
HashTableType *initializeHashTable( int capacity )
{
    // initialize variables
    HashTableType *hashData;
    int index;

    // allocate memory for the hash table
    hashData = ( HashTableType * )malloc( sizeof( HashTableType ) );

    // allocate memory for the array of CityTypeArray pointers
    hashData->table = ( CityArrayType** )malloc( capacity * sizeof( CityArrayType * ) );


    // initialize each cityArrayType
    for( index = 0; index < capacity; index++ )
    {
        hashData->table[index] = createArray( capacity );
    }

    // set capacity
    hashData->capacity = capacity;

    // return new hashtable
    return hashData;
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