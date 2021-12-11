#include <QApplication>
#include "bistromatic.h"

int main(int ac, char **av)
{
    QApplication *app = new QApplication(ac, av);

    bistromatic b;
    b.show();

    return app->exec();
}
