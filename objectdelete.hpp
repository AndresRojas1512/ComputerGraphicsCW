#ifndef OBJECTDELETE_H
#define OBJECTDELETE_H

#include <QDialog>
#include "sceneinf.hpp"
#include <QErrorMessage>
#include <QDebug>
#include "facade.hpp"

namespace Ui
{
class ObjectDelete;
}

class ObjectDelete : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectDelete(SceneInf *scene_, BaseMotherboardConfig *mbConfig, bool lightSet_, Facade *facade_, QWidget *parent = nullptr);
    ~ObjectDelete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ObjectDelete *ui;
    SceneInf *scene;
    BaseMotherboardConfig *motherboardConfig;
    bool lightSet = false;
    Facade *facade;

    void recalculationModelsNum();
};

#endif
