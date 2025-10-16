Servo m1; // base
Servo m2;
Servo m3; // topmost
double x = 5; // world coords, changes throughout
double y = 0;
double z = 2; 
Servo stepper;
const double l1 = 10; // length 1
const double l2 = 10; // arm length 2

double degToRad (double deg) {
  return (deg * (M_PI / 180));
}
double radToDeg (double rad) {
  return (rad * (180/M_PI));
}
// all acos, atan functions in radians not degrees

// returns in degree
double alphaFunc (bool rad = false) {
  double r = rFunc(x, z);
  double numerator = (sq(l1)+sq(l2)-sq(r)); // sq(x) is x squared
  double denom = (2*l1*l2); // this math is duplicated in alphaFunc and phiFunc
  double alpha = acos((numerator/denom));
  // if (!rad) {alpha = radToDeg(alpha);}
  alpha = radToDeg(alpha);
  return alpha;
}
double rFunc(double x, double z) { // straight distance from base to object
  return sqrt(sq(x)+sq(z));
}

double phiFunc(double x, double z) { // Φ
  double r = rFunc(x, z);
  double alpha = alphaFunc();
  // double numerator = (sq(l1)+sq(l2)-sq(r));
  // double denom = (2*l1*l2);  // this math is dupicated in alphaFunc and phiFunc
  // double phi = M_PI - acos((numerator/denom));
  double phi = 180 - alpha;
  // phi = radToDeg(phi);
  return phi;
}
double thetaFunc(double x, double z) { // θ
  double r = rFunc(x, z);
  // double alpha = alphaFunc();
  double alpha = degToRad(alphaFunc(true));


  double theta = atan(z/x) + asin((l2*sin(alpha))/r);
  theta = radToDeg(theta);
  return theta;
}
// theta and phi are provided in degrees
// if this is being funky, be sure you provided the arguments in the correct order lol
double epsilonFunc(double phi, double theta ) {
  double epsilon = ((180 - phi) + theta);
  // epsilon = radToDeg(epsilon);
  return epsilon;
}
double stepperMotorAngle(double x, double y){
  double angle = (atan(y/x));
  angle = radToDeg(angle);
  return angle;
}
// phi 148.759
// theta 96.1813
// epsilon 127.4215
// arctangent of y over x
void test() {
  double r = rFunc(x, z);
  double alpha = alphaFunc();
  double theta = thetaFunc(x,z);
  double phi = phiFunc(x,z);
  double epsilon = epsilonFunc(phi, theta);
  logThis(M_PI);
  logThis("r = " + String(r));
  logThis("alpha", alpha);
  logThis("phi", phi);
  logThis("theta", theta);
  logThis("epsilon", epsilon);
  // logThis("phi", radToDeg(phi));
  // logThis("theta", radToDeg(theta));
  // logThis("epsilon", radToDeg(epsilon));

  // logThis("phi = " + String(radToDeg(phi)));
  // logThis("theta = " + String(radToDeg(theta)));
  // logThis("epsilon = " + String(radToDeg(epsilon)));
  // logThis(M_PI);
}