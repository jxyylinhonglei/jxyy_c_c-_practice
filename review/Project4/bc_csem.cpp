#include "bc_csem.h"

void BC_CSEM::Set_E_H_A(const Point& _p,const Point& _psource,
                        unsigned int source_direction)
{
    _source_type  =0;
    _source_direction = source_direction;
    this->set_source(_psource);
    this->compute_E_H(_p);
    //this->compute_bgr(_p);
    return;
}

//Compute E and H at a given point.
void  BC_CSEM::compute_E_H(const Point& p)
{
    E.resize(3);
    H.resize(3);
    potentialA.resize(3);
    gradA.resize(3);
    Hankel_Integral& Hankel=*this->_hankel_integral;
    const std::vector<double>& _pBase = Hankel.get_points();
    const std::vector<double>& _pJ0     = Hankel.get_J0_weights();
    const std::vector<double>& _pJ1     = Hankel.get_J1_weights();
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    switch (_source_direction) {
    case 0:  //x-direciton
    {
        ComplexPoint sub_e;
        ComplexPoint sub_a;
        ComplexPoint sub_curla;
        ComplexPoint sub_grada;
        for(unsigned int i=0;i<_pBase.size();i++){
            Real lamda = _pBase[i]/R;
            this->init(lamda);
            ComplexPoint sub_pAxxyz = this->compute_waveNumber_ppAx(_pJ0[i],_pJ1[i],lamda,p);
            ComplexPoint sub_pAzxyz = this->compute_waveNumber_ppAz(_pJ0[i],_pJ1[i],lamda,p);
            sub_a = sub_a + this->compute_A_potential(_pJ0[i],_pJ1[i],lamda,p);
            sub_curla =  sub_curla + this->compute_Curl_A_potential(_pJ0[i],_pJ1[i],lamda,p);
            sub_e  = sub_e + (sub_pAxxyz + sub_pAzxyz)*(1.0/(EM::mu0*y_hat[this->p_in_which_layer(p)]));
            //
            sub_grada =  sub_grada + this->compute_pA(_pJ0[i],_pJ1[i],lamda,p);
        }
        E[0] = sub_e(0)  +  sub_a(0)*(this->get_z0()/EM::mu0);
        E[1] = sub_e(1)  +  sub_a(1)*(this->get_z0()/EM::mu0);
        E[2] = sub_e(2)  +  sub_a(2)*(this->get_z0()/EM::mu0);
        //
        H[0] = sub_curla(0)/(EM::mu0);
        H[1] = sub_curla(1)/(EM::mu0);
        H[2] = sub_curla(2)/(EM::mu0);
        //
        potentialA[0] =  sub_a(0);
        potentialA[1] =  sub_a(1);
        potentialA[2] = sub_a(2);
        //
        gradA[0] =  sub_grada(0);
        gradA[1] =  sub_grada(1);
        gradA[2] =  sub_grada(2);

    } break;
    case 1:  //y-direction
    {
        ComplexPoint sub_e;
        ComplexPoint sub_a;
        ComplexPoint sub_curla;
        ComplexPoint sub_grada;
        for(unsigned int i=0;i<_pBase.size();i++){
            Real lamda = _pBase[i]/R;
            this->init(lamda);
            ComplexPoint sub_pAyxyz = this->compute_waveNumber_ppAy(_pJ0[i],_pJ1[i],lamda,p);
            ComplexPoint sub_pAzxyz = this->compute_waveNumber_ppAz(_pJ0[i],_pJ1[i],lamda,p);
            sub_a = sub_a + this->compute_A_potential(_pJ0[i],_pJ1[i],lamda,p);
            sub_curla =  sub_curla + this->compute_Curl_A_potential(_pJ0[i],_pJ1[i],lamda,p);
            sub_e = sub_e +  (sub_pAyxyz + sub_pAzxyz)*(1.0/(EM::mu0*y_hat[this->p_in_which_layer(p)]));
            //
            sub_grada =  sub_grada + this->compute_pA(_pJ0[i],_pJ1[i],lamda,p);
        }
        E[0] = sub_e(0)  +  sub_a(0)*(this->get_z0()/EM::mu0);
        E[1] = sub_e(1)  +  sub_a(1)*(this->get_z0()/EM::mu0);
        E[2] = sub_e(2)  +  sub_a(2)*(this->get_z0()/EM::mu0);
        //
        H[0] = sub_curla(0)/EM::mu0;
        H[1] = sub_curla(1)/EM::mu0;
        H[2] = sub_curla(2)/EM::mu0;
        //
        potentialA[0] =  sub_a(0);
        potentialA[1] =  sub_a(1);
        potentialA[2] = sub_a(2);
        //
        gradA[0] =  sub_grada(0);
        gradA[1] =  sub_grada(1);
        gradA[2] =  sub_grada(2);
    }break;
    case 2:   //z-direciton
    {
        ComplexPoint sub_e;
        ComplexPoint sub_a;
        ComplexPoint sub_curla;
        ComplexPoint sub_grada;
        for(unsigned int i=0;i<_pBase.size();i++){
            Real lamda = _pBase[i]/R;
            this->init(lamda);
            ComplexPoint sub_pAzxyz = this->compute_waveNumber_ppAz(_pJ0[i],_pJ1[i],lamda,p);
            sub_a = sub_a + this->compute_A_potential(_pJ0[i],_pJ1[i],lamda,p);
            sub_curla =  sub_curla + this->compute_Curl_A_potential(_pJ0[i],_pJ1[i],lamda,p);
            sub_e= sub_e + sub_pAzxyz;
            //
            sub_grada =  sub_grada + this->compute_pA(_pJ0[i],_pJ1[i],lamda,p);
        }
        E[0] = sub_e(0)  +  sub_a(0)*(this->get_z0()/EM::mu0);
        E[1] = sub_e(1)  +  sub_a(1)*(this->get_z0()/EM::mu0);
        E[2] = sub_e(2)  +  sub_a(2)*(this->get_z0()/EM::mu0);
        //
        H[0] = sub_curla(0)/EM::mu0;
        H[1] = sub_curla(1)/EM::mu0;
        H[2] = sub_curla(2)/EM::mu0;
        //
        potentialA[0] =  sub_a(0);
        potentialA[1] =  sub_a(1);
        potentialA[2] = sub_a(2);
        //
        gradA[0] =  sub_grada(0);
        gradA[1] =  sub_grada(1);
        gradA[2] =  sub_grada(2);
    }break;
    default: std::cout<<"error, please input source direction!!"<<std::endl;
        break;
    }
    return ;
}

