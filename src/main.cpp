#include "../include/information.h"
#include "../include/flat_vector.h"
#include <iostream>
#include "../include/single_rigidbody.h"
#include "../include/double_rigidbody.h"
#include "../include/data_logger.h"

int main() {
    // random code ignore
    /*DoubleRigidbody dot = DoubleRigidbody(true, false);
    dot.addGravityForce();
    dot.addSpringForce(1500);
    dot.stepSimulationEuler();
    dot.reset();
    dot.addGravityForce();
    dot.addSpringForce(1500);
    dot.stepSimulationEuler();
    dot.reset();
    dot.addGravityForce();
    dot.addSpringForce(1500);
    dot.stepSimulationEuler();
    dot.reset();
    dot.addGravityForce();
    dot.addSpringForce(1500);
    dot.stepSimulationEuler();
    dot.reset();

    DoubleRigidbody dot1 = DoubleRigidbody(true, false);
    dot1.addGravityForce();
    dot1.stepSimulationEuler();
    dot1.reset();
    dot1.addGravityForce();
    dot1.stepSimulationEuler();
    dot1.reset();
    dot1.addGravityForce();
    dot1.stepSimulationEuler();
    dot1.reset();
    dot1.addGravityForce();
    dot1.stepSimulationEuler();
    dot1.reset();

    State t = State(false);
    t.f = FlatVector(-2,-10);
    t.v = FlatVector(9, 5);
    for (int i = 0; i < 100; ++i)
        EulerSolver::solve(&t);
    std::cout << "x: " << t.v.x << "y: " << t.v.y << std::endl;
    std::cout << "x: " << t.p.x << "y: " << t.p.y << std::endl;

    State t1 = State(false);
    t1.f = FlatVector(-2.0, -10.0);
    t1.v = FlatVector(9.0, 5.0);
    for (int i = 0; i < 100; ++i)
        RungeKuttaSolver::solve(&t1);
    std::cout<<"x: " << t1.v.x << "y: " << t1.v.y << std::endl;
    std::cout<<"x: " << t1.p.x << "y: " << t1.p.y << std::endl;
    */

    DataLogger log = DataLogger("data");
    DoubleRigidbody spring = DoubleRigidbody("spring", true, false);
    spring.state1.mass = 5;
    log.addData(&spring);
    log.writeHeaders();
    double time = 0;
    double dt = .003;
    double sim_time = 5;
    double it = sim_time / dt;
    std::cout << dt;

    for (int i = 0; i < it; i++) {
        spring.addGravityForce();
        spring.addSpringForce(100);
        spring.stepSimulationRK4(dt);
        time += dt;
        log.writeLine(time);
        spring.reset();
    }
    log.writeFile();

    return 0;
}
