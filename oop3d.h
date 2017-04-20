#ifndef OOP_3D_
#define OOP_3D_

#include <iostream>
#include <stdarg.h>
#include <stdio.h> /* include header for logging */
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <fstream>

#define __NEED_DEBUG /* TODO in qmake */

#ifdef __NEED_DEBUG
#include "log.h"
#endif

/**
  qt library
**/
#include <QMainWindow>

#include <QWidget>
#include <QtGui>
#include <QPen>
#include <QErrorMessage>
#include <QString>
#include <QStringList>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemGroup>
#include <QRegExpValidator>
#include <QIntValidator>
#include <QFileDialog>
#include <QTimer>
#include <QHBoxLayout>

#include <QPainter>
#include <QPaintEvent>

#include "my_stream.h"

#include "my_scene.h"

#include "action.h"
#include "edges.h"
#include "point.h"
#include "point_arr.h"

#include "work.h"
#include "draw_on_scene.h"
#include "errors.h"
#include "model.h"
#include "model_action.h"

#endif
