#include "clipboardmanager.h"

ClipBoardManager::ClipBoardManager(QWidget *parent) : QWidget(parent)
{

}

ClipBoardManager::~ClipBoardManager() {

}

const QClipboard* ClipBoardManager::getClipBoard()
{
    return QApplication::clipboard();
}


void ClipBoardManager::setClipBoardTo(QLabel* widget)
{
    const QClipboard * board = getClipBoard();
    QImage image = board->image();
    QString textOnBoard;
    if (image.isNull()) {
        textOnBoard = board->text();
        widget->setText(textOnBoard);
    } else {
        image = image.scaled(widget->width(), widget->height(), Qt::KeepAspectRatio);
        widget->setPixmap(QPixmap::fromImage(image));
    }
}


void ClipBoardManager::setFileTo(QLabel* widget) {
    QString filename;
    filename=QFileDialog::getOpenFileName(this, QObject::tr("选择图像"), "", QObject::tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;
        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this, QObject::tr("打开图像失败"), QObject::tr("打开图像失败!"));
            delete img;
            return;
        }
        *img = img->scaled(widget->width(), widget->height(), Qt::KeepAspectRatio);
        widget->setPixmap(QPixmap::fromImage(*img));
        delete img;
    }
}

void ClipBoardManager::appendClipBoardTo(QTextEdit *textEdit)
{
    const QClipboard * board = getClipBoard();
    QTextCursor cursor = textEdit->textCursor();
    QImage image = board->image();
    if (!image.isNull()) {
        cursor.insertText("[Local] Clipboard content:\n");
        cursor.insertImage(image);
        cursor.insertText(tr("\n"));
    } else {
        cursor.insertText(tr("[Local] Clipboard content:\n"));
        cursor.insertText(board->text());
        cursor.insertText(tr("\n"));
    }
}
