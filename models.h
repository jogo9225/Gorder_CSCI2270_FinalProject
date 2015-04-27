//Project by Joel Gorder and Christopher Sichko
// 4/26/2015

#ifndef MODELS_H
#define MODELS_H

#include<iostream>
#include<cmath>

struct part{
    int partNumber;
    double run1Forc = 0.0;
    double run2Forc = 0.0;
    std::string model1;
    std::string model2;
    part *next;
    bool modelChanged;
    double percentChange = 0.0;

    part(){};

    part(int in_partNumber, double in_run1Forc, double in_run2Forc, std::string in_model1,
    std::string in_model2){
        partNumber = in_partNumber;
        run1Forc = in_run1Forc;
        //std::cout << run1Forc << " ";
        run2Forc = in_run2Forc;
        model1 = in_model1;
        model2 = in_model2;
        modelChanged = (model1 != model2);
        if(run1Forc != 0.00000){ //*** THIS IS WHERE THE BUG IS*** or possibly in the way that the data is read in... 
			//We think that 'string to doboule' (stod) may not be correctly transforming the data into doubles.
            percentChange = abs((run2Forc-run1Forc)/run1Forc);
            //std::cout << percentChange << " ";
        }
        else if(run2Forc == 0.0){ //this is the case when both run1 and run2 have 0's
            percentChange = 0.0;
            //std::cout << percentChange << " ";
        }
        else{ //this is the case that run1 is 0 and run2 is not. We are calling this a 100% change which is perhaps not the best way to handle this.
            percentChange = 1.0;
            //std::cout << percentChange << " ";
        }
    }


};

class stats{
    public:
        stats();
        virtual ~stats();
        void addPartsNode(int partNumber, double run1Forc, double run2Forc, std::string model1,
        std::string model2); //#1 public function
        int countNodes(); //#2 public function
        int countNumbOfModelsChanged(); //#3 public function
        double calcAvgPercentChange(); //#4 public function
        double calcAvgChanged(); //#5 public function
		double calcAvgNotChanged(); //#6 public function
		double stdvChanged(); //#7 public function
		double stdvNotChanged(); //#8 public function
		double findMaxUnitChange(); //#9 public function
		double findMaxPercentChange(); //#10 public function
		int countForecastChangeOver20P(); //#11 public function
		int countForcFrom0(); //#12 public function

    protected:
    private:
        part *head;
        int countNodes(part *head);
        int countNumbOfModelsChanged(part *head);
        double calcAvgPercentChange(part *head);
        double calcAvgChanged(part *head);
        double calcAvgNotChanged(part *head);
        double stdvChanged(part *head);
		double stdvNotChanged(part *head);
		double findMaxUnitChange(part *head);
		double findMaxPercentChange(part *head);
		int countForecastChangeOver20P(part *head);
		int countForcFrom0(part *head);
};

#endif // MODELS_H
