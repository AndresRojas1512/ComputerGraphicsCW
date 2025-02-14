#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    std::cout << "MainWindow::MainWindow" << std::endl;
    ui->setupUi(this);

    facade = new Facade(configManager);

    ui->comboBoxMotherboardType->addItem("ATX");
    ui->comboBoxMotherboardType->addItem("Micro-ATX");
    ui->comboBoxMotherboardType->addItem("Mini-ITX");

    auto gpus = configManager.getCompatibleGPUs();
    auto rams = configManager.getCompatibleRAMs();
    auto cpus = configManager.getCompatibleCPUs(ConfigManager::MotherboardType::ATX);

    ui->listWidgetProcessor->clear();
    ui->listWidgetGPU->clear();
    ui->listWidgetRAM->clear();

    for (auto gpu : gpus)
    {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(gpuTypeToString(gpu)));
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<int>(gpu)));
        ui->listWidgetGPU->addItem(item);
    }
    for (auto cpu : cpus)
    {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(cpuTypeToString(cpu)));
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<int>(cpu)));
        ui->listWidgetProcessor->addItem(item);
    }
    for (auto ram : rams)
    {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(ramTypeToString(ram)));
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<int>(ram)));
        ui->listWidgetRAM->addItem(item);
    }

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QShortcut *shortcutDown = new QShortcut(QKeySequence("down"), this);
    QObject::connect(shortcutDown, SIGNAL(activated()), this, SLOT(pictureDown()));

    QShortcut *shortcutUp = new QShortcut(QKeySequence("up"), this);
    QObject::connect(shortcutUp, SIGNAL(activated()), this, SLOT(pictureUp()));

    QShortcut *shortcutLeft = new QShortcut(QKeySequence("left"), this);
    QObject::connect(shortcutLeft, SIGNAL(activated()), this, SLOT(pictureLeft()));

    QShortcut *shortcutRight = new QShortcut(QKeySequence("right"), this);
    QObject::connect(shortcutRight, SIGNAL(activated()), this, SLOT(pictureRight()));

    QShortcut *shortcutScaleUp = new QShortcut(QKeySequence("+"), this);
    QObject::connect(shortcutScaleUp, SIGNAL(activated()), this, SLOT(pictureScaleUp()));

    QShortcut *shortcutScaleDown = new QShortcut(QKeySequence("-"), this);
    QObject::connect(
        shortcutScaleDown, SIGNAL(activated()), this, SLOT(pictureScaleDown()));

    QShortcut *shortcutRotateXRight = new QShortcut(QKeySequence("s"), this);
    QObject::connect(
        shortcutRotateXRight, SIGNAL(activated()), this, SLOT(pictureRotateXRight()));

    QShortcut *shortcutRotateXLeft = new QShortcut(QKeySequence("w"), this);
    QObject::connect(
        shortcutRotateXLeft, SIGNAL(activated()), this, SLOT(pictureRotateXLeft()));

    QShortcut *shortcutRotateYRight = new QShortcut(QKeySequence("a"), this);
    QObject::connect(
        shortcutRotateYRight, SIGNAL(activated()), this, SLOT(pictureRotateYRight()));

    QShortcut *shortcutRotateYLeft = new QShortcut(QKeySequence("d"), this);
    QObject::connect(
        shortcutRotateYLeft, SIGNAL(activated()), this, SLOT(pictureRotateYLeft()));

    QShortcut *shortcutRotateZRight = new QShortcut(QKeySequence("q"), this);
    QObject::connect(
        shortcutRotateZRight, SIGNAL(activated()), this, SLOT(pictureRotateZRight()));

    QShortcut *shortcutRotateZLeft = new QShortcut(QKeySequence("e"), this);
    QObject::connect(
        shortcutRotateZLeft, SIGNAL(activated()), this, SLOT(pictureRotateZLeft()));
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::pictureDown()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveDownScene(MOVE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureUp()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveUpScene(MOVE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureLeft()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveLeftScene(MOVE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRight()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->moveRightScene(MOVE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureScaleUp()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->scaleScene(SCALE_VAL + 1, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureScaleDown()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->scaleScene(1 - SCALE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateXRight()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateXScene(ROTATE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateXLeft()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateXScene(-ROTATE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateYRight()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateYScene(ROTATE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateYLeft()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateYScene(-ROTATE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateZRight()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateZScene(ROTATE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureRotateZLeft()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->rotateZScene(-ROTATE_VAL, ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::pictureToCenter()
{
    if (!facade->isSceneSet())
        return;

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();

    QGraphicsScene *setScene = facade->toCenter(ui->graphicsView->rect());
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButtonCreateMotherboard_clicked()
{
    ConfigManager::MotherboardType type = static_cast<ConfigManager::MotherboardType>(ui->comboBoxMotherboardType->currentIndex());
    QString selectedType = ui->comboBoxMotherboardType->currentText();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подверждение формата материнской платы",
                                  "Выбранный формат: " + selectedType + ". Уверены, что хотите построить материнскую плату выбранного формата?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        facade->setSceneInfMotherboard(type);
        QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

        if (ui->graphicsView->scene())
            delete ui->graphicsView->scene();
        ui->graphicsView->setScene(setScene);
    }
    facade->removeLight();
    updateLightButton();
}

void MainWindow::on_comboBoxMotherboardType_currentIndexChanged(int index)
{
    ConfigManager::MotherboardType type = static_cast<ConfigManager::MotherboardType>(index);
    auto gpus = configManager.getCompatibleGPUs();
    auto rams = configManager.getCompatibleRAMs();
    auto cpus = configManager.getCompatibleCPUs(type);

    ui->listWidgetProcessor->clear();
    ui->listWidgetGPU->clear();
    ui->listWidgetRAM->clear();

    for (auto gpu : gpus)
    {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(gpuTypeToString(gpu)));
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<int>(gpu)));
        ui->listWidgetGPU->addItem(item);
    }
    for (auto cpu : cpus)
    {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(cpuTypeToString(cpu)));
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<int>(cpu)));
        ui->listWidgetProcessor->addItem(item);
    }
    for (auto ram : rams)
    {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(ramTypeToString(ram)));
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<int>(ram)));
        ui->listWidgetRAM->addItem(item);
    }
}

void MainWindow::on_pushButtonAddProcessor_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо сначала построить материнскую плату!");
        err.exec();
        return;
    }
    QListWidgetItem *currentItem = ui->listWidgetProcessor->currentItem();
    if (!currentItem)
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо выбрать процессор!");
        err.exec();
        return;
    }

    bool cpuSlotAvailable = facade->getMotherboardConfig()->isCpuSlotAvailable();
    if (!cpuSlotAvailable)
    {
        QErrorMessage err(this);
        err.showMessage("Разъём процессора занят!");
        err.exec();
        return;
    }

    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Подверждение установки процессора", "Уверены, что хотите установить выбранный процессор?", QMessageBox::Yes|QMessageBox::No);
    if (confirm != QMessageBox::Yes)
    {
        return;
    }

    ConfigManager::MotherboardType motherboardType = static_cast<ConfigManager::MotherboardType>(ui->comboBoxMotherboardType->currentIndex());
    ConfigManager::CPUType cpuType = static_cast<ConfigManager::CPUType>(currentItem->data(Qt::UserRole).toInt());

    facade->addCPU(motherboardType, cpuType);
    facade->getMotherboardConfig()->occupyCpuSlot();

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}


