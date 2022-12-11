/// \file
#include "glwidget.h"

/**
 * @brief Construct a new GLWidget::GLWidget object
 *
 * @param parent
 */
GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
  data = NULL;

  rL = 0.0;
  gL = 1.0;
  bL = 0.0;
  rV = 1;
  gV = 0;
  bV = 0;
  rW = 0;
  gW = 0;
  bW = 0;
  aW = 0;
  widthLine = 1.0;
  widthVertex = 3.0;
  perspective = 1;
  typeLine = 0;
}
/**
 * @brief Destroy the GLWidget::GLWidget object
 *
 */
GLWidget::~GLWidget() {}

/**
 * @brief This function should set up any required OpenGL resources and state.
 *
 */
void GLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

/**
 * @brief This virtual function is called whenever the widget needs to be
 * painted.
 *
 */
void GLWidget::paintGL() {
  if (data != NULL) {
    glClearColor(rW, gW, bW, aW);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(widthLine);
    glColor3d(rL, gL, bL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, data->vertex.arr);
    glDrawElements(GL_LINES, data->index.memory, GL_UNSIGNED_INT,
                   data->index.arr);

    glPointSize(GLfloat(widthVertex));
    glColor3d(rV, gV, bV);

    glDrawArrays(GL_POINTS, 0, data->vertex.memory / 3);
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

/**
 * @brief
 *
 * @param pointer struct with all object state changes
 */
void GLWidget::setState(state_st *state) {
  stateСhange(&data->vertex, state);
  update();
}

/**
 * @brief parse the file and return data for rendering
 *
 * @param pointer string file name
 */
void GLWidget::setFilename(char *name) {
  if (data != NULL) {
    deleteData(data);
  }
  data = getData(name);
  update();
}

void GLWidget::setLook(look_st *look) {
  rW = look->rW;
  gW = look->gW;
  bW = look->bW;
  aW = look->aW;

  rV = look->rV;
  gV = look->gV;
  bV = look->bV;

  rL = look->rL;
  gL = look->gL;
  bL = look->bL;

  widthLine = look->widthLine;
  widthVertex = look->widthVertex;
  update();
}

/**
 * @brief projection change
 *
 */
void GLWidget::setProjection() {
  if (perspective == 1) {
    perspective = 0;
  } else {
    perspective = 1;
  }
  update();
}
