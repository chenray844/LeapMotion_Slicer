#include <QDebug>
#include <QByteArray>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <math.h>

#include "tracker.h"

#include "igtl/igtlOSUtil.h"
#include "igtl/igtlTransformMessage.h"
#include "igtl/igtlClientSocket.h"

Tracker::Tracker(QStringList &settings, QObject *parent)
    :QThread(parent)
{
    _settings.clear();
    _settings = settings;

    setTerminationEnabled(true);
}

Tracker::~Tracker()
{
    _settings.clear();
}

void Tracker::run()
{
    QByteArray tmp = _settings.at(0).toLatin1();
    char*  hostname = new char[tmp.size()];
    strcpy(hostname, tmp.data());
    int    port     = _settings.at(1).toInt();
    double fps      = _settings.at(2).toDouble();
    int    interval = (int) (1000.0 / fps);

    //------------------------------------------------------------
    // Establish Connection

    igtl::ClientSocket::Pointer socket;
    socket = igtl::ClientSocket::New();
    int r = socket->ConnectToServer(hostname, port);

    if (r != 0)
    {
        qDebug()<<"Cannot connect to the server.";
        return;
    }

    //------------------------------------------------------------
    // Allocate Transform Message Class

    igtl::TransformMessage::Pointer transMsg;
    transMsg = igtl::TransformMessage::New();
    transMsg->SetDeviceName("Tracker");

    //------------------------------------------------------------
    // Allocate TimeStamp class
    igtl::TimeStamp::Pointer ts;
    ts = igtl::TimeStamp::New();

    //------------------------------------------------------------
    igtl::Matrix4x4 matrix;
    float position[3];
    float orientation[4];
    // loop
    while (1)
    {

        QFile f("share.dat");
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
            continue;
        QTextStream in(&f);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList values = line.split(" ");
            if (values.size()!=3)
                continue;
            for (int i=0;i<values.size();i++)
            {
                QString value = values.at(i);
                position[i] = value.toDouble();
            }
        }
        f.close();

        // random orientation
        static float theta = 0.0;
        orientation[0]=0.0;
        orientation[1]=0.6666666666*cos(theta);
        orientation[2]=0.577350269189626;
        orientation[3]=0.6666666666*sin(theta);
        theta = theta + 0.1;

        //igtl::Matrix4x4 matrix;
        igtl::QuaternionToMatrix(orientation, matrix);

        matrix[0][3] = position[0];
        matrix[1][3] = position[1];
        matrix[2][3] = position[2];

        igtl::PrintMatrix(matrix);

//        ts->GetTime();
//        transMsg->SetMatrix(matrix);
//        transMsg->SetTimeStamp(ts);
//        transMsg->Pack();
//        socket->Send(transMsg->GetPackPointer(), transMsg->GetPackSize());
        igtl::Sleep(interval); // wait
    }

    //------------------------------------------------------------
    // Close connection

    socket->CloseSocket();
    delete [] hostname;

}
