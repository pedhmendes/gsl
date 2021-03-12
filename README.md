# Gnu Scientific Library

## The Library
<ul><p>A good tool for scientific programmin in C is GNU Scientific Library (GSL). In this page I will leave some codes where some simple functions can be implemented. More informantion can be found in this <a href="https://www.gnu.org/software/gsl/">link</a>.</p></ul>

<ul><p>If you don't have the library installed, open a terminal and type.</p></ul>

<ul><pre><code>sudo apt-get update
sudo apt-get install libgsl-dev</code></pre></ul>

<ul><p>GSL requires some special flags when compiling, take an example</p></ul>

<ul><pre><code>gcc programa.c -lgsl -lgslcblas -lm -static</code></pre></ul>

<ul><p>The last flag is important if you are using some cluster.</p></ul>

## Examples
  
### 01-Coupled ODEs
In physics there are some times we find some coupled ODE that we want to solve. Some can be a little bit trick to write an actual algorithm. We can use GSL to solve. In this repo you can find an code where I use the <a href="https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta%E2%80%93Fehlberg_method">Runge-Kutta-Fehlberg</a> method to solve the <a href="https://en.wikipedia.org/wiki/Compartmental_models_in_epidemiology">SIR</a> epidemiology model. All methods and more info in ODE resolution can be found <a href="https://www.gnu.org/software/gsl/doc/html/ode-initval.html">here</a>.
  
  
### 02-Random Number Generator
Is not very hard to write linear congruential generator (LCG), but, for cientifical reasons, they can't be taken very serious. GSL library has a list of good RNG that we can use. In this repo you can find an example where I introduce some basic rng functions that GLS has to offer. I choose the <a href="https://en.wikipedia.org/wiki/Mersenne_Twister">Mersenne Twister</a> because it has and period of (2<sup>19937</sup> - 1) and good proprieties. More options of RNG can be found <a href="https://www.gnu.org/software/gsl/doc/html/rng.html">here</a>.

### 03-Numbers Following Distributions
It can be convinient that we generate numbers following some distribution, GSL can do it. This special generators requires and random number as seed, then they return another number following the desired distribution. So we need the RNG, we talked about this above, and we can use one of GSL. We are gonna give the pointer as argument of the function, is not difficult as it sounds. As example there is a code in this repo that uses the <a href="https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform">Box-Muller</a> method to generate numbers following the Gaussian Distribution. You can check this making and histogram. More information about this generators and more avaiable distributions can be found <a href="https://www.gnu.org/software/gsl/doc/html/randist.html">here</a>.


