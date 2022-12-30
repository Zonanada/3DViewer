#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <glwidget.h>
#include <QMainWindow>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rotation_x_valueChanged();
    void on_rotation_y_valueChanged();
    void on_rotation_z_valueChanged();
    void on_transfer_x_valueChanged();
    void on_transfer_y_valueChanged();
    void on_scale_valueChanged();
    void on_openFile_clicked();

    void on_rW_valueChanged();
    void on_gW_valueChanged();
    void on_bW_valueChanged();
    void on_aW_valueChanged();

    void on_rV_valueChanged();
    void on_gV_valueChanged();
    void on_bV_valueChanged();
    void on_rL_valueChanged();
    void on_gL_valueChanged();
    void on_bL_valueChanged();
    void on_widthLine_valueChanged();
    void on_widthVertex_valueChanged();

private:
    Ui::MainWindow *ui;
    GLWidget *glwidget;

public:
    state_st *getState();
    look_st *getLook();



signals:
    void setState(state_st *state);
    void setFilename(char *name);
    void setLook(look_st *look);
    void setProjection();

};
#endif // MAINWINDOW_H