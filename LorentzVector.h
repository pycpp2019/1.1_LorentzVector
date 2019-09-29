#pragma once

class LorentzVector {
private:
	double t_coord;
	double x_coord;
	double y_coord;
	double z_coord;

public:
//##########___CONSTRUCTORS___#########################################################################################################
	LorentzVector();
	LorentzVector(double input_t, double input_x,\
				double input_y, double input_z);
//##########___GETTERS___##############################################################################################################
	double t() const;
	double x() const;
	double y() const;
	double z() const;
//##########___SETTERS___##############################################################################################################
	void t(double new_t);
	void x(double new_x);
	void y(double new_y);
	void z(double new_z);
//##########___OUTPUTTING_METHOD___####################################################################################################
	void print() const;
//##########___INPUTTING_METHOD___#####################################################################################################
	void read();
//##########___OPERATIONS___###########################################################################################################
	LorentzVector add(const LorentzVector & other_vector) const;
	LorentzVector sub(const LorentzVector & other_vector) const;
	LorentzVector mul(double Lambda) const;
	double dot(const LorentzVector & other_vector) const;
	double norm() const;
//##########___CONVERSION_METHOD___####################################################################################################	
	void zboost(double beta);		//If |beta| > 1, this function do nothing
	
};