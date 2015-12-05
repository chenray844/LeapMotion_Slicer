#ifndef TRACKER_H
#define TRACKER_H

#include <QThread>
#include <QStringList>
#include <QString>
#include <QList>

class Tracker : public QThread
{
    Q_OBJECT
public:
    Tracker(QStringList &settings, QObject *parent=0);
    ~Tracker();

    void run();

private:
    QStringList _settings;
};

#endif // TRACKER_H

