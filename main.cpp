//Project by Joel Gorder and Christopher Sichko
// 4/26/2015

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "models.h"

using namespace std;

int main() {
	//This is where the data is read in.  It's hardcoded to read our data file, 'Data.txt.' 
	//We creat an instance of the class and fill it with our data in the while loop below.
    ifstream fin("data.txt");
    stats *myLinkedList = new stats(); //create a new instance of the stats class

    string in_partNumb;
    string in_run1Forc;
    string in_run2Forc;
    string model1;
    string model2;

    while(fin >> in_partNumb >> in_run1Forc >> in_run2Forc >> model1 >> model2){
        int partNumb = stoi(in_partNumb);
        double run1Forc = stod(in_run1Forc);
        double run2Forc = stod(in_run2Forc);
        myLinkedList->addPartsNode(partNumb, run1Forc, run2Forc, model1, model2);
    }

	//Here we call the public functions, which will call the private functions where we pass in the head of the list.
    int counter = myLinkedList->countNodes();
    int modelCounter = myLinkedList->countNumbOfModelsChanged();
    double avgPercentChange = myLinkedList->calcAvgPercentChange();
    double avgChanged = myLinkedList -> calcAvgChanged();
    double avgNotChanged = myLinkedList -> calcAvgNotChanged();
    double stdvChanged = myLinkedList->stdvChanged();
    double stdvNotChanged = myLinkedList->stdvNotChanged();
    double maxUnitChange = myLinkedList->findMaxUnitChange();
    double maxPercentChange = myLinkedList->findMaxPercentChange();
    int counterPartsOver20Percent = myLinkedList->countForecastChangeOver20P();
    int countFrom0 = myLinkedList->countForcFrom0();

	//This is our output.  The print statments give us the information we wanted out of the data we read in. 
    cout << "The number of parts is: " << counter << endl;
    cout << modelCounter << " of the " << counter << " parts used different models for the two forecasts." << endl;
    cout << "The average percent change in the amount forecasted between runs is: " << avgPercentChange*100 << "%" << endl;
    cout << "The average percent change in the forecast when the model did change is: " << avgChanged*100 << "%" << endl;
    cout << "The average percent change in the forecast when the model remained the same is : " << avgNotChanged*100 << "%" << endl;
    cout << "The standard deviation of the parts forcast with models that changed is: " << stdvChanged << endl;
    cout << "The standard deviation of parts forcast with models that remained the same is: " << stdvNotChanged << endl;
    cout << "The largest change in the number of parts forecasted for a particular part number is: " << maxUnitChange << endl;
    cout << "The largest percent change in the number of parts forecasted for a particular part number is: " << maxPercentChange*100 << "%" << endl;
    cout << "The number of forecasts that changed by more than 20% is: " << counterPartsOver20Percent << endl;
    cout << "The number of parts that went from 0 forecast in run 1 to having a forecast in run 2 is: " << countFrom0 << endl;

    return 0;
}
