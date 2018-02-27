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

#include "GraphicsOverlaysResultsManager.h"

#include "IdentifyGraphicsOverlayResult.h"

using namespace Esri::ArcGISRuntime;

// RAII helper to ensure the QList<IdentifyGraphicsOverlayResult*> is deleted when we leave the scope
GraphicsOverlaysResultsManager::GraphicsOverlaysResultsManager(QList<Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult*>& results):
  m_results(results)
{

}

GraphicsOverlaysResultsManager::~GraphicsOverlaysResultsManager()
{
  qDeleteAll(m_results);
}
