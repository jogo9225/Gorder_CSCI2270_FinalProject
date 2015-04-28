Project Summary

J&C Inc is an automobile parts manufacturer. In order to have the right amount of material 
to build their parts, this company needs to produce forecasts of how many parts they are 
going to sell over the next year. J&C uses a statistical engine to produce forecasts 
of how many parts they expect to sell over the next year for each individual part that 
they manufacture. This statistical engine uses historic data on the sales of the parts 
over the last year, runs multiple forecasting models, picks the forecasting model that fits
best with that part’s historic data, and outputs a forecast based on that model. J&C runs 
the statistical engine once per month in order to update the historic data with the most 
recent sales. Unfortunately, J&C’s statistical engine is liable to have huge swings in the 
number of parts forecasted from month to month. 

Two researchers want to investigate how large the swings are on an individual part basis. 
They also wants to investigate whether changing between the forecasting model used for each 
part affects the magnitude of the swing in the number of that part forecasted. 

Definitions from 'data.txt'

*Column 1: four digit number read in as 'partNumber' in the part struct.
This is the unique part number. E.g. part 3109 is an alternator belt; part 4204 is a CV joint. 

*Column 2: integer amount of number of a particular part in the first forecast read in as 
'run1Forc' in the part struct.

*Column 3: integer amount of number of a particular part in the second forecast read in as 
'run2Forc' in the part struct.

*Column 4: model acronym read in as 'model1' in the part struct.  This is the statistical 
forecasting model used for the first run of a particular part. E.g. 'H' is a Holt Model,
'R' is a regression model. 

*Column 5: model acronym read in as 'model2' in the part struct. This is the statistical 
forecasting model used for the second run of a particular part. 

*Note: any particular model may have been used for the first or second run or both.  

How to Run

To run this program you will need four things: 

1. data.txt
2. main.cpp
3. models.cpp
4. models.h

We have been running the program from the terminal: 

After setting the project folder to your working directory and ensuring the data.txt file is in 
the folder: 

Compil with: g++ models.cpp main.cpp -std=c++11
Run with: ./a.out

Dependencies

No dependencies. Several libraries are used and included in the standard way.

SystemRequirements

This program was built on Linux but should run fine on Windows or iOS. 

Group Members

Joel Gorder and Christopher Sichko

Contributors

N/A

Open issues/bugs

There is a significant bug in the program. We are not able to calculate the percent change as a double. 
Moreover, c++ is not rounding, it is using a floor function - rounding down. So all of our 
calculations are slightly wrong. We will also upload an excel file that shows that the proper 
output for the various calculations. 

