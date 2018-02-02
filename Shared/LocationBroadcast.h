// Copyright 2017 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#ifndef LOCATIONBROADCAST_H
#define LOCATIONBROADCAST_H

#include "Message.h"
#include "Point.h"

#include <QObject>

class MessageSender;
class QTimer;

class LocationBroadcast : public QObject
{
  Q_OBJECT

public:
  explicit LocationBroadcast(QObject* parent = nullptr);
  LocationBroadcast(const QString& messageType, int udpPort, QObject* parent = nullptr);
  ~LocationBroadcast();

  bool isEnabled() const;
  void setEnabled(bool enabled);

  Esri::ArcGISRuntime::Point location() const;
  void setLocation(const Esri::ArcGISRuntime::Point& location);

  bool useCurrentLocation() const;
  void setUseCurrentLocation(bool useCurrentLocation);

  QString messageType() const;
  void setMessageType(const QString& messageType);

  int udpPort() const;
  void setUdpPort(int port);

  int frequency() const;
  void setFrequency(int frequency);

  Message message() const;

signals:
  void messageChanged();

private:
  Q_DISABLE_COPY(LocationBroadcast)

  void update();
  void broadcastLocation();

  bool m_enabled = true;
  Esri::ArcGISRuntime::Point m_location;
  bool m_useCurrentLocation = true;
  QString m_messageType;
  int m_udpPort = -1;
  int m_frequency = 3000;

  MessageSender* m_messageSender = nullptr;
  Message m_message;
  QTimer* m_timer = nullptr;

  QMetaObject::Connection m_locationChangedConn;
};

#endif // LOCATIONBROADCAST_H