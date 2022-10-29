#include "read_file.h"
#include <fstream>
#include <sstream>

DecrypErrors parse_file(const string filename, vector<double>& x, vector<double>& y) {
	ifstream file;
	file.open(filename);
	if (!file) {
		return DecrypErrors::WRONG_PATH_OR_FTYPE;
	}
	else {
		int count = 0;
		while (!file.eof()) {
			string bufx, bufy;
			double bufx2, bufy2;
			file >> bufx >> bufy;
			istringstream issx(bufx);
			istringstream issy(bufy);
			issx >> bufx2;
			issy >> bufy2;
			//cout << bufx2 << " " << bufy2 << endl; 

			if ((issx.fail()) || (issy.fail())) { 
				return DecrypErrors::INCORRECT_DTYPE;
			}
			x.push_back(bufx2);
			y.push_back(bufy2);
			count += 1;
		}
		x.push_back(x[0]);
		y.push_back(y[0]);
		if (count % 2 != 0) {
			return DecrypErrors::WRONG_NUMBER_OF_COORDINATES;
		}
	}
	return DecrypErrors::SUCCESS;
}

string get_error_name(DecrypErrors err_info) {
	switch (err_info)
	{
	case DecrypErrors::WRONG_PATH_OR_FTYPE:
		return "Incrorrect path or file type.";
	case DecrypErrors::INCORRECT_DTYPE:
		return "Data is not double, check your file.";
	case DecrypErrors::WRONG_NUMBER_OF_COORDINATES:
		return "Numbers of X and Y is different, chek your file.";
	case DecrypErrors::SUCCESS:
		return "Polygon is imported successfully!";
	default:
		return "Unknown data import error.";
	}
	return "Unknown data import error.";
}