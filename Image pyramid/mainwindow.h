#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QSpinBox>
#include<QPixmap>
#include<QScrollArea>
#include<QPushButton>
#include<QComboBox>
#include<QLineEdit>
#include<QtAlgorithms>
#include<QMessageBox>
#include<qmath.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget wgt;
    QHBoxLayout horLay;//= new QHBoxLayout;
    QVBoxLayout vertBar;//= new QVBoxLayout;
    QComboBox imageBx;//= new QComboBox;
    QDoubleSpinBox layer;//= new QDoubleSpinBox;
    QLabel* imageLbl= new QLabel;
    QLabel* fileLbl=new QLabel("Image num: ");
    QLabel* layerLbl= new QLabel("Layer: ");
    QLabel* sizeLbl= new QLabel("Size: ");
    QLabel* chC= new QLabel("Coefficient: ");
    QDoubleSpinBox changeStep;//= new QDoubleSpinBox;
    QLabel size;

    QHBoxLayout lyt;
      QPixmap pxm;
      int w,h;
      QScrollArea sa;
      QPushButton* download= new QPushButton("Download image");
      QStringList lst;

        QHBoxLayout downHorlyt;//= new QHBoxLayout;
        QWidget downWgt;//= new QWidget;
        QPushButton* btn= new QPushButton("Load");
        QLabel* addr= new QLabel("Path: ");
        QLineEdit ln;//n= new QLineEdit;
        QVector<QPixmap> vectPxm;
           QMessageBox msbx;




    public slots:
       void changeLayer(double count);
       void downloadPxmp();
       void load();
       void changePix(int number);
       void changeCoef(double c);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
