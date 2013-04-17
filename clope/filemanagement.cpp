#include "filemanagement.h"

std::list<dataElement*>* readFromFile()
{
    std::ifstream myfile;
    std::string line;
    std::string name;
    char* stringTemp;
    int NoFeatures;
    bool* features;
    int firstSemiColon, firstColon;
    std::list<dataElement *>* inputData = new std::list<dataElement *>;
    std::list<dataElement*>::iterator it;

    myfile.open ("/home/gosciunew/Dokumenty/ChimneyLABS_documents/repo/clope/myplants.data");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            std::getline(myfile,line);
            firstSemiColon = line.find_first_of(';');
            firstColon = line.find_last_of(',');
            NoFeatures = (firstColon-firstSemiColon)/2;
            features = new bool[NoFeatures];

            for(int i = 0 ; i < NoFeatures ; ++i)
                if(line[firstSemiColon+1+2*i]=='0')
                    features[i]=0;
                else
                    features[i]=1;

            stringTemp = new char[firstSemiColon+1];
            stringTemp[line.copy(stringTemp, firstSemiColon)]='\0';
            name = stringTemp;

            if(NoFeatures != 0)
                inputData->push_back( new dataElement(name,NoFeatures,features) );
            delete stringTemp;
        }
        myfile.close();
        return inputData;
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
        return 0;
    }
}

int writetoFile(int* _labelsArray)
{
    return 0;
}
