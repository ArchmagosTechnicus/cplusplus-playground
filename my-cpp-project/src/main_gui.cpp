#include <QApplication>
#include <QPushButton>
#include <QString>
#include "MyClass.h"
#include <sstream>
#include <iostream>

class MyClassGui : public QPushButton {
public:
    MyClassGui(QWidget* parent = nullptr) : QPushButton(parent) {
        MyClass myObject;
        // Capture the output of myMethod
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        myObject.myMethod();
        std::cout.rdbuf(old);
        setText(QString::fromStdString(buffer.str()));
        connect(this, &QPushButton::clicked, qApp, &QApplication::quit);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyClassGui button;
    button.setWindowTitle("Qt Hello World");
    button.resize(300, 100);
    button.show();
    return app.exec();
}
