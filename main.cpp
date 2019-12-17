#include <iostream>
#include <unistd.h>
#include "Robot.h"
#include "vibes.h"
#include <time.h>  
#include <math.h>     /* time */
using namespace std;




int main()

{
    srand (time(NULL));
    
    
    
    vibes::beginDrawing();
    vibes::newFigure("Flocking");
    vibes::setFigureProperties("Flocking",  vibesParams("x", 100, "y", 100, "width", 700, "height", 700));
    vibes::axisLimits(-100.,100.,-100.,100.);
    int a = 30;
    int b = 50;

    float t=0;
    float dt=0.1;
    float tfin = 1000;
    int n = 20;

    vector<Robot> swarm;

    swarm.push_back(Robot(&swarm));
    cout << "x : " << swarm[0].x() << endl;
    int compteur = 0; 
    while(t<tfin)
    {
        vibes::clearFigure("Flocking");
        t += dt;

        if(swarm.size() < n && compteur > 200 ) // tant que le nb de drone dans l'essain n'est pas bon et tous les 50*0.2=10 unités de temps on ajoute un drone 

        {
            Robot r = Robot(&swarm);

            r.pos = swarm.size();
            swarm.push_back(r);
            
            compteur = 0;  
        }
        
        for(int i=0; i<swarm.size(); i++)
        {
            float xdot, ydot, thetadot;

            swarm[i].f(swarm[i].u(), xdot, ydot, thetadot);
            swarm[i].set(swarm[i].x() + xdot * dt, swarm[i].y() + ydot * dt, swarm[i].theta()+dt*thetadot); // euler integration
            if(i!=0){
                swarm[i].draw();
            swarm[i].X.push_back(swarm[i].x());
            swarm[i].Y.push_back(swarm[i].y());
            }
            

        
            
        }
        swarm[0].set(a*sin(t/b),a*sin(2*t/b),atan2(a*2*cos( 2*t / b )/b, a*2*cos( t / b )/b)); 
        
        swarm[0].draw();
        swarm[0].X.push_back(swarm[0].x());
        swarm[0].Y.push_back(swarm[0].y());

        usleep(1000.);
        compteur += 1;

    }

    

    for(int i=0; i<swarm.size(); i++)
    {
        swarm[i].trajectoire();                  // Trace les trajectoires des drones 
    }
    

}

