/*****************************************************************************/
/*                                                                                                                                                      */
/*  Copyright 2017                                                                                                                       */
/*  Feng Zhou                                                                                                                                */
/*  peakzhou@csu.edu.cn                                                                                                            */
/*                                                                                                                                                      */
/*****************************************************************************/
//This class offers Marine control source electricmagnetic fields (E , H and A) at a given point P by the vector potential(Lorenz gauged)
//the excited source is dipole point source
// the formula from Kerry Key(2009,geophysics)
// N=1, the half-space model

// usage:
// exp(-i*w*t)
// +z downward, z=0 is the flat air-earth-interface
//written by Feng Zhou, 11/29/2017
// !!!!!!!!!!!!!
// Please note, we define z_hat = -i*omega*mu, please do not use the sub-routines
// outside this class BC_CSEM!

#ifndef BC_CSEM_H
#define BC_CSEM_H
#include <cmath>
#include <vector>
#include <iostream>
#include "em.h"
#include "point.h"
#include "hankel_integral.h"

class BC_CSEM
{
public:
    BC_CSEM(const std::vector<std::vector<Real> >& electric_parameters,
        const Real frequency, const unsigned int p_hankel);
    ~BC_CSEM();
    // init
    void init(const Real lamda);
    void set_source(const Point& _p);
    //
    void get_A(std::vector<Dcomplex>& a) { a = this->potentialA; }
    // void get_CoulombA(ComplexPoint& a){a=this->_CoulombA;}
    void get_E_H(std::vector<Dcomplex>& e, std::vector<Dcomplex>& h)
    {
        e = this->E;  h = this->H;
    }
    //void get_Curl_A(ComplexPoint& Curl_a) {Curl_a = this->_Curl_A;}
    void get_grad_A(std::vector<Dcomplex>& grada) { grada = this->gradA; }
    int p_in_which_layer(const Point& p);
    //Compute E and H at a given point.
    void compute_E_H(const Point& p);
    //Compute Rotation A potential
    ComplexPoint  compute_Curl_A_potential(const Real _J0, const Real _J1, const Real lamda, const Point& p);
    // Compute A at a given point
    ComplexPoint  compute_A_potential(const Real _J0, const Real _J1, const Real lamda, const Point& p);
    //Compute wave domain A at a given point
    ComplexPoint  compute_waveNumber_A(const Real _lamda, const Point& p);
    //Compute  pAx at a given point
    ComplexPoint  compute_waveNumber_pAx(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //Compute  pAy at a given point
    ComplexPoint  compute_waveNumber_pAy(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //Compute  pAz at a given point
    ComplexPoint  compute_waveNumber_pAz(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //Compute  gradient(divergence A)
    ComplexPoint compute_waveNumber_ppAx(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //Compute  gradient(divergence A)
    ComplexPoint compute_waveNumber_ppAy(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //Compute  gradient(divergence A)
    ComplexPoint compute_waveNumber_ppAz(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //
    //Compute  gradient_gradient(divergence A)
    ComplexPoint compute_waveNumber_pppAx(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //Compute  gradient_gradient(divergence A)
    ComplexPoint compute_waveNumber_pppAy(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //Compute  gradient_gradient(divergence A)
    ComplexPoint compute_waveNumber_pppAz(const Real _J0, const Real _J1, const Real _lamda, const Point& p);
    //
    // return pAx pAy pAz
    ComplexPoint compute_pA(const Real _J0, const Real _J1, const Real lamda, const Point& p);
    //Set E. H.  A  potential and Rotation A potential commad
    void Set_E_H_A(const Point& p, const Point& _psource, unsigned int source_direction);
    // A routine to calculate and print the phase and apparent resistivity on the surface
    friend std::ostream& operator <<(std::ostream& os, const BC_CSEM& loe);
    // transform electric_parameters to wavenumber, admittivity, impedivity etc.
    void inner_parameters(const std::vector<std::vector<Real> >& ep,
        const Real frequency);
    // get z0 and y0
    Dcomplex get_z0() { return z_hat[0] * -1.0; } /*Please note that in other codes, we use*/
                                                /*z_hat =- i*omega*\mu */
                                                /*in this class, we use z_hat = -1*omega*\mu */
                                                /*so, there is a -1.0 in this return */
                                                /*which will be used by other class's subroutines*/
    Dcomplex get_y0() { return y_hat[0]; }
    Dcomplex get_k0() { return k[0]; }
    // return layer parameters
    Dcomplex get_z(int i) {
        return z_hat[i];
    }
    Dcomplex get_y(int i) {
        return y_hat[i];
    }
    //half-space condition background field compute
public:
    void compute_bgr(const Point& p);
    void compute_field_component(const Point& source_center, const Point& record, Vector3C& m_pE, Vector3C& m_pH);
    void compute_Ecomponent(Vector5C& m_pxyz, double freIn, double rIn, double zIn);
    void compute_Hcompoment(Vector4C& m_pxyz, double freIn, double rIn, double zIn);

private:
    int sgn(const Real z, const Real zs);
public:
    //
    unsigned int                          N; /*N-layer earth model*/
    std::vector<double>             h; /*thickness of each layer, h>0*/
    std::vector<double>             depth;/*depth to bottom of each layer*/
    std::vector<double>             depth_t;  /*depth to top of each layer*/
    std::vector<Dcomplex>        k;  /*k=a+b*i,a>0,b>0, k^2 = -z_hat*y_hat*/
    std::vector<Dcomplex>        z_hat; /*z_hat = -i*omega*\mu*/
    std::vector<Dcomplex>        y_hat; /*y_hat = sigma-i*omega*epsilon*/
    std::vector<Dcomplex>       Y0; /*Y0=a+bi,Y0^2=J0^2 + k^2*/
    std::vector<Dcomplex>       rm; /*(Yi-Yi-1)/(Yi+Yi-1)*/
    std::vector<Dcomplex>       rp; /*(Yi-Yi+1)/(Yi+Yi+1)*/
    std::vector<Dcomplex>       sm; /*(Yi*yi-1 - Yi-1*yi)/(Yi*yi-1 + Yi-1*yi)*/
    std::vector<Dcomplex>       sp; /*(Yi*yi+1 - Yi+1*yi)/(Yi*yi+1 + Yi+1*yi)*/
    std::vector<Dcomplex>       Rm;/*coefficients*/
    std::vector<Dcomplex>       Rp;/*coefficients*/
    std::vector<Dcomplex>       Sm;/*coefficients*/
    std::vector<Dcomplex>       Sp;/*coefficients*/
    std::vector<Dcomplex>       A; /*Reflection coefficient for Ay and Ax*/
    std::vector<Dcomplex>       B; /*Reflection coefficient for Ay and Ax*/
    std::vector<Dcomplex>       C; /*Reflection coefficient for Az*/
    std::vector<Dcomplex>       D; /*Reflection coefficient for A z*/

    //---------speical for a given p----------
    // electric fields E
    std::vector<Dcomplex>       E;
    // magentic fields H
    std::vector<Dcomplex>       H;
    //--------speical for a given p----------
    // Lorenz gauged vector potential A
    std::vector<Dcomplex>        potentialA;
    // Lorenz gauged vector potential A's Rotation
    std::vector<Dcomplex>        curlA;
    //Coulomb gauged  vector potential

    //Coulomb gauged vector potential Grad Ax
    std::vector<Dcomplex>  gradA;
    //Coulomb gauged vector potential Grad Ay

    //Coulomb gauged vector potential Grad Az

protected:
    const unsigned int               _p_hankel;
    Hankel_Integral* _hankel_integral;
    Point                                      _source;
    unsigned int                         _source_direction;
    unsigned int                         _source_type;
    Real                                        _fre;
};

inline
BC_CSEM::BC_CSEM(const std::vector<std::vector<Real> >& electric_parameters,
    const Real frequency, const unsigned int p_hankel) :
    _p_hankel(p_hankel),
    _hankel_integral(new Hankel_Integral(_p_hankel))
{
    // Prepare k, z_hat, y_hat
   // std::cout<<"inner_parameters"<<std::endl;
    this->inner_parameters(electric_parameters, frequency);
}

inline
BC_CSEM:: ~BC_CSEM()
{
    A.clear();
    B.clear();
    C.clear();
    D.clear();
    Rm.clear();
    Rp.clear();
    Sm.clear();
    Sp.clear();
    rm.clear();
    rp.clear();
    sm.clear();
    sp.clear();
    E.clear();
    H.clear();
    potentialA.clear();
}

#endif // BC_CSEM_H
#pragma once
