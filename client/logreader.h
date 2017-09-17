// 声明日志读取器类
#ifndef _LOGREADER_H
#define _LOGREADER_H
#include <string>
#include <list>
using namespace std;
#include "data.h"
#include "except.h"
// 日志读取器类
class LogReader {
public:
	// 构造器
	LogReader (const string& logFile,
		const string& loginsFile);
	// 读取日志
	list<MLogRec>& readLog (void)
		throw (ReadException);
private:
	// 备份日志文件
	void backup (void)
		throw (BackupException);
	// 读取登入文件
	void readLoginsFile (void)
		throw (ReadException);
	// 读取备份文件
	void readBackupFile (void)
		throw (ReadException);
	// 匹配登入登出
	void match (void);
	// 保存登入文件
	void saveLoginsFile (void)
		throw (SaveException);
	string m_logFile;    // 日志文件
	string m_loginsFile; // 登入文件
	string m_backupFile; // 备份文件
	list<LogRec>  m_logins;  // 登入日志记录集
	list<LogRec>  m_logouts; // 登出日志记录集
	list<MLogRec> m_logs;    // 匹配日志记录集
};
#endif // _LOGREADER_H
