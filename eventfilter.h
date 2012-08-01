#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>

class EventFilter : public QObject
{
    Q_OBJECT


public:
    explicit EventFilter(QObject *parent = 0);

signals:
    void activated();
    void deactivated();

protected:
    bool eventFilter(QObject *, QEvent *);

    
};

#endif // EVENTFILTER_H
