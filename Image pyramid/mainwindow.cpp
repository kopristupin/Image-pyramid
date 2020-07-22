#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layer.setRange(0, 20);
    layer.setSingleStep(2);
    layer.setValue(0);

    changeStep.setValue(2.0);
    changeStep.setRange(1.0,3.0);


    horLay.addWidget(fileLbl);
    horLay.addWidget(&imageBx);
    horLay.addWidget(sizeLbl);
    horLay.addWidget(&layer);
    horLay.addWidget(&size);
    horLay.addWidget(chC);
    horLay.addWidget(&changeStep);

    lyt.addWidget(imageLbl);
    wgt.setLayout(&lyt);
    sa.setWidget(&wgt);
    ui->verticalLayout->addLayout(&horLay);
    ui->verticalLayout->addWidget(&sa);
    ui->verticalLayout->addWidget(download);

    downHorlyt.addWidget(addr);
    downHorlyt.addWidget(&ln);
    downHorlyt.addWidget(btn);
    downWgt.setLayout(&downHorlyt);

    connect(&layer, SIGNAL(valueChanged(double)), this, SLOT(changeLayer(double)));
    connect(download, &QPushButton::clicked, this, &MainWindow::downloadPxmp);
    connect(btn, &QPushButton::clicked, this, &MainWindow::load);
    connect(&imageBx, SIGNAL(currentIndexChanged(int)), this, SLOT(changePix(int)));
    connect(&changeStep, SIGNAL(valueChanged(double)), this, SLOT(changeCoef(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeLayer(double count){
if(!vectPxm.empty()){
    if(count==0)
        count=1;
    imageLbl->setScaledContents(true);
    QPixmap newPm= vectPxm[imageBx.currentIndex()].scaled(vectPxm[imageBx.currentIndex()].width()/count, vectPxm[imageBx.currentIndex()].height()/count);
    imageLbl->setPixmap(newPm);
    size.setText(QString::number(newPm.height())+"x"+QString::number(newPm.width()) );
    }
}

void MainWindow::changePix(int number){
    layer.setValue(0);
    imageLbl->setScaledContents(false);
    wgt.resize(vectPxm[number].width(), vectPxm[number].height());
    imageLbl->setPixmap(vectPxm[number]);
    size.setText( QString::number(vectPxm[number].height())+"x"+QString::number(vectPxm[number].width()));
}

void MainWindow::downloadPxmp(){
    downWgt.show();
}

void MainWindow::load(){
    QPixmap* loadedpxmp= new QPixmap;
    if(!loadedpxmp->load(ln.text())){
        QMessageBox::warning(nullptr, "Information", "Load error!");
    }
    else{

        vectPxm.push_back(*loadedpxmp);
        qSort(vectPxm.begin(), vectPxm.end(), [](QPixmap p1, QPixmap p2) { return qSqrt(qPow(p1.width(),2)+qPow(p1.height(),2)) < qSqrt(qPow(p2.width(),2)+ qPow(p2.height(),2));});
        lst.push_back(QString::number(lst.count()+1));
        imageBx.addItem(QString::number(lst.size()));
        QMessageBox::information(nullptr, "Information", "Image loaded!");
    }
}

void MainWindow::changeCoef(double c){
    layer.setSingleStep(c);
    layer.setValue(0);
}



