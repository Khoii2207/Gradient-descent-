#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
                    GRADIENT DESCENT USING C++
                                                                 */
// data
vector<float> Pounds = {3.5, 3.69, 3.44, 3.43, 4.34, 4.42, 2.37};
vector<float> Mile_per_gallon = {18, 15, 18, 16, 15, 14, 24};

int main()
{
    double m = -2.4, b = 13; // given weight and bias
    double prediction = 0;
    double L1_loss = 0;
    double L2_loss = 0;
    for(int i = 0 ; i < 7 ; i++) 
    {
        prediction = m * Pounds[i] + b;
        L2_loss += pow((Mile_per_gallon[i] - prediction), 2); 
        L1_loss += abs(Mile_per_gallon[i] - prediction);
    }
    cout << "L1 loss: " << L1_loss << '\n';     // calculate L1 loss
    cout << "L2 loss: " << L2_loss << '\n';    // calculate L2 loss

    // gradient descent
    m = 0.0;
    b = 0.0;
    double Loss = 0;
    int i = 0;
    double learning_Rate = 0.003;
    for(int j = 0; j < 100 ; j++) 
    {
        double Delta_m = 0.0;
        double Delta_b = 0.0;
        Loss = 0;
        for(int i = 0 ; i < 7 ; i++) 
        {
            double Prediction = m * Pounds[i] + b; // guessing part
            double Error = Prediction -  Mile_per_gallon[i];
            Loss += pow((Mile_per_gallon[i] - Prediction), 2);  // L2 loss
            // we need to minimize loss.
            Delta_m +=  (Error) * Pounds[i]; // adjust weight
            Delta_b +=  (Error); // adjust bias

        }
        m -= Delta_m * learning_Rate ; // the "-" sign show that weight and bias change to minimize loss function (go down hill) 
        b -= Delta_b * learning_Rate ;
        // we print 10 times to show the decrease of Loss
        if(j >= 0 && j <= 9){
            cout << "Loss " << j + 1 << ": " << Loss << '\n' ;
        }
    }

    cout<< "New weight: " << m << " " << "New bias: " << b << '\n'; // the final weight and bias used for predicting
    // predict
    double x_test = 3.67;
    double y_pre = m * x_test + b;
    cout << "Prediction for x_test = 3.67: " << y_pre << '\n'; 
    return 0;
}