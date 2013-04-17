#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <list>
#include "data_structures/dataelement.h"
#include "filemanagement.h"
#include "clope.h"
#include "tbb/tbb.h"
#include "tbb/tick_count.h"


using namespace std;
using namespace tbb;

int main()
{
    tick_count startTime = tick_count::now();
    list<dataElement*> *inputData;
    int* labelsArray;
    inputData = readFromFile();
    labelsArray = clusteringCLOPE(inputData,2.0);
    printf("Duration : %g \n",(tick_count::now()-startTime).seconds() );
//    for(int i = 30000 ; i < static_cast<int>(inputData->size()) ; ++i)
//        cout << labelsArray[i] << " " << endl;
//    cout << "Hello World!" << endl;

    return 0;

}

