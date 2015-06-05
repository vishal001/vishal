#include <iostream>
#include <string>
#include <stdio.h>

#ifdef TINYDB
#include "tinydb/tinydb.h"
#endif

using namespace std;
int main(int /*argc*/ , char * /*args*/[])
{
	string message("Hello, world!!");
	cout << message << endl;

	int exitCode = 0;
#ifdef TINYDB
	try {
		TinyDB db;
		db.init("Hello", true); // auto flush when dirty
		cout << "English: " << db.getMString("en_US") << endl;
		cout << "Chinese: " << db.getMString("zh_TW") << endl;

		db.setMString("en_US", "hello, world!");
		db.setMString("zh_TW", "你好，世界！");
	}
	catch (TinyDBError& error) {
		cerr << error.what() << endl;
		exitCode = 1;
	}
#endif

	return exitCode;
}

