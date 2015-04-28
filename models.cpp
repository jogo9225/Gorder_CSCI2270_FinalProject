//Project by Joel Gorder and Christopher Sichko
// 4/26/2015

#include "models.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>


stats::stats(){
    head = NULL;
}

stats::~stats(){

}

/*
Function Prototype:
void stats::addPartsNode(int, double, double, std::string,
std::string)

Function Description:
This function is called in the while loop that read in data from a .txt file in the main. The function is
executed for each iteration of the while loop, i.e. for each line in the text file. This function first
creates a new part struct by calling the part constructor inside the part struct. Then it adds
the part into the linked list of parts.

Example:
Adding to the linked list named myLinkedList:
myLinkedList->addPartsNode(partNumb, run1Forc, run2Forc, model1, model2);

Pre-conditions:
The txt data file is opened by c++, and an instance of the stats class has been created.


Post-conditions:
A linked list fully populated with parts nodes has been created and is ready to be used
to produce summary statistics.
*/

void stats::addPartsNode(int partNumber, double run1Forc, double run2Forc, std::string model1,
std::string model2){
    part *myPart = new part(partNumber, run1Forc, run2Forc, model1, model2);
    part *y = NULL;
    part *x = head;
    while(x != NULL){
        y = x;
        x = x->next;
    }
    if(y == NULL){
        head = myPart;
    }
    else{
        y->next = myPart;
    }
}

/*
Function Prototype:
int stats::countNodes();
int stats::countNodes(part *);

***All of the following functions follow this format: one public function that takes no parameters and
serves to call the private function which takes the head of the linked list as its parameter and does
the leg work of the function.***

Function Description:
This function starts at the head of the linked list and simply counts the number of nodes that we have
in our linked list.

Example:
Linked List called myLinkedList.
int counter = myLinkedList->countNodes(); //(called from main)
->
int numbnodes = countNodes(head); //(called inside the public function)

Pre-conditions:
A linked list has been insantiated and the attributes of each parts node have been assigned.

Post-conditions:
An integer count of the number of nodes in the linked list is returned for what ever purpose the
end-user desires.
*/

int stats::countNodes(){
    int numbnodes = countNodes(head);
    return numbnodes;
}
int stats::countNodes(part *head){
    part *z = head;
    int counter = 0;
    while(z != NULL){
        counter++;
        z = z->next;
    }
    return counter;
}
/*
Function Prototype:
int stats::countNumbOfModelsChanged();
int stats::countNumbOfModelsChanged(part *);

Function Description:
This function starts at the head of the linked list and counts the number of parts which had different models
used to produce their forecast for the first and the second runs of the statistical forecast.

Example:
Linked List called myLinkedList.
int modelCounter = myLinkedList->countNumbOfModelsChanged(); //(called from main)
->
int counter = countAndPrintNumbOfModelsChanged(head); //(called inside the public function)

Pre-conditions:
A linked list has been built and the attributes of each parts node have been populated.

Post-conditions:
An integer count of the number of parts whose prediction model changed between runs
is returned for what ever purpose the end-user desires.
*/


int stats::countNumbOfModelsChanged(){
    int counter = countNumbOfModelsChanged(head);
    return counter;
}

int stats::countNumbOfModelsChanged(part *head){
    part *z = head;
    int counterChanged = 0;
    while(z != NULL){
        if(z->modelChanged == true){
            counterChanged++;
        }
        z = z->next;
    }
    return counterChanged;
}

/*
Function Prototype:
double stats::calcAvgPercentChange();
double stats::calcAvgPercentChange(part *);

Function Description:
This function starts at the head of the linked list. It calculates the average percentage change in the forcasted amount of parts from the first forcast to the second.

Example:
Linked List called myLinkedList.
double avgPercentChange = myLinkedList->calcAvgPercentChange(); //(called from main)
->
double AvgPercentChange = calcAvgPercentChange(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
A double of the average percent change between forecasts for each part in the linked list is returned for what
ever purpose the end-user desires.
*/

double stats::calcAvgPercentChange(){
    double AvgPercentChange = calcAvgPercentChange(head);
    return AvgPercentChange;
}

double stats::calcAvgPercentChange(part *head){
    part *z = head;
    double sumOfPercentChanged = 0.0;
    double average = 0.0;
    while(z != NULL)
    {
        sumOfPercentChanged = sumOfPercentChanged + z -> percentChange;
        z = z->next;
    }
    return average = sumOfPercentChanged/1627;
}

