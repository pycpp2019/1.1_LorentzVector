#include <iostream>

#include <cassert>
#include <cmath>

#include <LorentzVector.h>

using namespace std;


bool f_eq(double a, double b, double eps=1e-8) {
    return fabs(a - b) < eps;
}

bool lv_eq(LorentzVector a, LorentzVector b, double eps=1e-8) {
    return
        f_eq(a.t(), b.t(), eps) &&
        f_eq(a.x(), b.x(), eps) &&
        f_eq(a.y(), b.y(), eps) &&
        f_eq(a.z(), b.z(), eps);
}

bool constructor_default() {
    LorentzVector lv = LorentzVector();
    return 
        f_eq(lv.t(), 0.0) &&
        f_eq(lv.x(), 0.0) &&
        f_eq(lv.y(), 0.0) &&
        f_eq(lv.z(), 0.0);
}

bool constructor_component() {
    LorentzVector lv = LorentzVector(1.0, 2.71, -3.5, 0.0);
    return 
        f_eq(lv.t(), 1.0) &&
        f_eq(lv.x(), 2.71) &&
        f_eq(lv.y(), -3.5) &&
        f_eq(lv.z(), 0.0);
}

int main() {
    if (constructor_default() && constructor_component()) {
        cout << "[OK] All tests passed" << endl;
    } else {
        cout << "[FAIL] Some tests failed" << endl;
    }
    return 0;
}
