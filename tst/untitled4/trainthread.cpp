#include "trainthread.h"
#include "QThread"
#include "QRandomGenerator"


TrainThread::TrainThread()
{
    vectorFile->open(QIODevice::ReadWrite | QFile::Append | QFile::Text);
}
TrainThread::~TrainThread()
{
    vectorFile->close();
}
/*
int TrainThread::generate(int countGenerateFiles, QVector<int> vector){
    for(int n=0;n<=countGenerateFiles;n++){
        vector.push_back(generateNum(0,9));
    }
}
*/
QVector<int> TrainThread::generate(int countGenerateFiles){
    QVector<int> vector;
    for(int n=0;n<countGenerateFiles;n++){
        //vector.push_back(generateNum(0,9));
        vector.push_back(n);
    }
    return vector;
}

int TrainThread::saveToFile(QVector<int> input){
    QTextStream out(vectorFile);
    for(int n=0;n<=input.length();n++){
        out << input[n];
        if(n==input.length()){
            return 0;
        }
        else{
            return 1;
        }
    }
}

int TrainThread::saveToFile(QChar Operation,QVector<int> input_a, QVector<int> input_b, QVector<int> input_c){
    QTextStream out(vectorFile);
    for(int n=0;n<=input_a.length();n++){
        out << input_a[n] << Operation << input_b[n] <<"=" <<input_c[n]<<"\n" ;
    }
    return 0;
}

int TrainThread::loadFromFile(QVector<int> output){
    int n=0;
    while(!vectorFile->atEnd()){
        output[n] = vectorFile->readLine().toInt();
        n++;
    }
}



int TrainThread::generateNum(int min, int max){
    QRandomGenerator gen(10);
    gen.bounded(max);
    //gen.generate();
}

int TrainThread::generateNum(int min, int max,int seed){
    QRandomGenerator gen(seed);
    gen.bounded(min,max);
    gen.generate();
}

int TrainThread::sum(QVector<int> a,QVector<int> b, QVector<int> output){
    int lengthVector;
    if(a.length()!= b.length()){
        if(a.length()>=b.length()){
            lengthVector = a.length();
        }
        else{
            lengthVector = b.length();
        }

    }
    for(int n=0;n<lengthVector;n++){
        output[n] = a[n] + b[n];
    }
}
int TrainThread::subtract(QVector<int> a,QVector<int> b, QVector<int> output){
    int lengthVector;
    if(a.length()!= b.length()){
        if(a.length()>=b.length()){
            lengthVector = a.length();
        }
        else{
            lengthVector = b.length();
        }

    }
    for(int n=0;n<lengthVector;n++){
        output[n] = a[n] - b[n];
    }
    return 0;
}
int TrainThread::multiply(QVector<int> a,QVector<int> b, QVector<int> output){
    int lengthVector;
    if(a.length()!= b.length()){
        if(a.length()>=b.length()){
            lengthVector = a.length();
        }
        else{
            lengthVector = b.length();
        }

    }
    for(int n=0;n<lengthVector;n++){
        output[n] = a[n] * b[n];
    }
    return 0;
}
int TrainThread::divide(QVector<int> a,QVector<int> b, QVector<int> output){
    int lengthVector;
    if(a.length()!= b.length()){
        if(a.length()>=b.length()){
            lengthVector = a.length();
        }
        else{
            lengthVector = b.length();
        }
        return 0;

    }
    for(int n=0;n<lengthVector;n++){
        if(b[n] == 0){
            output[n] = 0;
        }
        else{
            output[n] = a[n] / b[n];
        }
        return 0;
    }
}



