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

//  W A R N I N G
//  -------------
//
// This file is not part of the Qt Enterprise Chart API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef QHORIZONTALBARSERIES_P_H
#define QHORIZONTALBARSERIES_P_H

#include <private/qabstractbarseries_p.h>
#include <private/abstractdomain_p.h>

QT_CHARTS_BEGIN_NAMESPACE

class QHorizontalBarSeriesPrivate: public QAbstractBarSeriesPrivate
{
public:
    QHorizontalBarSeriesPrivate(QHorizontalBarSeries *q);
    void initializeGraphics(QGraphicsItem* parent);
    void initializeDomain();
private:
    Q_DECLARE_PUBLIC(QHorizontalBarSeries)
};

QT_CHARTS_END_NAMESPACE

#endif // QHORIZONTALBARSERIES_P_H