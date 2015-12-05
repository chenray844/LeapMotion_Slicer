#include <QCoreApplication>
#include <QDebug>

#include "lm/leapmotionlistener.h"
#include "igt/tracker.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    QStringList settings = QStringList()
            <<QString("%1").arg(argv[1])<<QString("%1").arg(argv[2])<<QString("%1").arg(argv[3]);

    LeapMotionListener listener;
    Leap::Controller controller;

    controller.addListener(listener);

    Tracker *tracker = new Tracker(settings, 0);
    tracker->start();

    std::cin.get();

    controller.removeListener(listener);

    tracker->terminate();
    tracker->quit();

    return 0;
}
