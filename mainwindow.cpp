#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    std::cout << "MainWindow::MainWindow" << std::endl;
    ui->setupUi(this);

    facade = new Facade(configManager);

    QListWidgetItem *brick     = new QListWidgetItem(" Кирпичик"); // not in use (deprecated)
    ui->listWidget->addItem(brick);

    QListWidgetItem *plate       = new QListWidgetItem(" Пластинка"); // not in use (deprecated)
    ui->listWidget->addItem(plate);

    QListWidgetItem *tile       = new QListWidgetItem(" Плитка"); // not in use (deprecated)
    ui->listWidget->addItem(tile);

    QListWidgetItem *arc41       = new QListWidgetItem(" Арка (4х1)"); // not in use (deprecated)
    ui->listWidget->addItem(arc41);

    QListWidgetItem *arc14       = new QListWidgetItem(" Арка (1x4)"); // not is use (deprecated)
    ui->listWidget->addItem(arc14);

    QListWidgetItem *cylinder1       = new QListWidgetItem(" Цилиндр (1x1)"); // not in use (deprecated)
    ui->listWidget->addItem(cylinder1);

    QListWidgetItem *cylinder2       = new QListWidgetItem(" Цилиндр (2x2)"); // not in use (deprecated)
    ui->listWidget->addItem(cylinder2);

    QListWidgetItem *flashlight = new QListWidgetItem(" Источник света"); // not in use (deprecated)
    ui->listWidget->addItem(flashlight);

    // motherboard types combobox
    ui->comboBoxMotherboardType->addItem("ATX");
    ui->comboBoxMotherboardType->addItem("Micro-ATX");
    ui->comboBoxMotherboardType->addItem("Mini-ITX");

    // gpu, cpu, ram list widgets
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
    reply = QMessageBox::question(this, "Confirm Motherboard Type",
                                  "The mother to build is of type: " + selectedType + ". Are you sure you want to build it?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        std::cout << "Building motherboard type: " << static_cast<int>(type) << std::endl;
        facade->setSceneInfMotherboard(type);
        QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

        if (ui->graphicsView->scene())
            delete ui->graphicsView->scene();
        ui->graphicsView->setScene(setScene);
    }
}

void MainWindow::on_comboBoxMotherboardType_currentIndexChanged(int index)
{
    std::cout << "Selected motherboard type: " << index << std::endl;

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
    std::cout << "MainWindow::on_PushButtonAddProcessor_clicked" << std::endl;

    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Choose motherboard layout first!");
        err.exec();
        return;
    }
    QListWidgetItem *currentItem = ui->listWidgetProcessor->currentItem();
    if (!currentItem)
    {
        QErrorMessage err(this);
        err.showMessage("Select a processor first!");
        err.exec();
        return;
    }

    bool cpuSlotAvailable = facade->getMotherboardConfig()->isCpuSlotAvailable();
    if (!cpuSlotAvailable)
    {
        QErrorMessage err(this);
        err.showMessage("CPU slot already in use!");
        err.exec();
        return;
    }

    // prepare arguments
    ConfigManager::MotherboardType motherboardType = static_cast<ConfigManager::MotherboardType>(ui->comboBoxMotherboardType->currentIndex());
    int cpuTypeIndex = currentItem->data(Qt::UserRole).toInt();
    ConfigManager::CPUType cpuType = static_cast<ConfigManager::CPUType>(cpuTypeIndex);
    facade->addCPU(motherboardType, cpuType);
}

