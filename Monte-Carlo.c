// Using the Monte Carlo method for option pricing applications.

#include <stdio.h>
#include <math.h>

int main () {

    double Sell = 100.0; // Price of underlying asset = $100
    double Volatility = 0.25; // lower case sigma symbol = 25%
    double Time = 90; // Time until expiration = 90 Days
    double Ks = 110; // Strike price = $110
    double r = 0.05; // Risk-free rate = 5%
    double Nsteps = 10000;
    double Nrep = 1000;

    double Calls = (Sell - Ks) * exp(-r * Time);
    double Puts = (Ks - Sell) * exp(-r * Time);

    printf("Call option price: %lf\n", Calls);
    printf("Put option price: %lf", Puts);

}
