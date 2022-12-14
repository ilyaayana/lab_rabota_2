#ifndef TABLEWIDGETITEMNUMBER_H
#define TABLEWIDGETITEMNUMBER_H

#include <QTableWidgetItem>

class TableWidgetItemNumber : public QTableWidgetItem
{
public:
    TableWidgetItemNumber(const QString &text):QTableWidgetItem(text)
    {
    }
         bool operator <(const QTableWidgetItem &other) const
         {
             if (text()=="")
                 return text().toDouble() > other.text().toDouble();
             else
                 return text().toDouble() < other.text().toDouble();
         }
};

#endif // TABLEWIDGETITEMNUMBER_H
