#include <iostream>
#include <cmath>
#include<math.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstring> 
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iterator>


using namespace std;

double compute_cost(vector <double> &y_pred,vector <double> &y){
    double cost = 0.0;
    for(int i= 0; i<y.size();i++){
        cost += pow(y_pred[i]-y[i],2.0);
    }
    return cost/(y.size()*2.0);
}

double sigmoid(double linear){
	return 1/(1+exp(-linear));
}

void pred_y(vector<double> &weights, vector<vector<double> > &X,vector <double> &y,double bias,int iterations, double learning_rate,string type){
    int m = y.size();
    int n = weights.size();
    for (int iter = 0; iter < iterations;iter++){
        vector <double> y_pred;
        for(int i = 0; i<m; i++){
            double linear = bias;
            for (int j = 0;j<n;j++){
                linear += weights[j]*X[i][j];
            }
            if (type == "logistic"){
            	linear = sigmoid(linear);
			}
            y_pred[i] = linear;
        }
        // if error > last_error: STOP
        for (int i= 0;i<m;i++){
			for (int j = 0;j<n;j++){
				weights[j] += learning_rate*(y[i]-y_pred[i])*X[i][j];// Burada problem olabilir.
			}
		}
    }
}

void predict(vector<double> &weights, vector<vector<double> > &X_test,vector <double> &y_test,double bias, vector <double> &y_pred_test,string type){
    int m = y_test.size();
    int n = weights.size();
    for(int i = 0;i<m;i++){
        y_pred_test.push_back(bias);
        for(int j= 0;j<n;j++){
        	
            y_pred_test[i] += weights[j]*X_test[i][j];
            if(type == "logistic"){
            	y_pred_test[i] = sigmoid(y_pred_test[i]);
            	if (y_pred_test[i] <0.5) y_pred_test[i] = 0;
            	else y_pred_test[i];
			}
        }
    }
}


std::vector<double> getNextLineAndSplitIntoTokens(std::istream& str)
{
    std::vector<double>   result;
    std::string                line;
    std::getline(str,line);

    std::stringstream          lineStream(line);
    std::string                cell;

    while(std::getline(lineStream,cell, ','))
    {
    	double n = strtod(cell.c_str(),NULL);
        result.push_back(n);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back(0);
    }
    return result;
}
int main(){
	
	string myText;
	ifstream file; 

    	const char* filename = "clean_data.csv"; 
  
    // Attempt to open the file 
    file.open(filename); 
    cout << "sleam";
    // Check if the open operation failed 
    if (!file.is_open()) { 
        cerr << "Error opening file: " << filename 
             << std::endl; 
  
        // Check for specific error conditions 
        if (file.bad()) { 
            cerr << "Fatal error: badbit is set." << endl; 
        } 
  
        if (file.fail()) { 
            // Print a more detailed error message using 
            // strerror 
            cerr << "Error details: " << strerror(errno) 
                 << endl; 
        } 
        // Handle the error or exit the program 
        return 1;
    } 
  
    // File opened successfully, continue processing... 
    int j = 1,k=1;
	vector <vector<double> > X_train,X_test;
	vector <double> y_train,y_test;
	vector <double> add_vector,weights,y_pred;
	for (int i = 0; i<12;i++){
		weights.push_back(0);
	}
	
	vector<vector<string> > lines;
	std::vector<double>   result;
	getNextLineAndSplitIntoTokens(file);
	result = getNextLineAndSplitIntoTokens(file);
	y_train.push_back(result[j]);
	j = 2;
	for(int i =0;i<4600*13;i++){
		if (j%14 == 0){
			j= 1;
			result = getNextLineAndSplitIntoTokens(file);
			k++;
			
			if(k <250){
				y_train.push_back(result[j]);
				X_train.push_back(add_vector);	
			}
			else{
				y_test.push_back(result[j]);
				X_test.push_back(add_vector);
			}
			add_vector.clear();
		}
		else{
			add_vector.push_back(result[j]);
		}
		j++;
	}
	pred_y(weights,X_train,y_train,0,1, 0.15,"linear");
	predict(weights,X_test,y_test,0,y_pred,"linear");
	std::copy(X_test[0].begin(), X_test[0].end(), ostream_iterator<double>(std::cout, " "));
    // Close the file when done 
    file.close(); 
    
	return 0;
}