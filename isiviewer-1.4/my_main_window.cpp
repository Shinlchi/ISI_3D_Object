#include "my_main_window.h"
#include <cmath>
#include <QMessageBox>

/**
 * Construct MyMainWindow
 *
 * @param myScene
 * @param parent
 */
MyMainWindow::MyMainWindow(MyScene* myScene, QWidget *parent) : QMainWindow(parent), _myScene(myScene){
  _ui.setupUi(this);
  _ui.viewer->setMyScene(_myScene);

  // Connect menu items
  connect(_ui.actionQuit, SIGNAL(triggered()),
          this, SLOT(close()));

  connect(_ui.actionAbout, SIGNAL(triggered()),
          this, SLOT(slotAbout()));

  // Connect GUI and myScene
  connect(_ui.radiusSpinBox, SIGNAL(valueChanged(double)),
          _myScene, SLOT(slotSetRadius(double)));

  connect(_myScene, SIGNAL(sigRadiusChanged(double)),
          _ui.radiusSpinBox, SLOT(setValue(double)));

  connect(_myScene, SIGNAL(sigRadiusChanged(double)),
          _ui.viewer, SLOT(updateGL()));


  connect(_ui.checkBox_wireframe, SIGNAL(toggled(bool)),
          _myScene, SLOT(slotSetWireframe(bool)));
  connect(_myScene, SIGNAL(sigWireframeChanged(bool)),
          _ui.viewer, SLOT(updateGL()));
  connect(_myScene, SIGNAL(sigWireframeChanged(bool)),
          _ui.checkBox_wireframe, SLOT(setChecked(bool)));

  connect(_ui.checkBox_smooth, SIGNAL(toggled(bool)),
          _myScene, SLOT(slotSetSmooth(bool)));
  connect(_myScene, SIGNAL(sigSmoothChanged(bool)),
          _ui.viewer, SLOT(updateGL()));
  connect(_myScene, SIGNAL(sigSmoothChanged(bool)),
          _ui.checkBox_smooth, SLOT(setChecked(bool)));

  connect(_ui.checkBox_normals, SIGNAL(toggled(bool)),
          _myScene, SLOT(slotSetDisplayNormals(bool)));
  connect(_myScene, SIGNAL(sigDisplayNormalsChanged(bool)),
          _ui.viewer, SLOT(updateGL()));
  connect(_myScene, SIGNAL(sigDisplayNormalsChanged(bool)),
          _ui.checkBox_normals, SLOT(setChecked(bool)));

  connect(_ui.checkBox_flipnormals, SIGNAL(toggled(bool)),
          _myScene, SLOT(slotSetFlipNormals(bool)));
  connect(_myScene, SIGNAL(sigFlipNormalsChanged(bool)),
          _ui.viewer, SLOT(updateGL()));
  connect(_myScene, SIGNAL(sigFlipNormalsChanged(bool)),
          _ui.checkBox_flipnormals, SLOT(setChecked(bool)));


  // Init GUI default values
  _ui.radiusSpinBox->setValue     (_myScene->radius());
  _ui.radiusSpinBox->setMinimum   (_myScene->radiusMin());
  _ui.radiusSpinBox->setMaximum   (_myScene->radiusMax());
  _ui.radiusSpinBox->setSingleStep(_myScene->radiusIncr());

}

/**
 * Slot About
 *
 */
void MyMainWindow::slotAbout(){
  QMessageBox::about(this, "ISI Viewer", "Base program by\nBruno Jobard\nNoyer Stephane\nSabos Bastien");
}