// Compute A at a given point
ComplexPoint  BC_CSEM::compute_A_potential(const Real _J0,const Real _J1,const Real lamda,const Point& p)
{
    // to locate which layer z belongs to
    //consider the source's depth is located[i] ~located[i+1](include source's depth equal to located[i+1])
    // allocate memory
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    ComplexPoint sub_A;
    switch (_source_direction) {
    case 0:  //x-direciton(Ax,0,Az)
    {
        sub_A = this->compute_waveNumber_A(lamda,p);
        sub_A(0) = sub_A(0)*lamda*_J0*(w/R);
        sub_A(1) =1e-30;
        sub_A(2) = -1.0*x*sub_A(2)*lamda*lamda*_J1*w/R/R;
    } break;
    case 1:  //y-direction(0,Ay,Az)
    {
        sub_A = this->compute_waveNumber_A(lamda,p);
        sub_A(0) = 1e-30;
        sub_A(1) = sub_A(1)*lamda*_J0*(w/R);
        sub_A(2) = -1.0*y*sub_A(2)*lamda*lamda*_J1*w/R/R;
    }break;
    case 2:   //z-direciton(0,0,Az)
    {
        sub_A = this->compute_waveNumber_A(lamda,p);
        sub_A(0) = 1e-30;
        sub_A(1) =1e-30;
        sub_A(2) = sub_A(2)*lamda*_J0*(w/R);
    }break;
    default: std::cout<<"error, please input source direction!!"<<std::endl;
        break;
    }
    return sub_A;
}

ComplexPoint BC_CSEM::compute_waveNumber_A(const Real _lamda,const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    switch (_source_direction) {
    case 0:
    {
       if(ns_located == np_located) {
           expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
          expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
           expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
           a(0) = A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs;
           a(1) =1e-30;
           a(2) = (C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm);
       }else {
            expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
            expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
           a(0) = A[np_located]*expscrp +B[np_located]*expscrm;
           a(1) = 1e-30;
           a(2) = (C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm);
       }
    }break;
    case 1:
    {
        if(ns_located == np_located) {
            expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
            expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
            expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
            a(0) = 1e-30;
            a(1) = A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs;           
            a(2) = (C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm);
        }else {
            if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
            if(np_located != N)    expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
            a(0) =1e-30;
            a(1) = A[np_located]*expscrp +B[np_located]*expscrm;
            a(2) = (C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm);
        }
    }break;
    case 2:
    {
        if(ns_located == np_located) {
            expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
            expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
            expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
            a(0) = 1e-30;
            a(1) = 1e-30;
            a(2) = C[np_located]*expscrp + D[np_located]*expscrm +  0.5*EM::mu0/Y0[ns_located]*expscrs;
        }else {
           expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
            expscrp =std::exp(-1.0*Y0[np_located]*(p(2) - depth[np_located]));
            a(0) = 1e-30;
            a(1) = 1e-30;
            a(2) = C[np_located]*expscrp + D[np_located]*expscrm;
        }
    }
    default: std::cout<<"error, please input right source direction 0->x_direction, 1->y_direction, 2->direction !!" <<std::endl;
        break;
    }
    return a;
}

//Compute Rotation A potential
ComplexPoint  BC_CSEM::compute_Curl_A_potential(const Real _J0,const Real _J1,const Real lamda,const Point& p)
{
    ComplexPoint sub_curlA;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    switch (_source_direction) {
    case 0:  //x-direciton
    {
        ComplexPoint sub_pAx = this->compute_waveNumber_pAx(_J0,_J1, lamda, p);
        //ComplexPoint sub_pAy = this->compute_waveNumber_pAy(_J0,_J1, lamda, p);
        ComplexPoint sub_pAz = this->compute_waveNumber_pAz(_J0,_J1, lamda, p);
        sub_pAx = sub_pAx*(w/R);
        sub_pAz = sub_pAz*(w/R);
        sub_curlA(0) = sub_pAz(1);
        sub_curlA(1) = (sub_pAx(2) - sub_pAz(0));
        sub_curlA(2) = -1.0*sub_pAx(1);
    } break;
    case 1:  //y-direction
    {
        //ComplexPoint sub_pAx = this->compute_waveNumber_pAx(_J0,_J1, lamda, p);
        ComplexPoint sub_pAy = this->compute_waveNumber_pAy(_J0,_J1, lamda, p);
        ComplexPoint sub_pAz = this->compute_waveNumber_pAz(_J0,_J1, lamda, p);
        sub_pAy = sub_pAy*(w/R);
        sub_pAz = sub_pAz*(w/R);
        sub_curlA(0) = -1.0*sub_pAy(2) +sub_pAz(1) ;
        sub_curlA(1) = -1.0*sub_pAz(0);
        sub_curlA(2) =  sub_pAy(0);
    }break;
    case 2:   //z-direciton
    {
        ComplexPoint sub_pAz = this->compute_waveNumber_pAz(_J0,_J1, lamda, p);
        sub_pAz = sub_pAz*(w/R);
        sub_curlA(0) = sub_pAz(1);
        sub_curlA(1) = -1.0*sub_pAz(0);
        sub_curlA(2) = 1e-30;
    }break;
    default: std::cout<<"error, please input source direction!!"<<std::endl;
        break;
    }
    return sub_curlA;
}
//
ComplexPoint BC_CSEM::compute_pA(const Real _J0,const Real _J1,const Real lamda,const Point& p)
{
    ComplexPoint sub_curlA;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    switch (_source_direction) {
    case 0:  //x-direciton
    {
        sub_curlA = this->compute_waveNumber_pAx(_J0,_J1, lamda, p) + (this->compute_waveNumber_pppAx(_J0,_J1, lamda, p)
                +this->compute_waveNumber_pppAz(_J0,_J1, lamda, p))*(1.0/(this->get_z0()*y_hat[this->p_in_which_layer(p)]));
        sub_curlA = sub_curlA*(w/R);
    } break;
    case 1:  //y-direction
    {
        sub_curlA = this->compute_waveNumber_pAy(_J0,_J1, lamda, p)+ (this->compute_waveNumber_pppAy(_J0,_J1, lamda, p)
                +this->compute_waveNumber_pppAz(_J0,_J1, lamda, p))*(1.0/(this->get_z0()*y_hat[this->p_in_which_layer(p)]));
        sub_curlA = sub_curlA*(w/R);
    }break;
    case 2:   //z-direciton
    {
        sub_curlA = this->compute_waveNumber_pAz(_J0,_J1, lamda, p);
        sub_curlA = sub_curlA*(w/R);

    }break;
    default: std::cout<<"error, please input source direction!!"<<std::endl;
        break;
    }
    return sub_curlA;
}

//Compute The Ax's gradient  Ay's gradient and Az's gradient
ComplexPoint  BC_CSEM::compute_waveNumber_pAx(const Real _J0,const Real _J1, const Real _lamda ,const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    if(ns_located == np_located) {
        expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*x/R*_lamda*_lamda*_J1;
        a(1) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*y/R*_lamda*_lamda*_J1;
        a(2) =  (A[np_located]*expscrp - B[np_located]*expscrm - 0.5*EM::mu0/Y0[ns_located]*expscrs)*Y0[np_located ]*_J0*_lamda;
    }else {
       expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm)*x/R*_lamda*_lamda*_J1;
        a(1) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm)*y/R*_lamda*_lamda*_J1;
        a(2) = (A[np_located]*expscrp - B[np_located]*expscrm)*Y0[np_located]*_J0*_lamda;
    }
    return a;
}

