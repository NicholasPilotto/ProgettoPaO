#include <QApplication>

#include "./Utilities/deep_ptr.hpp"
#include "./Utilities/u_vector.hpp"
#include "io_json.h"
#include "view.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	io_json* io = new io_json(":/data/data.json");
	u_vector<deep_ptr<product>> products = io->read();
	view v;
	v.show();
	return a.exec();
}
