/********************************************************************************
** Form generated from reading UI file 'WaypointNavigation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAYPOINTNAVIGATION_H
#define UI_WAYPOINTNAVIGATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaypointNavigationWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_topic;
    QLineEdit *topic_line_edit;
    QLabel *label_frame;
    QLineEdit *frame_line_edit;
    QCheckBox *sixDcheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *wp_height_label;
    QDoubleSpinBox *wp_height_doubleSpinBox;
    QLabel *waypoint_count_label;
    QLabel *sel_label;
    QLabel *sel_wp_label;
    QPushButton *load_wp_button;
    QHBoxLayout *horizontalLayout;
    QLabel *x_label;
    QDoubleSpinBox *x_doubleSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *y_label;
    QDoubleSpinBox *y_doubleSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *z_label;
    QDoubleSpinBox *z_doubleSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *yaw_label;
    QDoubleSpinBox *yaw_doubleSpinBox;
    QPushButton *clear_all_button;
    QPushButton *save_wp_button;
    QPushButton *publish_wp_button;

    void setupUi(QWidget *WaypointNavigationWidget)
    {
        if (WaypointNavigationWidget->objectName().isEmpty())
            WaypointNavigationWidget->setObjectName(QString::fromUtf8("WaypointNavigationWidget"));
        WaypointNavigationWidget->resize(469, 175);
        gridLayout = new QGridLayout(WaypointNavigationWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_topic = new QLabel(WaypointNavigationWidget);
        label_topic->setObjectName(QString::fromUtf8("label_topic"));

        horizontalLayout_3->addWidget(label_topic);

        topic_line_edit = new QLineEdit(WaypointNavigationWidget);
        topic_line_edit->setObjectName(QString::fromUtf8("topic_line_edit"));

        horizontalLayout_3->addWidget(topic_line_edit);

        label_frame = new QLabel(WaypointNavigationWidget);
        label_frame->setObjectName(QString::fromUtf8("label_frame"));

        horizontalLayout_3->addWidget(label_frame);

        frame_line_edit = new QLineEdit(WaypointNavigationWidget);
        frame_line_edit->setObjectName(QString::fromUtf8("frame_line_edit"));

        horizontalLayout_3->addWidget(frame_line_edit);

        sixDcheckBox = new QCheckBox(WaypointNavigationWidget);
        sixDcheckBox->setObjectName(QString::fromUtf8("sixDcheckBox"));

        horizontalLayout_3->addWidget(sixDcheckBox);


        gridLayout->addLayout(horizontalLayout_3, 5, 1, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wp_height_label = new QLabel(WaypointNavigationWidget);
        wp_height_label->setObjectName(QString::fromUtf8("wp_height_label"));

        horizontalLayout_2->addWidget(wp_height_label);

        wp_height_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        wp_height_doubleSpinBox->setObjectName(QString::fromUtf8("wp_height_doubleSpinBox"));
        wp_height_doubleSpinBox->setMinimum(-5.000000000000000);
        wp_height_doubleSpinBox->setSingleStep(0.100000000000000);

        horizontalLayout_2->addWidget(wp_height_doubleSpinBox);

        waypoint_count_label = new QLabel(WaypointNavigationWidget);
        waypoint_count_label->setObjectName(QString::fromUtf8("waypoint_count_label"));

        horizontalLayout_2->addWidget(waypoint_count_label);

        sel_label = new QLabel(WaypointNavigationWidget);
        sel_label->setObjectName(QString::fromUtf8("sel_label"));

        horizontalLayout_2->addWidget(sel_label);

        sel_wp_label = new QLabel(WaypointNavigationWidget);
        sel_wp_label->setObjectName(QString::fromUtf8("sel_wp_label"));

        horizontalLayout_2->addWidget(sel_wp_label);


        gridLayout->addLayout(horizontalLayout_2, 6, 1, 1, 3);

        load_wp_button = new QPushButton(WaypointNavigationWidget);
        load_wp_button->setObjectName(QString::fromUtf8("load_wp_button"));

        gridLayout->addWidget(load_wp_button, 10, 2, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        x_label = new QLabel(WaypointNavigationWidget);
        x_label->setObjectName(QString::fromUtf8("x_label"));

        horizontalLayout->addWidget(x_label);

        x_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        x_doubleSpinBox->setObjectName(QString::fromUtf8("x_doubleSpinBox"));
        x_doubleSpinBox->setMinimum(-1000.000000000000000);
        x_doubleSpinBox->setMaximum(1000.000000000000000);
        x_doubleSpinBox->setSingleStep(0.500000000000000);

        horizontalLayout->addWidget(x_doubleSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        y_label = new QLabel(WaypointNavigationWidget);
        y_label->setObjectName(QString::fromUtf8("y_label"));

        horizontalLayout->addWidget(y_label);

        y_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        y_doubleSpinBox->setObjectName(QString::fromUtf8("y_doubleSpinBox"));
        y_doubleSpinBox->setMinimum(-1000.000000000000000);
        y_doubleSpinBox->setMaximum(1000.000000000000000);
        y_doubleSpinBox->setSingleStep(0.500000000000000);

        horizontalLayout->addWidget(y_doubleSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        z_label = new QLabel(WaypointNavigationWidget);
        z_label->setObjectName(QString::fromUtf8("z_label"));

        horizontalLayout->addWidget(z_label);

        z_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        z_doubleSpinBox->setObjectName(QString::fromUtf8("z_doubleSpinBox"));
        z_doubleSpinBox->setMinimum(-1000.000000000000000);
        z_doubleSpinBox->setMaximum(1000.000000000000000);
        z_doubleSpinBox->setSingleStep(0.500000000000000);

        horizontalLayout->addWidget(z_doubleSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        yaw_label = new QLabel(WaypointNavigationWidget);
        yaw_label->setObjectName(QString::fromUtf8("yaw_label"));

        horizontalLayout->addWidget(yaw_label);

        yaw_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        yaw_doubleSpinBox->setObjectName(QString::fromUtf8("yaw_doubleSpinBox"));
        yaw_doubleSpinBox->setMinimum(-3.150000000000000);
        yaw_doubleSpinBox->setMaximum(3.150000000000000);
        yaw_doubleSpinBox->setSingleStep(0.100000000000000);

        horizontalLayout->addWidget(yaw_doubleSpinBox);


        gridLayout->addLayout(horizontalLayout, 8, 1, 1, 3);

        clear_all_button = new QPushButton(WaypointNavigationWidget);
        clear_all_button->setObjectName(QString::fromUtf8("clear_all_button"));

        gridLayout->addWidget(clear_all_button, 9, 1, 1, 1);

        save_wp_button = new QPushButton(WaypointNavigationWidget);
        save_wp_button->setObjectName(QString::fromUtf8("save_wp_button"));

        gridLayout->addWidget(save_wp_button, 10, 1, 1, 1);

        publish_wp_button = new QPushButton(WaypointNavigationWidget);
        publish_wp_button->setObjectName(QString::fromUtf8("publish_wp_button"));

        gridLayout->addWidget(publish_wp_button, 9, 2, 1, 2);


        retranslateUi(WaypointNavigationWidget);

        QMetaObject::connectSlotsByName(WaypointNavigationWidget);
    } // setupUi

    void retranslateUi(QWidget *WaypointNavigationWidget)
    {
        WaypointNavigationWidget->setWindowTitle(QApplication::translate("WaypointNavigationWidget", "Quadrotor Steering", nullptr));
        label_topic->setText(QApplication::translate("WaypointNavigationWidget", "Topic", nullptr));
        topic_line_edit->setText(QApplication::translate("WaypointNavigationWidget", "/waypoints", nullptr));
        label_frame->setText(QApplication::translate("WaypointNavigationWidget", "Frame", nullptr));
        frame_line_edit->setText(QApplication::translate("WaypointNavigationWidget", "map", nullptr));
        sixDcheckBox->setText(QApplication::translate("WaypointNavigationWidget", "6D", nullptr));
        wp_height_label->setText(QApplication::translate("WaypointNavigationWidget", "Default Height", nullptr));
        waypoint_count_label->setText(QApplication::translate("WaypointNavigationWidget", "Total Waypoints: ", nullptr));
        sel_label->setText(QApplication::translate("WaypointNavigationWidget", "Selected wp: ", nullptr));
        sel_wp_label->setText(QString());
        load_wp_button->setText(QApplication::translate("WaypointNavigationWidget", "Load Waypoints", nullptr));
        x_label->setText(QApplication::translate("WaypointNavigationWidget", "X:", nullptr));
        y_label->setText(QApplication::translate("WaypointNavigationWidget", "Y:", nullptr));
        z_label->setText(QApplication::translate("WaypointNavigationWidget", "Z:", nullptr));
        yaw_label->setText(QApplication::translate("WaypointNavigationWidget", "Yaw:", nullptr));
        clear_all_button->setText(QApplication::translate("WaypointNavigationWidget", "Clear All", nullptr));
        save_wp_button->setText(QApplication::translate("WaypointNavigationWidget", "Save Waypoints", nullptr));
        publish_wp_button->setText(QApplication::translate("WaypointNavigationWidget", "Publish Waypoints", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaypointNavigationWidget: public Ui_WaypointNavigationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAYPOINTNAVIGATION_H
