#include <iostream>
#include <vector>

using namespace std;

// Here we define 3 input data corresponding to the independent variable (1,2,3).
// Each data should be stored in a vector starting with number 1
vector<vector<double>> x_values = {

            { 1, 1 },
            { 1, 2 },
            { 1, 3 }

      };

// Here we define 3 values corresponding to the dependent variable (6,11,16).
vector<double> y_values = { 6, 11, 16};

// Here we define the learning rate.
float lambda = 0.001;

// Here we define the number of iteration.
int iterations = 50000;

int number_of_data = 3;
int dimensions = 2;
////////////////////////////////////////////////////
vector<vector<double>> matrix_x;

vector<double> matrix_y_real;

vector<double> matrix_y_predict;
////////////////////////////////////////////////////

float gamma;
vector<double> alpha = {0, 0};


vector<double> new_values_to_predict = {1, 4};

float predict (vector<double> coefficients,vector<double> new_inputs){

float new_predict;
   for (int p = 0 ; p < new_inputs.size(); p++){
      new_predict += coefficients[p] * new_inputs[p];
   }
   return new_predict;
}

int main(){

for (int i = 0 ; i < number_of_data ; i++){

   matrix_x.push_back(vector<double>());
   
   for (int j = 0 ; j < dimensions ; j++){

      matrix_x[i].push_back(x_values[i][j]);
   }
}

for (int k = 0 ; k < number_of_data ; k++){
      matrix_y_real.push_back(y_values[k]);
      matrix_y_predict.push_back(0);
}

////////////////////////////////////

for (int f = 0 ; f < iterations ; f++){


   for (int m = 0 ; m < number_of_data ; m++){

    float result = 0;
      for (int n = 0 ; n < dimensions ; n++){

        result += alpha[n] * matrix_x[m][n];
      }
        matrix_y_predict[m] = result;
   }


   for (int p = 0 ; p < dimensions; p++){


      for (int q = 0 ; q < number_of_data ; q++){


            gamma +=  (matrix_y_predict[q] - matrix_y_real[q]) * matrix_x[q][p];

      }

      alpha [p] = alpha [p] - (2./number_of_data) * lambda * gamma;

      gamma = 0;

      }

   cout << "Iteration number: " << f << endl;
   cout << "alpha 1 is: " << alpha[0] << endl;
   cout << "alpha 2 is: " << alpha[1] << endl;

   }

   cout << "The predicted value is: " << predict (alpha,new_values_to_predict ) << endl;


      return 0;
}
