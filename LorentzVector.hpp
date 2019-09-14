class LorentzVector {
private:
	double t;
	double x;
	double y;
	double z;

public:
	LorentzVector(): t(0), x(0), y(0), z(0);
	LorentzVector(double input_t, double input_x,\
				double input_y, double input_z);
	double get_t() const;
	double get_x() const;
	double get_y() const;
	double get_z() const;
	void print() const;
	LorentzVector add(const LorentzVector & other_vector) const;
	LorentzVector sub(const LorentzVector & other_vector) const;
	LorentzVector mul(double Lambda) const;
	double dot(const LorentzVector & other_vector) const;
	
	
};