#ifndef RJPSHAPES_H
#define RJPSHAPES_H

#include "QVector"
#include "QString"
#include "QPaintDevice"

#include "include/RjpClass/rjpshape.h"
#include "include/RjpClass/rjpshapescommand.hpp"

namespace ob = rjpshapefile::obpart;    // use namespace obpart

namespace rjpshapefile{
namespace drawpart{

class RjpShapes
{
public:
    ~RjpShapes();
    RjpShapes();    // 3 constructor
    RjpShapes(ob::ShapesObCommand* obc);
    RjpShapes(RjpShapes* shapes);
    RjpShape* at(int i) const ;// at
    void setOb(ob::ShapesObCommand* ob);
    void addShapes(QStringList filepathlist);
    void drawAllShapes(QPainter* painter) const;
    void notify();
    // 'get' series
    void getDatabox(QVector<double>& databox) const;
    int getLayersSize() const;
    QStringList getPathList() const;
    ob::ShapesObCommand* getOb() const;

private:
    ob::ShapesObCommand* _ob;
    QVector<RjpShape* > _mylayers;
    QVector<double> _shps_databox;
    QStringList _pathlist;
};

// Design pattern: Singleton
class SingletonShapes{
public:
    static RjpShapes* getGlobalData();
    static void releaseGlobalData();
private:
    static RjpShapes* _global_data;
};

}   // namespace drawpart
}   // namespace rjpshapefile



#endif // RJPSHAPES_H
