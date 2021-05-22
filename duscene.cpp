#include "duscene.h"
#include "gifanimation.h"
#include <QLabel>
DuScene::DuScene(QObject *parent)
  : QGraphicsScene(parent)
{
mGifAnimation = new GifAnimation(this);
mGifAnimation->setFilename("C:/projet-new/projet/logo_motion.gif");
mGifAnimation->startMovie();
addWidget(mGifAnimation->getWidget());

}
