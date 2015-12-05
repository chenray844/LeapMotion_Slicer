#ifndef LEAPMOTIONLISTENER_H
#define LEAPMOTIONLISTENER_H

#include <QString>
#include <QStringList>
#include <QList>

#include "Leap.h"


class LeapMotionListener : public Leap::Listener
{
public:
    void onInit(const Leap::Controller&);
    void onConnect(const Leap::Controller&);
    void onDisconnect(const Leap::Controller&);
    void onExit(const Leap::Controller&);
    void onFrame(const Leap::Controller&);
    void onFocusGained(const Leap::Controller&);
    void onFocusLost(const Leap::Controller&);
    void onDeviceChange(const Leap::Controller&);
    void onServiceConnect(const Leap::Controller&);
    void onServiceDisconnect(const Leap::Controller&);


private:


};


#endif // LEAPMOTIONLISTENER_H

