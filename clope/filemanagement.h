#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "data_structures/dataelement.h"
#include "data_structures/cluster.h"

std::list<dataElement*>* readFromFile();
int writetoFile(int* _labelsArray);

#endif // FILEMANAGEMENT_H
