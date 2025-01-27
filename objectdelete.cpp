#include "objectdelete.hpp"
#include "ui_objectdelete.h"

#include "objectdelete.hpp"
#include "ui_objectdelete.h"

ObjectDelete::ObjectDelete(SceneInf *scene_, QWidget *parent)
    : QDialog(parent), ui(new Ui::ObjectDelete)
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

    for (int i = 0; i < modelIndexMap.size(); ++i)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setData(Qt::UserRole, QVariant(modelIndexMap[i]));
    }
}


ObjectDelete::~ObjectDelete() { delete ui; }

void ObjectDelete::on_pushButton_clicked() {
    int curRow = this->ui->listWidget->currentRow();
    if (curRow < 0) return;

    int mainModelIndex = ui->listWidget->item(curRow)->data(Qt::UserRole).toInt();
    PolygonModel mainModel = scene->getModel(mainModelIndex);
    PolygonModel::model_t mainModelType = mainModel.getModelType();
    PolygonModel::model_t accessoryModelType = mapModelAccessory(mainModelType);

    int accessoryModelIndex = -1;
    for (size_t i = 0; i < scene->getModelsNum(); i++) {
        if (scene->getModel(i).getModelType() == accessoryModelType) {
            accessoryModelIndex = i;
            break;
        }
    }

    if (accessoryModelIndex != -1) {
        scene->deleteModel(accessoryModelIndex);
    }

    scene->deleteModel(mainModelIndex);
    ui->listWidget->takeItem(curRow);

    close();
}

void ObjectDelete::recalculationModelsNum() {
    size_t modelsNum = scene->getModelsNum();
    for (size_t i = 0; i < modelsNum; i++) {
        scene->getModel(i).setModelNum(i);
    }
}
