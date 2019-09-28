#include "LorentzVector.hpp"
#include <iostream>
#include <cmath>




//##########___CONSTRUCTORS___#########################################################################################################


LorentzVector::LorentzVector(): t(0), x(0), y(0), z(0) {

}

LorentzVector::LorentzVector(double input_t, double input_x, double input_y, double input_z) {

	this->t = input_t;
	this->x = input_x;
	this->y = input_y;
	this->z = input_z;
}


//##########___GETTERS___##############################################################################################################


double LorentzVector::t() const {
	return this->t;
}

double LorentzVector::x() const {
	return this->x;
}

double LorentzVector::y() const {
	return this->y;
}

double LorentzVector::z() const {
	return this->z;
}


//##########___SETTERS___##############################################################################################################


void LorentzVector::t(double new_t) {
	this->t = new_t;
	return;
}

void LorentzVector::x(double new_x) {
	this->x = new_x;
	return;
}

void LorentzVector::y(double new_y) {
	this->y = new_y;
	return;
}

void LorentzVector::z(double new_z) {
	this->z = new_z;
	return;
}


//##########___OUTPUTTING_METHOD___####################################################################################################


void LorentzVector::print() const {
	std::cout << '(' << LIGHT_VEL * this->t << ';' << this->x <<\
		';' << this->y << ';' << this->z << ')' << std::endl;
	return;
}


//##########___OPERATIONS___###########################################################################################################


LorentzVector LorentzVector::add(const LorentzVector & other_vector) const {
	return LorentzVector(this->t + other_vector.t(),\
		this->x + other_vector.x(),\
		this->y + other_vector.y(),\
		this->z + other_vector.z());
}

LorentzVector LorentzVector::sub(const LorentzVector & other_vector) const {
	return LorentzVector(this->t - other_vector.t(),\
		this->x - other_vector.x(),\
		this->y - other_vector.y(),\
		this->z - other_vector.z());
}

LorentzVector LorentzVector::mul(double lambda) const {
	return LorentzVector(lambda * this->t,\
		lambda * this->x,\
		lambda * this->y,\
		lambda * this->z);
}

double LorentzVector::dot(const LorentzVector & other_vector) const {
	return (this->t * other_vector.t() - this->x * other_vector.x() -\
		this->y * other_vector.y() - this->z * other_vector.z());
}

double LorentzVector::norm() const {
	return this->dot(*this);
}


//##########___CONVERSION_METHOD___####################################################################################################


void LorentzVector::zboost(double beta) {									//If |beta| > 1, this function do nothing
	if(beta * beta > 1) {
		return;
	}

	double gamma_factor = 1 / sqrt(1 - beta * beta);
	double tmp_t = this->t;
	double tmp_z = this->z;
	
	this->z = gamma_factor * (tmp_z - beta * tmp_t);
	this->t = gamma_factor * (tmp_t - beta * tmp_z);
	return;
}
