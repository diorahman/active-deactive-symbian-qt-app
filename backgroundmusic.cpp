#include "backgroundmusic.h"

#include <QDesktopServices>
#include <QFile>

#include <QDebug>

BackgroundMusic::BackgroundMusic(QObject *parent) :
    QObject(parent)
{
    mediaObject = new Phonon::MediaObject(parent);
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, parent);
    Phonon::createPath(mediaObject, audioOutput);
    connect(mediaObject, SIGNAL(finished()), SLOT(loop()));
}

void BackgroundMusic::play()
{
    //qDebug() << "->" << QFile::exists("E:/Sounds/Digital/Beautiful_World.mp3");
    mediaObject->setCurrentSource(Phonon::MediaSource("E:/Sounds/Digital/Beautiful_World.mp3"));
    mediaObject->play();
}

void BackgroundMusic::stop()
{
    mediaObject->stop();
}

void BackgroundMusic::loop()
{
    play();
}
