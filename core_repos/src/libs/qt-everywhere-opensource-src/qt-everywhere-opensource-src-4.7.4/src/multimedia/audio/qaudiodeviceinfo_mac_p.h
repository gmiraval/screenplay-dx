/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtMultimedia module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//


#ifndef QDEVICEINFO_MAC_P_H
#define QDEVICEINFO_MAC_P_H

#include <CoreAudio/CoreAudio.h>

#include <QtMultimedia/qaudioengine.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class QAudioDeviceInfoInternal : public QAbstractAudioDeviceInfo
{
public:
    AudioDeviceID   deviceId;
    QString         name;
    QAudio::Mode   mode;

    QAudioDeviceInfoInternal(QByteArray const& handle, QAudio::Mode mode);

    bool isFormatSupported(const QAudioFormat& format) const;
    QAudioFormat preferredFormat() const;
    QAudioFormat nearestFormat(const QAudioFormat& format) const;

    QString deviceName() const;

    QStringList codecList();
    QList<int> frequencyList();
    QList<int> channelsList();
    QList<int> sampleSizeList();
    QList<QAudioFormat::Endian> byteOrderList();
    QList<QAudioFormat::SampleType> sampleTypeList();

    static QByteArray defaultInputDevice();
    static QByteArray defaultOutputDevice();

    static QList<QByteArray> availableDevices(QAudio::Mode mode);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif  // QDEVICEINFO_MAC_P_H