//Compute The Ax's gradient  Ay's gradient and Az's gradients
ComplexPoint  BC_CSEM::compute_waveNumber_pAy(const Real _J0,const Real _J1, const Real _lamda ,const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    if(ns_located == np_located) {
        expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
         expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*x/R*_lamda*_lamda*_J1;
        a(1) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*y/R*_lamda*_lamda*_J1;
        a(2) =  (A[np_located]*expscrp - B[np_located]*expscrm -  0.5*EM::mu0/Y0[ns_located]*expscrs)*Y0[np_located]*_J0*_lamda;
    }else {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
         expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm)*x/R*_lamda*_lamda*_J1;
        a(1) = -1.0*(A[np_located]*expscrp +B[np_located]*expscrm)*y/R*_lamda*_lamda*_J1;
        a(2) = (A[np_located]*expscrp - B[np_located]*expscrm)*Y0[np_located]*_J0*_lamda;
    }
    return a;
}

//Compute The Ax's gradient  Ay's gradient and Az's gradient
ComplexPoint  BC_CSEM::compute_waveNumber_pAz(const Real _J0,const Real _J1, const Real _lamda ,const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    switch (_source_direction) {
    case 0:  //x-direciton
    {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
         expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
                *(2.0*x*x*_lamda*_J1/R/R/R - 1.0/R*_lamda*_J1 - x*x/R/R*_lamda*_lamda*_J0)*_lamda;
        a(1) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
                *(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R/R*_lamda*_lamda*_J0)*_lamda;
        a(2) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]*expscrm)*Y0[np_located])
                *(-1.0*_lamda*x/R*_J1)*_lamda;
    } break;
    case 1:  //y-direction
    {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
                *(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R/R*_lamda*_lamda*_J0)*_lamda;
        a(1) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
                *(2.0*y*y*_lamda*_J1/R/R/R - 1.0/R*_lamda*_J1 - y*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(2) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]*expscrm)*Y0[np_located])
                *(-1.0*_lamda*y/R*_J1)*_lamda;
    }break;
    case 2:   //z-direciton
    {
        if(ns_located == np_located) {
            expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
            if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
            if(np_located != N)    expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
            a(0) = -1.0*(C[np_located]*expscrp +D[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*x/R*_lamda*_lamda*_J1;
            a(1) = -1.0*(C[np_located]*expscrp +D[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*y/R*_lamda*_lamda*_J1;
            a(2) =  (C[np_located]*expscrp - D[np_located]*expscrm -  0.5*EM::mu0/Y0[ns_located]*expscrs)*Y0[np_located]*_J0*_lamda;
        }else {
            if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
            if(np_located != N)    expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
            a(0) = -1.0*(C[np_located]*expscrp +D[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*x/R*_lamda*_lamda*_J1;
            a(1) = -1.0*(C[np_located]*expscrp +D[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)*y/R*_lamda*_lamda*_J1;
            a(2) = (C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*_J0*_lamda;
        }
    }break;
    default: std::cout<<"error, please input source direction!!"<<std::endl;
        break;
    }
    return a;
}

//Compute wave domain gradient(divergence A)
ComplexPoint BC_CSEM::compute_waveNumber_ppAx(const Real _J0, const Real _J1, const Real _lamda, const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    if(ns_located == np_located) {
        expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
        if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        if(np_located != N)    expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *(2.0*x*x/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - x*x/R/R*_lamda*_lamda*_J0)*_lamda;
        a(1) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(2) =  -1.0*(A[np_located]*expscrp - B[np_located]*expscrm -  0.5*EM::mu0/Y0[ns_located]*expscrs)
                *Y0[np_located]*x/R*_lamda*_lamda*_J1;
    }else {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = (A[np_located]*expscrp +B[np_located]*expscrm)
                *(2.0*x*x/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - x*x/R/R*_lamda*_lamda*_J0)*_lamda;
        a(1) =  (A[np_located]*expscrp +B[np_located]*expscrm)
                *(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(2) = -1.0*(A[np_located]*expscrp - B[np_located]*expscrm)*Y0[np_located]*x/R*_lamda*_lamda*_J1;
    }
    return a*(w/R);
}
//Compute wave domain gradient(divergence A)
ComplexPoint BC_CSEM::compute_waveNumber_ppAy(const Real _J0, const Real _J1, const Real _lamda, const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    if(ns_located == np_located) {
        expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(1) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *(2.0*y*y/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - y*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(2) =  -1.0*(A[np_located]*expscrp - B[np_located]*expscrm -  0.5*EM::mu0/Y0[ns_located]*expscrs)
                *Y0[np_located]*y/R*_lamda*_lamda*_J1;
    }else {
        if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        if(np_located != N)    expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) =  (A[np_located]*expscrp +B[np_located]*expscrm)
                *(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(1) = (A[np_located]*expscrp +B[np_located]*expscrm)
                *(2.0*y*y/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - y*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(2) = -1.0*(A[np_located]*expscrp - B[np_located]*expscrm)*Y0[np_located]*y/R*_lamda*_lamda*_J1;
    }
    return a*(w/R);
}
//Compute wave domain gradient(divergence A)
ComplexPoint BC_CSEM::compute_waveNumber_ppAz(const Real _J0, const Real _J1, const Real _lamda, const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    switch (_source_direction) {
    case 0:
    {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
               *expscrm)*Y0[np_located])*(2.0*x*x/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - x*x/R/R*_lamda*_lamda*_J0)*_lamda;
        a(1) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
               *expscrm)*Y0[np_located])*(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R*_lamda*_lamda*_J0)*_lamda ;
        a(2) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
               *(Y0[np_located]*Y0[np_located])*(-1.0*x/R*_J1*_lamda)*_lamda;
    } break;
    case 1:
    {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
                *expscrm)*Y0[np_located])*(2.0*x*y/R/R/R*_lamda*_J1 - x*y/R/R*_lamda*_lamda*_J0)*_lamda ;
        a(1) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
                *expscrm)*Y0[np_located])*(2.0*y*y/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - y*y/R/R*_lamda*_lamda*_J0)*_lamda;
        a(2) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
                *(Y0[np_located]*Y0[np_located])*(-1.0*y/R*_J1*_lamda)*_lamda;
    }break;
    case 2://
    {
        if(ns_located == np_located){
            expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
            if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) -  depth_t[np_located]));
            if(np_located != N)    expscrp =std::exp(1.0*Y0[np_located]*(p(2) -  depth[np_located]));
            a(0) = (C[np_located]*expscrp - D[np_located]*expscrm -  0.5*EM::mu0/Y0[np_located]*expscrs)
                    *(Y0[np_located])*(-1.0*x/R*_lamda*_J1)*_lamda;
            a(1) = (C[np_located]*expscrp - D[np_located]*expscrm -  0.5*EM::mu0/Y0[np_located]*expscrs)
                    *(Y0[np_located])*(-1.0*x/R*_lamda*_J1)*_lamda;
            a(2) = (C[np_located]*expscrp + D[np_located]*expscrm +  0.5*EM::mu0/Y0[np_located]*expscrs)*(Y0[np_located])*_lamda;
        }else{
            if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) -  depth_t[np_located]));
            if(np_located != N)    expscrp =std::exp(1.0*Y0[np_located]*(p(2) -  depth[np_located]));
            a(0) = (C[np_located]*expscrp - D[np_located]*expscrm)*(Y0[np_located])*(-1.0*x/R*_lamda*_J1)*_lamda;
            a(1) = (C[np_located]*expscrp - D[np_located]*expscrm)*(Y0[np_located])*(-1.0*x/R*_lamda*_J1)*_lamda;
            a(2) = (C[np_located]*expscrp + D[np_located]*expscrm)*(Y0[np_located])*_lamda;
        }
    }break;
    default: std::cout<<"error, please input source direction!!"<<std::endl;
        break;
    }
    return a*(w/R);
}
//
//Compute  gradient_gradient(divergence A)
ComplexPoint BC_CSEM::compute_waveNumber_pppAx(const Real _J0, const Real _J1, const Real _lamda, const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    //
    if(ns_located == np_located) {
        expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
        if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        if(np_located != N)    expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *((3.0*x*x*x*x*x/R/R/R/R/R - 3.0*x/R/R/R)*(-1.0*_lamda*_J1)   + (3.0*x/R/R - 3.0*x*x*x/R/R/R/R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0)
                  + x*x*x/R/R/R*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(1) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *( (2.0*x*x*y/(R*R*R*R*R) - y/(R*R*R) )*(-1.0*_lamda*_J1) + (y/(R*R) - 3.0*x*x*y/(R*R*R*R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0))
                   +(x*y*y/(R*R*R))*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(2) =  (A[np_located]*expscrp - B[np_located]*expscrm -  0.5*EM::mu0/Y0[ns_located]*expscrs)
                *Y0[np_located]*(2.0*x*x/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - x*x/R/R*_lamda*_lamda*_J0)*_lamda;
    }else {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = (A[np_located]*expscrp +B[np_located]*expscrm)
                *((3.0*x*x*x*x*x/R/R/R/R/R - 3.0*x/R/R/R)*(-1.0*_lamda*_J1)   + (3.0*x/R/R - 3.0*x*x*x/R/R/R/R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0)
                  + x*x*x/R/R/R*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1))*_lamda;
        a(1) =  (A[np_located]*expscrp +B[np_located]*expscrm)
                *( (2.0*x*x*y/(R*R*R*R*R) - y/(R*R*R) )*(-1.0*_lamda*_J1) + (y/(R*R) - 3.0*x*x*y/(R*R*R*R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0))
                   +(x*y*y/(R*R*R))*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(2) = (A[np_located]*expscrp - B[np_located]*expscrm)*Y0[np_located]
                *(2.0*x*x/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - x*x/R/R*_lamda*_lamda*_J0)*_lamda;
    }
    return a;
}

//Compute  gradient_gradient(divergence A)
ComplexPoint BC_CSEM::compute_waveNumber_pppAy(const Real _J0, const Real _J1, const Real _lamda, const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    //
    if(ns_located == np_located) {
        expscrs = std::exp(-1.0*Y0[ns_located]*std::abs(p(2) - _source(2)));
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *((3.0*y*y*y*y*x/R/R/R/R/R - 3.0*y/R/R/R)*(-1.0*_lamda*_J1)   + (3.0*y/R/R - 3.0*y*y*y/R/R/R/R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0)
                  + y*y*y/R/R/R*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(1) = (A[np_located]*expscrp +B[np_located]*expscrm + 0.5*EM::mu0/Y0[ns_located]*expscrs)
                *( (2.0*y*x*y/(R*R*R*R*R) - x/(R*R*R) )*(-1.0*_lamda*_J1) + (x/(R*R) - 3.0*y*x*y/(R*R*R*R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0))
                   +(x*x*y/(R*R*R))*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(2) =  (A[np_located]*expscrp - B[np_located]*expscrm -  0.5*EM::mu0/Y0[ns_located]*expscrs)
                *Y0[np_located]*(2.0*y*y/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - y*y/R/R*_lamda*_lamda*_J0)*_lamda;
    }else {
        if(np_located != 0)     expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        if(np_located != N)    expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = (A[np_located]*expscrp +B[np_located]*expscrm)
                *((3.0*y*y*y*y*x/R/R/R/R/R - 3.0*y/R/R/R)*(-1.0*_lamda*_J1)   + (3.0*y/R/R - 3.0*y*y*y/R/R/R/R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0)
                  + y*y*y/R/R/R*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(1) =  (A[np_located]*expscrp +B[np_located]*expscrm)
                *( (2.0*y*x*y/(R*R*R*R*R) - x/(R*R*R) )*(-1.0*_lamda*_J1) + (x/(R*R) - 3.0*y*x*y/(R*R*R*R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0))
                   +(x*x*y/(R*R*R))*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(2) = (A[np_located]*expscrp - B[np_located]*expscrm)*Y0[np_located]
                *(2.0*y*y/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - y*y/R/R*_lamda*_lamda*_J0)*_lamda;
    }
    return a;
}
//Compute  gradient_gradient(divergence A)
ComplexPoint BC_CSEM::compute_waveNumber_pppAz(const Real _J0, const Real _J1, const Real _lamda, const Point& p)
{
    ComplexPoint a;
    int ns_located = this->p_in_which_layer(_source);
    int np_located = this->p_in_which_layer(p);
    Dcomplex expscrm=.0;
    Dcomplex expscrp =.0;
    Dcomplex expscrs =.0;
    const Real x = p(0) - _source(0);
    const Real y = p(1) - _source(1);
    const Real z = p(2) - _source(2);
    const Real R = std::sqrt(x*x + y*y);
    Real w = 0.5/EM::pi;
    switch (_source_direction) {
    case 0:
    {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
               *expscrm)*Y0[np_located])*((3.0*x*x*x*x*x/R/R/R/R/R - 3.0*x/R/R/R)*(-1.0*_lamda*_J1)   + (3.0*x/R/R - 3.0*x*x*x/R/R/R/R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0)
                 + x*x*x/R/R/R*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(1) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
               *expscrm)*Y0[np_located])*( (2.0*x*x*y/(R*R*R*R*R) - y/(R*R*R) )*(-1.0*_lamda*_J1) + (y/(R*R) - 3.0*x*x*y/(R*R*R*R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0))
                 +(x*y*y/(R*R*R))*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(2) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
               *(Y0[np_located]*Y0[np_located])*(2.0*x*x/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - x*x/R/R*_lamda*_lamda*_J0)*_lamda;
    } break;
    case 1:
    {
        expscrm=std::exp(-1.0*Y0[np_located]*(p(2) - depth_t[np_located]));
        expscrp =std::exp(1.0*Y0[np_located]*(p(2) - depth[np_located]));
        a(0) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
                *expscrm)*Y0[np_located])*((3.0*y*y*y*y*x/R/R/R/R/R - 3.0*y/R/R/R)*(-1.0*_lamda*_J1)   + (3.0*y/R/R - 3.0*y*y*y/R/R/R/R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0)
               + y*y*y/R/R/R*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(1) = ((C[np_located]*expscrp - D[np_located]*expscrm)*Y0[np_located]*(EM::mu0/(_lamda*_lamda)) - 1.0*Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp + B[np_located]
                *expscrm)*Y0[np_located])*( (2.0*y*x*y/(R*R*R*R*R) - x/(R*R*R) )*(-1.0*_lamda*_J1) + (x/(R*R) - 3.0*y*x*y/(R*R*R*R)*(_lamda/R*_J1  -  _lamda*_lamda*_J0))
                 +(x*x*y/(R*R*R))*(_lamda*_lamda/R*_J0 + _lamda*_lamda*_lamda*_J1 - 2.0*_lamda/(R*R*R)*_J1) )*_lamda;
        a(2) = ((C[np_located]*expscrp + D[np_located]*expscrm)*(EM::mu0/(_lamda*_lamda)) - Y0[np_located]/(_lamda*_lamda)*(A[np_located]*expscrp - B[np_located]*expscrm))
                *(Y0[np_located]*Y0[np_located])*(2.0*y*y/R/R/R*_lamda*_J1 - 1.0/R*_lamda*_J1 - y*y/R/R*_lamda*_lamda*_J0)*_lamda;
    }break;
    case 2://
    {
       //
    }break;
    default: std::cout<<"error, please input source direction!!"<<std::endl;
        break;
    }
    return a;
}

//
int BC_CSEM::p_in_which_layer(const Point& p)
 {
     const Real z=p(2);
     double h_up[this->N+1], h_down[this->N+1];
     for(int i=0; i<this->N+1; i++) {
        if(i==0) { h_up[i]= -1E50; h_down[i]=this->depth[0]; }
        else { h_up[i]= this->depth[i-1]; h_down[i]=this->depth[i]; }
     }
     int located_n = -1; // z must be in [-1E50, 1E50], so we must find its layer number
     for(int i=0; i<this->N+1; i++) {
       if(z>h_up[i]&&z<h_down[i]) {
         located_n=i;
         break;
       }else if(std::abs(z-h_up[i])<1e-10) { // on h_up[i]
         located_n=i;
         break;
       }else if(std::abs(z-h_down[i])<1e-10) { // on h_down[i]
         located_n=i;
         break;
       }
    }
    assert(located_n!=-1);
    assert(located_n>=0&&located_n<this->N+1);
    //std::cout<<located_n<<std::endl;
    return located_n;
 }

void BC_CSEM::inner_parameters(const std::vector<std::vector<Real> >& ep,
                      const Real frequency)
{
    // exp(-iwt) used
    // zhat=-i*u*omega; yhat=cond-i*omega*epsilon
    // k2= -zhat*yhat
   this->N = ep.size()-1; // ep contains air layer, N does not acount for air layer
   assert(N>=1);      // at least, we are doing half-space model
   k.resize(N+1);
   z_hat.resize(N+1);
   y_hat.resize(N+1);
   depth.resize(N+1);
   _fre = frequency;
    // Compute the wavenumber, impedivity, admittivity
   for(unsigned int n=0; n<N+1; n++)
   {
       const Real cond=ep[n][0];
       const Real epsilon=ep[n][1]*EM::epsilon0;
       const Real mu=ep[n][2]*EM::mu0;
       const Real omega=2.*EM::pi*frequency;
       assert(omega>0.);
        z_hat[n]= -EM::II*omega*mu;
        y_hat[n] = cond;
       //y_hat[n]= cond-EM::II*omega*epsilon;
       k[n]=std::sqrt(-z_hat[n]*y_hat[n]);
       //std::cout<<frequency<<"\n";
       //std::cout<<k[n]<<"\n";
       assert(std::real(k[n])>-1E-50); //a>0
       assert(std::imag(k[n])>-1E-50); //b>0
       depth[n]=ep[n][3];  // depth to botton of each layer
       // std::cout<<n<<"\t"<<depth[n]<<"\n";
       assert(depth[0]<1e-12);   // h0 is zero at the air-earth interface
   }
   // h
   this->h.resize(N+1);
   h[0] = 1E50;
   h[N] = 1E50;
   for(int i=1; i<=N-1; i++) {
     //std::cout<<i<<"\t"<<depth[i]<<"\t"<<depth[i-1]<<"\n";
     //assert(depth[i]>depth[i-1]);
     h[i]= this->depth[i] - this->depth[i-1];
     //std::cout<<i<<"\t"<<h[i]<<"\t"<<depth[i-1]<<"\n";
   }
   //depth_t
   this->depth_t.resize(N+1);
   depth_t[0] = -1E50;
   for(int i=1; i<N+1; i++){
       depth_t[i] = this->depth[i-1];
       //std::cout<<i<<"\t"<<h[i]<<'\t'<<depth_t[i]<<"\n";
   }
}

void BC_CSEM::set_source(const Point& _p)
{
    _source = _p;
}

void BC_CSEM::init(const Real lamda)
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
    Y0.clear();
    //
    Y0.resize(N+1);
    for(unsigned int n=0; n< N+1; n++) {
        Y0[n] =std::sqrt(std::pow(lamda,2) - std::pow(k[n],2));
    }
    //compute coefficients
    int ns_located = this->p_in_which_layer(_source);
    sm.resize(N+1);
    sp.resize(N+1);
    rm.resize(N+1);
    rp.resize(N+1);
    sm[0]=1e-40; sp[N]=1e-40;
    rm[0]=1e-40; rp[N]=1e-40;
    for(int i=0; i<N; i++)
    {
        rp[i]=(Y0[i] - Y0[i+1])/(Y0[i] + Y0[i+1]);
        sp[i]=(Y0[i]*y_hat[i+1] - Y0[i+1]*y_hat[i])/(Y0[i]*y_hat[i+1] + Y0[i+1]*y_hat[i]);
    }
   for(int j=1; j<=N; j++)
   {
       rm[j]=(Y0[j] - Y0[j-1])/(Y0[j] + Y0[j-1]);
       sm[j]=(Y0[j]*y_hat[j-1] - Y0[j-1]*y_hat[j])/(Y0[j]*y_hat[j-1] + Y0[j-1]*y_hat[j]);
   }
    //compute coefficients
    Sm.resize(N+1);
    Sp.resize(N+1);
    Rm.resize(N+1);
    Rp.resize(N+1);
    Sm[0] = .0;  Rm[0] =.0;
    Sp[N] = .0; Rp[N]=.0;
    for(int i=1; i<=ns_located; i++)
    {
        Rm[i-1] = Rm[i-1] *std::exp(-1.0*Y0[i-1]*h[i-1]);
        Rm[i]=(rm[i] + Rm[i-1]*std::exp(-1.0*Y0[i-1]*h[i-1]))/(1.0 + rm[i]*Rm[i-1]*std::exp(-1.0*Y0[i-1]*h[i-1]));
        //
        Sm[i-1] =  Sm[i-1]*std::exp(-1.0*Y0[i-1]*h[i-1]);
        Sm[i]=(sm[i] + Sm[i-1]*std::exp(-1.0*Y0[i-1]*h[i-1]))/(1.0 + sm[i]*Sm[i-1]*std::exp(-1.0*Y0[i-1]*h[i-1]));
    }
    for(int j=N-1; j>=ns_located; j--)
    {
        Rp[j+1] = Rp[j+1]*std::exp(-1.0*Y0[j+1]*h[j+1]);
        Rp[j]=(rp[j] + Rp[j+1]*std::exp(-1.0*Y0[j+1]*h[j+1]))/(1.0 + rp[j]*Rp[j+1]*std::exp(-1.0*Y0[j+1]*h[j+1]));
        //
        Sp[j+1] = Sp[j+1]*std::exp(-1.0*Y0[j+1]*h[j+1]);
        Sp[j]=(sp[j] + Sp[j+1]*std::exp(-1.0*Y0[j+1]*h[j+1]))/(1.0 + sp[j]*Sp[j+1]*std::exp(-1.0*Y0[j+1]*h[j+1]));
    }
    //Aollcate
    A.resize(N+1);  B.resize(N+1); C.resize(N+1);  D.resize(N+1);
    Dcomplex expscrm =.0;
    Dcomplex expsrcp  =.0;
    Dcomplex  expgh    =.0;
    //first compute the source located layer coefficients
    //  zs
    if((_source_direction == 0) || (_source_direction == 1)) {//x-direction and y-direction
        int source_n_located = this->p_in_which_layer(_source);
        if(source_n_located !=0) expscrm = std::exp(-1.0*Y0[source_n_located]*std::abs(depth_t[source_n_located] - _source(2)));
        if(source_n_located != N) expsrcp  =  std::exp(-1.0*Y0[source_n_located]*std::abs(depth[source_n_located] - _source(2)));
        expgh  = std::exp(-1.0*Y0[source_n_located]*h[source_n_located]);
        Dcomplex rmrp     = Rm[source_n_located]*Rp[source_n_located];
        Dcomplex smsp     = Sm[source_n_located]*Sp[source_n_located];
        Dcomplex rhs0        = (EM::mu0/(2.0*Y0[source_n_located]));
        Dcomplex rhs1        = 0.5;
        //Dcomplex rhs1        = (EM::mu0/(2.0*lamda*lamda));
        Dcomplex srcp0       = expsrcp*rhs0;
        Dcomplex srcm0     = expscrm*rhs0;
        Dcomplex srcp1       = expsrcp*rhs1;
        Dcomplex srcm1     = expscrm*rhs1;
        Dcomplex onemrmrp = 1.0 - rmrp*expgh*expgh;
        Dcomplex onersmsp   = 1.0 - smsp*expgh*expgh;
        //
        A[source_n_located] = (srcp0*Rp[source_n_located] + rmrp*srcm0*expgh)/onemrmrp;
        B[source_n_located] = (rmrp*expgh*srcp0 +Rm[source_n_located]*srcm0)/onemrmrp;
        C[source_n_located] = (-1.0*Sp[source_n_located]*srcp1 + smsp*srcm1*expgh)/onersmsp;
        D[source_n_located] = (-1.0*smsp*srcp1*expgh + Sm[source_n_located]*srcm1)/onersmsp;
        //other layers coefficients
        //the coefficients in a layer above the source layer are computed
        for(int i=source_n_located - 1 ; i>=0; i--)
        {
            expscrm =.0;
            Dcomplex  expgh0 = std::exp(-1.0*Y0[i]*h[i]);
            Dcomplex  expgh1 = std::exp(-1.0*Y0[i+1]*h[i+1]);
            //
            if((i+1) == source_n_located) {
                if(source_n_located != 0)  expscrm = std::exp(-1.0*Y0[source_n_located]*std::abs(depth_t[source_n_located] - _source(2)));
                A[i] = (A[i+1]*expgh1 + B[i+1])/(1.0 + Rm[i]*expgh0*expgh0)//*expgh0
                        + rhs0*expscrm/(1.0 + Rm[i]*expgh0*expgh0);//*expgh0
                B[i] = A[i]*Rm[i]*expgh0;//*expgh0
                C[i] = (C[i+1]*expgh1 + D[i+1])/(1.0 + Sm[i]*expgh0*expgh0)//*expgh0
                        + rhs1*expscrm/(1.0 + Sm[i]*expgh0*expgh0);//*expgh0
                D[i] = C[i]*Sm[i]*expgh0;//*expgh0
            }else {
                A[i] = (A[i+1]*expgh1 + B[i+1])/(1.0 + Rm[i]*expgh0*expgh0) ;//*expgh0
                B[i] = A[i]*Rm[i]*expgh0;//*expgh0
                C[i] = (C[i+1]*expgh1 + D[i+1])/(1.0 + Sm[i]*expgh0*expgh0);//*expgh0
                D[i] = C[i]*Sm[i]*expgh0;//*expgh0
            }
        }
        //the coefficients in a layer below the source layer are computed
        for(int i=source_n_located + 1 ; i<N+1; i++)
        {
            expsrcp  =.0;
            Dcomplex  expgh0 = std::exp(-1.0*Y0[i-1]*h[i-1]);
            Dcomplex  expgh1 = std::exp(-1.0*Y0[i]*h[i]);
            //
            if((i-1) == source_n_located) {
                if(source_n_located != N) expsrcp  =  std::exp(-1.0*std::abs(depth[source_n_located] - _source(2))*Y0[source_n_located]);
                B[i] = (B[i-1]*expgh0 + A[i-1])/(1.0 + Rp[i]*expgh1*expgh1)//*expgh1
                        + rhs0*expsrcp/(1.0 + Rp[i]*expgh1*expgh1);//*expgh1
                A[i] = B[i]*Rp[i]*expgh1;//*expgh1
                D[i] = (D[i - 1]*expgh0 + C[i-1])/(1.0 + Sp[i]*expgh1*expgh1)//*expgh1
                        - rhs1*expsrcp/(1.0 + Sp[i]*expgh1*expgh1);//*expgh1
                C[i] = D[i]*Sp[i]*expgh1;//*expgh1
            } else {
                B[i] = (B[i-1]*expgh0 + A[i-1])/(1.0 + Rp[i]*expgh1*expgh1) ;//*expgh1
                A[i] = B[i]*Rp[i]*expgh1;//*expgh1
                D[i] = (D[i-1]*expgh0 + C[i-1])/(1.0 + Sp[i]*expgh1*expgh1);//*expgh1
                C[i] = D[i]*Sp[i]*expgh1;//*expgh1
            }
        }
    }else{//z-direction
        int source_n_located = this->p_in_which_layer(_source);
        if(source_n_located !=0) expscrm = std::exp(-1.0*Y0[source_n_located]*std::abs(depth_t[source_n_located] - _source(2)));
        if(source_n_located != N) expsrcp  =  std::exp(-1.0*std::abs(depth[source_n_located] - _source(2))*Y0[source_n_located]);
        expgh = std::exp(-1.0*Y0[source_n_located]*h[source_n_located]);
        Dcomplex smsp     = Sm[source_n_located]*Sp[source_n_located];
        Dcomplex rhs0        = (EM::mu0/(2.0*Y0[source_n_located]));
        Dcomplex srcp0       = expsrcp*rhs0;
        Dcomplex srcm0      = expscrm*rhs0;
        Dcomplex onersmsp   = 1.0 - smsp*expgh*expgh;
        C[source_n_located] = (srcp0*Sp[source_n_located]  + smsp*srcm0*expgh)/onersmsp;
        D[source_n_located] = (smsp*srcp0*expgh + Sm[source_n_located]*srcm0)/onersmsp;
        //other layers coefficients
        //the coefficients in a layer above the sourc layer are computed
        for(int i=source_n_located - 1 ; i>=0; i--)
        {
            expscrm =.0;
            Dcomplex  expgh0 = std::exp(-1.0*Y0[i]*h[i]);
            Dcomplex  expgh1 = std::exp(-1.0*Y0[i+1]*h[i+1]);
            //
            if((i+1) == source_n_located) {
                if(source_n_located != 0)  expscrm = std::exp(-1.0*Y0[source_n_located]*std::abs(depth_t[source_n_located] - _source(2)));
                C[i] = (C[i+1]*expgh1 + D[i+1])/(1.0 + Sm[i]*expgh0*expgh0)
                        + 0.5*(EM::mu0/Y0[source_n_located])*expscrm/(1.0 + Sm[i]*expgh0*expgh0);
                D[i] = C[i]*Sm[i]*expgh0;
            }else {
                C[i] = (C[i+1]*expgh1 + D[i+1])/(1.0 + Sm[i]*expgh0*expgh0);
                D[i] = C[i]*Sm[i]*expgh0;
            }
        }
        //the coefficients in a layer below the sourc layer are computed
        for(int i=source_n_located + 1 ; i<N+1; i++)
        {
            expsrcp  =.0;
            Dcomplex  expgh0 = std::exp(-1.0*Y0[i-1]*h[i-1]);
            Dcomplex  expgh1 = std::exp(-1.0*Y0[i]*h[i]);
            //
            if((i-1) == source_n_located) {
                if(source_n_located != N) expsrcp  =  std::exp(-1.0*std::abs(depth_t[source_n_located+1] - _source(2))*Y0[source_n_located]);
                D[i] = (D[i - 1]*expgh0 + C[i-1])/(1.0 + Sp[i]*expgh1*expgh1)
                        + 0.5*(EM::mu0/Y0[source_n_located])*expsrcp/(1.0 + Sp[i]*expgh1*expgh1);
                C[i] = D[i]*Sp[i]*expgh1;
            } else {
                D[i] = (D[i-1]*expgh0 + C[i-1])/(1.0 + Sp[i]*expgh1*expgh1);
                C[i] = D[i]*Sp[i]*expgh1;
            }
        }
    }
}

 int BC_CSEM::sgn(const Real z, const Real zs)
 {
     if(z >= zs)  return 1;
     else   return -1;
 }



//half-space condition background field compute
 void BC_CSEM::compute_bgr(const Point& p){
     E.resize(3);
     H.resize(3);
     Vector3C m_pEIn,m_pHIn;
     m_pEIn.setZero();m_pHIn.setZero();
     this->compute_field_component(_source,p,m_pEIn,m_pHIn);
     //
     E[0] = m_pEIn(0) ;
     E[1] = m_pEIn(1) ;
     E[2] = m_pEIn(2) ;
     //
     H[0] = m_pHIn(0);
     H[1] = m_pHIn(1);
     H[2] = m_pHIn(2);
     //std::cout<<E[0]<<std::endl;
 }

 void BC_CSEM::compute_field_component(const Point& source_center,const Point& record,Vector3C& m_pE,Vector3C& m_pH)
 {
       double x1 = record(0) - source_center(0); double y1 = record(1) - source_center(1);
       double z = .0;
       if(record(2) >= TOLERANCE ) z = record(2) - source_center(2);
       else z = -record(2) + source_center(2);
       //
       double R  = std::sqrt(std::pow(x1,2) + std::pow(y1,2));
       double Idl = 1.0;
       Real fre = _fre;
       double omega = 2.0*pi*fre;
       Dcomplex z2 = -1.0*II*omega*mu0;
       Dcomplex y2 = y_hat[1] - II*omega*epsilon0;
       Vector5C m_pE0;
       Vector4C m_pH0;
       this->compute_Ecomponent(m_pE0,fre,R,z);
       this->compute_Hcompoment(m_pH0,fre,R,z);
       if(_source_type == 0)//
       {
          switch(_source_direction)
          {
           case 0:
              {
                 // x-direction
                 m_pE(0) = -z2*(m_pE0(0) + 1.0/(-z2*y2)*((2.0*std::pow(x1,2)/std::pow(R,3) - 1.0/R)*m_pE0(2) - std::pow(x1/R,2)*m_pE0(3)));
                 m_pE(1) = -z2*(1.0/(-z2*y2)*(2.0*x1*y1/std::pow(R,3)*m_pE0(2) - x1*y1/std::pow(R,2)*m_pE0(3)));
                 m_pE(2) = -z2*(m_pE0(1)*(x1/R) + 1.0/(-z2*y2)*(x1/R)*m_pE0(4));
                 m_pH(0) = (x1*y1/std::pow(R,2)*m_pH0(0) - 2.0*x1*y1/std::pow(R,3)*m_pH0(1));
                 m_pH(1) = (-1.0/R + 2.0*std::pow(x1,2)/std::pow(R,3))*m_pH0(1) - std::pow(x1/R,2)*m_pH0(0) - m_pH0(3);
                 m_pH(2) = (y1/R)*m_pH0(2);
                 //
                 m_pE = m_pE*Idl;
                 m_pH = m_pH*Idl;
              }
              break;
           case 1:
              {
                 //y-direction
                 m_pE(0) = -z2*(1.0/(-z2*y2)*(2.0*x1*y1/std::pow(R,3)*m_pE0(2) - x1*y1/std::pow(R,2)*m_pE0(3)));
                 m_pE(1) = -z2*(m_pE0(0) + 1.0/(-z2*y2)*((2.0*std::pow(y1,2)/std::pow(R,3) - 1.0/R)*m_pE0(2) - std::pow(y1/R,2)*m_pE0(3)));
                 m_pE(2) = -z2*(m_pE0(1)*(y1/R) + 1.0/(-z2*y2)*(y1/R)*m_pE0(4));
                 m_pH(0) = (1.0/R - 2.0*std::pow(y1,2)/std::pow(R,3))*m_pH0(1) + std::pow(y1/R,2)*m_pH0(0) + m_pH0(3);
                 m_pH(1) = (-1.0*x1*y1/std::pow(R,2)*m_pH0(0) + 2.0*x1*y1/std::pow(R,3)*m_pH0(1));
                 m_pH(2) = (-1.0*x1/R)*m_pH0(2);
                 //
                 m_pE = m_pE*Idl;
                 m_pH = m_pH*Idl;
              }
              break;
           case 2:
                { // z-direction

                }
                break;
           default:
              {
                 // x-direction
                 m_pE(0) = -z2*(m_pE0(0) + 1.0/(-z2*y2)*((2.0*std::pow(x1,2)/std::pow(R,3) - 1.0/R)*m_pE0(2) - std::pow(x1/R,2)*m_pE0(3)));
                 m_pE(1) = -z2*(1.0/(-z2*y2)*(2.0*x1*y1/std::pow(R,3)*m_pE0(2) - x1*y1/std::pow(R,2)*m_pE0(3)));
                 m_pE(2) = -z2*(m_pE0(1)*(x1/R) + 1.0/(-z2*y2)*(x1/R)*m_pE0(4));
                 m_pH(0) = (x1*y1/std::pow(R,2)*m_pH0(0) - 2.0*x1*y1/std::pow(R,3)*m_pH0(1));
                 m_pH(1) = (-1.0/R + 2.0*std::pow(x1,2)/std::pow(R,3))*m_pH0(1) - std::pow(x1/R,2)*m_pH0(0) - m_pH0(3);
                 m_pH(2) = (y1/R)*m_pH0(2);
                 //
                 m_pE = m_pE*Idl;
                 m_pH = m_pH*Idl;
              }
           }
       }else{// magnetic source

       }
 }

 void BC_CSEM::compute_Ecomponent(Vector5C& m_pxyz, double freIn, double rIn, double zIn)
 {
     //std::cout<<_source_type<<std::endl;
     const double omega = 2.0*pi*freIn;
     Dcomplex z1 = -1.0*II*omega*mu0;
     Dcomplex y1 = y_hat[0] - II*omega*epsilon0;
     Dcomplex z2 = -1.0*II*omega*mu0;
     Dcomplex y2 = y_hat[1] - II*omega*epsilon0;
       //
       double z = zIn;
       double r = rIn;
       Dcomplex m1,m2;
       m1 = .0;
       m2 = .0;
       Hankel_Integral& Hankel=*this->_hankel_integral;
       const std::vector<double>& _pBase = Hankel.get_points();
       const std::vector<double>& _pJ0     = Hankel.get_J0_weights();
       const std::vector<double>& _pJ1     = Hankel.get_J1_weights();
       unsigned int num = _pBase.size();
       //
       for(unsigned int i = 0 ; i < num; i++) {
         m1 = std::sqrt(std::pow(_pBase[i]/r,2) + z1*y1);
         m2 = std::sqrt(std::pow(_pBase[i]/r,2) + z2*y2);
         //
         m_pxyz(0) += (_pBase[i]/r)/(m1 + m2)*_pJ0[i]*std::exp(-1.0*z*m2);
         m_pxyz(1) += 1.0/(m1 + m2)*(-1.0*z2*y2*std::pow(m1,2) + z1*y1*std::pow(m2,2))/(-1.0*m1*z2*y2 - m2*z1*y1)*std::exp(-1.0*z*m2)*_pJ1[i];
         m_pxyz(2) += (1.0/(m1 + m2)*std::pow(_pBase[i]/r,2)+1.0*m2/(m1 + m2)*(-1.0*z2*y2*std::pow(m1,2)+ z1*y1*std::pow(m2,2))/(-1.0*m1*z2*y2 - m2*z1*y1)
                      )*std::exp(-1.0*z*m2)*_pJ1[i];
         m_pxyz(3) += (1.0/(m1 + m2)*std::pow(_pBase[i]/r,3) + 1.0*(_pBase[i]/r)*m2/(m1 + m2)*(-1.0*z2*y2*std::pow(m1,2) + z1*y1*std::pow(m2,2))/(-1.0*m1*z2*y2 - m2*z1*y1)
                      )*std::exp(-1.0*z*m2)*_pJ0[i];
         m_pxyz(4) += (1.0*m2/(m1 + m2)*std::pow(_pBase[i]/r,2)+1.0*std::pow(m2,2)/(m1 + m2)*(-1.0*z2*y2*std::pow(m1,2) + z1*y1*std::pow(m2,2))
                        /(-1.0*m1*z2*y2 - m2*z1*y1))*std::exp(-1.0*z*m2)*_pJ1[i];
       }
       m_pxyz = m_pxyz/r/(2.0*pi);
 }

 void BC_CSEM::compute_Hcompoment(Vector4C& m_pxyz, double freIn, double rIn, double zIn)
 {
     const double omega = 2.0*pi*freIn;
     Dcomplex z1 = -1.0*II*omega*mu0;
     Dcomplex y1 = y_hat[0] -II*omega*epsilon0;
     Dcomplex z2 = -1.0*II*omega*mu0;
     Dcomplex y2 = y_hat[1] - II*omega*epsilon0;
       //
       double z = zIn;
       double r = rIn;
       Dcomplex m1,m2;
       m1 = .0;
       m2 = .0;
       Hankel_Integral& Hankel=*this->_hankel_integral;
       const std::vector<double>& _pBase = Hankel.get_points();
       const std::vector<double>& _pJ0     = Hankel.get_J0_weights();
       const std::vector<double>& _pJ1     = Hankel.get_J1_weights();
       unsigned int num = _pBase.size();
       for(unsigned int i = 0 ; i < num ; i++) {
           m1 = std::sqrt(std::pow(_pBase[i]/r,2) + z1*y1);
           m2 = std::sqrt(std::pow(_pBase[i]/r,2) + z2*y2);
           //
           m_pxyz(0) +=  (-1.0*z2*y2*std::pow(m1,2) + z1*y1*std::pow(m2,2))/(-1.0*m1*z2*y2 - m2*z1*y1)*(1.0*(_pBase[i]/r)/(m1 + m2))
                          *std::exp(-1.0*z*m2)*_pJ0[i];
           m_pxyz(1) +=  (-1.0*z2*y2*std::pow(m1,2) + z1*y1*std::pow(m2,2))/(-1.0*m1*z2*y2 - m2*z1*y1)*(1.0/(m1 + m2))*std::exp(-1.0*z*m2)*_pJ1[i];
           m_pxyz(2) +=  (1.0*std::pow(_pBase[i]/r,2)/(m1 + m2))*std::exp(-1.0*z*m2)*_pJ1[i];
           m_pxyz(3) +=  1.0*(_pBase[i]/r)*m2/(m1 + m2)*std::exp(-1.0*z*m2)*_pJ0[i];
         }
         m_pxyz = m_pxyz/r/(2.0*pi);
 }
