#ifndef BUTTONCONTEXTMENU_H
#define BUTTONCONTEXTMENU_H

#include <QToolButton>
#include <QVector>
#include "ImageDisplay.h"
class ButtonContextMenu : public QToolButton
{
    Q_OBJECT
public:
    ButtonContextMenu();
    int buttonIndex;
    QVector<ButtonContextMenu*> buttonMenuVector;

    ImageDisplay * imageDisplay;

protected slots:
    void actionOneSlot();
    void actionTwoSlot();
    void actionThreeSlot();

private:
    QAction *m_actionOne;
    QAction *m_actionTwo;
    QAction *m_actionThree;

};

#endif // BUTTONCONTEXTMENU_H
