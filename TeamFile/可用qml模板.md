### 圆角按钮

```qss
QPushButton{
background-color: rgb(225, 225, 225);
border:2px groove gray;
border-radius:10px;
padding:2px 4px;
border-style: outset;
}

QPushButton:hover{
background-color:rgb(229, 241, 251); 
color: black;
}

QPushButton:pressed{
background-color:rgb(204, 228, 247);
border-style: inset;
}

```

浅蓝色按钮

```qss
.QPushButton,.QToolButton{
border-style:none;
border:1px solid #C0DCF2;
color:#386487;
padding:5px;
min-height:15px;
border-radius:5px;
background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #DEF0FE,stop:1 #C0DEF6);
}

.QPushButton:hover,.QToolButton:hover{
background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F9FF,stop:1 #DAEFFF);
}

.QPushButton:pressed,.QToolButton:pressed{
background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #DEF0FE,stop:1 #C0DEF6);
}
```

浅蓝色滑动条

```qss
QScrollBar:horizontal{
background:#DEF0FE;
padding:0px;
border-radius:6px;
max-height:12px;
}

QScrollBar::handle:horizontal{
background:#C0DCF2;
min-width:50px;
border-radius:6px;
}

QScrollBar::handle:horizontal:hover{
background:#386488;
}

QScrollBar::handle:horizontal:pressed{
background:#386488;
}

QScrollBar::add-page:horizontal{
background:none;
}

QScrollBar::sub-page:horizontal{
background:none;
}

QScrollBar::add-line:horizontal{
background:none;
}

QScrollBar::sub-line:horizontal{
background:none;
}

QScrollBar:vertical{
background:#DEF0FE;
padding:0px;
border-radius:6px;
max-width:12px;
}

QScrollBar::handle:vertical{
background:#C0DCF2;
min-height:50px;
border-radius:6px;
}

QScrollBar::handle:vertical:hover{
background:#386488;
}

QScrollBar::handle:vertical:pressed{
background:#386488;
}

QScrollBar::add-page:vertical{
background:none;
}

QScrollBar::sub-page:vertical{
background:none;
}

QScrollBar::add-line:vertical{
background:none;
}

QScrollBar::sub-line:vertical{
background:none;
}

QScrollArea{
border:0px;
}
```

黑色按钮

```qss
.QPushButton,.QToolButton{
border-style:none;
border:1px solid #242424;
color:#DCDCDC;
padding:5px;
min-height:15px;
border-radius:5px;
background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #484848,stop:1 #383838);
}

.QPushButton:hover,.QToolButton:hover{
background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252);
}

.QPushButton:pressed,.QToolButton:pressed{
background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #484848,stop:1 #383838);
}
```

浅灰色下拉框

```qss
QComboBox::down-arrow,QDateEdit[calendarPopup="true"]::down-arrow,QTimeEdit[calendarPopup="true"]::down-arrow,QDateTimeEdit[calendarPopup="true"]::down-arrow{
image:url(:/qss/flatgray/add_bottom.png);
width:10px;
height:10px;
right:2px;
}

QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{
subcontrol-origin:padding;
subcontrol-position:top right;
width:15px;
border-left-width:0px;
border-left-style:solid;
border-top-right-radius:3px;
border-bottom-right-radius:3px;
border-left-color:#B6B6B6;
}

QComboBox::drop-down:on{
top:1px;
}
```

浅灰色滑动条

```qss
QScrollBar:horizontal{
background:#E4E4E4;
padding:0px;
border-radius:6px;
max-height:12px;
}

QScrollBar::handle:horizontal{
background:#B6B6B6;
min-width:50px;
border-radius:6px;
}

QScrollBar::handle:horizontal:hover{
background:#575959;
}

QScrollBar::handle:horizontal:pressed{
background:#575959;
}

QScrollBar::add-page:horizontal{
background:none;
}

QScrollBar::sub-page:horizontal{
background:none;
}

QScrollBar::add-line:horizontal{
background:none;
}

QScrollBar::sub-line:horizontal{
background:none;
}

QScrollBar:vertical{
background:#E4E4E4;
padding:0px;
border-radius:6px;
max-width:12px;
}

QScrollBar::handle:vertical{
background:#B6B6B6;
min-height:50px;
border-radius:6px;
}

QScrollBar::handle:vertical:hover{
background:#575959;
}

QScrollBar::handle:vertical:pressed{
background:#575959;
}

QScrollBar::add-page:vertical{
background:none;
}

QScrollBar::sub-page:vertical{
background:none;
}

QScrollBar::add-line:vertical{
background:none;
}

QScrollBar::sub-line:vertical{
background:none;
}

QScrollArea{
border:0px;
}
```

