/*****************************************************************************/
/*                                                                                                                                                      */
/*  Copyright 2017                                                                                                                       */
/*  Zhengyong Ren                                                                                                                       */
/*  renzhengyong@csu.edu.cn                                                                                                    */
/*                                                                                                                                                      */
/*****************************************************************************/



#ifndef _NAMESPACEEM_H
#define _NAMESPACEEM_H

#define EIGEN_DONT_VECTORIZE // remove issues with STL containers
#define EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT
//#define EIGEN_USE_MKL_ALL

#include <complex>
#include <Eigen/Dense>  // Linear Algebra Lib.
#include <Eigen/Sparse> // Sparse Lib
#include <Eigen/StdVector>
#include "tnm.h"
class ComplexPoint;

//----------------------------------------------------------------------------
namespace EM
{  
  // Data-type 
  typedef double Real; 
  typedef std::complex<Real> Dcomplex;  
  typedef std::complex<Real> dcomplex;
 
  typedef Tnm<std::complex<double> > TnmC;
  typedef Eigen::SparseMatrix<Dcomplex, 
       Eigen::RowMajor>                     EigenSparseMatrix; 
  typedef Eigen::VectorXcd                  EigenDenseVector;
  typedef Eigen::Matrix<Dcomplex, 3, 1>     Grad;
  typedef Eigen::Matrix<Real,     6, 6>     Matrix6D;
  typedef Eigen::Matrix<Dcomplex, 6, 6>     Matrix6C;
  typedef Eigen::Matrix<Dcomplex, 6, 3>     Matrix63C;
typedef Eigen::Matrix<Dcomplex, 3, 6>     Matrix36C;
  typedef Eigen::Matrix<Dcomplex, 2, 2>     Matrix2C;
  typedef Eigen::Matrix<Dcomplex, 2, 1>     Vector2C;
   //
  typedef Eigen::Matrix<Dcomplex,   5,   1>    Vector5C;
  typedef Eigen::Matrix<Dcomplex,   4,   1>    Vector4C;
  typedef Eigen::Matrix<Dcomplex,   3,   1>    Vector3C;
  typedef Eigen::Matrix<Dcomplex,   4,   4>    Matrix4C;
  typedef Eigen::Matrix<Dcomplex,   4,   3>    Matrix43C;
  typedef Eigen::Matrix<Dcomplex,   1,   3>    Matrix13C;
  typedef Eigen::Matrix<Dcomplex,   1,   4>    Matrix14C;
  typedef Eigen::Matrix<Dcomplex,   3,   3>    Matrix33C;
  typedef Eigen::Matrix<double,   3,   3>         Matrix33D;
  typedef Eigen::Matrix<double,   4,   1>         Vector4D;
  //
  typedef Eigen::Vector3d                  Vector3D;
  typedef Eigen::Vector3f                   Vector3f;
  typedef Eigen::VectorXd                  Vector;

  // Pi=3.14159... 
  static const Real           pi   = 3.1415926535897932384626433832795;
  static const Dcomplex       zero = Dcomplex(0.,0.);
  static const Dcomplex       II   = Dcomplex(0.,1.);
  static const unsigned int   INVALID_UNIT=static_cast<unsigned int>(-1);
  static const Real           TOLERANCE = 1e-10;
  static const Real           mu0       =4.0*pi*1e-7; 
  static const Real           epsilon0  =8.854187817*1e-12;
  enum Mode {TE, TM, INVALID_MODE};
  // + or - signs 
  double sgn(const double m);
}

inline 
double EM::sgn(const double m) {
  if (std::abs(m)<EM::TOLERANCE) return 0.;
  else return m/std::abs(m);
}

//---------------------------------------------
using namespace EM;

#endif // #define _NAMESPACEEM_H
