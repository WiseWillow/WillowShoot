#ifndef CLOPE_H
#define CLOPE_H

#include <iostream>
#include <list>
#include "data_structures/dataelement.h"
#include "data_structures/cluster.h"

int* clusteringCLOPE(std::list<dataElement*>* inputData, double repulsion);

#endif // CLOPE_H
