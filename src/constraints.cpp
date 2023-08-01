#include "../include/constraints.h"
#include <iostream>

static Matrix W = Matrix();
static Matrix Q = Matrix();
static Matrix Qhat = Matrix();
static Matrix qdot = Matrix();
static Matrix J = Matrix();
static Matrix Jt = Matrix();
static Matrix Jdot = Matrix();
static Matrix lambda = Matrix();
static Matrix left = Matrix();
static Matrix left1 = Matrix();
static Matrix right = Matrix();
static Matrix right1 = Matrix();
static Matrix right2 = Matrix();

void Constraints::calculateCircleConst(SingleRigidbody* rb) { //deprecated
	double lambda = (-1 * (rb->state.f * rb->state.p) - (rb->state.mass * (rb->state.v * rb->state.v))) / (rb->state.p * rb->state.p);
	rb->state.f = rb->state.f + (rb->state.p * lambda);
}

void Constraints::calculateRigidSpringConst(SingleRigidbody* rb, SingleRigidbody* rb1) { //deprecated
	FlatVector dist = FlatVector(rb->state.p.x - rb1->state.p.x, rb->state.p.y - rb1->state.p.y);
	FlatVector rel_v = FlatVector(rb->state.v.x - rb1->state.v.x, rb->state.v.y - rb1->state.v.y);
	double n = (rb->state.mass)*(-1*(rel_v*rel_v)+((rb1->state.f*dist)/rb1->state.mass)-((rb->state.f * dist)/rb->state.mass))*(rb1->state.mass);
	double d = rb1->state.mass * (dist * dist) + rb->state.mass * (dist * dist);
	double lambda = (n/d);
	rb->state.f = rb->state.f + dist*lambda;
	rb1->state.f = rb1->state.f - dist*lambda;
}

void Constraints::addCircleConstraint(SingleRigidbody* rb) {
	Constraint* con = new Constraint();
	con->j = Matrix(2, 1, 0);
	con->jdot = Matrix(2, 1, 0);

	double* arr = new double[2]{2*rb->state.p.x, 2*rb->state.p.y};
	double* arrdot = new double[2]{2*rb->state.v.x, 2*rb->state.v.y};

	con->j.set(arr);
	con->jdot.set(arrdot);

	rb->constraint_list.push_back(con);

	delete[](arr);
	delete[](arrdot);
}

void Constraints::createMatrices() {
	int num_of_rb = SingleRigidbody::rb_list.size();
	double* w_vec = new double[num_of_rb*2];
	int constraint_count = 0;

	for (int i = 0; i < num_of_rb; i++) {
		*(w_vec+2*i) = 1/SingleRigidbody::rb_list[i]->state.mass;
		*(w_vec+(2*i+1)) = 1/SingleRigidbody::rb_list[i]->state.mass; 

		constraint_count += SingleRigidbody::rb_list[i]->constraint_list.size();
	}

	W = Matrix(num_of_rb*2, num_of_rb*2,0);
	W.diag(w_vec);
	Q = Matrix(1, num_of_rb*2,0);
	qdot = Matrix(1, num_of_rb * 2, 0);
	J = Matrix(num_of_rb * 2, constraint_count);
	Jdot = Matrix(num_of_rb * 2, constraint_count);

	delete[](w_vec);
}

void Constraints::calculate() {
	int num_of_rb = SingleRigidbody::rb_list.size();
	double* Q_vec = new double[num_of_rb * 2];
	double* qdot_vec = new double[num_of_rb * 2];
	int constraint_count = 0;

	for (int i = 0; i < num_of_rb; i++) {
		*(Q_vec + 2 * i) = SingleRigidbody::rb_list[i]->state.f.x;
		*(Q_vec + (2 * i + 1)) = SingleRigidbody::rb_list[i]->state.f.y;

		*(qdot_vec + 2 * i) = SingleRigidbody::rb_list[i]->state.v.x;
		*(qdot_vec + (2 * i + 1)) = SingleRigidbody::rb_list[i]->state.v.y;

	}

	Q.set(Q_vec);
	qdot.set(qdot_vec);

	delete[](Q_vec);
	delete[](qdot_vec);

	for (int i = 0; i < num_of_rb; i++) {
		for (int j = 0; j < SingleRigidbody::rb_list[i]->constraint_list.size(); j++) {
			J.setBlock(i * 2, constraint_count, &SingleRigidbody::rb_list[i]->constraint_list[j]->j);
			Jdot.setBlock(i * 2, constraint_count, &SingleRigidbody::rb_list[i]->constraint_list[j]->jdot);
			constraint_count++;
		}
		SingleRigidbody::rb_list[i]->constraint_list.clear();
	}

	J.multiply(W, &left1);
	left1.transposeMultiply(J,&left);

	Jdot.multiplyScalar(-1);
	Jdot.multiply(qdot, &right1);
	left1.multiply(Q, &right2);
	right1.subtract(right2, &right);

	GaussianElimination::solve(&left, &right, &lambda);

	J.transpose(&Jt);
	Jt.multiply(lambda, &Qhat);

	for (int i = 0; i < num_of_rb; i+=2) {
		SingleRigidbody::rb_list[0]->state.f.x += Qhat.matrix[i][0];
		SingleRigidbody::rb_list[0]->state.f.y += Qhat.matrix[i+1][0];
	}
}