/*
Function Prototype:
double stats::calcAvgChanged();
double stats::calcAvgChanged(part *head);

Function Description:
This function starts at the head of the linked list and calculates the average percent change between forecast
for parts that had different models used to produce each forecast.

Example:
Linked List called myLinkedList.
double avgChanged = myLinkedList -> calcAvgChanged(); //(called from main)
->
double avgChanged = calcAvgChanged(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
A double of the average percent change in the forecasted number of parts which had different models used to produce
each of its forecasts is returned for what ever purpose the end-user desires.
*/

double stats::calcAvgChanged()
{
	double avgChanged = calcAvgChanged(head);
	return avgChanged;
}

double stats::calcAvgChanged(part *head)
{
	part *z = head;
	double counter = 0.0;
	double sumOfPercentChanged = 0.0;
    double average = 0.0;
    while(z != NULL)
    {
        if(z -> modelChanged == true)
        {
			sumOfPercentChanged = sumOfPercentChanged + z -> percentChange;
			counter++;
		}
        z = z->next;
    }
    return average = sumOfPercentChanged/counter;
}

/*
Function Prototype:
double stats::calcAvgNotChanged();
double stats::calcAvgNotChanged(part *head);

Function Description:
This function starts at the head of the linked list and calculates the average percent change between forecast
for parts that had the same model used to produce each forecast.

Example:
Linked List called myLinkedList.
double avgNotChanged = myLinkedList -> calcAvgNotChanged(); //(called from main)
->
double avgNotChanged = calcAvgNotChanged(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
A double of the average percent change in the forecasted number of parts that had the same model used to produce
each of its forecast is returned for what ever purpose the end-user desires.
*/

double stats::calcAvgNotChanged()
{
	double avgNotChanged = calcAvgNotChanged(head);
	return avgNotChanged;
}

double stats::calcAvgNotChanged(part *head)
{
	part *z = head;
	double counter = 0.0;
	double sumOfPercentChanged = 0.0;
    double average = 0.0;
    while(z != NULL)
    {
        if(z -> modelChanged == false)
        {
			sumOfPercentChanged = sumOfPercentChanged + z -> percentChange;
			counter++;
		}
        z = z->next;
    }
    return average = sumOfPercentChanged/counter;
}

/*
Function Prototype:
double stats::stdvChanged();
double stats::stdvChanged(part *);

Function Description:
This function calculates the standard deviation for parts forcast when a different model was used to forcast
the first and second runs.

Example:
Linked List called myLinkedList.
double stdvChanged = myLinkedList->stdvChanged(); //(called from main)
->
double calcStdvChanged = stdvChanged(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
A double is returned for the standard deviation of forcast parts that changed when a different model was used between runs for what ever
purpose the end-user desires.
*/

double stats::stdvChanged(){
    double calcStdvChanged = stdvChanged(head);
    return calcStdvChanged;
}

double stats::stdvChanged(part *head){
  part *z = head;
  double mean = calcAvgChanged();
  double squaredSumOfDevFromMean = 0.0;
  int counter = 0;
  while(z != NULL){
    if(z->modelChanged == true){
        squaredSumOfDevFromMean = squaredSumOfDevFromMean + (z->percentChange - mean)*(z->percentChange - mean);
        counter++;
    }
    z = z->next;
  }
  double stdDev = sqrt(squaredSumOfDevFromMean/counter);
  return stdDev;
}

/*
Function Prototype:
double stats::stdvNotChanged();
double stats::stdvNotChanged(part *);

Function Description:
This function calculates the standard deviation for parts when the same model was used to
produce a forecast for the first and second run.

Example:
Linked List called myLinkedList.
double stdvNotChanged = myLinkedList->stdvNotChanged(); //(called from main)
->
double calcStdvNotChanged = stdvNotChanged(head); //(called inside the public function)

Pre-conditions:
The linked list has been built and the attributes of each parts node have been populated.

Post-conditions:
A double for the std dev for parts that did not changed which model was used between runs is returned for
what ever purpose the programmer desires.
*/

double stats::stdvNotChanged(){
    double calcStdvNotChanged = stdvNotChanged(head);
    return calcStdvNotChanged;
}

double stats::stdvNotChanged(part *head){
    part *z = head;
  double mean = calcAvgNotChanged();
  double squaredSumOfDevFromMean = 0.0;
  int counter = 0;
  while(z != NULL){
    if(z->modelChanged == false){
        squaredSumOfDevFromMean = squaredSumOfDevFromMean + (z->percentChange - mean)*(z->percentChange - mean);
        counter++;
    }
    z = z->next;
  }
  double stdDev = sqrt(squaredSumOfDevFromMean/counter);
  return stdDev;
}

