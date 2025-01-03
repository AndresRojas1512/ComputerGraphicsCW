#ifndef OBJECTCHANGE_H
#define OBJECTCHANGE_H

#include <QDialog>
#include "sceneinf.hpp"
#include "facade.hpp"
#include "objectmove.hpp"
#include <iostream>
#include <QErrorMessage>
#include <QDebug>

namespace Ui
{
class ObjectChange;
}

class ObjectChange : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectChange(Facade *facade_, QWidget *parent = nullptr);
    ~ObjectChange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ObjectChange *ui;
    Facade *facade;

    int changeModel(PolygonModel &model, int newXCell, int newYCell);
    void recalculationModelsNum();
};

#endif
