#include "objectdelete.hpp"
#include "ui_objectdelete.h"

#include "objectdelete.hpp"
#include "ui_objectdelete.h"

ObjectDelete::ObjectDelete(SceneInf *scene_, BaseMotherboardConfig *mbConfig, bool lightSet_, Facade *facade_, QWidget *parent)
    : QDialog(parent), motherboardConfig(mbConfig), lightSet(lightSet_), facade(facade_), ui(new Ui::ObjectDelete)
{
    ui->setupUi(this);
    this->setWindowTitle("Удаление объектов сцены");

    scene = scene_;
    std::vector<PolygonModel> models = scene->getModels();
    std::vector<int> modelIndexMap;

    int count = 0;
    for (size_t i = 0; i < models.size(); ++i)
    {
        QString modelName = models[i].getName();
        if (!modelName.startsWith("ATX") && !modelName.startsWith("MICROATX") && !modelName.startsWith("MINIITX") && !modelName.contains("ACC"))
        {
            ui->listWidget->addItem(QString::number(count + 1) + ". " + modelName);
            modelIndexMap.push_back(i);
            count++;
        }
    }

    if (lightSet && scene->getLightNum() > 0)
    {
        for (size_t i = 0; i < scene->getLightNum(); i++)
        {
            QString lightDescription = QString::number(count + 1) + ". Light Source (" +
                                       QString::number(scene->getLight(i).getXAngle()) + "°; " +
                                       QString::number(scene->getLight(i).getYAngle()) + "°)";
            QListWidgetItem* item = new QListWidgetItem(lightDescription);
            item->setData(Qt::UserRole, QVariant(int(models.size() + i)));
            item->setData(Qt::UserRole + 1, true);
            ui->listWidget->addItem(item);
        }
    }

    for (int i = 0; i < modelIndexMap.size(); ++i)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setData(Qt::UserRole, QVariant(modelIndexMap[i]));
    }
}

ObjectDelete::~ObjectDelete() { delete ui; }

void ObjectDelete::on_pushButton_clicked()
{
    int curRow = this->ui->listWidget->currentRow();
    if (curRow < 0) return;

    bool isLightItem = ui->listWidget->item(curRow)->data(Qt::UserRole + 1).toBool();

    if (isLightItem)
    {
        int lightIndex = ui->listWidget->item(curRow)->data(Qt::UserRole).toInt() - scene->getModelsNum();
        scene->deleteLight(lightIndex);
        facade->removeLight();
        ui->listWidget->takeItem(curRow);
    }
    else
    {
        int modelIndex = ui->listWidget->item(curRow)->data(Qt::UserRole).toInt();
        PolygonModel mainModel = scene->getModel(modelIndex);
        PolygonModel::model_t mainModelType = mainModel.getModelType();
        PolygonModel::model_t accessoryModelType = mapModelAccessory(mainModelType);

        int accessoryModelIndex = -1;
        for (size_t i = 0; i < scene->getModelsNum(); i++)
        {
            if (scene->getModel(i).getModelType() == accessoryModelType)
            {
                accessoryModelIndex = i;
                break;
            }
        }

        if (accessoryModelIndex != -1)
        {
            scene->deleteModel(accessoryModelIndex);
        }

        scene->deleteModel(modelIndex);
        if (isRamModel(mainModel.getModelType()))
        {
            motherboardConfig->freeRamSlot(mainModel.getSlot());
        }
        else if (isGpuModel(mainModel.getModelType()))
        {
            motherboardConfig->freeGpuSlot(mainModel.getSlot());
        }
        else
        {
            motherboardConfig->freeCpuSlot();
        }

        ui->listWidget->takeItem(curRow);
    }

    recalculationModelsNum();
    close();
}


void ObjectDelete::recalculationModelsNum()
{
    size_t modelsNum = scene->getModelsNum();
    for (size_t i = 0; i < modelsNum; i++)
    {
        scene->getModel(i).setModelNum(i);
    }
}
