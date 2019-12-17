#include "Robot.h"
#include <vector>
#include <iostream>
#include "vibes.h"
#include "math.h"
#include <math.h>
using namespace std;

const float alpha = 0.005;
const float beta = 5.;
const float gamam = 0.5;


Robot::Robot(std::vector<Robot>* v_swarm, float x, float y, float theta) : m_v_swarm(v_swarm), m_x(x), m_y(y), m_theta(theta)
{

}

Robot::Robot(std::vector<Robot>* v_swarm) : m_v_swarm(v_swarm)
{
  m_x = customrand()*200;
  m_y = customrand()*200;
  m_theta = 0;
}



float Robot::x()
{
    return m_x; 
}

float Robot::y()
{
    return m_y; 
}

float Robot::theta()
{
    return m_theta; 
}

void Robot::set(float x, float y, float theta)
{
    m_x = x; 
    m_y = y; 
    m_theta = theta; 
}

void Robot::move(float dx, float dy, float dtheta)
{
    m_x += dx;
    m_y += dy;
    m_theta += dtheta;
}


void Robot::f(float u, float &xdot, float &ydot, float &thetadot)
{
  xdot = cos(m_theta);
  ydot = sin(m_theta);
  thetadot = u;

}

float Robot::u() const
{
  float s[2];
  s[0] = 0;
  s[1] = 0;

  

  for (int j=0; j < m_v_swarm->size(); j++)
  {
    vector<Robot>& vecRef = *m_v_swarm; // vector is not copied here
    Robot r = vecRef[j];

    
    
    if(pos != j) // verification de la condtion i != j dans le calcul de la somme
    {
    
    
    float diff[2];
  
    diff[0] = m_x -r.x();
    diff[1] = m_y  - r.y();
    
    cout << "d0   :  " << diff[0] << endl ;

    float N = norm(diff);
    

    s[0] += -2*alpha*(m_x - r.x()) + (m_x - r.x())*5./pow(N,3) + gamam*cos(r.theta());
    
    s[1] += -2*alpha*(m_y - r.y()) + (m_y - r.y())*5./pow(N, 3) + gamam*sin(r.theta());

    }


  }


  float res = sawtooth(angle(s) - m_theta);
 
  
  return res;
}

void Robot::draw()
{
  
  vibes::drawTank(m_x , m_y, m_theta, 4., vibesParams("figure", "Flocking"));

}



void Robot::trajectoire()
{
  
  
  vibes::drawLine(X, Y, "green");
}