void MainWindow::on_pushButtonAddRAM_clicked()
{
    std::cout << "MainWindow::on_PushButtonAddRAM_clicked" << std::endl;

    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Choose motherboard layout first!");
        err.exec();
        return;
    }
    QListWidgetItem *currentItem = ui->listWidgetRAM->currentItem();
    if (!currentItem)
    {
        QErrorMessage err(this);
        err.showMessage("Select a RAM block first!");
        err.exec();
        return;
    }
    QList<int> availableSlots = facade->getMotherboardConfig()->getAvailableRamSlots();
    if (availableSlots.empty())
    {
        QErrorMessage err(this);
        err.showMessage("No available slots!");
        err.exec();
        return;
    }

    // prepare arguments
    ConfigManager::MotherboardType motherboardType = static_cast<ConfigManager::MotherboardType>(ui->comboBoxMotherboardType->currentIndex());
    ConfigManager::RAMType ramType = static_cast<ConfigManager::RAMType>(currentItem->data(Qt::UserRole).toInt());

    // std::cout << "--> motherboard type: " << motherboardTypeToString(motherboardType) << std::endl;
    // std::cout << "--> ram type: " << ramTypeToString(ramType) << std::endl;

    bool ok;
    QStringList items;
    for (int slot : availableSlots)
    {
        items << QString::number(slot);
    }

    QString item = QInputDialog::getItem(this, "Select RAM Slot", "Available Slots:", items, 0, false, &ok);
    int slotIndex = item.toInt();

    if (ok && !item.isEmpty())
    {
        facade->addRAM(motherboardType, ramType, slotIndex);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButtonAddGPU_clicked()
{
    std::cout << "MainWindow::on_PushButtonAddGPU_clicked" << std::endl;

    if (!facade->isSceneSet())
    {
        QErrorMessage err(this);
        err.showMessage("Choose motherboard layout first!");
        err.exec();
        return;
    }
    QListWidgetItem *currentItem = ui->listWidgetGPU->currentItem();
    if (!currentItem)
    {
        QErrorMessage err(this);
        err.showMessage("Select a GPU first!");
        err.exec();
        return;
    }
    QList<int> availableSlots = facade->getMotherboardConfig()->getAvailableGpuSlots();
    if (availableSlots.empty())
    {
        QErrorMessage err(this);
        err.showMessage("Now available slots!");
        err.exec();
        return;
    }

    // prepare arguments
    ConfigManager::MotherboardType motherboardType = static_cast<ConfigManager::MotherboardType>(ui->comboBoxMotherboardType->currentIndex());
    ConfigManager::GPUType gpuType = static_cast<ConfigManager::GPUType>(currentItem->data(Qt::UserRole).toInt());

    bool ok;
    QStringList items;
    for (int slot : availableSlots)
    {
        items << QString::number(slot);
    }
    QString item = QInputDialog::getItem(this, "Select GPU Slot", "Available Slots:", items, 0, false, &ok);
    int slotIndex = item.toInt();

    if (ok && !item.isEmpty())
    {
        facade->addGPU(motherboardType, gpuType, slotIndex);
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButtonAddLight_clicked()
{
    AddLight lightPlaceWindow(nullptr);
    lightPlaceWindow.setModal(true);
    lightPlaceWindow.exec();

    if (lightPlaceWindow.status == AddLight::OK)
        facade->addLight(
            lightPlaceWindow.getXAngle(),
            lightPlaceWindow.getYAngle());
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
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    ObjectDelete objectDeleteWindow(facade->getScene(), nullptr);
    objectDeleteWindow.setModal(true);
    objectDeleteWindow.exec();

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButton_sceneToInitianPosition_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
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
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureRotateXLeft();
}

void MainWindow::on_pushButton_down_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureRotateXRight();
}

void MainWindow::on_pushButton_left_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureRotateYRight();
}

void MainWindow::on_pushButton_right_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureRotateYLeft();
}

void MainWindow::on_pushButton_leftCircle_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureRotateZRight();
}

void MainWindow::on_pushButton_rightCircle_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureRotateZLeft();
}

void MainWindow::on_pushButton_up_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureUp();
}

void MainWindow::on_pushButton_down_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureDown();
}

void MainWindow::on_pushButton_left_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureLeft();
}

void MainWindow::on_pushButton_right_scene_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    pictureRight();
}

void MainWindow::on_pushButton_zoom_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureScaleUp();
}

void MainWindow::on_pushButton_distance_clicked()
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Сцена ещё не была задана.");
        return;
    }

    pictureScaleDown();
}

/*
 * =========================== DEPRECATED ==========================
*/


void MainWindow::on_pushButton_createScene_clicked() // deprecated
{
    std::cout << "MainWindow::on_pushButton_createScene_clicked" << std::endl;
    CreateScene Window(nullptr);
    Window.setModal(true);
    Window.exec();

    if (Window.getWidth() == -1 || Window.getheight() == -1)
        return;

    facade->setSceneInf(Window.getWidth(), Window.getheight());
    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButton_addCastle_clicked() // deprecated
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    int ch = 0;

    ch += facade->addPlate(3, 3, 10, 12);
    if (ch != 0)
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("На некоторых ячейках стоит плитка\n"
                         "или замок выходит за границы сцены!");
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        facade->addBrick(4, 3, 8, 1);
        facade->addBrick(3, 4, 1, 9);
        facade->addBrick(12, 4, 1, 9);
    }

    for (int i = 0; i < 2; i++)
    {
        facade->addBrick(4, 13, 3, 1);
        facade->addBrick(9, 13, 3, 1);
    }

    facade->addBrick(4, 13, 2, 1);
    facade->addBrick(10, 13, 2, 1);

    for (int i = 0; i < 5; i++)
    {
        facade->addCylinder1(3, 3);
        facade->addCylinder1(3, 13);
        facade->addCylinder1(12, 3);
        facade->addCylinder1(12, 13);

        facade->addCylinder1(6, 5);
        facade->addCylinder1(6, 7);
        facade->addCylinder1(6, 9);
        facade->addCylinder1(9, 5);
        facade->addCylinder1(9, 7);
        facade->addCylinder1(9, 9);
    }
    facade->addTile(6, 5, 4, 5);


    for (int i = 0; i < 8; i += 2)
    {
        facade->addBrick(i + 5, 3, 1, 1);
        facade->addTile(i + 4, 3, 1, 1);
    }
    for (int i = 0; i < 8; i += 2)
    {
        facade->addBrick(3, i + 5, 1, 1);
        facade->addBrick(12, i + 5, 1, 1);
        facade->addTile(3, i + 4, 1, 1);
        facade->addTile(12, i + 4, 1, 1);
    }


    facade->addArc41(6, 13);
    facade->addTile(4, 13, 8, 1);

    facade->addTile(3, 3, 1, 1);
    facade->addTile(3, 13, 1, 1);
    facade->addTile(12, 3, 1, 1);
    facade->addTile(12, 13, 1, 1);

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButton_moveModel_clicked() // deprecated
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    ObjectChange objectChangeWindow(facade, nullptr);
    objectChangeWindow.setModal(true);
    objectChangeWindow.exec();

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}

