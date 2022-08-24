#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include "../include/FileHandler.h"


void Files::writeToFile(std::string filePath, std::string message) {
    QFile file(QString::fromStdString(filePath));
    if(!file.open(QIODevice::WriteOnly)){
        return;
    }
    QTextStream out(&file);
    out << QString::fromStdString(message);
}

std::string Files::readFromFile(std::string filePath) {
    QFile file(QString::fromStdString(filePath));
    if(!file.open(QIODevice::ReadOnly)){
        return "BADFILE";
    }
    QTextStream in(&file);
    return in.readAll().toStdString();
}

bool Files::badText(std::string message) {

    if (message == "BADFILE") {
        std::cout << "The file is empty!" << std::endl;
        return true;
    }
    else if (message.length() == 0) {
        std::cout << "The file does not exist!" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}