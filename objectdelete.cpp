#include "objectdelete.hpp"
#include "ui_objectdelete.h"

ObjectDelete::ObjectDelete(SceneInf *scene_, QWidget *parent)
    : QDialog(parent), ui(new Ui::ObjectDelete)
{
    std::cout << "ObjectDelete::ObjectDelete" << std::endl;
    ui->setupUi(this);
    this->setWindowTitle("Удаление объектов сцены");

    scene = scene_;

    PolygonModel model;
    int count = 0;

    for (size_t i = 0; i < scene->getModelsNum(); i++)
    {
        model = scene->getModel(i);
        count++;
        ui->listWidget->addItem(
            QString::number(count) + ". " +
            scene->getModel(i).getName()       + " - (" +
            QString::number(scene->getModel(i).getUsedXCell() + 1) + "; " +
            QString::number(scene->getModel(i).getUsedYCell() + 1) + "; " +
            QString::number(scene->getModel(i).getUsedZCell()) + ")");
    }

    for (size_t i = 0; i < scene->getLightNum(); i++)
        ui->listWidget->addItem(
            QString::number(count + i + 1)                       + ". Источ. света (" +
            QString::number(scene->getLight(i).getXAngle()) + "°; " +
            QString::number(scene->getLight(i).getYAngle()) + "°)");
}

ObjectDelete::~ObjectDelete() { delete ui; }

void ObjectDelete::on_pushButton_clicked()
{
    size_t curRow = size_t(this->ui->listWidget->currentRow());
    if (curRow < 0)
        return;

    size_t modelsNum = scene->getModelsNum();
    bool flag = true;
    PolygonModel model;

    if (curRow < modelsNum)
    {
        int modelLength;
        int modelWidth;

        model = scene->getModel(curRow);
        modelLength = model.getLengthModel();
        modelWidth = model.getWidthModel();

        if (flag)
        {
            scene->deleteModel(curRow);
            modelsNum --;
        }

        recalculationModelsNum();
    }
    else
    {
        scene->deleteLight(curRow - modelsNum);
    }
    close();
}

void ObjectDelete::recalculationModelsNum()
{
    size_t modelsNum = scene->getModelsNum();
    PolygonModel model;
    int cur = 0;

    for (size_t i = 0; i < modelsNum; i++)
    {
        scene->getModel(cur).setModelNum(i);
        model = scene->getModel(cur);
    }
}
