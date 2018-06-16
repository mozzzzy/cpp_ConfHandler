#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum readLineStatus {
	GETTING_KEY,
	GETTING_VALUE,
	COMPLETE
};


class confHandler {
	private:
		std::string file_name;
		std::vector<std::string> confKey;
		std::vector<std::string> confValue;
	public:
		confHandler(const std::string conf_file_name);	// constructor
		~confHandler();	// destructor
		std::vector<std::string> getKeys();		// return confKey vector
		std::vector<std::string> getValues();	// return confValue vector
		std::string get(std::string key);	// return value which match to key
};
