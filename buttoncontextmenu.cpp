#include "buttoncontextmenu.h"
#include <QAction>
ButtonContextMenu::ButtonContextMenu()
{
    setContextMenuPolicy(Qt::ActionsContextMenu);

        m_actionOne = new QAction(this);
        m_actionTwo = new QAction(this);
        m_actionThree = new QAction(this);

        m_actionOne->setText("清除像素");
        m_actionTwo->setText("显示图片");
        m_actionThree->setText("删除该流程");

        addAction(m_actionOne);
        addAction(m_actionTwo);
        addAction(m_actionThree);

        connect(m_actionOne, SIGNAL(triggered()), this, SLOT(actionOneSlot()));
        connect(m_actionTwo, SIGNAL(triggered()), this, SLOT(actionTwoSlot()));
        connect(m_actionThree, SIGNAL(triggered()), this, SLOT(actionThreeSlot()));

        imageDisplay = new ImageDisplay();

}

void ButtonContextMenu::actionOneSlot()
{

}

void ButtonContextMenu::actionTwoSlot()
{
    imageDisplay->AddImage(imageDisplay->imageVector.at(this->buttonIndex));
    imageDisplay->imageVector.pop_back();
}

void ButtonContextMenu::actionThreeSlot()
{
    this->close();
}
