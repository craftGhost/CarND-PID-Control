#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

// double PID::get_kp() {
//   return Kp;
// }

// double PID::get_ki() {
//   return Ki;
// }

// double PID::get_kd() {
//   return Kd;
// }

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  pre_cte = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  d_error = cte - pre_cte;
  i_error += cte;
  pre_cte = cte;

}

double PID::CalcSteer() {
  //calculate steer value
  static double steer;
  steer = -Kp*p_error - Kd*d_error - Ki*i_error;
    
  return steer;  // TODO: Add your total error calc here!
}