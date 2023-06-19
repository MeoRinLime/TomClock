

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import TomClock
import FlowView
import Qt.SafeRenderer
import QtQuick.Layouts
import QtQuick.Studio.Components
import QtQuick.Studio.Effects
import QtQuick.Studio.LogicHelper
import QtQuick.Studio.MultiText
import QtCharts
import QtInsightTracker
import QtMultimedia
import QtQuick.Effects
import QtQuick.Studio.Application
import QtQuick.Timeline
import QtQuickUltralite.Layers
import QtQuick.Window
import QtQuickUltralite.Extras

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor
    clip: false

    Timer {
        id: timer
        interval: 20000
        triggeredOnStart: true
        running: false
    }

    Button {
        id: timer_controler
        x: 737
        y: 767
        width: 446
        height: 161
        text: qsTr("Start")
        font.weight: Font.Light
        icon.height: 40
        icon.width: 40
        spacing: 8
        font.pointSize: 47
        font.family: "Arial"
        icon.source: "images/Icons/Default_Color/os-icon-arrow-right.png"
        transformOrigin: Item.Bottom

        Timer {
            id: timer1
            interval: 20000
        }
    }

    Item {
        id: __materialLibrary__
    }
}