void MainWindow::on_pushButtonAddRAM_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо сначала построить материнскую плату!");
        err.exec();
        return;
    }
    QListWidgetItem *currentItem = ui->listWidgetRAM->currentItem();
    if (!currentItem)
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо выбрать модуль RAM!");
        err.exec();
        return;
    }
    QList<int> availableSlots = facade->getMotherboardConfig()->getAvailableRamSlots();
    if (availableSlots.empty())
    {
        QErrorMessage err(this);
        err.showMessage("Все разъёмы для модулей RAM заняты!");
        err.exec();
        return;
    }

    // prepare arguments
    ConfigManager::MotherboardType motherboardType = static_cast<ConfigManager::MotherboardType>(ui->comboBoxMotherboardType->currentIndex());
    ConfigManager::RAMType ramType = static_cast<ConfigManager::RAMType>(currentItem->data(Qt::UserRole).toInt());

    bool ok;
    QStringList items;
    QMap<QString, int> slotMap;
    QString slotName;
    for (int slot : availableSlots)
    {
        switch(motherboardType)
        {
        case ConfigManager::MotherboardType::ATX:
            slotName = QString::fromStdString(atxRamSlotToString(static_cast<ATXMotherboardConfig::RAMSlot>(slot)));
            items << slotName;
            slotMap[slotName] = slot;
            break;
        case ConfigManager::MotherboardType::MicroATX:
            slotName = QString::fromStdString(microAtxRamSlotToString(static_cast<MicroATXMotherboardConfig::RAMSlot>(slot)));
            items << slotName;
            slotMap[slotName] = slot;
            break;
        case ConfigManager::MotherboardType::MiniITX:
            slotName = QString::fromStdString(miniItxRamSlotToString(static_cast<MiniITXMotherboardConfig::RAMSlot>(slot)));
            items << slotName;
            slotMap[slotName] = slot;
            break;
        }
    }

    QInputDialog inputDialog(this);
    inputDialog.setWindowTitle("Выбор разъёма для модуля RAM");
    inputDialog.setLabelText("Доступные разъёмы:");
    inputDialog.setComboBoxItems(items);
    inputDialog.resize(480, inputDialog.size().height());
    int ret = inputDialog.exec();
    QString item = inputDialog.textValue();

    if (ret == QDialog::Accepted && !item.isEmpty())
    {
        int slotIndex = slotMap[item];
        facade->addRAM(motherboardType, ramType, slotIndex);
        facade->getMotherboardConfig()->occupyRamSlot(slotIndex);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButtonAddGPU_clicked()
{

    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо сначала построить материнскую плату!");
        err.exec();
        return;
    }
    QListWidgetItem *currentItem = ui->listWidgetGPU->currentItem();
    if (!currentItem)
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо выбрать модуль видеокарты!");
        err.exec();
        return;
    }
    QList<int> availableSlots = facade->getMotherboardConfig()->getAvailableGpuSlots();
    if (availableSlots.empty())
    {
        QErrorMessage err(this);
        err.showMessage("Все разъёмы для виделокарт заняты!");
        err.exec();
        return;
    }

    // prepare arguments
    ConfigManager::MotherboardType motherboardType = static_cast<ConfigManager::MotherboardType>(ui->comboBoxMotherboardType->currentIndex());
    ConfigManager::GPUType gpuType = static_cast<ConfigManager::GPUType>(currentItem->data(Qt::UserRole).toInt());

    bool ok;
    QStringList items;
    QMap<QString, int> slotMap;
    QString slotName;
    for (int slot : availableSlots)
    {
        switch(motherboardType)
        {
        case ConfigManager::MotherboardType::ATX:
            slotName = QString::fromStdString(atxGpuSlotToString(static_cast<ATXMotherboardConfig::GPUSlot>(slot)));
            items << slotName;
            slotMap[slotName] = slot;
            break;
        case ConfigManager::MotherboardType::MicroATX:
            slotName = QString::fromStdString(microAtxGpuSlotToString(static_cast<MicroATXMotherboardConfig::GPUSlot>(slot)));
            items << slotName;
            slotMap[slotName] = slot;
            break;
        case ConfigManager::MotherboardType::MiniITX:
            slotName = QString::fromStdString(miniItxGpuSlotToString(static_cast<MiniITXMotherboardConfig::GPUSlot>(slot)));
            items << slotName;
            slotMap[slotName] = slot;
            break;
        }
    }

    QInputDialog inputDialog(this);
    inputDialog.setWindowTitle("Выбор разъёма для видеокарты");
    inputDialog.setLabelText("Доступные разъёмы:");
    inputDialog.setComboBoxItems(items);
    inputDialog.resize(480, inputDialog.size().height());
    int ret = inputDialog.exec();
    QString item = inputDialog.textValue();

    if (ret == QDialog::Accepted && !item.isEmpty())
    {
        int slotIndex = slotMap[item];
        facade->addGPU(motherboardType, gpuType, slotIndex);
        facade->getMotherboardConfig()->occupyGpuSlot(slotIndex);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButtonAddLight_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо сначала построить материнскую плату!");
        err.exec();
        return;
    }
    if (facade->isLightSet())
    {
        QMessageBox::information(this, "Установка источника света", "Источник света уже установлен!");
        return;
    }

    AddLight lightPlaceWindow(nullptr);
    lightPlaceWindow.setModal(true);
    lightPlaceWindow.exec();

    if (lightPlaceWindow.status == AddLight::OK)
    {
        facade->addLight(lightPlaceWindow.getXAngle(),lightPlaceWindow.getYAngle());
        updateLightButton();
    }
    else
        return;

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}


