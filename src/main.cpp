#include "../include/information.h"
#include "../include/flat_vector.h"
#include <iostream>
#include "../include/single_rigidbody.h"
#include "../include/double_rigidbody.h"
#include "../include/data_logger.h"
#include "../include/gravity_fg.h"
#include "../include/spring_fg.h"

DataLogger loger = DataLogger("data");
SingleRigidbody base = SingleRigidbody("base", true);
SingleRigidbody mass = SingleRigidbody("mass", false);
double dt = .003;
double sim_time = 5;

void addForces() {
    GravityFg::calculate(&mass);
    SpringFg::calculate(&mass, &base, 1000);
}


int main() {
    // random code ignore

    mass.state.mass = 5;

    loger.addData(&base);
    loger.addData(&mass);
    loger.writeHeaders();
    double time = 0;
    double it = sim_time / dt;

    for (int i = 0; i < it; i++) {
        mass.stepSimulationRK4(dt, &addForces);
        time += dt;

        loger.writeLine(time);
        base.reset();
        mass.reset();
    }
    loger.writeFile();

    return 0;
}
