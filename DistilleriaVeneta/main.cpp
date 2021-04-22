#include <QApplication>

#include "./Utilities/deep_ptr.hpp"
#include "./Utilities/u_vector.hpp"
#include "view.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	view v;
	v.show();
	return a.exec();
}
