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
SingleRigidbody mass3 = SingleRigidbody("mass3", false);

double dt = .001;
double sim_time = 15;
double fps = 30;

void addForces() {
    GravityFg::calculate(&mass2);
    GravityFg::calculate(&mass3);
    //Constraints::calculateRigidSpringConst(&mass1, &mass2);
    //Constraints::calculateRigidSpringConst(&mass2, &mass3);
}

void addConstraints() {
    //Constraints::calculateCircleConst(&mass2);
    Constraints::addCircleConstraint(&mass2);
}

int main() {
    // random code ignore
    double time = 0;
    double it = sim_time / dt;

    //SingleRigidbody::rb_list.push_back(&mass1);
    SingleRigidbody::rb_list.push_back(&mass2);
    //SingleRigidbody::rb_list.push_back(&mass3);

    //loger.addData(&mass1);
    loger.addData(&mass2);
    loger.addData(&mass3);
    loger.writeHeaders();
    
   // mass1.state.mass = 999999;

    mass2.state.mass = 2;
    mass2.state.p.x = 1;

    mass3.state.mass = 5;
    //mass3.state.p.x = 2;

    addForces();
    addConstraints();
    Constraints::createMatrices();
    Constraints::calculate();


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
