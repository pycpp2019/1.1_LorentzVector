#ifndef LORENTZVECTOR_H   
#define LORENTZVECTOR_H
class LorentzVector {
	private:
		int c=300000000;
		double vt,vx,vy,vz;
	public:
		LorentzVector(); //default constructor
		LorentzVector(double t, double x, double y, double z); //t,x,y,z constructor
		double t() const; //get t
		double x() const; //get x
		double y() const; //get y
		double z() const; //get z
		double norm() const; //get norm
		void t(double n); //put t
		void x(double n); //put x
		void y(double n); //put y
		void z(double n); //put z
		LorentzVector add(const LorentzVector& v2) const;//addition
		LorentzVector sub(const LorentzVector& v2) const;//subtraction
		LorentzVector mul(double a) const;//multiplication by a const
		double dot(const LorentzVector& v2) const;//multiplication of vectors
		void zboost(double beta); //translation to system with speed beta*C
		void print() const; //printing vector in standart output
		void read(); //reading vector from standart input
};

#endif
