#include "std_lib_facilities.h"
struct Point {
	double x, y;
};

double getnumber() {
	double d;
	while (!(cin >> d)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	return d;
};


void getpoints(int loop, vector<Point>& points)
{

	Point p;

	for (int i = 0; i < loop; ++i) {
		cout << "Please enter 7 pair(s) of points." << endl;
		cout << "Point " << i + 1 << endl;
		cout << "x: "; p.x = getnumber();
		cout << "y: "; p.y = getnumber();
		points.push_back(p);
		system("CLS");
	}
}

void outputPointsToFile(string filename, const vector<Point>& points)
{
	if (ofstream outFile{ filename })
		for (Point p : points)
			outFile << '(' << p.x << ',' << p.y << ")\n";
	else
		cout << "Error, can't open output file " << filename << endl;
}

void inputPointsToFile(string filename, vector<Point>& points)
{
	string line, num1, num2;
	Point p;
	if (ifstream inFile{ filename })
	{
		while (getline(inFile, line))/* getline() is a standard library function that is used
									  to read a string or a line from an input stream*/
		{
			//find where the comma is
			size_t found = line.find_first_of(",");

			//get first number (from after '(' until ',' )
			num1 = line.substr(1, found - 1);
			//get second number (from after ',' until ')' )
			num2 = line.substr(found + 1, line.size() - 2);

			p.x = stod(num1); p.y = stod(num2);
			points.push_back(p);
			//stod() converts string to double.
		}
	}
	else
		cout << "Error, can't open input file " << filename << endl;
}

bool compareVectors(const vector<Point>& p1, const vector<Point>& p2)
{
	if (p1.size() != p2.size())
		return false;
	else
	{
		for (uint32_t i = 0; i < p1.size(); ++i)
		{
			if (p1[i].x != p2[i].x ||
				p1[i].y != p2[i].y)
				return false;
		}
	}

	return true;
}
int main() {
	Vector<Point> Original_points;
	Vector<Point> processed_Points;
	outputPointsToFile("mydata.txt", Original_points);
	inputPointsToFile("mydata.txt", processed_Points);

	getpoints(7, Original_points);

	cout << "[original Points]---------------------" << endl;
	for (int i = 0; i < Original_points.size(); ++i)
		cout << "x[" << i + 1 << "]: " << Original_points[i].x << " , " << "y[" << i + 1 << "]: " << Original_points[i].y << endl;
	cout << "[processed Points]---------------------" << endl;
	for (int i = 0; i < processed_Points.size(); ++i)
		cout << processed_Points[i].x << ", " << processed_Points[i].y << endl;
	if (!compareVectors(Original_points, processed_Points))
		cout << "Something's wrong!" << endl;
	return 0;
}
