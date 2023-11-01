#include "Arduino.h"
#include "MicrostepToLinear.h"

// Update precomputed value; called in setters.
void MicrostepToLinear::updateAnglePerMicrostep() {
  _anglePerMicrostep = _stepAngle / _microsteps;
}

// Core constructor; uses setters for initialization.
MicrostepToLinear::MicrostepToLinear(float stepAngle, int microsteps, float pitch) : _pitch(pitch) {
  setStepAngle(stepAngle);
  setMicrosteps(microsteps);
}

// Default constructor; delegates to core constructor.
MicrostepToLinear::MicrostepToLinear() : MicrostepToLinear(1.8, 1, 2.0) {}

// Set step angle; updates precomputed value.
bool MicrostepToLinear::setStepAngle(float stepAngle) {
  if (stepAngle <= 0) return false;
  _stepAngle = stepAngle;
  updateAnglePerMicrostep();
  return true;
}

// Set microsteps; updates precomputed value.
bool MicrostepToLinear::setMicrosteps(int microsteps) {
  if (microsteps <= 0) return false;
  _microsteps = microsteps;
  updateAnglePerMicrostep();
  return true;
}

// Set pitch; no precomputed value to update.
bool MicrostepToLinear::setPitch(float pitch) {
  if (pitch <= 0) return false;
  _pitch = pitch;
  return true;
}

// Get step angle.
float MicrostepToLinear::getStepAngle() const {
  return _stepAngle;
}

// Get microsteps.
int MicrostepToLinear::getMicrosteps() const {
  return _microsteps;
}

// Get pitch.
float MicrostepToLinear::getPitch() const {
  return _pitch;
}

// Convert microsteps to linear distance.
float MicrostepToLinear::convert(int microstepCount) const {
  float totalAngle = _anglePerMicrostep * microstepCount;
  float revolutions = totalAngle / 360.0;
  float linearDistance = revolutions * _pitch;
  return linearDistance;
}
