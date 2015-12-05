#include <QDebug>
#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

#include "leapmotionlistener.h"


const QStringList fingerNames = QStringList()<<"Thumb"<<"Index"<<"Middle"<<"Ring"<<"Pinky";
const QStringList boneNames = QStringList()<<"Metacarpal"<<"Proximal"<<"Middle"<<"Distal";
const QStringList stateNames = QStringList()<<"STATE_INVALID"<<"STATE_START"<<"STATE_UPDATE"<<"STATE_END";

void LeapMotionListener::onInit(const Leap::Controller & controller)
{
    Q_UNUSED(controller);
    qDebug()<<"Initialized Leap Motion";
}

void LeapMotionListener::onConnect(const Leap::Controller & controller)
{
    qDebug()<<"Connected Leap Motion";
    controller.enableGesture(Leap::Gesture::TYPE_CIRCLE);
    controller.enableGesture(Leap::Gesture::TYPE_KEY_TAP);
    controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);
    controller.enableGesture(Leap::Gesture::TYPE_SWIPE);

}

void LeapMotionListener::onDisconnect(const Leap::Controller & controller)
{
    Q_UNUSED(controller);
    qDebug()<<"Disconnected Leap Motion";

}

void LeapMotionListener::onExit(const Leap::Controller & controller)
{
    Q_UNUSED(controller);
    qDebug()<<"Exit Leap Motion";
}

void LeapMotionListener::onFrame(const Leap::Controller & controller)
{
    const Leap::Frame frame = controller.frame();

    Leap::HandList hands = frame.hands();
    for (Leap::HandList::const_iterator hl = hands.begin(); hl!=hands.end();hl++)
    {
        const Leap::Hand hand = *hl;
        QString handType = hand.isLeft() ? "Left hand" : "Right hand";
        qDebug()<<handType<<"id: "<<hand.id()<<"palm position: "
               <<hand.palmPosition().x<<hand.palmPosition().y<<hand.palmPosition().z;

        QFile f("share.dat");
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&f);
        out<<QString("%1 %2 %3").arg(hand.palmPosition().x)
          .arg(hand.palmPosition().y).arg(hand.palmPosition().z);

        f.close();

    }

}

void LeapMotionListener::onFocusGained(const Leap::Controller & controller)
{
    Q_UNUSED(controller);
    qDebug()<<"Focus Gained ";

}

void LeapMotionListener::onFocusLost(const Leap::Controller & controller)
{
    Q_UNUSED(controller);
    qDebug()<<"Focus Lost";

}

void LeapMotionListener::onDeviceChange(const Leap::Controller &controller)
{
    Q_UNUSED(controller);
}

void LeapMotionListener::onServiceConnect(const Leap::Controller &controller)
{
    Q_UNUSED(controller);
    qDebug()<<"Service Connected";
}

void LeapMotionListener::onServiceDisconnect(const Leap::Controller &controller)
{
    Q_UNUSED(controller);
    qDebug()<<"Service Disconnected";
}


