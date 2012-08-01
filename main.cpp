#include <QtGui/QApplication>
#include <qdeclarative.h>
#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include "qmlapplicationviewer.h"

#include "backgroundmusic.h"
#include "eventfilter.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    EventFilter eventFilter;
    app->installEventFilter(&eventFilter);

    qmlRegisterType<BackgroundMusic>("test.app", 1, 0, "BackgroundMusic");

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("AppEvents", &eventFilter);

    viewer.setMainQmlFile(QLatin1String("qml/Sound/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
