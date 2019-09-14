#include "LorentzVector.hpp"
#include <iostream>

#define LIGHT_VEL 299 792 458

LorentzVector::LorentzVector(): t(0), x(0), y(0), z(0) {

}

LorentzVector::LorentzVector(double input_t, double input_x, double input_y, double input_z) {

	this->t = input_t;
	this->x = input_x;
	this->y = input_y;
	this->z = input_z;
}

double LorentzVector::get_t() const {
	return this->t;
}

double LorentzVector::get_x() const {
	return this->x;
}

double LorentzVector::get_y() const {
	return this->y;
}

double LorentzVector::get_z() const {
	return this->z;
}

void LorentzVector::set_t(double new_t) {
	this->t = new_t;
	return;
}

void LorentzVector::set_x(double new_x) {
	this->x = new_x;
	return;
}

void LorentzVector::set_y(double new_y) {
	this->y = new_y;
	return;
}

void LorentzVector::set_z(double new_z) {
	this->z = new_z;
	return;
}

void LorentzVector::print() const {
	std::cout << '(' << LIGHT_VEL * this->t << ';' << this->x <<\
		';' << this->y << ';' << this->z << ')' << std::endl;
	return;
}

LorentzVector LorentzVector::add(const LorentzVector & other_vector) const {
	return LorentzVector(this->t + other_vector.get_t(),\
		this->x + other_vector.get_x,\
		this->y + other_vector.get_y,\
		this->z + other_vector.get_z);
}

LorentzVector LorentzVector::sub(const LorentzVector & other_vector) const {
	return LorentzVector(this->t - other_vector.get_t(),\
		this->x - other_vector.get_x,\
		this->y - other_vector.get_y,\
		this->z - other_vector.get_z);
}

LorentzVector LorentzVector::mul(double lambda) const {
	return LorentzVector(lambda * this->t,\
		lambda * this->x,\
		lambda * this->y,\
		lambda * this->z);
}

double dot(const LorentzVector & other_vector) const {
	return (LIGHT_VEL * this->t  * LIGHT_VEL * other_vector.t -\
		this->x * other_vector
}
