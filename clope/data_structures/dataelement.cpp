#include "dataelement.h"

dataElement::dataElement()
{
    this->name = "Default";
    this->NoFeatures = 0;
    this->featuresArray = 0;
}

dataElement::dataElement(std::string _name, int _NoFeatures, bool* _featuresArray)
{
    this->name = _name;
    this->NoFeatures = _NoFeatures;
    this->featuresArray = _featuresArray;
}

dataElement::~dataElement()
{
    if(this->featuresArray != 0)
        delete this->featuresArray;
}

std::string dataElement::getName()
{
    return this->name;
}

int dataElement::getNoFeatures()
{
    return this->NoFeatures;
}

bool* dataElement::getFeaturesArray()
{
    return this->featuresArray;
}
