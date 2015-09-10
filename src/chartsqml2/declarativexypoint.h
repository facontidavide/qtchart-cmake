/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd
** All rights reserved.
** For any questions to The Qt Company, please use contact form at http://qt.io
**
** This file is part of the Qt Charts module.
**
** Licensees holding valid commercial license for Qt may use this file in
** accordance with the Qt License Agreement provided with the Software
** or, alternatively, in accordance with the terms contained in a written
** agreement between you and The Qt Company.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.io
**
****************************************************************************/

#ifndef DECLARATIVE_XY_POINT_H
#define DECLARATIVE_XY_POINT_H

#include <QtCharts/QChartGlobal>
#include <QtCore/QObject>
#include <QtCore/QPointF>

QT_CHARTS_BEGIN_NAMESPACE

class DeclarativeXYPoint : public QObject, public QPointF
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
    Q_PROPERTY(qreal y READ y WRITE setY)

public:
    explicit DeclarativeXYPoint(QObject *parent = 0);
};

QT_CHARTS_END_NAMESPACE

#endif // DECLARATIVE_XY_POINT_H