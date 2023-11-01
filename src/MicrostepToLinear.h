#ifndef MicrostepToLinear_h
#define MicrostepToLinear_h

// Class for converting microsteps to linear distance
class MicrostepToLinear {
  public:
    MicrostepToLinear();  // Default constructor
    MicrostepToLinear(float stepAngle, int microsteps, float pitch);  // Custom constructor
    bool setStepAngle(float stepAngle);  // Set step angle
    bool setMicrosteps(int microsteps);  // Set microsteps
    bool setPitch(float pitch);  // Set pitch
    float getStepAngle() const;  // Get step angle
    int getMicrosteps() const;  // Get microsteps
    float getPitch() const;  // Get pitch
    float convert(int microstepCount) const;  // Convert microsteps to distance
  private:
    float _stepAngle;  // Step angle in degrees
    int _microsteps;  // Microsteps per full step
    float _pitch;  // Lead screw pitch in mm
    float _anglePerMicrostep;  // Precomputed angle per microstep
    void updateAnglePerMicrostep();  // Update precomputed value
};

#endif
