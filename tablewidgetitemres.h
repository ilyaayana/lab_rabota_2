#ifndef TABLEWIDGETITEMRES_H
#define TABLEWIDGETITEMRES_H

#include <QTableWidgetItem>
#include <QStringList>
#include <QDebug>

class TableWidgetItemRes : public QTableWidgetItem
{
public:
    TableWidgetItemRes(const QString &text):QTableWidgetItem(text)
    {
    }
         bool operator <(const QTableWidgetItem &other) const
         {
             QStringList nums1 = text().split('x');
             QStringList nums2 = other.text().split('x');
                 return nums1[0].toInt()*nums1[1].toInt() < nums2[0].toInt()*nums2[1].toInt();
         }
};

#endif // TABLEWIDGETITEMRES_H
