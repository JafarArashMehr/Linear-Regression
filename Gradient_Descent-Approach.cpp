#include <iostream>
#include "/Users/jafararashmehr/Desktop/ML_C++/libs/dlib/matrix.h"
#include <vector>

using namespace std;


std::vector<std::vector<double>> x_values = {
            
            { 1, 1 },
            { 1, 2 },
            { 1, 3 }

        };

std::vector<double> y_values = { 6, 11, 16};


float lambda = 0.001;
int iterations = 50000;  



static constexpr uint8_t number_of_data = 3;
static constexpr uint8_t dimensions = 2;

dlib::matrix<float, number_of_data, dimensions> matrix_x;
dlib::matrix<float, number_of_data, 1> matrix_y_real;
dlib::matrix<float, number_of_data, 1> matrix_y_predict;

float gamma; 
std::vector<double> alpha = {0, 0};


std::vector<double> new_values_to_predict = {1, 4};

float predict (std::vector<double> coefficients,std::vector<double> new_inputs){
    
float new_predict;
    for (int p = 0 ; p < new_inputs.size(); p++){
        new_predict += coefficients[p] * new_inputs[p];
    }
    return new_predict; 
}

int main(){

for (int i = 0 ; i < number_of_data ; i++){

    for (int j = 0 ; j < dimensions ; j++){

        matrix_x(i,j) = x_values [i][j];
    }
}

for (int k = 0 ; k < number_of_data ; k++){
        matrix_y_real(k,0) = y_values[k];
}


/////////////////////////////////////
////////////////////////////////////

for (int f = 0 ; f < iterations ; f++){

    for (int r = 0 ; r < number_of_data ; r++){
        matrix_y_predict(r,0) = 0;
    }


    for (int m = 0 ; m < number_of_data ; m++){
        for (int n = 0 ; n < dimensions ; n++){

            
            matrix_y_predict(m,0) += alpha[n] * x_values[m][n];
        }
    }


    for (int p = 0 ; p < dimensions; p++){


        for (int q = 0 ; q < number_of_data ; q++){
            
            
            gamma +=  (matrix_y_predict(q,0) - matrix_y_real(q,0)) * matrix_x(q,p);

        }

        alpha [p] = alpha [p] - (2./number_of_data) * lambda * gamma;

        gamma = 0;

        }

    cout << "alpha 1 is: " << alpha[0] << endl;
    cout << "alpha 2 is: " << alpha[1] << endl;

    }

    cout << "The predicted value is: " << predict (alpha,new_values_to_predict ) << endl;


        return 0;
}