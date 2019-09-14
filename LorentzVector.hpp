#ifndef _LORENTZ_VECTOR_
#define _LORENTZ_VECTOR_

class LorentzVector {
private:
	double t;
	double x;
	double y;
	double z;

public:
	LorentzVector();
	LorentzVector(double input_t, double input_x,\
				double input_y, double input_z);

	double get_t() const;
	double get_x() const;
	double get_y() const;
	double get_z() const;

	double set_t(double new_t);
	double set_x(double new_x);
	double set_y(double new_y);
	double set_z(double new_z);

	void print() const;
	
	LorentzVector add(const LorentzVector & other_vector) const;
	LorentzVector sub(const LorentzVector & other_vector) const;
	LorentzVector mul(double Lambda) const;
	double dot(const LorentzVector & other_vector) const;
	double norm() const;
	
	void zboost(double beta);		//If |beta| > 1, this function do nothing
	
};

#endif