void MainWindow::on_pushButton_addModel_clicked() // deprecated
{
    if (!facade->isSceneSet())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("Необходимо создать сцену!");
        return;
    }

    int curRow = this->ui->listWidget->currentRow();
    if (curRow < 0)
        return;

    if (curRow >= 0 && curRow < 7)
    {
        int ch = 0;

        if (curRow == 0)
        {
            AddBrick placeBrickWindow(nullptr);
            placeBrickWindow.setModal(true);
            placeBrickWindow.exec();

            if (placeBrickWindow.status == AddBrick::OK)
                ch = facade->addBrick(
                    placeBrickWindow.getXCell(),
                    placeBrickWindow.getYCell(),
                    placeBrickWindow.getModelLength(),
                    placeBrickWindow.getModelWidth());
            else
                return;
        }
        else if (curRow == 1)
        {
            AddPlate placePlateWindow(nullptr);
            placePlateWindow.setModal(true);
            placePlateWindow.exec();

            if (placePlateWindow.status == AddPlate::OK)
                ch = facade->addPlate(
                    placePlateWindow.getXCell(),
                    placePlateWindow.getYCell(),
                    placePlateWindow.getModelLength(),
                    placePlateWindow.getModelWidth());
            else
                return;
        }
        else if (curRow == 2)
        {
            AddTile placeTileWindow(nullptr);
            placeTileWindow.setModal(true);
            placeTileWindow.exec();

            if (placeTileWindow.status == AddTile::OK)
                ch = facade->addTile(
                    placeTileWindow.getXCell(),
                    placeTileWindow.getYCell(),
                    placeTileWindow.getModelLength(),
                    placeTileWindow.getModelWidth());
            else
                return;
        }
        else if (curRow == 3)
        {
            AddArc placeArcWindow(nullptr);
            placeArcWindow.setModal(true);
            placeArcWindow.exec();

            if (placeArcWindow.status == AddArc::OK)
                ch = facade->addArc41(
                    placeArcWindow.getXCell(),
                    placeArcWindow.getYCell());
            else
                return;
        }
        else if (curRow == 4)
        {
            AddArc placeArcWindow(nullptr);
            placeArcWindow.setModal(true);
            placeArcWindow.exec();

            if (placeArcWindow.status == AddArc::OK)
                ch = facade->addArc14(
                    placeArcWindow.getXCell(),
                    placeArcWindow.getYCell());
            else
                return;
        }
        else if (curRow == 5)
        {
            AddCylinder placeCylinderWindow(nullptr);
            placeCylinderWindow.setModal(true);
            placeCylinderWindow.exec();

            if (placeCylinderWindow.status == AddCylinder::OK)
                ch = facade->addCylinder1(
                    placeCylinderWindow.getXCell(),
                    placeCylinderWindow.getYCell());
            else
                return;
        }
        else if (curRow == 6)
        {
            AddCylinder placeCylinderWindow(nullptr);
            placeCylinderWindow.setModal(true);
            placeCylinderWindow.exec();

            if (placeCylinderWindow.status == AddCylinder::OK)
                ch = facade->addCylinder2(
                    placeCylinderWindow.getXCell(),
                    placeCylinderWindow.getYCell());
            else
                return;
        }


        if (ch == 1)
        {
            QErrorMessage *err = new QErrorMessage();
            err->showMessage("На некоторых ячейках стоит плитка!\n"
                             "На плитку нельзя ставить элементы LEGO!");
            return;
        }
        else if(ch == 2)
        {
            QErrorMessage *err = new QErrorMessage();
            err->showMessage("Объект не помещается на сцене!");
            return;
        }
    }
    else
    {
        AddLight lightPlaceWindow(nullptr);
        lightPlaceWindow.setModal(true);
        lightPlaceWindow.exec();

        if (lightPlaceWindow.status == AddLight::OK)
            facade->addLight(
                lightPlaceWindow.getXAngle(),
                lightPlaceWindow.getYAngle());
        else
            return;
    }

    QGraphicsScene *setScene = facade->drawScene(ui->graphicsView->rect());

    if (ui->graphicsView->scene())
        delete ui->graphicsView->scene();
    ui->graphicsView->setScene(setScene);
}
