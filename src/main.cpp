#include "../include/information.h"
#include "../include/flat_vector.h"
#include <iostream>
#include "../include/single_rigidbody.h"
#include "../include/double_rigidbody.h"
#include "../include/data_logger.h"
#include "../include/gravity_fg.h"
#include "../include/spring_fg.h"

DataLogger loger = DataLogger("data");
SingleRigidbody base = SingleRigidbody("base", false);
SingleRigidbody mass1 = SingleRigidbody("mass1", false);
//SingleRigidbody mass2 = SingleRigidbody("mass2", false);
double dt = .003;
double sim_time = 15;

void addForces() {
    GravityFg::calculate(&mass1);
    //GravityFg::calculate(&mass2);
    SpringFg::calculate(&mass1, &base, 164, 0,.05);
    //SpringFg::calculate(&mass1, &mass2, 750);
}


int main() {
    // random code ignore
    double time = 0;
    double it = sim_time / dt;

    SingleRigidbody::rb_list.push_back(&mass1);
    //SingleRigidbody::rb_list.push_back(&mass2);

    loger.addData(&base);
    loger.addData(&mass1);
    //loger.addData(&mass2);
    loger.writeHeaders();
    
    mass1.state.mass = 6;
    mass1.state.p.x = .05;
    mass1.state.p.y = .01;

    //mass2.state.mass = 5;
    //mass2.state.p.x = .1;

    for (int i = 0; i < it; i++) {
        
        RungeKuttaSolver::solve(dt, &addForces);
        time += dt;

        loger.writeLine(time);
        mass1.reset();
        base.reset();
    }
    loger.writeFile();

    return 0;
}
