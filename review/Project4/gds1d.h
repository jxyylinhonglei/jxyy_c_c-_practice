/*****************************************************************************/
/*                                                                                                                                                      */
/*  Copyright 2018                                                                                                                        */
/*  Feng zhou                                                                                                                                 */
/*  peakzhou@csu.edu.cn                                                                                                             */
/*                                                                                                                                                       */
/*****************************************************************************/

#ifndef GDS1D_H
#define GDS1D_H

//C++
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
//local
#include "em.h"
#include "point.h"
#include "tnm.h"

class GDS1D
{
public:
    GDS1D(const std::vector<std::vector<Real> >& electric_parameters,
          const Real  frequency,
          const int    _n = 7,
          const Real _R=6.371E6);
    ~GDS1D();
    void xyz_r_theta_phi(const double x, const double y, const double z,
                         Real& r0,
                         Real& theta,
                         Real& phi);
    int p_in_which_layer(const Point& p);
    // Compuate E and H at a given point.
    void compute_E_H(const Point& p);
    //Compute the E and H at Point p
    void compute_oblique_E_H(const Point& p);
    // Compute the C response function
    void compute_C_function(const Point& p);
    //Compute the C response function at  the Point p
    void compute_oblique_C(const Point& p);
    // A routine to calculate and print the field component and C response function's values  on the surface
    friend std::ostream& operator <<(std::ostream& os, const GDS1D& loe);
    //
    //get a vector for n order sphercial bessel function
    void compute_sfunc_R(const unsigned int _Nmax,  unsigned int l, EigenDenseVector& _R);
    //get sub the n order spherical bessel function
    Dcomplex compute_sfunc_subR(unsigned int l, int _n);
    //get a vector for n order spherical bessel function derivate
    void compute_sfunc_dR(const unsigned int _Nmax,  unsigned int l, EigenDenseVector& dR);
    //get sub the n spherical bessel function derivate
    Dcomplex compute_sfunc_subdR(unsigned int l, int _n);
    //compute spherical bessel function jn(x)
    void compute_sfunc_j_dj(unsigned int l,  Dcomplex& jn, Dcomplex& djn, int _order,  bool flag);
    //compute spherical bessel function yn(x)
    void compute_sfunc_y_dy(unsigned int l, Dcomplex& yn, Dcomplex& dyn, int _order,  bool flag);
    // Associated Legendre polynomials Pnm(x) and dPnm(x)/dx
    // Pnm(x) = (1-x^2)^(m/2)dm/dx^m Pn(x)
    // checked
    void Pnm(const unsigned int _Nmax, const double theta,
              Tnm<double>& pnm,  Tnm<double>& dpnm);
    // Associated Legendre polynomials Ynm(theta,phi) , dYnm(theta, phi)/dtheta and dYnm(theta, phi)/dphi
    //Ynm(theta,phi)=sqrt((2n+1)*(n-m)!/(4*pi*(n+m)!))Pnm(cos(theta))e^imphi
    // checked
    void Ynm(const unsigned int _Nmax, const double theta, const double phi,TnmC&  ynm,
              TnmC& dynm_theta, TnmC& dynm_phi);
    // init
    void init();
    // transform electric_parameters to wavenumber, admittivity, impedivity etc.
    void inner_parameters(const std::vector<std::vector<Real> >& ep,
                          const Real frequency);
    // checked
    double factorial(int n);
    //
    Dcomplex get_z0() { return z_hat[0]*-1.0; } /*Please note that in other codes, we use*/
                                                /*z_hat =  i*omega*\mu */
                                                /*in this class, we use z_hat = -1*omega*\mu */
                                                /*so, there is a -1.0 in this return */
                                                /*which will be used by other class's subroutines*/
    Dcomplex get_y0() { return y_hat[0]; }
    Dcomplex get_k0() { return k[0]; }
public:
    unsigned int                          N; /*N-layer earth model*/
    std::vector<Dcomplex>        k; /*k=a+b*i,a>0,b>0, k^2 = -z_hat*y_hat*/
    std::vector<Dcomplex>        z_hat; /*z_hat = -i*omega*\mu*/
    std::vector<Dcomplex>        y_hat; /*y_hat = sigma-i*omega*epsilon*/
    std::vector<double>             radius;/*r is spherical's radius*/
    std::vector<double>             depth;
    std::vector<double>             h;/*thickness of each spherical shell */
    std::vector<Dcomplex>       z;/*z=kr,k=a+b*i,r is radius*/
    unsigned int                          Nmax;/*spherical bessel function order number n*/
    Real                                        R;/*the earth's radius*/
    Real                                        freq;/*excited frequency*/
    bool                                         flag_init=false; /* init : conpute A and B coefficient; other flag_init =true*/
    std::vector<std::vector<Dcomplex> >      A, B; /*a pair of coefficients in each layer*/
    // fast power function for (-1)^n
    double minus_one_power(const int m);
        //---------speical for a given p for spherical coordinate system----------
    // electric fields E
    std::vector<Dcomplex>        E_s;  //E_theta, E_phi, E_r
    // magentic fields H
    std::vector<Dcomplex>        H_s; //H_theta, H_phi, H_r

    //--------speical for a given for cartesian coordinate system
    //electric fields E
    std::vector<Dcomplex>       E_c;
    //magnetic fields H
    std::vector<Dcomplex>       H_c;
    //----------C-respone function
    std::vector<Dcomplex>       C;

};

inline
GDS1D::~GDS1D()
{
    E_s.clear(); H_s.clear();
    E_c.clear(); H_c.clear();
    C.clear();
}
#endif // GDS1D_H
