/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through CANARIE.

==============================================================================*/

#ifndef __qSlicerPlmProtonDoseEngineModule_h
#define __qSlicerPlmProtonDoseEngineModule_h

// SlicerQt includes
#include "qSlicerLoadableModule.h"

#include "qSlicerPlmProtonDoseEngineModuleExport.h"

class qSlicerPlmProtonDoseEngineModulePrivate;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_PLMPROTONDOSEENGINE_EXPORT qSlicerPlmProtonDoseEngineModule : public qSlicerLoadableModule
{
  Q_OBJECT
#ifdef Slicer_HAVE_QT5
  Q_PLUGIN_METADATA(IID "org.slicer.modules.loadable.qSlicerLoadableModule/1.0");
#endif
  Q_INTERFACES(qSlicerLoadableModule);

public:

  typedef qSlicerLoadableModule Superclass;
  explicit qSlicerPlmProtonDoseEngineModule(QObject *parent=0);
  virtual ~qSlicerPlmProtonDoseEngineModule();

  qSlicerGetTitleMacro(QTMODULE_TITLE);

  virtual QString helpText()const;
  virtual QString acknowledgementText()const;
  virtual QStringList contributors()const;

  virtual QStringList categories()const;
  virtual QStringList dependencies() const;

  /// Make this module hidden
  virtual bool isHidden()const { return true; };

protected:

  /// Initialize the module. Register the volumes reader/writer
  virtual void setup();

  /// Create and return the widget representation associated to this module
  virtual qSlicerAbstractModuleRepresentation * createWidgetRepresentation();

  /// Create and return the logic associated to this module
  virtual vtkMRMLAbstractLogic* createLogic();

private:
  Q_DECLARE_PRIVATE(qSlicerPlmProtonDoseEngineModule);
  Q_DISABLE_COPY(qSlicerPlmProtonDoseEngineModule);

};

#endif
