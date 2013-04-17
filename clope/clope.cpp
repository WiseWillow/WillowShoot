#include "clope.h"

int* clusteringCLOPE(std::list<dataElement*>* inputData, double repulsion)
{
    std::list<cluster*>* clustersList = new std::list<cluster*>;
    int* labelsArray = new int[inputData->size()];
    cluster** clustersArray = new cluster*[inputData->size()];
    int NoFeatures = (*(inputData->begin()))->getNoFeatures();
    int actualLabel = 1;
    int i = 0;
    int j = 0;
    cluster* newCluster = 0;
    double newProfit = 0.0;
    double deltaSub = 0.0;
    double deltaAdd = 0.0;
    bool changes = 1;
    bool switcher = 0;

    clustersList->push_back( new cluster(actualLabel,NoFeatures));
    actualLabel++;
//    clustersArray[i] = *(clustersList->begin());
//    labelsArray[i] = clustersArray[i]->getLabel();
//    i++;
//    (*(clustersList->begin()))->addTransaction(*(inputData->begin()));
//    clustersList->push_back( new cluster(actualLabel,NoFeatures));
//    actualLabel++;

//    for(std::list<dataElement*>::iterator iti=++(inputData->begin()) ; iti != inputData->end() ; ++iti)
//    {
//        newCluster=0;
//        newProfit = 0.0;

//        for(std::list<cluster*>::iterator itj=clustersList->begin() ; itj != clustersList->end() ; ++itj)
//        {
//            deltaAdd = (*itj)->deltaAdd(*iti,repulsion);
//            if( newProfit < deltaAdd )
//            {
//                newProfit = deltaAdd;
//                newCluster = *itj;
//            }
//        }

//        if( newCluster != 0 )
//        {
//            if( newCluster->getNoTransactions() == 0 )
//            {
//                clustersList->push_back( new cluster(actualLabel,NoFeatures));
//                actualLabel++;
//            }

//            labelsArray[i]= newCluster->getLabel();
//            clustersArray[i] = newCluster;
//            newCluster->addTransaction(*iti);
//        }
//        else
//            std::cout << "clusteringCLOPE(std::list<dataElement*>* inputData, double repulsion) for(std::list<dataElement*>::iterator iti=++(inputData->begin()) ; iti != inputData->end() ; ++iti) | newCluster != 0" << std::endl;
//        i++;
//    }

    while(changes)
    {
        std::cout << j << " " << actualLabel << std::endl;
        i = 0;
        changes = 0;


        for(std::list<dataElement*>::iterator iti=inputData->begin() ; iti != inputData->end() ; ++iti)
        {
            newCluster=0;
            newProfit = 0.0;
            if( j == 0 )
                deltaSub = 0.0;
            else
                deltaSub = clustersArray[i]->deltaSub(*iti,repulsion,switcher);

            for(std::list<cluster*>::iterator itj=clustersList->begin() ; itj != clustersList->end() ; ++itj)
            {
                if( j==0 || (*itj)->getLabel() != labelsArray[i] )
                {
                    deltaAdd = (*itj)->deltaAdd(*iti,repulsion);
                    if( newProfit < deltaAdd+deltaSub )
                    {
                        newProfit = deltaAdd+deltaSub;
                        newCluster = *itj;
                    }
                }
            }

            if( newCluster != 0 )
            {
                changes = 1;

                if( j != 0 )
                {
                    clustersArray[i]->subTransaction(*iti);
                    if(clustersArray[i]->getNoTransactions() == 0)
                    {
                        clustersList->remove(clustersArray[i]);
                        clustersArray[i]->~cluster();
                    }
                }

                if( newCluster->getNoTransactions() == 0 )
                {
                    clustersList->push_back( new cluster(actualLabel,NoFeatures));
                    actualLabel++;
                }

                labelsArray[i]= newCluster->getLabel();
                newCluster->addTransaction(*iti);
                clustersArray[i] = newCluster;
            }
//            else
//                std::cout << "clusteringCLOPE(std::list<dataElement*>* inputData, double repulsion) for(std::list<dataElement*>::iterator iti=++(inputData->begin()) ; iti != inputData->end() ; ++iti) | newCluster != 0" << std::endl;
            i++;
        }
        j++;
    }
    return labelsArray;
}
