#include "dblock.hpp"

// ------------------------------------
// Gain
// ------------------------------------

Gain::Gain(void)
{
}

void Gain::setparams(double K,double ymin,double ymax)
{
  p_K = K;
  p_ymin = ymin;
  p_ymax = ymax;
}

double Gain::getoutput(double u)
{
  double yout;

  yout = std::max(p_ymin,std::min(p_K*u,p_ymax));

  return yout;
}

double Gain::getoutput(double u, double ymin, double ymax)
{
  double yout;

  p_ymin = ymin;
  p_ymax = ymax;

  yout = getoutput(u);

  return yout;
}


// ------------------------------------
// Slope
// ------------------------------------

Slope::Slope(void)
{
  // Initialize to zero slope
  p_u[0] = 0.0;
  p_u[1] = 1.0;
  p_y[0] = p_y[1] = 0.0;
  p_ya = p_yb = 0.0;
}

void Slope::setparams(double *u,double *y,double ya, double yb)
{
  p_u[0] = u[0];
  p_u[1] = u[1];
  p_y[0] = y[0];
  p_y[1] = y[1];
  p_ya   = ya;
  p_yb   = yb;

  p_dydu = (p_y[1] - p_y[0])/(p_u[1] - p_u[0]);
}

double Slope::getoutput(double u)
{
  double yout;

  if(u - p_u[0] < 1e-5) yout = p_ya;
  else if(p_u[1] - u < 1e-5) yout = p_yb;
  else yout = p_y[0] + p_dydu*(u - p_u[0]);

  return yout;
}

// ------------------------------------
// Deadband
// ------------------------------------

Deadband::Deadband(void)
{
  p_u1 = p_u2 = 0.0;
}

void Deadband::setparams(double u1,double u2)
{
  p_u1 = u1;
  p_u2 = u2;
}

double Deadband::getoutput(double u)
{
  double yout;

  if(u - p_u1 > 1e-6 && p_u2 - u > 1e-6) yout = 0.0; // In the deadband
  else yout = u;
  
  return yout;
}

//-------------------
//   PieceWiseSlope
//-------------------

PiecewiseSlope::PiecewiseSlope(void)
{
  p_n = 0;
  p_increasing = true;
}

void PiecewiseSlope::setparams(int n, double *uin, double *yin)
{
  double u[2],y[2],ya,yb;
  int    i;

  // Check the slope direction - increasing or decreasing
  if(uin[1] > uin[0]) p_increasing = true;
  else p_increasing = false;
  
  for(i=0; i < n-1; i++) {
    // Check if the segment is valid, i.e., monotonically increasing or decreasing
    if((p_increasing && uin[i+1] > uin[i]) || (!p_increasing && uin[i+1] < uin[i])) {
      p_u[p_n]   = uin[i];
      p_u[p_n+1] = uin[i+1];
      p_y[p_n]   = yin[i];
      p_y[p_n+1] = yin[i+1];

      p_slopes[p_n].setparams(p_u,p_y,p_y[p_n],p_y[p_n+1]);
      p_n++;
    }
  }
}

double PiecewiseSlope::getoutput(double u)
{
  int i, yout;

  if(p_increasing  && u <= p_u[0])   yout = p_y[0];
  if(p_increasing  && u >= p_u[p_n]) yout = p_y[p_n];
  if(!p_increasing && u >= p_u[0])   yout = p_y[0];
  if(!p_increasing && u <= p_u[p_n]) yout = p_y[p_n];

  for(i=0; i < p_n; i++) {
    if(p_u[i] <= u && u <= p_u[i+1]) yout = p_slopes[i].getoutput(u);
  }

  return yout;
}
    
    
  
