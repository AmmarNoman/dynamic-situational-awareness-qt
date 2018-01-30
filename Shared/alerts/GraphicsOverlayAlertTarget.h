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

#ifndef GRAPHICSOVERLAYALERTTARGET_H
#define GRAPHICSOVERLAYALERTTARGET_H

namespace Esri
{
namespace ArcGISRuntime
{
class Graphic;
class GraphicsOverlay;
}
}

#include "AlertTarget.h"

class GraphicsOverlayAlertTarget : public AlertTarget
{
  Q_OBJECT

public:
  explicit GraphicsOverlayAlertTarget(Esri::ArcGISRuntime::GraphicsOverlay* graphicsOverlay);
  ~GraphicsOverlayAlertTarget();

  virtual QList<Esri::ArcGISRuntime::Geometry> targetGeometries() const override;

private:
  void setupGraphicConnections(Esri::ArcGISRuntime::Graphic* graphic);

  Esri::ArcGISRuntime::GraphicsOverlay* m_graphicsOverlay = nullptr;
  QList<QMetaObject::Connection> m_graphicConnections;
};

#endif // GRAPHICSOVERLAYALERTTARGET_H
