#ifndef DATAELEMENT_H
#define DATAELEMENT_H

#include <string>

class dataElement
{
    std::string  name;
    int    NoFeatures;
    bool*  featuresArray;
public:
    dataElement();
    dataElement(std::string _name, int _NoFeatures, bool* _featuresArray);
    ~dataElement();
    std::string getName();
    int getNoFeatures();
    bool* getFeaturesArray();
};

#endif // DATAELEMENT_H
