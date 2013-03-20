#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Witam"<< endl;//Arek
    cout << "Arek, Ty wiesz kim jestes, nie?" << endl;
    cout << "Nie podskakuj, bo dzieki temu, ze dodalem iostrema masz w ogole glos" << endl;
    return a.exec();
}
