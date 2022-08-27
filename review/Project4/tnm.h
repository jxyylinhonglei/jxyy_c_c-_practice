#ifndef _T_NM_H
#define _T_NM_H
#include <ostream>
#include <vector>
#include <cmath>
#include <cassert>


/*
 * 
 *   n,  m=-n, -n+1, ..., 0, ..., n-1, n 
 * 
 */

template<class T> class Tnm
{
public:
    Tnm() {}
    Tnm(unsigned int N); 
    ~Tnm() {}
    void init(unsigned int N);
    T& operator()(unsigned int n, int m);
    unsigned int get_cols() const { assert(N==data.size()); return N;}
    void setZero();
    template <class U> 
    friend std::ostream& operator<<(std::ostream& os,
				    const Tnm<U>& t);    
    void operator =(const Tnm<T>& t);
    Tnm(const Tnm<T>& t); 
    void add(const Tnm<T>& t);
    

public:
    std::vector<std::vector<T> >  data;
    unsigned int N;
};



template<class T> Tnm<T>::Tnm(unsigned int Nmax) 
{
  this->N= Nmax+1;
  this->data.resize(N);
  for(unsigned int n=0; n<N; n++)  {
    data[n].resize(2*n+1);
    for(int m=0; m<data[n].size(); m++) {
      data[n][m]= 0.;
    }
  }
  
  return;  
}



template<class T> void Tnm<T>::init(unsigned int Nmax) 
{  
  this->N= Nmax+1;
  this->data.resize(N);
  for(unsigned int n=0; n<N; n++)  {
    data[n].resize(2*n+1);
    for(int m=0; m<data[n].size(); m++) {
      data[n][m]= 0.;
    }
  }
  
  return;  
}


template<class T> void Tnm<T>::setZero()
{  
  for(unsigned int n=0; n<N; n++)  {
    for(int m=0; m<data[n].size(); m++) {
      data[n][m]= 0.;
    }
  }
  
  return;  
}



template<class T> T& Tnm<T>::operator()(unsigned int n, int m)
{
  assert(n>=std::abs(m));
  return data[n][n+m];
}



template<class T> std::ostream& operator<<(std::ostream& os, 
					   Tnm<T>& t)
{
  for(int n=0; n<t.N; n++) {
    os<<"\n";
    for(int m=0; m<t.data[n].size(); m++) {
      os<<t.data[n][m]<<"\t";
    }
  }

  return os; 
}



template<class T> void Tnm<T>::operator =( const Tnm<T>& t )
{
  this->N = t.N;
  this->data = t.data;
}


template<class T> Tnm<T>::Tnm(const Tnm<T>& t)
{
  this->N = t.N;
  this->data = t.data;
}


template<class T> void Tnm<T>::add(const Tnm<T>& t)
{
  assert(N==t.N);
  
  for(int n=0; n<N; n++)  {
    for(int m=0; m<data[n].size(); m++) {
      data[n][m]= data[n][m] + t.data[n][m];
    }
  }
  
  return;  
}

    
#endif //_T_NM_H

