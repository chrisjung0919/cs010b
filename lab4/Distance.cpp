#include "Distance.h"
#include <cmath>

Distance::Distance() {
   _feet = 0;
   _inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
   _feet = ft;
   _inches = in;
   init();
}

Distance::Distance(double in) {
   _feet = 0;
   _inches = in;
   init();
}

unsigned Distance::getFeet() const {
   return _feet;
}

double Distance::getInches() const {
   return _inches;
}

double Distance::distanceInInches() const {
   return _feet * 12.0 + _inches;
}

double Distance::distanceInFeet() const {
   return _feet + (_inches / 12.0);
}

double Distance::distanceInMeters() const {
   return distanceInInches() * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const {
   double totalInches = distanceInInches() + rhs.distanceInInches();
   return Distance(totalInches);
}

Distance Distance::operator-(const Distance &rhs) const {
   double totalInches = std::abs(distanceInInches() - rhs.distanceInInches());
   return Distance(totalInches);
}

ostream &operator<<(ostream &out, const Distance &rhs) {
   out << rhs._feet << "' " << rhs._inches << "\"";
   return out;
}

void Distance::init() {
   if (_inches < 0) {
      _inches = std::abs(_inches);
   }
   _feet += static_cast<unsigned>(_inches / 12);
   _inches = fmod(_inches, 12);
}