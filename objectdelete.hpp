#ifndef OBJECTDELETE_H
#define OBJECTDELETE_H

#include <QDialog>
#include "sceneinf.hpp"
#include <QErrorMessage>
#include <QDebug>

namespace Ui
{
class ObjectDelete;
}

class ObjectDelete : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectDelete(SceneInf *scene_, QWidget *parent = nullptr);
    ~ObjectDelete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ObjectDelete *ui;
    SceneInf *scene;

    void recalculationModelsNum();
};

#endif
