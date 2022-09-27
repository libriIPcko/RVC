#include "dialog_2.h"
#include "ui_dialog_2.h"

Dialog_2::Dialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_2)
{
    ui->setupUi(this);
    //mThread1 = new MyThread();
    //mThread2 = new MyThread();
    //mThread3 = new MyThread();

    obj1 = new myNon_QThread;
    obj2 = new myNon_QThread;

}

Dialog_2::~Dialog_2()
{
    delete ui;
}

void Dialog_2::ThrFunction_1(){
    ui->textBrowser->append("Thread_1");
}
void Dialog_2::ThrFunction_2(){
    ui->textBrowser->append("Thread_2");
}

//start
void Dialog_2::on_pushButton_clicked()
{
    /*
        mThread1->name = "mThread1";
        mThread2->name = "mThread2";
        mThread3->name = "mThread3";

        connect(mThread1,SIGNAL(NumberChanged(int,QString)),this,SLOT(on_NumberChanged(int,QString)));
        connect(mThread2,SIGNAL(NumberChanged(int,QString)),this,SLOT(on_NumberChanged(int,QString)));
        connect(mThread3,SIGNAL(NumberChanged(int,QString)),this,SLOT(on_NumberChanged(int,QString)));
     */

        //connect(mThread1,SIGNAL(randomizer_out(int,QString)),this,SLOT(on_randomizer_out(int,QString)));
        //connect(mThread2,SIGNAL(randomizer_out(int,QString)),this,SLOT(on_randomizer_out(int,QString)));
        //connect(mThread3,SIGNAL(randomizer_out(int,QString)),this,SLOT(on_randomizer_out(int,QString)));

        obj1->name = "obj1";
        obj2->name = "obj2";

        QThread first;
        QThread second;

        //mThread1->start(QThread::HighPriority);
        //mThread2->start(QThread::NormalPriority);
        //mThread3->start(QThread::HighestPriority);
        //std::thread thread1(&ThrFunction_1(),std::ref(log));



        /*
        testC *stopwatch = new testC;
        //stopwatch->testCase_Initialize_RADAR("rad");
        TrainThread *trainT = new TrainThread;

        *trainT->var_a = trainT->generate(10);
        for(int n=0;n<=trainT->var_a->length();n++){
            qDebug() <<"n:" << n << " ->" << trainT->var_a->at(n);
        }
        qDebug() << "----------------------------";
        qDebug() << "End";
        //trainT->generate(10,*trainT->var_b);
        //trainT->sum(*trainT->var_a,*trainT->var_b,*trainT->var_c);
        //trainT->saveToFile('+',*trainT->var_a,*trainT->var_b,*trainT->var_c);
        */

}

void Dialog_2::on_NumberChanged(int number,QString name){
    ui->textBrowser->append(name +"\t"+QString::number(number));
}

void Dialog_2::on_NumberChanged(int number){
    ui->textBrowser->append("\t"+QString::number(number));
}
void Dialog_2::on_randomizer_out(int number, QString name){
    ui->textBrowser->append(name + QString::number(number));
}

//stop
void Dialog_2::on_pushButton_2_clicked()
{
    //mThread1->stop = true;
    //mThread2->stop = true;
    //mThread3->stop = true;
}

