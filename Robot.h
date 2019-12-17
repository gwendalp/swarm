#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <vector>
#include <string>

class Robot
{
  public:

    Robot(std::vector<Robot>* v_swarm);
    Robot(std::vector<Robot>* v_swarm, float x, float y, float theta);

    float x();
    float y();
    int pos; // Indique la position d'ajout dans l'essaim utile pour le calcul de la somme où on a la condition i != j
    float theta();
    float u() const;
    std::vector<double> X; // Historique des positions x
    std::vector<double> Y; // Historique des positions y

    void trajectoire(); //Trace la trajectoire à la fin de la simulation 


    void set(float x, float y, float theta); // modifie les variable x, y et theta
    void move(float dx, float dy, float dtheta);

    void f(float u, float &xdot, float &ydot, float &thetadot);
    void draw();

  private:

    float m_x, m_y, m_theta;
    std::vector<Robot> *m_v_swarm;
};

#endif