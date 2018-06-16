#include <vector>
#include "ConfHandler.h"

int main() {

	confHandler ch("./test.conf");
	std::vector<std::string> Keys = ch.getKeys();
	std::vector<std::string> Values = ch.getValues();

	// get number of keys
	std::cout << "Keys.size() = " << Keys.size() << std::endl;

	// get each key and value
	int kc = 0;
	for(kc = 0; kc < Keys.size(); kc ++) {
		std::cout << "(key) : " << Keys[kc] << " (value) : " << Values[kc] << std::endl;
	}

	// get value of "server"
	std::cout << "value of server : \"" << ch.get("server") << "\"" << std::endl;

	return 0;
}
