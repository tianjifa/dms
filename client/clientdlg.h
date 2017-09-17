#ifndef _CLIENTDLG_H
#define _CLIENTDLG_H
#include <QDialog>
#include <QTextBrowser>
#include <QPushButton>
#include "workthread.h"
class ClientDlg : public QDialog {
	Q_OBJECT
public:
	ClientDlg (void);
	~ClientDlg (void);
public slots:
	void onStart (void);
	void onUpdate (QString text);
private:
	QTextBrowser* m_browser;
	QPushButton*  m_start;
	QPushButton*  m_close;
	WorkThread    m_work;
};
#endif // _CLIENTDLG_H
