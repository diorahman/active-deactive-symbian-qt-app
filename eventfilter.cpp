#include "eventfilter.h"
#include <QEvent>
#include <QDebug>

EventFilter::EventFilter(QObject *parent) :
    QObject(parent)
{
}

bool EventFilter::eventFilter(QObject * obj, QEvent * e)
{
    if (e->type() == QEvent::ApplicationDeactivate) {
        emit deactivated();
        return true;
    }

    if (e->type() == QEvent::ApplicationActivate) {
        emit activated();
        return true;
    }

    return QObject::eventFilter(obj, e);
}
