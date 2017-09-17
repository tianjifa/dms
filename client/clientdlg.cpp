#include "clientdlg.h"
ClientDlg::ClientDlg (void) {
	resize (560, 439);
	m_browser = new QTextBrowser (this);
	m_browser->resize (540, 383);
	m_browser->move (10, 10);
	m_start = new QPushButton ("Start", this);
	m_start->move (384, 404);
	connect (m_start, SIGNAL (clicked ()),
		this, SLOT (onStart ()));
	m_close = new QPushButton ("Close", this);
	m_close->move (474, 404);
	connect (m_close, SIGNAL (clicked ()),
		this, SLOT (close ()));
	connect (&m_work,
		SIGNAL (update (QString)), this,
		SLOT (onUpdate (QString)));
}
ClientDlg::~ClientDlg (void) {
	delete m_close;
	delete m_start;
	delete m_browser;
}
void ClientDlg::onStart (void) {
	m_work.start ();
}
void ClientDlg::onUpdate (QString text) {
	m_browser->append (text);
}
