#include <QApplication>
#include "view.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	view v;
	v.show();
	return a.exec();
}
