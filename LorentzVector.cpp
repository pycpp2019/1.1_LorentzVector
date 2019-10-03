#include <iostream>
#include <math.h>
#include "LorentzVector.h"
		LorentzVector::LorentzVector(){ //default constructor
		vt=0;
		vx=0;
		vy=0;
		vz=0;
		} 
		LorentzVector::LorentzVector(double t, double x, double y, double z){ //t,x,y,z constructor
			this->vt=t*c;
			this->vx=x;
			this->vy=y;
			this->vz=z;
		}
		double LorentzVector::t() const { //get t
			return vt/c;
		}
		double LorentzVector::x() const { //get x
			return vx;
		}
		double LorentzVector::y() const { //get y
			return vy;
		}
		double LorentzVector::z() const { //get z
			return vz;
		}
		double LorentzVector::norm() const { //get norm
			double norm=sqrt(abs(vx*vx+vy*vy+vz*vz-vt*vt));
			return norm;
		}
		void LorentzVector::t(double n){ //put t
			vt=n*c;
		}
		void LorentzVector::x(double n){ //put x
			vx=n;
		}
		void LorentzVector::y(double n){ //put y
			vy=n;
		}
		void LorentzVector::z(double n){ //put z
			vz=n;
		}
		LorentzVector LorentzVector::add(const LorentzVector& v2) const{ //addition
			LorentzVector vres(vt + vt , vx + v2.vx , vy + vy , vz + v2.vz);
			return vres;
		} 
		LorentzVector LorentzVector::sub(const LorentzVector& v2) const{ //subtraction
			LorentzVector vres(vt - v2.vt , vx - v2.vx , vy - vy , vz - v2.vz);
			return vres;
		}
		LorentzVector LorentzVector::mul(double a) const{ //multiplication by a const
			LorentzVector vres(vt*a ,vx*a ,vy*a ,vz*a);
			return vres;
		}
		double LorentzVector::dot(const LorentzVector& v2) const{
			return (-vt * v2.vt + vx * v2.vx + vy * v2.vy + vz * v2.vz);	
		}
		void LorentzVector::zboost(double beta){
			double vzOld=vz;
			vz=(vz-vt*beta)/sqrt(1-beta*beta);
			vt=c*(vt/c-vzOld*beta/c)/sqrt(1-beta*beta);
		}
		void LorentzVector::print() const {
			std::cout<<"vector:\n\n("<< vt <<", "<< vx <<", "<< vy <<", "<< vz <<")\n";
		} 
		void LorentzVector::read(){
			std::cout<<"enter vector:\n\nt=";
			std::cin>>vt;
			std::cout<<"\nx=";
			std::cin>>vx;
			std::cout<<"\ny=";
			std::cin>>vy;
			std::cout<<"\nz=";
			std::cin>>vz;
			std::cout<<"\n";		
		}
