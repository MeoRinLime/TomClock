// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.5
import TomClock

Window {
    width: mainScreen.width
    height: mainScreen.height

    visible: true
    title: "TomClock"

    Screen01 {
        id: mainScreen
    }

}

