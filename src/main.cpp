#include "../include/information.h"
#include "../include/flat_vector.h"
#include <iostream>
#include "../include/single_rigidbody.h"
#include "../include/double_rigidbody.h"
#include "../include/data_logger.h"
#include "../include/gravity_fg.h"
#include "../include/spring_fg.h"
#include "../include/constraints.h"

DataLogger loger = DataLogger("data");
SingleRigidbody mass1 = SingleRigidbody("mass1", false);
SingleRigidbody mass2 = SingleRigidbody("mass2", false);

double dt = .001;
double sim_time = 15;
double fps = 30;

void addForces() {
    GravityFg::calculate(&mass1);
    mass2.state.f.x = 1999998;
    //SpringFg::calculate(&mass1, &mass2, 100, 0, 2);
    //Constraints::calculateCircleConst(&mass1);
    Constraints::calculateRigidSpringConst(&mass1, &mass2);
}


int main() {
    // random code ignore
    double time = 0;
    double it = sim_time / dt;

    SingleRigidbody::rb_list.push_back(&mass1);
    SingleRigidbody::rb_list.push_back(&mass2);

    loger.addData(&mass1);
    loger.addData(&mass2);
    loger.writeHeaders();
    
    mass1.state.mass = 6;
    mass1.state.p.x = -2;
    mass1.state.p.y = -9.8;

    mass2.state.mass = 999999;
    mass2.state.v.x = 0;
    mass1.state.v.x = 0;

    for (int i = 0; i < it; i++) {
        
        RungeKuttaSolver::solve(dt, &addForces);
        time += dt;

        if(i%10 == 0)
            loger.writeLine(time);
        mass1.reset();
        mass2.reset();
    }
    loger.writeFile();

    return 0;
}
