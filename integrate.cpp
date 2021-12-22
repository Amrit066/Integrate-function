#include <iostream>
#include <cmath>

double Integrate(double,int,double,int,double);
double Differentiate(double,int,double,int,double);
double Calculate(double,int,double,int,double);


int main() {
  int c_t1,c_t2,p_t1,p_t2,t,eq_type,op_type;
  
  std::cout << "Please input the expression:\n";
  std::cout << "Coeficient of expression 1: ";
  std::cin>>c_t1;
  std::cout << "Power for expression 1: ";
  std::cin>>p_t1;
   std::cout << "Coeficient of expression 2: ";
  std::cin>>c_t2;
  std::cout << "Power for expression 2: ";
  std::cin>>p_t2;
  
  std::cout << "Is this equation for:\n1. Dispklacement\n2.Velocity\n3. Acceleration ";
  std::cin>>eq_type;

  std::cout << "Value of t ";
  std::cin>>t;
  
  std::cout << "What would you like to find:\n1. Dispklacement\n2.Velocity\n3. Acceleration ";
  std::cin>>op_type;

  if(eq_type==1){
    if(op_type==1)
        std::cout << "Displacement when t is "<<t<<" is "<<Calculate(c_t1,p_t1,c_t2,p_t2,t);
    else if(op_type==2)
        std::cout << "Velocity when t is "<<t<<" is "<<Differentiate(c_t1,p_t1,c_t2,p_t2,t);
    else
      std::cout << "Acceleration when t is "<<t<<" is "<<Differentiate(c_t1*p_t1,p_t1-1,c_t2*p_t2,p_t2-1,t);
  }
  else if(eq_type==2){
    if(op_type==1)
        std::cout << "Displacement when t is "<<t<<" is "<<Integrate(c_t1,p_t1,c_t2,p_t2,t);
    else if(op_type==2)
        std::cout << "Velocity when t is "<<t<<" is "<<Calculate(c_t1,p_t1,c_t2,p_t2,t);
    else
      std::cout << "Acceleration when t is "<<t<<" is "<<Differentiate(c_t1,p_t1,c_t2,p_t2,t);
  }
  else{
    if(op_type==1)
        std::cout << "Displacement when t is "<<t<<" is "<<Integrate(c_t1/(p_t1+1),p_t1+1,c_t2/(p_t2+1),p_t2+1,t);
    else if(op_type==2)
        std::cout << "Velocity when t is "<<t<<" is "<<Integrate(c_t1,p_t1,c_t2,p_t2,t);
    else
      std::cout << "Acceleration when t is "<<t<<" is "<<Calculate(c_t1,p_t1,c_t2,p_t2,t);
  }
    return 0;
}


// Defining Integrate() function

double Integrate(double x, int y,double a, int b,double t){
  double value=0.0;
  
  if(y+1<0)
    value=value+(x/((y+1)*pow(t,abs(y+1))));
  else
    value=value+(x*pow(t,y+1))/(y+1);
  if(b+1<0)
   value=value+(a/((b+1)*pow(t,abs(b+1))));
  else
    value=value+(a*pow(t,b+1))/(b+1);
  
  return value;
}



// Defining Differentiate() function

double Differentiate(double x, int y,double a, int b,double t){
  double value=0.0;
  
  if(y-1<0)
    value=value+(x*y/pow(t,abs(y-1)));
  else
    value=value+(x*y*pow(t,y-1));
  if(b-1<0)
    value=value+(a*b/pow(t,abs(b-1)));
  else
    value=value+(a*b*pow(t,b-1));
  
  return value;
}



// Defining Calculate() function

double Calculate(double x, int y,double a, int b,double t){
  double value=0.0;
  
  if(y<0)
    value=value+(x/pow(t,abs(y)));
  else
    value=value+(x*pow(t,y));
  if(b<0)
    value=value+(a/pow(t,abs(b)));
  else
    value=value+(a*pow(t,b));
  
  return value;
}
