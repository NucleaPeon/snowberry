#ifndef DAEMON_H
#define DAEMON_H

#include <QtCore/QDir>
#include <QtCore/QString>
#include <QtCore/QLockFile>
#include <QtCore/QProcess>

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>

const char* logfilename = "snowd.log";

class Daemon
{
public:
    Daemon();

    int start();
    int stop();
    int status();
    int restart();


    void log_message(char* filename, char* message);
    void signal_handler(int sig);
    void init_daemon();

private:
    int i;
    int lfp;
    char str[10];
    QLockFile *lockfile;
    QString lockfilename = "snowd.lock";
    QString pidfilename = "snowd.pid";
};

#endif // DAEMON_H