void MainWindow::on_pushButton_deleteModel_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    ObjectDelete objectDeleteWindow(facade->getScene(), facade->getMotherboardConfig(), facade->isLightSet(), facade, nullptr);
    objectDeleteWindow.setModal(true);
    objectDeleteWindow.exec();

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);

    updateLightButton();
}

void MainWindow::on_pushButton_sceneToInitianPosition_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    QGraphicsScene *setScene = facade->toCenter(ui->graphicsView->rect());

    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButton_up_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureRotateXLeft();
}

void MainWindow::on_pushButton_down_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureRotateXRight();
}

void MainWindow::on_pushButton_left_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureRotateYRight();
}

void MainWindow::on_pushButton_right_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureRotateYLeft();
}

void MainWindow::on_pushButton_leftCircle_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureRotateZRight();
}

void MainWindow::on_pushButton_rightCircle_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureRotateZLeft();
}

void MainWindow::on_pushButton_up_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureUp();
}

void MainWindow::on_pushButton_down_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureDown();
}

void MainWindow::on_pushButton_left_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureLeft();
}

void MainWindow::on_pushButton_right_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureRight();
}

void MainWindow::on_pushButton_zoom_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureScaleUp();
}

void MainWindow::on_pushButton_distance_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо сначала построить материнскую плату!");
        return;
    }

    pictureScaleDown();
}

