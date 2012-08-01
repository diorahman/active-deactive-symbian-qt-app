#ifndef BACKGROUNDMUSIC_H
#define BACKGROUNDMUSIC_H

#include <QObject>

#include <phonon/MediaObject>
#include <phonon/AudioOutput>


class BackgroundMusic : public QObject
{
    Q_OBJECT
public:
    explicit BackgroundMusic(QObject *parent = 0);

public slots:
    void play();
    void stop();

private slots:
    void loop();

private:
    Phonon::MediaObject *mediaObject;
    
};

#endif // BACKGROUNDMUSIC_H
