// header files
#include "File_Input_Utility.h"
#include "HashUtility.h"

// constant definitions
   // none

// main function
int main( int argc, char *argv[] )
   {
    HashTableType *hashTablePtr;
    char fileName[] = "AZ_Cities.csv";
    int hashSize = 19;  // hash table capacity
    bool uploadDisplayFlag;

    printf( "\nHash Table Analysis\n" );
    printf( "===================\n" );

    uploadDisplayFlag = true;
    hashTablePtr = getHashDataFromFile( fileName, hashSize, uploadDisplayFlag );

    printf( "\nORIGINAL HASH TABLE\n" );
    showHashTableStatus( *hashTablePtr );

    // clear hash table
       // function: clearHashTable
    hashTablePtr = clearHashTable( hashTablePtr );

       // show program end
          // function: printf
       printf( "\nEnd Program\n" );

       // return success
       return 0;
   }

