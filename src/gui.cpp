#include "gui.h"
#include "backend.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow() {
    setWindowTitle("Stream Deck Configuration");
    setFixedSize(400, 200);

    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label1 = new QLabel("Select Hotkey:");
    QComboBox* keySelector = new QComboBox();
    for (int i = VK_F1; i <= VK_F12; i++) {
        keySelector->addItem(QString("F%1").arg(i - VK_F1 + 1), i);
    }

    QLabel* label2 = new QLabel("Window Title:");
    QLineEdit* windowTitleInput = new QLineEdit();

    QPushButton* saveButton = new QPushButton("Save Hotkey");
    connect(saveButton, &QPushButton::clicked, [=]() {
        int selectedKey = keySelector->currentData().toInt();
        QString windowTitle = windowTitleInput->text();

        hotkeyMap[selectedKey] = windowTitle.toStdString();
        saveHotkeys();
    });

    layout->addWidget(label1);
    layout->addWidget(keySelector);
    layout->addWidget(label2);
    layout->addWidget(windowTitleInput);
    layout->addWidget(saveButton);
}
