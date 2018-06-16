#include "ConfHandler.h"

// constructor
confHandler::confHandler(std::string conf_file_name) {

	file_name = conf_file_name;

	std::ifstream ifs(file_name);

	int buf_size = 512;
	char one_line[buf_size];
	while (ifs.getline(one_line, buf_size)) {
		int read_line_status = GETTING_KEY;
		std::string key = "";
		std::string value = "";

		int cc = 0;
		for(cc = 0; cc < buf_size; cc++){

			if(one_line[cc] == '#') {
				read_line_status = COMPLETE;
			// key
			}else if(read_line_status == GETTING_KEY && one_line[cc] != ' ' && one_line[cc] != '\t' && one_line[cc] != '\0'){
				key += one_line[cc];

			// key end
			}else if(read_line_status == GETTING_KEY && (one_line[cc] == ' ' || one_line[cc] == '\t')) {
				// do nothing
				read_line_status = GETTING_VALUE;

			// value
			}else if(read_line_status == GETTING_VALUE && one_line[cc] != ' ' && one_line[cc] != '\t' && one_line[cc] != '\0'){
				value += one_line[cc];
			// value end
			}else if(read_line_status == GETTING_VALUE && value != "" && (one_line[cc] == ' ' || one_line[cc] == '\t')){
				read_line_status = COMPLETE;
			// line end
			}else if(one_line[cc] == '\0') {
				if(key != "" && value != ""){
					confKey.push_back(key);
					confValue.push_back(value);
				}else{
					// if key is "" or value is "", do nothing
				}
				break;
			}
		}
	}
}

// destructor
confHandler::~confHandler(){}

// return key vector
std::vector<std::string> confHandler::getKeys() {
	return confKey;
}


// return value vector
std::vector<std::string> confHandler::getValues() {
	return confValue;
}

// return value string
std::string confHandler::get(std::string key) {
	std::string return_value = "";
	int kc = 0;
	for(kc = 0; kc < confKey.size(); kc++) {
		if(confKey[kc] == key) {
			return_value = confValue[kc];
		}
	}
	return return_value;
}


