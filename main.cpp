#include "MainWidget.h"
#include <winsock2.h>

#include <QApplication>

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);

    try {

        MainWidget window;
        window.setWindowTitle("Client");
        window.show();

        set_terminate([](){

            qDebug() << "Ex";

        });

        return app.exec();
    }
    catch (exception ex){

        exit(EXIT_FAILURE);
    }

}
