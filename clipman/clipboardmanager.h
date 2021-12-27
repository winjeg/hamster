#ifndef CLIPBOARDMANAGER_H
#define CLIPBOARDMANAGER_H

#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QTextEdit>



class ClipBoardManager : public QWidget
{
    Q_OBJECT

public:
    ClipBoardManager(QWidget *parent);
    ~ClipBoardManager();

public:
    void setClipBoardTo( QLabel * widget);
    void setFileTo(QLabel * widget);
    void appendClipBoardTo(QTextEdit * textEdit);
    const QClipboard * getClipBoard();

private:


};

#endif // CLIPBOARDMANAGER_H
