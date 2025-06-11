# Using the Monte Carlo method for option pricing applications.

import numpy as np

def mc_asset (Sell, Volatility, Time, Ks, r, Nsteps, Nrep):
    SPATH = np.zeros((Nrep, 1 + Nsteps))
    SPATH[:, 0] = Sell
    dt = Time/Nsteps
    nudt = (r - 0.5 * Volatility **2) * dt
    sidt = Volatility * np.sqrt(dt)

    for i in range(0, Nrep):
        for j in range(0, Nsteps):
            SPATH[i, j+1] = SPATH[i, j] * np.exp(nudt + sidt * np.random.normal())
            return SPATH

Sell = 100.0 # Price of underlying asset = $100
Volatility = 0.25 # lower case sigma symbol = 25%
Time = 90 # Time until expiration = 90 Days
Ks = 110 # Strike price = $110
r = 0.05 # Risk-free rate = 5%
Nsteps = 10000 # Numbers of time interval
Nrep = 1000 # Numbers of stock path
SPATH = mc_asset(Sell, Volatility, Time, Ks, r, Nsteps, Nrep)

def mc_options(SPATH, Ks, Sell, r, Volatility, Time, Nsteps, Nrep):
    temp1 = np.maximum(SPATH[:,-1] - Ks, 0)
    temp2 = np.maximum(Ks - SPATH[:,-1] - Ks, 0)
    Calls = np.mean(temp1) * np.exp(-r * Time)
    Puts = np.mean(temp2) * np.exp(-r * Time)
    return Calls, Puts

CnP = mc_options(SPATH, Ks, Sell, r, Volatility, Time, Nsteps, Nrep)

print(f'Calls: {CnP[0]}')
print(f'Puts: {CnP[1]}')
