#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include <math.h>
#include "data_structures/dataelement.h"

class cluster
{
    int label;
    int NoFeatures;
    int sumElements;
    int NoTransactions;
    int width;
    int* sumFeaturesArray;
public:
    cluster();
    cluster(int _label, int _NoFeatures, int _sumElements, int _NoTransactions, int* _sumFeaturesArray);
    cluster(int _label, int _NoFeatures);
    ~cluster();
    int getLabel();
    int getNoFeatures();
    int getSumElements();
    int getNoTransactions();
    int getWidth();
    int* getSumFeaturesArray();
    void addTransaction(dataElement* transaction);
    void subTransaction(dataElement* transaction);
    double deltaAdd(dataElement* transaction,double repulsion);
    double deltaSub(dataElement* transaction,double repulsion,bool switcher);

};

#endif // CLUSTER_H
