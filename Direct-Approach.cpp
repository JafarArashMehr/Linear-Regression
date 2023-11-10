#include <iostream>
#include "/Users/jafararashmehr/Desktop/ML_C++/libs/dlib/matrix.h"
#include <vector>

using namespace std;
// Here we define 3 input data corresponding to the independent variable (1,2,3). 
// Each data should be stored in a vector starting with number 1
std::vector<std::vector<double>> x_values = { 
            
            { 1, 1 },
            { 1, 2 },
            { 1, 3 }

        };

// Here we define 3 values corresponding to the dependent variable (6,11,16).         
std::vector<double> y_values = { 6, 11, 16};

static constexpr uint8_t number_of_data = 3;
static constexpr uint8_t dimensions = 2;

dlib::matrix<float, number_of_data, dimensions> matrix_x;
dlib::matrix<float, number_of_data, 1> matrix_y;

class Linear_Regression {

    public:
    dlib::matrix<float, dimensions, 1> return_alpha (std::vector<std::vector<double>> vec_x, std::vector<double> vec_y){

    for (int i = 0 ; i < number_of_data ; i++){
        for (int j = 0 ; j < dimensions ; j++){
         matrix_x(i,j) = vec_x[i][j];
        }
    }
    for (int k = 0 ; k < number_of_data ; k++){
         matrix_y(k,0) = vec_y[k];
        }
    
    return inv(trans(matrix_x) * matrix_x) * trans(matrix_x) * matrix_y;       

    };
};
    
float predict (dlib::matrix<float, dimensions, 1> coefficients,std::vector<double> new_inputs){
    
    float new_predict;
    for (int p = 0 ; p < new_inputs.size(); p++){
        new_predict += coefficients(p,0) * new_inputs[p];
    }
    return new_predict; 
}
int main(){

    Linear_Regression lg;

    dlib::matrix<float, dimensions, 1> alpha = lg.return_alpha(x_values,y_values); 

    cout << "The calculated coefficients are: " << endl;
    for (int z = 0 ; z < alpha.size() ; z++){

        cout << alpha(z,0) << endl;
        }
// Here we define new independent variable (4) to predict the dependent variable. 
// This new value should be stored in a vector starting with number 1
std::vector<double> new_values_to_predict = {1, 4};

cout << "The predicted value is: "  << predict (alpha,new_values_to_predict ) << endl;

        return 0;
}