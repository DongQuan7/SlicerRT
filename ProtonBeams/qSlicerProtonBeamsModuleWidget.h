/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

#ifndef __qSlicerProtonBeamsModuleWidget_h
#define __qSlicerProtonBeamsModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerProtonBeamsModuleExport.h"

class qSlicerProtonBeamsModuleWidgetPrivate;
class vtkMRMLNode;
class QTableWidgetItem;

// STD includes
#include <map>

/// \ingroup Slicer_QtModules_Beams
class Q_SLICER_QTMODULES_PROTONBEAMS_EXPORT 
qSlicerProtonBeamsModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT
  QVTK_OBJECT

public:
  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerProtonBeamsModuleWidget(QWidget *parent=0);
  virtual ~qSlicerProtonBeamsModuleWidget();

  virtual void enter();

public slots:
  /// Set the current MRML scene to the widget
  virtual void setMRMLScene(vtkMRMLScene*);

  /// Process loaded scene
  void onSceneImportedEvent();

  /// Set current parameter node
  void setBeamsNode(vtkMRMLNode *node);

  /// Update widget GUI from parameter node
  void updateWidgetFromMRML();

protected slots:
  void isocenterFiducialNodeChanged(vtkMRMLNode*);
  void sourceFiducialNodeChanged(vtkMRMLNode*);

  void beamModelNodeChanged(vtkMRMLNode*);

  void applyClicked();

  void onLogicModified();

protected:
  QScopedPointer<qSlicerProtonBeamsModuleWidgetPrivate> d_ptr;

protected:
  virtual void setup();
  void onEnter();

protected:
  /// Updates button states
  void updateButtonsState();

  /// Assemble new output volume base name from the selected input fiducial names
  void refreshOutputBaseName();

private:
  Q_DECLARE_PRIVATE(qSlicerProtonBeamsModuleWidget);
  Q_DISABLE_COPY(qSlicerProtonBeamsModuleWidget);
};

#endif