void MainWindow::on_pushButtonChangeCPUColor_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо сначала построить материнскую плату!");
        err.exec();
        return;
    }
    QColor color = QColorDialog::getColor(Qt::white, this, "Выбор цвета процессора");
    if (color.isValid())
    {
        QColor shadow = color.darker(150);
        facade->changeCPUColor(color, shadow);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}


void MainWindow::on_pushButtonChangeRAMColor_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо сначала построить материнскую плату!");
        err.exec();
        return;
    }
    QColor color = QColorDialog::getColor(Qt::white, this, "Выбор цвета модулей RAM");
    if (color.isValid())
    {
        QColor shadow = color.darker(150);
        std::cout << "color: " << color.red() << ", " << color.green() << ", " << color.blue() << std::endl;
        std::cout << "shadow: " << shadow.red() << ", " << shadow.green() << ", " << shadow.blue() << std::endl;
        facade->changeRAMColor(color, shadow);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}


void MainWindow::on_pushButtonGPUColor_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Необходимо сначала построить материнскую плату!");
        err.exec();
        return;
    }
    QColor color = QColorDialog::getColor(Qt::white, this, "Выбор цвета модулей видеокарт");
    if (color.isValid())
    {
        QColor shadow = color.darker(150);
        std::cout << "color: " << color.red() << ", " << color.green() << ", " << color.blue() << std::endl;
        std::cout << "shadow: " << shadow.red() << ", " << shadow.green() << ", " << shadow.blue() << std::endl;
        facade->changeGPUColor(color, shadow);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());
    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::updateLightButton()
{
    ui->pushButtonAddLight->setEnabled(!facade->isLightSet());
}
