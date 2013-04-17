#include "cluster.h"

cluster::cluster()
{
    this->label = 0;
    this->NoFeatures = 0;
    this->sumElements = 0;
    this->NoTransactions = 0;
    this->width = 0;
    this->sumFeaturesArray = 0;
}

cluster::cluster(int _label, int _NoFeatures, int _sumElements, int _NoTransactions, int* _sumFeaturesArray)
{
    this->label = _label;
    this->NoFeatures = _NoFeatures;
    this->sumElements = _sumElements;
    this->NoTransactions = _NoTransactions;
    this->sumFeaturesArray = _sumFeaturesArray;
    for(int i = 0 ; i < this->NoFeatures ; ++i)
    {
        if(this->sumFeaturesArray[i] != 0)
            this->width++;
    }

}

cluster::cluster(int _label, int _NoFeatures)
{
    this->label = _label;
    this->NoFeatures = _NoFeatures;
    this->sumElements = 0;
    this->NoTransactions = 0;
    this->width = 0;
    this->sumFeaturesArray = new int[this->NoFeatures];
    for(int i = 0 ; i < this->NoFeatures ; ++i)
        this->sumFeaturesArray[i] = 0;
}

cluster::~cluster()
{
    if(this->sumFeaturesArray != 0)
    {
        delete this->sumFeaturesArray;
        //delete this->sumFeaturesArray;
    }
}

int cluster::getLabel()
{
    return this->label;
}

int cluster::getNoFeatures()
{
    return this->NoFeatures;
}

int cluster::getSumElements()
{
    return this->sumElements;
}

int cluster::getNoTransactions()
{
    return this->NoTransactions;
}

int cluster::getWidth()
{
    return this->width;
}

int* cluster::getSumFeaturesArray()
{
    return this->sumFeaturesArray;
}

void cluster::addTransaction(dataElement* transaction)
{
    bool* transactionfeaturesArray = transaction->getFeaturesArray();
    this->NoTransactions++;
    this->sumElements = 0;
    this->width = 0;
    for(int i = 0 ; i < this->NoFeatures ; ++i)
    {
        if(transactionfeaturesArray[i] != 0 )
            this->sumFeaturesArray[i]++;

        if( this->sumFeaturesArray[i] != 0 )
        {
            this->sumElements += this->sumFeaturesArray[i];
            this->width++;
        }
    }
}

void cluster::subTransaction(dataElement* transaction)
{
    bool* transactionfeaturesArray = transaction->getFeaturesArray();
    this->NoTransactions--;
    if( this->NoTransactions < 0 )
        std::cout << "cluster::subTransaction(dataElement* transaction) (this->NoTransactions--) < 0" << std::endl;
    this->sumElements = 0;
    this->width = 0;
    for(int i = 0 ; i < this->NoFeatures ; ++i)
    {
        if(transactionfeaturesArray[i] != 0 )
            this->sumFeaturesArray[i]--;

        if( this->sumFeaturesArray[i] != 0 )
        {
            this->sumElements += this->sumFeaturesArray[i];
            this->width++;
        }
    }
}


double cluster::deltaAdd(dataElement* transaction,double repulsion)
{
    bool* transactionfeaturesArray = transaction->getFeaturesArray();
    double toReturn = 0.0;
    int sumElementsNew = 0;
    int widthNew = 0;
    int* sumFeaturesArrayNew = new int[this->NoFeatures];

    for(int i = 0 ; i < this->NoFeatures ; ++i)
    {
        if(transactionfeaturesArray[i] != 0 )
            sumFeaturesArrayNew[i] = this->sumFeaturesArray[i] + 1;
        else
            sumFeaturesArrayNew[i] = this->sumFeaturesArray[i];

        if( sumFeaturesArrayNew[i] != 0 )
        {
            sumElementsNew += sumFeaturesArrayNew[i];
            widthNew++;
        }
    }

    if( widthNew != 0 )
    {
        toReturn = static_cast<double>(sumElementsNew*(this->NoTransactions+1))/pow( static_cast<double>(widthNew),repulsion);
        if(this->sumElements != 0)
            toReturn -= static_cast<double>(this->sumElements*this->NoTransactions)/pow(static_cast<double>(this->width),repulsion);
        delete sumFeaturesArrayNew;
        return toReturn;

    } else {
        std::cout << "cluster::deltaAdd(dataElement* transaction,double repulsion) widthNew == 0" << std::endl;
        delete sumFeaturesArrayNew;
        return 0.0;
    }
}

double cluster::deltaSub(dataElement* transaction, double repulsion,bool switcher)
{
    bool* transactionfeaturesArray = transaction->getFeaturesArray();
    double toReturn = 0.0;
    int sumElementsNew = 0;
    int widthNew = 0;
    int* sumFeaturesArrayNew = new int[this->NoFeatures];

    if( this->NoTransactions-1 > 0 )
        for(int i = 0 ; i < this->NoFeatures ; ++i)
        {
            if(transactionfeaturesArray[i] != 0 )
            {
                sumFeaturesArrayNew[i] = this->sumFeaturesArray[i] - 1;
                if( sumFeaturesArrayNew[i] < 0 )
                {
                    std::cout << "cluster::deltaSub(dataElement* transaction,double repulsion) sumFeaturesArrayNew[" << i << "] < 0 " << sumFeaturesArrayNew[i] <<  std::endl;
                    return 0.0;
                }
            } else
                sumFeaturesArrayNew[i] = this->sumFeaturesArray[i];

            if( sumFeaturesArrayNew[i] != 0 )
            {
                sumElementsNew += sumFeaturesArrayNew[i];
                ++widthNew;
            }
        }

    if( sumElementsNew >= 0 )
    {
        toReturn -= static_cast<double>(this->sumElements*this->NoTransactions)/pow(static_cast<double>(this->width),repulsion);
        if( sumElementsNew > 0 )
            toReturn += static_cast<double>(sumElementsNew*(this->NoTransactions-1))/pow( static_cast<double>(widthNew),repulsion);
        delete sumFeaturesArrayNew;
        return toReturn;

    } else {
        std::cout << "cluster::deltaSub(dataElement* transaction,double repulsion) sumElementsNew < 0" << std::endl;
        delete sumFeaturesArrayNew;
        return 0;
    }
}


