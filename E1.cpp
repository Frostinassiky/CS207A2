#include<iostream>
#include<cmath>
#include<iomanip> /* setprecision */
#define PI 3.14159265

using namespace std;

// define the polygon structure
struct polygon{
	// the # of sides
	int nSides = 0;
	// radius
	double radius = 0.0;
	// side length
	double length = 0.0;
	// apothem:  from the center to the midpoint of one of its sides
	double apothem = 0.0;
	// exterior angle, degree. we still need double precision
	double angle = 0.0;
	// perimeter length. 
	double perimeter = 0.0;
	// area
	double area = 0.0;
	
};

void NewPolygon(polygon * &p){ /* I use pointer to avoid large data transfer */
	// ask for input
	cout << "Please enter the number of side of your polygon: ";
	int n = 0;
	cin >> n;
	cout << endl;
	cout << "Please enter a regular polygon radius: ";
	double r = 0.0;
	cin >> r;
	cout << endl;
	// check the input
	// to have a valid polygon, n_min is 3
	if ( (n<=2) || (r<=0) ){
		cout << "Wrong or missing plygon definition measurements.\n" << endl;
		p = NULL;
		return;
	}
	// init a polygon
	p = new polygon;
	// save parameters
	p->nSides = n;
	p->radius = r;
	// compute side length
	double theta = 2.0 * PI / n / 2.0; /* rad, not degree */
	p->length = 2.0 * r * sin(theta);
	// compute perimeter
	p->perimeter = p->length * n;
	// compute apothem
	p->apothem = r * cos (theta);
	// compute exterior angle;
	p->angle = 360.0 / n;
	// compute area
	p->area = p->apothem * p->perimeter * 0.5;
	
	return;
} 

void PrintPolygon(polygon *p){ /* do not use reference to protect data */
	// overall infomation
	cout << "For a polygon having " << p->nSides \
	     << " sides and side of radius " << p->radius << endl;
	// print details
	cout << "* The length of the polygon side is: " << p->length << endl;
	cout << "* The length of the perimeter is: " << p->perimeter << endl;
	cout << "* The length of the apothem is: " << p->apothem << endl;
	cout << "* The exterior angle is: " << (int)p->angle << " degrees. " << endl; /* in the example, the output displays as int */
	//cout << "* The exterior angle is: " << setprecision(0) << p->angle << endl; /* in the example, the output displays as int */
	return;
}

int main(){
	// explain the program
	cout << "This pregram will give you the measurement of regular polygons that you define.\n" << endl;
	cout << "To quit, enter a negative or null number of sides or radius.\n" << endl;
	polygon *p = NULL;
	// if p is still NULL, quit program
	do {
		NewPolygon(p);
		PrintPolygon(p);
	} while (p!=NULL);

	return 0;
}
