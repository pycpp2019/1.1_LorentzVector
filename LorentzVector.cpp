#include "LorentzVector.h"
#include <iostream>
#include <cmath>




//##########___CONSTRUCTORS___#########################################################################################################


LorentzVector::LorentzVector(): t_coord(0), x_coord(0), y_coord(0), z_coord(0) {

}

LorentzVector::LorentzVector(double input_t, double input_x, double input_y, double input_z) {

	this->t_coord = input_t;
	this->x_coord = input_x;
	this->y_coord = input_y;
	this->z_coord = input_z;
}


//##########___GETTERS___##############################################################################################################


double LorentzVector::t() const {
	return this->t_coord;
}

double LorentzVector::x() const {
	return this->x_coord;
}

double LorentzVector::y() const {
	return this->y_coord;
}

double LorentzVector::z() const {
	return this->z_coord;
}


//##########___SETTERS___##############################################################################################################


void LorentzVector::t(double new_t) {
	this->t_coord = new_t;
	return;
}

void LorentzVector::x(double new_x) {
	this->x_coord = new_x;
	return;
}

void LorentzVector::y(double new_y) {
	this->y_coord = new_y;
	return;
}

void LorentzVector::z(double new_z) {
	this->z_coord = new_z;
	return;
}


//##########___OUTPUTTING_METHOD___####################################################################################################


void LorentzVector::print() const {
	std::cout << '(' << this->t_coord << ';' << this->x_coord <<\
		';' << this->y_coord << ';' << this->z_coord << ')' << std::endl;
	return;
}


//##########___INPUTTING_METHOD___#####################################################################################################


void LorentzVector::read() {
	std::cin >> this->t_coord;
	std::cin >> this->x_coord;
	std::cin >> this->y_coord;
	std::cin >> this->z_coord;
	return;
}


//##########___OPERATIONS___###########################################################################################################


LorentzVector LorentzVector::add(const LorentzVector & other_vector) const {
	return LorentzVector(this->t_coord + other_vector.t(),\
		this->x_coord + other_vector.x(),\
		this->y_coord + other_vector.y(),\
		this->z_coord + other_vector.z());
}

LorentzVector LorentzVector::sub(const LorentzVector & other_vector) const {
	return LorentzVector(this->t_coord - other_vector.t(),\
		this->x_coord - other_vector.x(),\
		this->y_coord - other_vector.y(),\
		this->z_coord - other_vector.z());
}

LorentzVector LorentzVector::mul(double lambda) const {
	return LorentzVector(lambda * this->t_coord,\
		lambda * this->x_coord,\
		lambda * this->y_coord,\
		lambda * this->z_coord);
}

double LorentzVector::dot(const LorentzVector & other_vector) const {
	return (this->t_coord * other_vector.t() - this->x_coord * other_vector.x() -\
		this->y_coord * other_vector.y() - this->z_coord * other_vector.z());
}

double LorentzVector::norm() const {
	return sqrt(abs(this->dot(*this)));
}


//##########___CONVERSION_METHOD___####################################################################################################


void LorentzVector::zboost(double beta) {									//If |beta| > 1, this function do nothing
	if(beta * beta > 1) {
		return;
	}

	double gamma_factor = 1 / sqrt(1 - beta * beta);
	double tmp_t = this->t_coord;
	double tmp_z = this->z_coord;
	
	this->z_coord = gamma_factor * (tmp_z - beta * tmp_t);
	this->t_coord = gamma_factor * (tmp_t - beta * tmp_z);
	return;
}