/*
Function Prototype:
double stats::findMaxUnitChange();
double stats::findMaxUnitChange(part *)

Function Description:
This function starts at the head of the linked list and finds the part (node) which has the largest
unit change (difference) between forecast 1 and forecast 2.

Example:
double maxUnitChange = myLinkedList->findMaxUnitChange(); //Linked List called myLinkedList.
(called from main)
->
double maxUnitChange = findMaxUnitChange(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
A double of the largest unit change in forecasted amount is returned for what ever purpose the
programmer desires.
*/

double stats::findMaxUnitChange(){
    double maxUnitChange = findMaxUnitChange(head);
    return maxUnitChange;
}

double stats::findMaxUnitChange(part *head){
    part *z = head;
    double maxUnitChange = 0.0;

    while(z != NULL){
        if(abs(z->run1Forc - z->run2Forc) > maxUnitChange){
            maxUnitChange = abs(z->run1Forc - z->run2Forc);
        }
        z = z->next;
    }
    return maxUnitChange;
}

/*
Function Prototype:
double stats::findMaxPercentChange();
double stats::findMaxPercentChange(part *)

Function Description:
This function starts at the head and calculates the maximum percent change in the number of parts forecasted
for a particular part (node) between forecast 1 and forecast 2.

Example:
Linked List called myLinkedList.
double maxPercentChange = myLinkedList->findMaxPercentChange(); //(called from main)
->
double maxPercentChange = findMaxPercentChange(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
A double of the maximum percent change between statistical forecasts is returned for what ever purpose the
end-user desires.
*/

double stats::findMaxPercentChange(){
    double maxPercentChange = findMaxPercentChange(head);
    return maxPercentChange;
}

double stats::findMaxPercentChange(part *head){
    part *z = head;
    double maxPercentChange = 0.0;

    while(z != NULL){
        if(z->percentChange > maxPercentChange){
            maxPercentChange = z->percentChange;
        }
        z = z->next;
    }
    return maxPercentChange;
}

/*
Function Prototype:
int stats::countForecastChangeOver20P();
int countOver20Percent = countForecastChangeOver20P(head);

Function Description:
This function starts at the head of the linked list and counts the number of parts (nodes) that have a
percent change of less than 20% between the first and second run. 20% was picked picked because this might be
considered a reasonable amount of fluctuation between forecasts.

Example:
Linked List called myLinkedList.
int counterPartsOver20Percent = myLinkedList->countForecastChangeOver20P(); //(called from main)
->
int countOver20Percent = countForecastChangeOver20P(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
An integer count of the number of parts that had forecasts that changed less than 20%
is returned for what ever purpose the end-user desires.
*/

int stats::countForecastChangeOver20P(){
    int countOver20Percent = countForecastChangeOver20P(head);
    return countOver20Percent;
}

int stats::countForecastChangeOver20P(part *head){
    part *z = head;
    int counter = 0;
    while(z != NULL){
        if(z->percentChange > .2){
            counter++;
        }
        z = z->next;
    }
    return counter;
}

/*
Function Prototype:
int stats::countForcFrom0();
int stats::countForcFrom0(part *);

Function Description:
This function starts at the head of the linked list and counts the number of parts that had a zero forecast
for run 1 and had a forecast of greater than 0 for run 2. This is important because we are counting these as
a 100% change in value which might not be the best way to treat these instances if this occurs frequently.
This function ends up telling us that only 5 parts meet this criteria so our way of handling these parts is fine
since there are so few of them.

Example:
Linked List called myLinkedList.
int countFrom0 = myLinkedList->countForcFrom0(); //(called from main)
->
int countFrom0 = countForcFrom0(head); //(called inside the public function)

Pre-conditions:
The linked list has been instantiated and the attributes of each parts node have been assigned.

Post-conditions:
An integer of the count of the number of nodes in the linked list (parts) that have a forecast of 0 for run 1
and a forecast grater than 0 for run 2 is returned for what ever purpose the end-user desires.
*/

int stats::countForcFrom0(){
    int countFrom0 = countForcFrom0(head);
    return countFrom0;
}

int stats::countForcFrom0(part *head){
    part *z = head;
    int counter = 0;
    while(z != NULL){
        if(z->run1Forc == 0 && z->run2Forc != 0){
            counter++;
        }
        z = z->next;
    }
    return counter;
}
