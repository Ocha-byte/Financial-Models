// Using the Black-Scholes method for option pricing applications.

#include <stdio.h>
#include <math.h>

double normalCDF (double input); // Prototype.

int main () {

    double Sell = 100.0; // Price of underlying asset = $100
    double Volatility = 0.25; // lower case sigma symbol = 25%
    double Time = 90; // Time until expiration = 90 Days
    double Ks = 110; // Strike price = $110
    double r = 0.05; // Risk-free rate = 5%

    // Risk-adjusted probability of receiving stock at expiration
    double d1 = (log(Sell/Ks) + (r + (pow(Volatility,2)/2)) * Time) / (Volatility * sqrt(Time));
    double Nd1 = normalCDF(d1);

    // Risk-adjusted probability of the option will be exercised.
    double d2 = Nd1 - Volatility * sqrt(Time);
    double Nd2 = normalCDF(d2);

    // Calculate fair value of the European calls and puts
    double Calls = Nd1 * Sell - Ks * exp(-r * Time) * Nd2;
    double Puts = Ks * exp(-r * Time) * normalCDF(-d2) - Sell * normalCDF(-d1);

    printf("Call option price: %lf\n", Calls);
    printf("Put option price: %lf", Puts);

}

// Cumulative Normal Distribution Function
double normalCDF (double input) {
    return 0.5 * erfc(-input * M_SQRT1_2);
}
